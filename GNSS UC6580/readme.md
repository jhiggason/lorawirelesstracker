## ESP32-S3 to UC6580 GNSS Connections

| Wireless Tracker Pin   | ESP32-S3 Label | UC6580 Pin | UC6580 Label |
|----------------|----------------|------------|--------------|
| `38`           | `GNSS_TX`      | `19`       | `RX`         |
| `39`           | `GNSS_RX`      | `18`       | `TX`         |
| `35`           | `GNSS_RST`     | `17`       | `RESETN`     |
| `36`           | `PPS`          | `35`       | `PPS`        |

The ESP32-S3's `GNSS_TX` (pin 38) connects to the `RX` pin (pin 19) on the UC6580, and `GNSS_RX` (pin 39) connects to the `TX` pin (pin 18) on the UC6580. This makes sense as TX (transmit) on one device should connect to RX (receive) on the other, and vice versa. Additionally, the `GNSS_RST` (pin 35) of the ESP32-S3 connects to the `RESETN` pin (pin 17) on the UC6580. Lastly, the `PPS` (pin 36) of the ESP32-S3 is connected to the `PPS` pin (pin 35) on the UC6580.

For a library recommendation and usage with ESP32:

## Recommended GNSS Library

[TinyGPS++](https://github.com/mikalhart/TinyGPSPlus)

- **Description**: Designed for parsing NMEA data from GNSS modules. Offers an API for location, date, time, altitude, speed, and other data.
- **Installation**: Install from Arduino IDE's Library Manager or clone from GitHub.
- **Usage**:
  1. Include TinyGPS++ in your code.
  2. Create an instance of the TinyGPS++ object.
  3. Read UART data from the GNSS module and feed it to the TinyGPS++ object.
  4. Retrieve parsed data with the TinyGPS++ API.

### Sample Setup Code:

```cpp
#include <TinyGPS++.h>
TinyGPSPlus gps;

void setup(){
  Serial2.begin(9600); // Assuming GNSS module communicates at 9600 baud
}

void loop(){
  while (Serial2.available() > 0){
    gps.encode(Serial2.read());
  }
  
  if (gps.location.isUpdated()){
    Serial.print("Latitude: "); Serial.println(gps.location.lat(), 6);
    Serial.print("Longitude: "); Serial.println(gps.location.lng(), 6);
  }
}
```


This setup provides a simple example to read and display the GPS coordinates. You can expand upon this based on your specific project requirements.
