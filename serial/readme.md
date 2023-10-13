```cpp
void setup() {
  // put your setup code here, to run once:
USBSerial.begin(115200);
while(!USBSerial);
}

void loop() {
  // put your main code here, to run repeatedly:
USBSerial.println("Test test test...");
delay(1000);
}
```

Ensure that that the correct com port and baud rate is selected for your arduino serial monitor.  
