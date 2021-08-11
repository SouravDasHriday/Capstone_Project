int trigPin = 5;
int echoPin = 6;
int trigPin2 = 7;
int echoPin2 = 8;

int val=0;

int buz = 2;
int led = 4;
int led2 = 3;
int vib=12;
int vibval;
int button=11;
int count=0;

void setup() {
  Serial.begin(9600); 
   pinMode(led, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(buz, OUTPUT);
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   pinMode(trigPin2, OUTPUT);
   pinMode(echoPin2, INPUT);
   pinMode(vib, INPUT);
   pinMode(button, INPUT);
   pinMode(10, OUTPUT);
}

void loop() {

vibval=digitalRead(vib);
if (vibval==1)
{    
      count++;
      if(digitalRead(button)==1)
      {
       count=0;
      }
    Serial.print("Count:");
   Serial.println(count);
  
      if(count>=300)
      {
        count=0;
        digitalWrite(10,HIGH);
        delay(100);
                digitalWrite(10,LOW);
      }
   }

  long duration, distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);
  duration=pulseIn(echoPin, HIGH);
  distance =(duration/2)/29.1;
  Serial.print("distance");
  Serial.print(distance);
  Serial.println("CM");
  delay(5);

  long duration2, distance2;
  digitalWrite(trigPin2,HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin2, LOW);
  duration2=pulseIn(echoPin2, HIGH);
  distance2 =(duration2/2)/29.1;
  Serial.print("distance2: ");
  Serial.print(distance2);
  Serial.println("CM");
  delay(5);


 
   if(distance<=50)
   {
    digitalWrite(led, HIGH);
   }
   
   else if(distance>=31)
   {
     digitalWrite(led, LOW);
   }

   if(distance2<=50)
   {
    digitalWrite(led2, HIGH);

   }
   else if(distance2>=51)
   {
     digitalWrite(led2, LOW);
   }  

   if(distance2<=30 ||distance<=50)
   {
    digitalWrite(buz, HIGH);
   }
   else if(distance2>=51 && distance>=51 )
   {
     digitalWrite(buz, LOW);
   } 
}
