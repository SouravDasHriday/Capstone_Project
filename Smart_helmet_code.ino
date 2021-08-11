int trigPin = 9;
int echoPin = 8;
int trigPin2 = 11;
int echoPin2 = 10;
float latitude = 26.980883;
float longitude = 82.893321;


int buz = 12;
int spk = 5;
int led = 13;
int led2 = A0;
int vib = 2;
int vibval;
int button = 3;
int button2 = 4;
int count = 0;

void setup() {
  Serial.begin(9600); 
   pinMode(led, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(buz, OUTPUT);
   pinMode(spk, OUTPUT);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(trigPin2, OUTPUT);
   pinMode(echoPin2, INPUT);
   pinMode(vib, INPUT);
   pinMode(button, INPUT);
   pinMode(button2, INPUT);
}

void loop() {
vibval = digitalRead(vib);

if (vibval == 1)
{    
      count ++;
      if(digitalRead(button) == 1)
      {
       count = 0;
      }
    Serial.print("Count:");
    Serial.println(count);
  
      if(count >= 30)
      {
        Serial.println("SMS Sending To +8801773464883");
        Serial.println("Accident Occurred.....!");
        Serial.print("Latitude is: ");
        Serial.println(latitude);
        Serial.print("Longitude is: ");
        Serial.println(longitude);
      }
}

if(digitalRead(button2) == 1)
      {
           digitalWrite(spk, HIGH);
      }
else
{
  digitalWrite(spk, LOW);
}
  
  long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2)/29.1;
  Serial.print(distance);
  Serial.println("CM");
  delay(10);


  long duration2, distance2;
  digitalWrite(trigPin2,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 =(duration2/2)/29.1;
  Serial.print("distance2");
  Serial.print(distance2);
  Serial.println("CM");
  delay(10);


 
 if(distance <= 400)
   {
    digitalWrite(led, HIGH);
    digitalWrite(buz, HIGH);
   }
else if(distance >= 401)
   {
     digitalWrite(led, LOW);
     digitalWrite(buz, LOW);

   }

 if(distance2 <= 400)
   {
    digitalWrite(led2, HIGH);

   }
else if(distance2 >= 401)
   {
     digitalWrite(led2, LOW);
    
   }  

   if(distance2 <= 400 ||distance <= 400)
   {
    digitalWrite(buz, HIGH);

   }
else if(distance2 >= 401 && distance >= 401 )
   {
     digitalWrite(buz, LOW);
    
   } 
}
