# 🎮 Tetris Game With Arduino

<div align="center">

**Classic Tetris on 8x24 LED Tower Display | 8x24 LED Kule Ekranında Klasik Tetris**

*Arduino Uno + MAX7219 LED Matrix Modules + Analog Joystick*

![Arduino](https://img.shields.io/badge/Arduino-00979D?style=for-the-badge&logo=arduino&logoColor=white)
![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Status](https://img.shields.io/badge/Status-Active-success?style=for-the-badge)

[🇬🇧 English](#-about-the-project) • [🇹🇷 Türkçe](#-proje-hakkında)

[Demo Video](#-demo--demo-video) • [Installation](#-installation--kurulum) • [Circuit Diagram](#-circuit-diagram--devre-şeması) • [How to Play](#-how-to-play--nasıl-oynanır)

</div>

---

## 📝 About The Project | Proje Hakkında

**🇬🇧 English:**

This project is a **vertical version** of the classic Tetris game running on Arduino-based hardware. Instead of standard horizontal displays, 3 MAX7219 LED Matrix modules are connected vertically to create an **8x24 pixel tower display**.

Game control is provided via an **Analog Joystick** instead of buttons for a smoother experience. The code structure uses a **"Render on Change"** technique to prevent screen flickering, and the game speed increases dynamically based on difficulty level.

**🇹🇷 Türkçe:**

Bu proje, klasik Tetris oyununun Arduino tabanlı donanım üzerinde çalışan **dikey bir versiyonudur**. Standart yatay ekranlar yerine, 3 adet MAX7219 LED Matris modülü dikey olarak birbirine bağlanarak **8x24 piksellik bir kule ekranı** oluşturulmuştur.

Oyun kontrolü, buton yerine **Analog Joystick** ile sağlanarak daha akıcı bir deneyim hedeflenmiştir. Kod yapısında, ekran titremesini önlemek için **"Render on Change"** (Sadece değişimde çiz) tekniği kullanılmış ve oyun hızı, zorluk seviyesine göre dinamik olarak artırılmıştır.

### 🎯 Project Goals | Proje Hedefleri

**🇬🇧 English:**
- Create a physical, hardware-based Tetris game
- Learn SPI communication and LED matrix control
- Implement efficient rendering algorithms
- Build a fun, interactive embedded system project

**🇹🇷 Türkçe:**
- Fiziksel, donanım tabanlı bir Tetris oyunu oluşturmak
- SPI haberleşmesi ve LED matris kontrolünü öğrenmek
- Verimli render algoritmaları geliştirmek
- Eğlenceli, interaktif bir embedded sistem projesi yapmak

### ✨ Key Features | Öne Çıkan Özellikler

- 🎯 **Vertical Gameplay | Dikey Oynanış**: Real Tetris experience on 8x24 LED Tower | 8x24 LED Kule ile gerçek Tetris deneyimi
- 🕹️ **Analog Joystick Control | Analog Joystick Kontrolü**: More precise and smooth movement than buttons | Butonlardan daha hassas ve akıcı hareket
- 🎨 **Flicker-Free Display | Titremesiz Görüntü**: Render on Change algorithm eliminates screen flickering | Render on Change algoritması ile flicker-free ekran
- ⚡ **Dynamic Difficulty | Dinamik Zorluk**: Game speed increases as you progress | Oyun ilerledikçe artan hız
- 🔄 **Smooth Rotation | Yumuşak Döndürme**: Debounce-protected smooth block rotation | Debounce korumalı yumuşak döndürme
- 📊 **Line Clear Animation | Satır Silme Animasyonu**: Filled rows are cleared with animation | Dolu satırlar animasyonla silinir
- 🎮 **7 Classic Tetris Pieces | 7 Klasik Tetris Şekli**: I, J, L, O, S, T, Z shapes | I, J, L, O, S, T, Z şekilleri
- ⚙️ **SPI Daisy Chain | SPI Zincirleme Bağlantı**: Efficient use of Arduino pins with chained modules | Zincirleme bağlı modüllerle Arduino pinlerinin verimli kullanımı

---

## 🎥 Demo | Demo Video

<div align="center">

### Gameplay Video | Oyun Görüntüsü

https://github.com/user-attachments/assets/sample-video.mp4

*Demo video of the project in action | Projenin çalışır halinin demo videosu*

</div>

---

## 🛠️ Hardware Requirements | Donanım Gereksinimleri

| Component | Quantity | Description |
|-----------|----------|-------------|
| **Arduino Uno/Nano** | 1x | Main controller board | Ana kontrol kartı |
| **MAX7219 8x8 LED Matrix** | 3x | Daisy-chain connected display modules | Zincirleme bağlı ekran modülleri |
| **Analog Joystick Module** | 1x | XY axis + button | XY eksenli + buton |
| **Jumper Wires** | - | Male-to-male connection wires | Erkek-erkek bağlantı kabloları |
| **Breadboard** | 1x | (Optional) For prototyping | (Opsiyonel) Prototip için |

### 💰 Estimated Cost | Tahmini Maliyet

**🇬🇧 English:** Total estimated cost: **~$15-20** (All components included)

**🇹🇷 Türkçe:** Tahmini toplam maliyet: **~15-20$** (Tüm bileşenler dahil)

---

## 🔌 Circuit Diagram | Devre Şeması

<div align="center">

![Circuit Diagram](diagram-image/circuit_diagram.png)

</div>

### Connection Details | Bağlantı Detayları

#### 1️⃣ Power Bus | Güç Hattı

**🇬🇧 English:** All components are powered from a common power bus.

**🇹🇷 Türkçe:** Tüm bileşenler ortak güç hattından beslenir.

```
Arduino 5V  → All Modules VCC + Joystick VCC | Tüm Modüllerin VCC + Joystick VCC
Arduino GND → All Modules GND + Joystick GND | Tüm Modüllerin GND + Joystick GND
```

#### 2️⃣ LED Matrix Connection (Daisy Chain) | LED Matris Bağlantısı (Zincirleme)

**🇬🇧 English:** 3 modules are connected in a chain. The module closest to Arduino (bottom) = **Module 1**

**🇹🇷 Türkçe:** 3 modül birbirine zincirleme bağlıdır. Arduino'ya en yakın modül (en alt) = **Modül 1**

| Arduino Pin | Module Pin | Description |
|-------------|------------|-------------|
| `Pin 13` | `CLK` | Parallel to all modules' CLK pins | Tüm modüllerin CLK pinine paralel |
| `Pin 10` | `CS (LOAD)` | Parallel to all modules' CS pins | Tüm modüllerin CS pinine paralel |
| `Pin 11` | `DIN` | **Only to Module 1's DIN pin** | **Sadece 1. modülün DIN pinine** |

**📡 Data Flow | Veri Akışı:**
```
Arduino (Pin 11) → Module 1 (DIN) | Modül 1 (DIN)
                   Module 1 (DOUT) → Module 2 (DIN) | Modül 1 (DOUT) → Modül 2 (DIN)
                                     Module 2 (DOUT) → Module 3 (DIN) | Modül 2 (DOUT) → Modül 3 (DIN)
```

#### 3️⃣ Joystick Connection | Joystick Bağlantısı

| Arduino Pin | Joystick Pin | Function |
|-------------|--------------|----------|
| `A0` | `HORZ / VRX` | 🔄 Left-Right movement | Sağa-Sola hareket |
| `A1` | `VERT / VRY` | ⬇️ Fast drop (Soft Drop) | Hızlı düşme (Soft Drop) |
| `Pin 2` | `SEL / SW` | 🔃 Block rotation (90°) | Blok döndürme (90°) |

---

## 📥 Installation | Kurulum

### 1. Arduino IDE Setup | Arduino IDE Kurulumu

**🇬🇧 English:**
1. Download and install [Arduino IDE](https://www.arduino.cc/en/software)
2. Connect Arduino to your computer via USB

**🇹🇷 Türkçe:**
1. [Arduino IDE](https://www.arduino.cc/en/software) indirin ve kurun
2. Arduino'yu USB ile bilgisayara bağlayın

### 2. Library Installation | Kütüphane Kurulumu

**🇬🇧 English:** Required library: **LedControl** (for MAX7219 control)

**🇹🇷 Türkçe:** Gerekli kütüphane: **LedControl** (MAX7219 kontrolü için)

**Via Arduino IDE:**
```
Sketch → Include Library → Manage Libraries
Search: "LedControl" | Arama: "LedControl"
Author: Eberhard Fahle | Yazar: Eberhard Fahle
→ Install
```

**Or manually | Veya manuel olarak:**
```bash
# Clone the library
git clone https://github.com/wayoda/LedControl.git
# Copy to Arduino libraries folder | Arduino kütüphaneler klasörüne kopyalayın
```

### 3. Upload Code | Kod Yükleme

**🇬🇧 English:**
1. Open `sketch_nov27a/sketch_nov27a.ino` file in Arduino IDE
2. **Tools → Board** → Select Arduino Uno/Nano
3. **Tools → Port** → Select your COM port
4. Click **Upload** button (➡️)

**🇹🇷 Türkçe:**
1. `sketch_nov27a/sketch_nov27a.ino` dosyasını Arduino IDE ile açın
2. **Tools → Board** → Arduino Uno/Nano seçin
3. **Tools → Port** → COM portunu seçin
4. **Upload** butonuna basın (➡️)

### 4. Physical Assembly | Fiziksel Montaj

**🇬🇧 English:** ⚠️ **IMPORTANT**: The breadboard must be held **VERTICALLY (portrait)** for the game!

**🇹🇷 Türkçe:** ⚠️ **ÖNEMLİ**: Oyun için breadboard'u **DİKEY (portre)** tutmalısınız!

```
      [Module 3] ← Top | [Modül 3] ← En Üst
          ↑
      [Module 2] ← Middle | [Modül 2] ← Orta
          ↑
      [Module 1] ← Bottom (closest to Arduino) | [Modül 1] ← En Alt (Arduino'ya en yakın)
          ↑
      [Arduino]
```

---

## 🎮 How to Play | Nasıl Oynanır?

| Control | Action |
|---------|--------|
| 🕹️ **Joystick Left | Joystick Sola** | Move block left | Bloğu sola hareket ettir |
| 🕹️ **Joystick Right | Joystick Sağa** | Move block right | Bloğu sağa hareket ettir |
| 🕹️ **Joystick Down | Joystick Aşağı** | Fast drop (Soft Drop) | Hızlı düşme (Soft Drop) |
| 🔘 **Joystick Button | Joystick Butonu** | Rotate block 90° | Bloğu 90° döndür |

### Game Mechanics | Oyun Mekanikleri

**🇬🇧 English:**
- ✅ **Line Clearing**: Fully filled rows are automatically cleared
- ⚡ **Difficulty**: Game speeds up with each cleared line
- 🎯 **Objective**: Clear maximum lines before blocks reach the top
- 🎮 **Game Over**: Game resets when blocks reach the top

**🇹🇷 Türkçe:**
- ✅ **Satır Doldurma**: Tam dolu satırlar otomatik silinir
- ⚡ **Zorluk**: Her silinen satırda oyun hızlanır
- 🎯 **Hedef**: Bloklar tavana ulaşmadan maksimum satır silme
- 🎮 **Oyun Bitişi**: Bloklar tavana ulaştığında oyun sıfırlanır

---

## ⚙️ Technical Details | Teknik Detaylar

### Software Architecture | Yazılım Mimarisi

#### 🎨 Render on Change Algorithm | Render on Change Algoritması

**🇬🇧 English:** The display is only updated when the game state changes, preventing flickering:

**🇹🇷 Türkçe:** Ekran sadece oyun durumu değiştiğinde güncellenir, titremeyi önler:

```cpp
// Screen is not constantly refreshed → Prevents flickering
// Ekran sürekli yenilenmez → Titreme önlenir
// Display updates only when block moves
// Sadece blok hareket ettiğinde ekran güncellenir
if (updateScreen) {
    renderGame();
    updateScreen = false;
}
```

#### 📐 Coordinate System | Koordinat Sistemi

**🇬🇧 English:** Physically separate 3 modules work as a **single 8x24 coordinate plane** in software:

**🇹🇷 Türkçe:** Fiziksel olarak ayrı 3 modül, yazılımsal olarak **tek bir 8x24 koordinat düzlemi** gibi çalışır:

```
Y: 0-7   → Module 1 (Bottom) | Modül 1 (Alt)
Y: 8-15  → Module 2 (Middle) | Modül 2 (Orta)
Y: 16-23 → Module 3 (Top) | Modül 3 (Üst)
```

#### 🔄 Joystick Calibration Values | Joystick Kalibrasyon Değerleri

```cpp
// X Axis (Left-Right) | X Ekseni (Sağ-Sol)
if (analogRead(A0) < 200)  → Left | Sola
if (analogRead(A0) > 800)  → Right | Sağa

// Y Axis (Fast Drop) | Y Ekseni (Hızlı Düşme)
if (analogRead(A1) > 800)  → Down (Soft Drop) | Aşağı (Soft Drop)

// Button (Rotation) | Buton (Döndürme)
digitalRead(2) == LOW      → 90° Rotate | 90° Döndür
```

#### 🛡️ Debounce Protection | Debounce Koruması

```cpp
// Prevents button bounce/ghost presses
// Buton ark atlamasını önleme
unsigned long debounceDelay = 250; // ms
```

#### 🎯 Line Clearing Algorithm | Satır Silme Algoritması

```cpp
// Byte value 255 = Row completely filled
// Byte değeri 255 = Satır tamamen dolu
for (int row = 0; row < SCREEN_HEIGHT; row++) {
    if (board[row] == 255) {
        clearLine(row); // Clear with animation | Animasyon ile sil
        shiftDown(row); // Shift upper rows down | Üst satırları aşağı kaydır
    }
}
```

### Technologies Used | Kullanılan Teknolojiler

- 🔧 **Library | Kütüphane**: LedControl.h (SPI communication | SPI haberleşmesi)
- 💻 **Programming | Programlama**: C++ (Arduino)
- 🎮 **Hardware Protocol | Donanım Protokolü**: SPI (Serial Peripheral Interface)
- 📟 **Display Driver | Ekran Sürücüsü**: MAX7219
- 🎯 **Game Logic | Oyun Mantığı**: Custom Tetris implementation | Özel Tetris implementasyonu

---

## 📂 Project Structure | Proje Yapısı

```
Tetris-Game-With-Arduino/
│
├── sketch_nov27a/
│   └── sketch_nov27a.ino      # Main Arduino code | Ana Arduino kodu
│
├── diagram-image/
│   └── circuit_diagram.png    # Circuit diagram | Devre şeması
│
├── sample/
│   └── sample-video.mp4       # Demo video | Demo video
│
└── README.md                  # This file | Bu dosya
```

---

## 🐛 Troubleshooting | Sorun Giderme

### Display Not Working | Ekran Yanmıyor

- ✅ Check 5V and GND connections | 5V ve GND bağlantılarını kontrol edin
- ✅ Verify modules' CLK, CS, DIN pins | Modüllerin CLK, CS, DIN pinlerini doğrulayın
- ✅ Ensure LedControl library is installed | LedControl kütüphanesinin yüklü olduğundan emin olun
- ✅ Check if modules are properly daisy-chained | Modüllerin düzgün zincirleme bağlı olduğunu kontrol edin

### Joystick Not Working | Joystick Çalışmıyor

- ✅ Verify VRX → A0, VRY → A1 connections | VRX → A0, VRY → A1 bağlantısını kontrol edin
- ✅ Confirm joystick button pin is connected to Pin 2 | Joystick buton pininin Pin 2'ye bağlı olduğunu doğrulayın
- ✅ Read analog values from Serial Monitor (should be 0-1023) | Serial Monitor'dan analog değerleri okuyun (0-1023 arası)
- ✅ Test joystick with Serial Monitor to see raw values | Joystick'i Serial Monitor ile test edin

### Blocks Moving in Wrong Direction | Bloklar Ters Yönde Hareket Ediyor

- ✅ Adjust joystick direction calibration by reversing < and > signs in code | Joystick yön kalibrasyonunu koddaki < ve > işaretlerini ters çevirerek ayarlayın
- ✅ Check physical order of modules (Bottom→Top) | Modüllerin fiziksel sırasını kontrol edin (Alt→Üst)
- ✅ Verify joystick is not inverted | Joystick'in ters bağlı olmadığını kontrol edin

### Screen Flickering | Ekran Titriyor

- ✅ Ensure Render on Change algorithm is working correctly | Render on Change algoritmasının doğru çalıştığından emin olun
- ✅ Check if power supply provides sufficient current (all modules need ~200mA) | Güç kaynağının yeterli akımı sağladığını kontrol edin (~200mA)
- ✅ Try reducing display intensity: `lc.setIntensity(i, 2);` | Ekran parlaklığını azaltmayı deneyin

### Game Not Starting | Oyun Başlamıyor

- ✅ Check if code uploaded successfully | Kodun başarıyla yüklendiğini kontrol edin
- ✅ Verify all connections are secure | Tüm bağlantıların sağlam olduğunu doğrulayın
- ✅ Reset Arduino and check Serial Monitor for errors | Arduino'yu sıfırlayın ve Serial Monitor'da hataları kontrol edin

---

## 🚀 Future Improvements | Geliştirme Fikirleri

- [ ] Score display (7-segment display) | Skor tablosu (7-segment display)
- [ ] Sound effects (Buzzer module) | Ses efektleri (Buzzer modülü)
- [ ] Level indicator | Seviye göstergesi
- [ ] Pause/Resume feature | Duraklat/Devam özelliği
- [ ] High score saving (EEPROM) | Yüksek skor kaydı (EEPROM)
- [ ] Ghost piece (showing where block will land) | Ghost piece (bloğun düşeceği yerin gösterimi)
- [ ] Next piece preview | Sonraki parça önizlemesi
- [ ] Multiplayer mode | Çok oyunculu mod
- [ ] Different game modes | Farklı oyun modları

---

## 📸 Screenshots | Ekran Görüntüleri

> Update this section with your actual project photos | Bu bölümü gerçek projenizin fotoğraflarıyla güncelleyebilirsiniz

```
📷 Assembled project photos | Kurulmuş proje fotoğrafları
📷 Gameplay screenshots | Oyun anı ekran görüntüleri
📷 Circuit connection details | Devre bağlantı detayları
```

---

## 🤝 Contributing | Katkıda Bulunma

**🇬🇧 English:** Contributions are welcome! Please:

**🇹🇷 Türkçe:** Katkılarınızı bekliyorum! Lütfen:

1. 🍴 Fork this repository | Bu repo'yu fork edin
2. 🔨 Create a new branch (`git checkout -b feature/NewFeature`) | Yeni bir branch oluşturun
3. 💾 Commit your changes (`git commit -m 'Add new feature'`) | Değişikliklerinizi commit edin
4. 📤 Push to the branch (`git push origin feature/NewFeature`) | Branch'inizi push edin
5. 🔃 Open a Pull Request | Pull Request açın

---

## 📞 Contact | İletişim

**🇬🇧 English:** For questions or feedback, feel free to reach out:

**🇹🇷 Türkçe:** Sorularınız veya geri bildirimleriniz için benimle iletişime geçebilirsiniz:

- 💼 **GitHub**: [@basaranbaran](https://github.com/basaranbaran)
- 🔗 **Repository**: [Tetris-Game-With-Arduino](https://github.com/basaranbaran/Tetris-Game-With-Arduino)

---

## 🎓 What I Learned | Öğrendiklerim

**🇬🇧 English:** Through this project, I learned:

**🇹🇷 Türkçe:** Bu proje sayesinde:

- ✅ MAX7219 LED Matrix control | MAX7219 LED Matris kontrolünü
- ✅ SPI communication protocol | SPI haberleşme protokolünü
- ✅ Analog sensor reading (Joystick) | Analog sensör okumayı (Joystick)
- ✅ Game loop and state management | Oyun döngüsü ve state management
- ✅ Render optimization techniques | Render optimization tekniklerini
- ✅ Debounce algorithm implementation | Debounce algoritmasını
- ✅ Hardware-software integration | Donanım-yazılım entegrasyonunu
- ✅ Embedded systems programming | Embedded sistem programlamayı öğrendim

---

## 🙏 Acknowledgments | Teşekkürler

**🇬🇧 English:** Thanks to the resources that helped during development:

**🇹🇷 Türkçe:** Bu projeyi geliştirirken yardımcı olan kaynaklara teşekkürler:

- Arduino Community
- LedControl Library (Eberhard Fahle)
- Tetris Game Logic References
- All contributors and testers | Tüm katkıda bulunanlar ve test edenler

---

<div align="center">

**⭐ If you liked this project, don't forget to give it a star! ⭐**

**⭐ Bu projeyi beğendiyseniz yıldız vermeyi unutmayın! ⭐**

Made with ❤️ and Arduino

[⬆ Back to Top | Yukarı Çık](#-tetris-game-with-arduino)

</div>
