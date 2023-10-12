## ESP32-S3 to UC6580 GNSS Connections

| Wireless Tracker Pin   | ESP32-S3 Label | UC6580 Pin | UC6580 Label |
|----------------|----------------|------------|--------------|
| `33`           | `GNSS_TX`      | `19`       | `RX`         |
| `34`           | `GNSS_RX`      | `18`       | `TX`         |
| `35`           | `GNSS_RST`     | `17`       | `RESETN`     |
| `36`           | `PPS`          | `35`       | `PPS`        |

The ESP32-S3's `GNSS_TX` (pin 38) connects to the `RX` pin (pin 19) on the UC6580, and `GNSS_RX` (pin 39) connects to the `TX` pin (pin 18) on the UC6580. This makes sense as TX (transmit) on one device should connect to RX (receive) on the other, and vice versa. Additionally, the `GNSS_RST` (pin 35) of the ESP32-S3 connects to the `RESETN` pin (pin 17) on the UC6580. Lastly, the `PPS` (pin 36) of the ESP32-S3 is connected to the `PPS` pin (pin 35) on the UC6580.

## Recommended GNSS Library

[TinyGPS++](https://github.com/mikalhart/TinyGPSPlus)

- **Description**: Designed for parsing NMEA data from GNSS modules. Offers an API for location, date, time, altitude, speed, and other data.
- **Installation**: Install from Arduino IDE's Library Manager or clone from GitHub.
- **Usage**:
  1. Include TinyGPS++ in your code.
  2. Create an instance of the TinyGPS++ object.
  3. Read UART data from the GNSS module and feed it to the TinyGPS++ object.
  4. Retrieve parsed data with the TinyGPS++ API.

### Sample Code:

```cpp
#include <TinyGPS++.h>
#include <time.h>

// Objects for GNSS parsing and serial communication
TinyGPSPlus gps;
HardwareSerial GNSSSerial(2);

// Pin definitions for GNSS module communication
const int GNSS_RXPin = 34;
const int GNSS_TXPin = 33;
const int GNSS_RSTPin = 35; //There is a function built for this in the example below- currently it isn't used
const int GNSS_PPS_Pin = 36;

// Flags for PPS handling and synchronization status
volatile bool ppsFlag = false;
volatile bool initialSyncDone = false;

// Timestamp for the last valid GNSS data received
unsigned long lastGNSSDataMillis = 0;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(115200);

  // Start GNSS module communication
  GNSSSerial.begin(115200, SERIAL_8N1, GNSS_TXPin, GNSS_RXPin);

  // Configure GNSS reset pin
  pinMode(GNSS_RSTPin, OUTPUT);
  digitalWrite(GNSS_RSTPin, HIGH);

  // Set up PPS pin and attach an interrupt handler
  pinMode(GNSS_PPS_Pin, INPUT);
  attachInterrupt(digitalPinToInterrupt(GNSS_PPS_Pin), ppsInterrupt, RISING);

  // Short delay for GNSS module initialization
  delay(1000);
}

void loop() {
  // Process incoming GNSS data
  while (GNSSSerial.available()) {
    if (gps.encode(GNSSSerial.read())) {
      // Update the timestamp when valid GNSS data is received
      lastGNSSDataMillis = millis();
      displayGNSSData();  // Display GNSS data for debugging
    }
  }

  // Perform initial synchronization using NMEA time data
  if (!initialSyncDone && gps.date.isValid() && gps.time.isValid()) {
    setSystemTime();
    initialSyncDone = true;
    Serial.println("Initial time synchronization done using NMEA data.");
  }

  // Disable interrupts to safely check and reset the PPS flag
  noInterrupts();
  if (ppsFlag) {
    fineTuneSystemTime();  // Adjust system time based on the PPS pulse
    ppsFlag = false;
  }
  // Re-enable interrupts
  interrupts();

  // Check if GNSS data has been absent for more than a minute
  if (millis() - lastGNSSDataMillis > 60000) {
    Serial.println("Warning: Haven't received GNSS data for more than 1 minute!");
    // Additional actions can be added here, like alerts or module resets.
  }
}

// Interrupt handler for the PPS signal
void ppsInterrupt() {
  ppsFlag = true;
}

// Function to set system time using GNSS data
void setSystemTime() {
  struct tm timeinfo;
  timeinfo.tm_year = gps.date.year() - 1900;
  timeinfo.tm_mon = gps.date.month() - 1;
  timeinfo.tm_mday = gps.date.day();
  timeinfo.tm_hour = gps.time.hour();
  timeinfo.tm_min = gps.time.minute();
  timeinfo.tm_sec = gps.time.second();
  time_t t = mktime(&timeinfo);

  timeval tv = { t, 0 };
  settimeofday(&tv, NULL);  // Update system time
}

// Function to fine-tune system time using the PPS pulse
void fineTuneSystemTime() {
  timeval tv;
  gettimeofday(&tv, NULL);
  tv.tv_usec = 0;  // Reset microseconds to zero
  settimeofday(&tv, NULL); // Update system time
  Serial.println("System time fine-tuned using PPS signal.");
}

// Debugging function to display GNSS data
void displayGNSSData() {
  Serial.print("Latitude: "); Serial.println(gps.location.lat(), 6);
  Serial.print("Longitude: "); Serial.println(gps.location.lng(), 6);
  Serial.print("Altitude: "); Serial.println(gps.altitude.meters());
  Serial.print("Speed: "); Serial.println(gps.speed.kmph());
  Serial.println("-----------------------------");
}
```

