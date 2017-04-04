#include <SoftwareSerial.h>

SoftwareSerial portOne(3, 2); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  delay(10);
  portOne.begin(9600);

  portOne.println("hc-05");
  // set the data rate for the SoftwareSerial port
  pinMode(13, OUTPUT); 

}
char serial = 0;
char port = 0;
int ifcount = 0;
void loop() { // run over and over
    portOne.listen();

    if (portOne.available()) {
      while(portOne.available()){
      port = portOne.read();
      digitalWrite(13, HIGH);
      portOne.write(port);
//      portOne.println();

      Serial.write(port);
//      Serial.println();

      }
            portOne.println();
            Serial.println();



    }
  

  if (Serial.available()) {
    while(Serial.available()){
    serial = Serial.read();
    digitalWrite(13, LOW);

    
    Serial.write(serial);
//Serial.println();
portOne.write(serial);
//portOne.println();
 }
 portOne.println();
            Serial.println();

  }
}
