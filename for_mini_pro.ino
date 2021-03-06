#include <TinyGPS++.h>
TinyGPSPlus gps;
double latitude, longitude;

#include <SoftwareSerial.h>
SoftwareSerial SIM800L(10, 11);

String response;
int lastStringLength = response.length();

String link;

void setup() {
  Serial.begin(9600);
  Serial.println("GPS Mulai");
  pinMode(9,INPUT);
    SIM800L.begin(9600);  
    SIM800L.println("AT+CMGF=1");
    Serial.println("SIM800L started at 9600");
    delay(1000);
    Serial.println("Setup Complete! SIM800L is Ready!");
    SIM800L.println("AT+CNMI=2,2,0,0,0");
 
}

void loop() {

  if (SIM800L.available()>0)
  {
    response = SIM800L.readStringUntil('\n');
  }
     
      GPS();
     if(digitalRead(9)==1)
    {
  
       SIM800L.println("AT+CMGF=1");    //Sets the GSM Module in Text Mode
       delay(1000);  // Delay of 1 second
       SIM800L.println("AT+CMGS=\"+8801773464883\"\r"); // Replace x with mobile number
       delay(1000);
       SIM800L.println("Accident Occurred ");// The SMS text you want to send
       delay(100);
       SIM800L.println(link);// The SMS text you want to send
       delay(100);
       SIM800L.println((char)26);// ASCII code of CTRL+Z for saying the end of sms to  the module 
       delay(1000);
    }

}

void GPS(){
  if(Serial.available()) {
    gps.encode(Serial.read());
  }
  if(gps.location.isUpdated()) {
    latitude = gps.location.lat();
    longitude = gps.location.lng();
    link = "www.google.com/maps/place/" + String(latitude, 6) + "," + String(longitude, 6) ;
       
  }
}
