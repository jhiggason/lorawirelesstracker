# Wireless Tracker (Heltek and MakerFocus) 

The Wireless Tracker is a cutting-edge development kit that combines the power of ESP32-S3FN8, SX1262, and UC6580 chips. This trifecta of hardware enables the device to provide versatile IoT applications, from GNSS solutions to LoRa communications plus an onboard OLED display. Whether you're tracking assets, monitoring livestock, locating vehicles, or safeguarding children, the Wireless Tracker is the perfect fit.

US Purchase: [Amazon.com](https://www.amazon.com/MakerFocus-Integrate-Bluetooth-Development-Intelligent/dp/B0CG1GG1LQ/ref=sr_1_1?crid=1SBXCY6AJ0AAO&keywords=makerfocus+tracker&qid=1696472127&sprefix=makerfocus+tracker%2Caps%2C148&sr=8-1) <$30.00USD

![Image of Wireless Tracker](/githubstuff/heltectrackerimg.png)

## Features
#Advanced Chips
  <summary><b>ESP32-S3FN8</b></summary>
  
  - **Connectivity**: The ESP32-S3FN8 supports both Wi-Fi and Bluetooth connectivity, allowing for versatile wireless communication.
  
  - **GPIO Pins**: There are 9 GPIO pins available for various functions:
    - `21 (GPIO)`
    - `26 (GPIO/SerialSPI)`
    - `4`
    - `5`
    - `6 (GPIO, ADC/DAC)`
    - `7 (GPIO, ADC/DAC)`
    - `15 (GPIO, ADC/DAC, SerialSPI)`
    - `16 (GPIO, ADC/DAC, SerialSPI)`
    - `17 (GPIO, ADC/DAC, SerialSPI)`

  <summary><b>SX1262</b></summary>
  
  - **LoRa Communication**: The SX1262 module facilitates long-range (LoRa) communication. LoRa is a spread spectrum modulation technique derived from chirp spread spectrum (CSS) technology, allowing for long-range communication with low power consumption.
  

  <summary><b>UC6580</b></summary>
  
  - **GNSS Solutions**: The UC6580 provides fast Global Navigation Satellite System (GNSS) solutions. This allows for high-precision tracking, making it suitable for applications where precise location tracking is crucial.
  


### Advanced GNSS Capabilities
- Dual-frequency multi-system based on 22nm technology.
- Supports L1 + L5/L2 positioning.
- Compatible with multiple satellite systems: GPS, GLONASS, BDS, Galileo, NAVIC, and QZSS.

### Design and Interfaces
- **Type-C USB Interface**: Equipped with voltage regulation, ESD protection, short circuit protection, RF shielding, and more.
- **Battery Management**: Onboard SH1.25-2 battery interface with integrated lithium battery management system, including charge/discharge management, overcharge protection, battery power detection, and automatic switching between USB and battery power.
- **Connectivity**: Dedicated 2.4GHz metal spring antenna for Wi-Fi and Bluetooth. Reserved IPEX (U.FL) interface for LoRa and GNSS.
- **Display**: 0.96-inch 160x80 dot matrix OLED for showcasing debugging information, battery status, and more.

### Developer-Friendly
- Seamless compatibility with the Arduino development environment, simplifying innovation and prototyping.

## Applications
- **Bicycle Sharing**: Track bicycles in real-time.
- **Pet and Livestock Tracking**: Ensure their safety and monitor movements.
- **Vehicle Location**: Manage fleet vehicles or locate personal cars.
- **Child Safety**: Actively track and ensure children's safety.

## Getting Started

[Heltec Wireless Tracker Manual](/manual/heltecwirelesstrackermanual.markdown)

[Arduino library for Heltec ESP32 (or ESP32+LoRa) based boards](https://github.com/HelTecAutomation/Heltec_ESP32)

[Heltec Additional Information](https://docs.heltec.cn/en/node/esp32/wireless_tracker/index.html)

[<img src="githubstuff/heltectracker.jpg" width="400" height="300" alt="3dprintphoto">](/3D%20Printed%20Case/README.md)

[3D printable case here!](/3D%20Printed%20Case/README.md)


### Prerequisites
- Arduino IDE
- [Any other dependencies or software requirements]

### Setup Instructions
1. Connect the device using the Type-C USB interface.
2. [Other steps for initial setup]

## Contributing

To contribute to the development or enhancement of the Wireless Tracker software, please [link to contributing guidelines or any related info].

## Support and Contact

For any questions, support, or feedback, reach out to [Your Contact Information/Support Channel].

## License
[Your licensing information]

---
