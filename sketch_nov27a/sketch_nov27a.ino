/*
  Arduino Vertical Tetris - STABLE VERSION
  Sorun Çözümü: "Render on Change" (Sadece değişimde çiz)
  Sonuç: Sıfır Titreme, Sabit Görüntü.
*/

#include "LedControl.h"

// --- PINLER ---
#define PIN_DIN 11
#define PIN_CLK 13
#define PIN_CS  10

// JOYSTICK
#define JOY_X A0
#define JOY_Y A1
#define JOY_SW 2

#define NUM_DEVICES 3 
#define MAX_Y 24 

LedControl lc = LedControl(PIN_DIN, PIN_CLK, PIN_CS, NUM_DEVICES);

// --- OYUN AYARLARI ---
unsigned long lastMoveTime = 0;
const int normalSpeed = 600; 
const int fastSpeed = 50;    

// Joystick ve Kontrol
unsigned long lastInputTime = 0;
unsigned long lastButtonPress = 0;

// EKRAN GÜNCELLEME BAYRAĞI (Sihirli Değişken)
bool updateScreen = true; 

byte board[24]; 

const uint16_t shapes[7][4] = {
  {0x0F00, 0x2222, 0x00F0, 0x4444}, // I
  {0x44C0, 0x8E00, 0xC880, 0xE200}, // J
  {0x4460, 0x0E80, 0xC440, 0x2E00}, // L
  {0xCC00, 0xCC00, 0xCC00, 0xCC00}, // O
  {0x06C0, 0x8C40, 0x6C00, 0x4620}, // S
  {0x0E40, 0x4C40, 0x4E00, 0x4640}, // T
  {0x0C60, 0x4C80, 0xC600, 0x2640}  // Z
};

int currentShape; 
int currentRot;   
int px, py;       
bool gameOver = false;

void setup() {
  pinMode(JOY_SW, INPUT_PULLUP);
  randomSeed(analogRead(A5));
  
  for (int i = 0; i < NUM_DEVICES; i++) {
    lc.shutdown(i, false);
    lc.setIntensity(i, 4); // Parlaklık
    lc.clearDisplay(i);
  }
  
  newBlock();
}

void loop() {
  if (gameOver) {
    playGameOver();
    resetGame();
    return;
  }

  // --- 1. JOYSTICK KONTROLÜ ---
  if (millis() - lastInputTime > 80) { 
    int xVal = analogRead(JOY_X);
    int yVal = analogRead(JOY_Y);
    int swVal = digitalRead(JOY_SW);

    // SAĞ - SOL
    if (xVal < 200) { 
      if (move(-1, 0)) updateScreen = true; // Sadece hareket ederse çiz
    }       
    else if (xVal > 800) {
      if (move(1, 0)) updateScreen = true;
    }

    // DÖNDÜRME
    if (swVal == LOW && (millis() - lastButtonPress > 250)) {
      rotate();
      lastButtonPress = millis();
      updateScreen = true; // Döndüyse çiz
    }
    lastInputTime = millis();
  }

  // --- 2. YERÇEKİMİ ---
  int currentSpeed = normalSpeed;
  if (analogRead(JOY_Y) > 800) currentSpeed = fastSpeed;

  if (millis() - lastMoveTime > currentSpeed) {
    if (move(0, -1)) {
      // Başarıyla aşağı indi
      updateScreen = true; // Hareket var, çiz
    } else { 
      // Çakıldı
      lockBlock();     
      checkLines();    
      newBlock();      
      updateScreen = true; // Yeni blok geldi, çiz
      
      if (checkCollision(px, py, currentRot)) {
        gameOver = true;
      }
    }
    lastMoveTime = millis();
  }
  
  // --- 3. EKRAN GÜNCELLEME (EN ÖNEMLİ KISIM) ---
  // Eğer hiçbir şey değişmediyse, ekrana dokunma!
  // Bu satır titremeyi tamamen yok eder.
  if (updateScreen) {
      renderGame();
      updateScreen = false; // Çizdik, bayrağı indir.
  }
}

// --- GÖRÜNTÜ OLUŞTURMA ---
void renderGame() {
    // 1. Görüntüyü hafızada hazırla
    byte displayBuffer[24];

    // Önce zemini kopyala
    for(int i=0; i<24; i++) {
        displayBuffer[i] = board[i];
    }

    // Sonra düşen bloğu ekle
    uint16_t bitMap = shapes[currentShape][currentRot];
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            if (bitMap & (0x8000 >> (row * 4 + col))) {
                int realX = px + col;
                int realY = py + (3 - row);
                
                if (realY >= 0 && realY < 24 && realX >= 0 && realX < 8) {
                    bitWrite(displayBuffer[realY], realX, 1);
                }
            }
        }
    }

    // Hafızadakini ekrana bas (Sadece değişen satırlar için optimize edilebilir ama şimdilik gerek yok)
    for(int y=0; y<24; y++) {
        setRowRaw(y, displayBuffer[y]);
    }
}

// --- OYUN MANTIĞI ---

void newBlock() {
  currentShape = random(0, 7);
  currentRot = 0;
  px = 2; 
  py = MAX_Y - 4; 
}

bool move(int dx, int dy) {
  if (!checkCollision(px + dx, py + dy, currentRot)) {
    px += dx;
    py += dy;
    return true; 
  }
  return false; 
}

void rotate() {
  int newRot = (currentRot + 1) % 4;
  if (!checkCollision(px, py, newRot)) {
    currentRot = newRot;
  }
}

bool checkCollision(int x, int y, int rot) {
  uint16_t bitMap = shapes[currentShape][rot];
  for (int row = 0; row < 4; row++) {
    for (int col = 0; col < 4; col++) {
      if (bitMap & (0x8000 >> (row * 4 + col))) {
        int realX = x + col;
        int realY = y + (3 - row);
        if (realX < 0 || realX >= 8 || realY < 0) return true;
        if (realY < MAX_Y && bitRead(board[realY], realX)) return true;
      }
    }
  }
  return false;
}

void lockBlock() {
  uint16_t bitMap = shapes[currentShape][currentRot];
  for (int row = 0; row < 4; row++) {
    for (int col = 0; col < 4; col++) {
      if (bitMap & (0x8000 >> (row * 4 + col))) {
        int realX = px + col;
        int realY = py + (3 - row);
        if (realY >= 0 && realY < MAX_Y) {
          bitWrite(board[realY], realX, 1);
        }
      }
    }
  }
}

void checkLines() {
  for (int y = 0; y < MAX_Y; y++) {
    if (board[y] == 255) { 
      // Efekt
      for(int k=0; k<2; k++) { setRowRaw(y, 0); delay(40); setRowRaw(y, 255); delay(40); }
      
      for (int k = y; k < MAX_Y - 1; k++) {
        board[k] = board[k + 1];
      }
      board[MAX_Y - 1] = 0; 
      y--; 
    }
  }
}

void setRowRaw(int y, byte data) {
    int device = y / 8;
    int row = y % 8;
    if(device < NUM_DEVICES) lc.setRow(device, row, data);
}

void playGameOver() {
    for(int i=0; i<3; i++) {
      for(int y=0; y<24; y++) setRowRaw(y, 255);
      delay(200);
      for(int y=0; y<24; y++) setRowRaw(y, 0);
      delay(200);
    }
}

void resetGame() {
  for (int i = 0; i < 24; i++) board[i] = 0;
  gameOver = false;
  newBlock();
  updateScreen = true;
}