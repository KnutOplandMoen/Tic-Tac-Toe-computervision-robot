#include <Servo.h>
#include <SoftwareSerial.h>
Servo servo1; 
Servo servo2;
Servo servo3;
Servo servo4;

int pos;
int incomingByte;
int dataval;
int brikke; 

void setup() {
  Serial.begin(9600);  
      
  servo1.attach(2);
  servo2.attach(3); 
  servo3.attach(4);
  servo4.attach(5);

  servo1.write(180); 
  servo2.write(90);
  servo3.write(0);
  servo4.write(90);

  delay(2000);
}

void startsted1()
//collecting the chip from startingposition 1
{
  for (pos = 90; pos >= 0; pos -= 1) { 
    //for loop that goes from one position another with a given 
    //delay between each 1 degree change in position so that the arm doesnt move too fast
    servo4.write(pos);
    delay(15); 
  }
  delay(1000);
  for (pos = 180; pos >= 90;pos -= 1) { 
    servo1.write(pos); 
    delay(15); 
  }
  for (pos = 90; pos <= 170; pos += 1) { 

    servo2.write(pos); 
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 0; pos <= 0; pos += 1) { 

    servo3.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(2000);
   
    for (pos = 0; pos <= 170; pos += 1) { 

    servo4.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  
delay(2000);

  
  for (pos = 173; pos >= 90; pos -= 1) { 

    servo2.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);

  for (pos = 0; pos >= 0; pos -= 1) { 

    servo3.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 170; pos >= 110; pos -= 1) { 

    servo4.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
    for (pos = 90; pos <= 93;pos += 1) { 

    servo1.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  

}

void startsted2()
{
  //collecting the chip from starting position 2
  for (pos = 90; pos <= 110; pos += 1) { 

    servo4.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);
  for (pos = 180; pos >= 90;pos -= 1) { 

    servo1.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 90; pos <= 168; pos += 1) { 

    servo2.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 0; pos <= 30; pos += 1) { 

    servo3.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(2000);
   
    for (pos = 110; pos <= 130; pos += 1) { 

    servo4.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  
delay(2000);
  
  for (pos = 168; pos >= 90; pos -= 1) { 

    servo2.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);

  for (pos = 20; pos >= 0; pos -= 1) { 

    servo3.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 110; pos <= 110; pos += 1) { 

    servo4.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 90; pos <= 93;pos += 1) { 

    servo1.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
}

void startsted3()
{
  //collecting the chip
  for (pos = 90; pos >= 0; pos -= 1) { 

    servo4.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);
  for (pos = 180; pos >= 116;pos -= 1) { 

    servo1.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 90; pos <= 165; pos += 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 0; pos <= 5; pos += 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(2000);
   
  for (pos = 0; pos <= 160; pos += 1) { 
   // in steps of 1 degree
   servo4.write(pos);// tell servo to go to position in variable "pos"
   delay(15); // waits 15ms for the servo to reach the position
  }
  
delay(2000);
 
  for (pos = 165; pos >= 90; pos -= 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);

  for (pos = 5; pos >= 0; pos -= 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 150; pos >= 110; pos -= 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
    for (pos = 116; pos >= 93;pos -= 1) { 

    servo1.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
}

 void startsted4()
 {
  //collecting the chip
  for (pos = 90; pos <= 110; pos += 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);
  for (pos = 180; pos >= 107;pos -= 1) { 

    servo1.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 90; pos <= 168; pos += 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 0; pos <= 30; pos += 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(2000);
   
    for (pos = 110; pos <= 130; pos += 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  
delay(2000);
  
  for (pos = 168; pos >= 90; pos -= 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);

  for (pos = 30; pos >= 0; pos -= 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 110; pos <= 110; pos += 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 107; pos >= 93;pos -= 1) { 

    servo1.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
 }
 
void startsted5()
{
  //collecting the chip 
  for (pos = 90; pos <= 150; pos += 1) { 

    servo4.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);
  for (pos = 180; pos >= 90;pos -= 1) { 

    servo1.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 90; pos <= 170; pos += 1) { 

    servo2.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 0; pos <= 50; pos += 1) { 

    servo3.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }

  for (pos = 150; pos >= 80; pos -= 1) { 

    servo4.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);
  for (pos = 50; pos <= 65; pos += 1) { 

    servo3.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }

  
delay(2000);

// Mellom posisjon
  
  for (pos = 170; pos >= 90; pos -= 1) { 

    servo2.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);

  for (pos = 65; pos >= 0; pos -= 1) { 
    
    servo3.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 80; pos <= 110; pos += 1) { 

    servo4.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 90; pos <= 93;pos += 1) { 

    servo1.write(pos); // tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
}


void loop() {
if (Serial.available() > 0) {
  //reads incomingbyte from python 
 incomingByte = Serial.read();
 //translates incomingbyte to what chip is being picket up (brikke)
 //and to what route the chip is going to (dataval) and saves these two values
  
 if (incomingByte == 'a')
 {
  dataval = 1;
  brikke = 1;
 }
  else if (incomingByte == 'j')
 {
  dataval = 1;
  brikke = 2;
 }
  else if (incomingByte == 's')
 {
  dataval = 1;
  brikke = 3;
 }
   else if (incomingByte == 'B')
 {
  dataval = 1;
  brikke = 4;
 }
   else if (incomingByte == 'K'){
  dataval = 1;
  brikke = 5;
 }
   else if (incomingByte == 'b')
 {
  dataval = 2;
  brikke = 1;
 }
   else if (incomingByte == 'k')
 {
  dataval = 2;
  brikke = 2;
 }
    
   else if (incomingByte == 't')
 {
  dataval = 2;
  brikke = 3;
 }
   else if (incomingByte == 'C')
 {
  dataval = 2;
  brikke = 4;
 }
  else if (incomingByte == 'L')
 {
  dataval = 2;
  brikke = 5;
 }

  else if (incomingByte == 'c')
 {
  dataval = 3;
  brikke = 1;
 }

  else if (incomingByte == 'l')
 {
  dataval = 3;
  brikke = 2;
 }

  else if (incomingByte == 'u')
 {
  dataval = 3;
  brikke = 3;
 }

  else if (incomingByte == 'D')
 {
  dataval = 3;
  brikke = 4;
 }

  else if (incomingByte == 'M')
 {
  dataval = 3;
  brikke = 5;
 }

  else if (incomingByte == 'd')
 {
  dataval = 4;
  brikke = 1;
 }

  else if (incomingByte == 'm')
 {
  dataval = 4;
  brikke = 2;
 }

  else if (incomingByte == 'v')
 {
  dataval = 4;
  brikke = 3;
 }

  else if (incomingByte == 'E')
 {
  dataval = 4;
  brikke = 4;
 }

  else if (incomingByte == 'N')
 {
  dataval = 4;
  brikke = 5;
 }

  else if (incomingByte == 'e')
 {
  dataval = 5;
  brikke = 1;
 }

  else if (incomingByte == 'n')
 {
  dataval = 5;
  brikke = 2;
 }
  else if (incomingByte == 'w')
 {
  dataval = 5;
  brikke = 3;
 }
  else if (incomingByte == 'F')
 {
  dataval = 5;
  brikke = 4;
 }

  else if (incomingByte == 'O')
 {
  dataval = 5;
  brikke = 5;
 }

  else if (incomingByte == 'f')
 {
  dataval = 6;
  brikke = 1;
 }

  else if (incomingByte == 'o')
 {
  dataval = 6;
  brikke = 2;
 }


  else if (incomingByte == 'x')
 {
  dataval = 6;
  brikke = 3;
 }

  else if (incomingByte == 'G')
 {
  dataval = 6;
  brikke = 4;
 }

  else if (incomingByte == 'P')
 {
  dataval = 6;
  brikke = 5;
 }

  else if (incomingByte == 'g')
 {
  dataval = 7;
  brikke = 1;
 }

  else if (incomingByte == 'p')
 {
  dataval = 7;
  brikke = 2;
 }

  else if (incomingByte == 'y')
 {
  dataval = 7;
  brikke = 3;
 }

  else if (incomingByte == 'H')
 {
  dataval = 7;
  brikke = 4;
 }

  else if (incomingByte == 'Q')
 {
  dataval = 7;
  brikke = 5;
 }

  else if (incomingByte == 'h')
 {
  dataval = 8;
  brikke = 1;
 }

  else if (incomingByte == 'q')
 {
  dataval = 8;
  brikke = 2;
 }

 
  else if (incomingByte == 'z')
 {
  dataval = 8;
  brikke = 3;
 }


 
  else if (incomingByte == 'I')
 {
  dataval = 8;
  brikke = 4;
 }

 else if (incomingByte == 'R')
 {
  dataval = 8;
  brikke = 5;
 }
  else if (incomingByte == 'i')
 {
  dataval = 9;
  brikke = 1;
 }
 else if (incomingByte == 'r')
 {
  dataval = 9;
  brikke = 2;
 }

 else if (incomingByte == 'A')
 {
  dataval = 9;
  brikke = 3;
 }

 
 else if (incomingByte == 'J')
 {
  dataval = 9;
  brikke = 4;
 }

 else if (incomingByte == 'S')
 {
  dataval = 9;
  brikke = 5;
 }


if (dataval == 9)
{
  if (brikke == 1){
    startsted1();
  }
  else if (brikke == 2){
    startsted2();
  }

  else if (brikke == 3){
    startsted3();
  }

  else if (brikke == 4){
    startsted4();
  }
  else if (brikke == 5){
    startsted5();
  }

 //putting the chip on the table

  for (pos = 110; pos <= 150; pos += 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position

  }
  delay(1000);
  for (pos = 93; pos >= 57; pos -= 1) { 

    servo1.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 90; pos <= 160; pos += 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }

  for (pos = 0; pos <= 0; pos += 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }

delay(2000);
  
//going back to starting position     
    
 for (pos = 150; pos >= 5; pos -= 1) { 

  servo4.write(pos);// tell servo to go to position in variable "pos"
  delay(15); // waits 15ms for the servo to reach the position
 }
  delay(2000);
  for (pos = 0; pos >= 0; pos -= 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 160; pos >= 90; pos -= 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);
  for (pos = 57; pos <= 180; pos += 1) { 

    servo1.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 5; pos <= 90; pos += 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position

  }  
}

else if (dataval == 8)
{
  if (brikke == 1){
    startsted1();
  }
  else if (brikke == 2){
    startsted2();
  }

  else if (brikke == 3){
    startsted3();
  }

  else if (brikke == 4){
    startsted4();
  }
  else if (brikke == 5){
    startsted5();
  }

//putting the chip on the table 

  for (pos = 110; pos <= 130; pos += 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);
  
  for (pos = 93; pos >= 38; pos -= 1) { 

    servo1.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }   
  delay(1000); 
  for (pos = 0; pos <= 25; pos += 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);
  for (pos = 90; pos <= 170; pos += 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }

  //going back to start position 
delay(2000);

  for (pos = 25; pos >= 0; pos -= 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }

delay(1000);


  for (pos = 170; pos >= 90; pos -= 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }

  delay(1000);
  for (pos = 38; pos <= 180; pos += 1) { 

    servo1.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 90; pos <= 90; pos += 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position

  }

}

else if (dataval == 7)
{
  if (brikke == 1){
    startsted1();
  }
  else if (brikke == 2){
    startsted2();
  }

  else if (brikke == 3){
    startsted3();
  }

  else if (brikke == 4){
    startsted4();
  }
  else if (brikke == 5){
    startsted5();
  }


//putting the chip on the table

  for (pos = 110; pos >= 80; pos -= 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position

  }
  delay(1000);
  for (pos = 93; pos >= 28; pos -= 1) { 

    servo1.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }    
  
  for (pos = 0; pos <= 55; pos += 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  
  for (pos = 90; pos <= 163; pos += 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }


delay(1000);

//Må gå tilbake til startposisjon

  for (pos = 55; pos >= 0; pos -= 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }  
  for (pos = 163; pos >= 90; pos -= 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }

  delay(1000);
  for (pos = 28; pos <= 180; pos += 1) { 

    servo1.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 80; pos <= 90; pos += 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }  
}

else if (dataval == 4)
{
  if (brikke == 1){
    startsted1();
  }
  else if (brikke == 2){
    startsted2();
  }

  else if (brikke == 3){
    startsted3();
  }

  else if (brikke == 4){
    startsted4();
  }
  else if (brikke == 5){
    startsted5();
  }



  //Skal legge brikke på bordet
   for (pos = 110; pos >= 80; pos -= 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);

  for (pos = 93; pos >= 43; pos -= 1) { 

    servo1.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }   
  for (pos = 80; pos >= 60; pos -= 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 0; pos <= 78; pos += 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
 } 
  for (pos = 90; pos <= 168; pos += 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }

//Startposisjon
  
  delay(2000);

  for (pos = 78; pos >= 60; pos -= 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
    }
  for (pos = 168; pos >= 90; pos -= 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);
  for (pos = 60; pos >= 0; pos -= 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
    }
  for (pos = 43; pos <= 180; pos += 1) { 

    servo1.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }  
  for (pos = 60; pos <= 90; pos += 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }


}
else if (dataval == 5)
{
  if (brikke == 1){
    startsted1();
  }
  else if (brikke == 2){
    startsted2();
  }

  else if (brikke == 3){
    startsted3();
  }

  else if (brikke == 4){
    startsted4();
  }
  else if (brikke == 5){
    startsted5();
  }

  //Skal legge brikke på bordet
 
  for (pos = 110; pos >= 100; pos -= 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);
  for (pos = 93; pos >= 50; pos -= 1) { 

    servo1.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }   
  for (pos = 0; pos <= 52; pos += 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
 } 

  for (pos = 90; pos <= 165; pos += 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
delay(2000);
//Startposisjon  
  for (pos = 100; pos >= 70; pos -= 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
 }
  for (pos = 52; pos >= 40; pos -= 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);
  for (pos = 165; pos >= 90; pos -= 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  
  for (pos = 40; pos >= 0; pos -= 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  
  for (pos = 50; pos <= 180; pos += 1) { 

    servo1.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }

  for (pos = 70; pos <= 90; pos += 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
 }
}
else if (dataval == 6)
{
  if (brikke == 1){
    startsted1();
  }
  else if (brikke == 2){
    startsted2();
  }

  else if (brikke == 3){
    startsted3();
  }

  else if (brikke == 4){
    startsted4();
  }
  else if (brikke == 5){
    startsted5();
  }

    //Skal legge brikke på bordet
 
  for (pos = 110; pos >= 100; pos -= 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);
  for (pos = 93; pos >= 65; pos -= 1) { 

    servo1.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }    
  
  for (pos = 0; pos <= 30; pos += 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
 }
  for (pos = 90; pos <= 165; pos += 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }

  
//Startposisjon  
delay(2000);
  for (pos = 30; pos >= 20; pos -= 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
    }  
  for (pos = 165; pos >= 90; pos -= 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }  
  
  delay(1000);
  for (pos = 20; pos >= 0; pos -= 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
    }  
  for (pos = 65; pos <= 180; pos += 1) { 

    servo1.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 100; pos >= 90; pos -= 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  
}
else if (dataval == 3)
{
  if (brikke == 1){
    startsted1();
  }
  else if (brikke == 2){
    startsted2();
  }

  else if (brikke == 3){
    startsted3();
  }

  else if (brikke == 4){
    startsted4();
  }
  else if (brikke == 5){
    startsted5();
  }
 
  for (pos = 110; pos >= 85; pos -= 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);

  for (pos = 93; pos >= 73; pos -= 1) { 

    servo1.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 0; pos <= 65; pos += 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
 } 
  for (pos = 90; pos <= 168; pos += 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
 delay(2000);
//Startposisjon

  for (pos = 85; pos >= 65; pos -= 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }  
delay(1000);
  for (pos = 65; pos >= 50; pos -= 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }    
  for (pos = 168; pos >= 90; pos -= 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 50; pos >= 0; pos -= 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  } 
  for (pos = 73; pos <= 180; pos += 1) { 

    servo1.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 65; pos <= 90; pos += 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }  

incomingByte = 1007;
brikke = 1007;
dataval = 1007;
} 
else if (dataval == 2)
{
  if (brikke == 1){
    startsted1();
  }
  else if (brikke == 2){
    startsted2();
  }

  else if (brikke == 3){
    startsted3();
  }

  else if (brikke == 4){
    startsted4();
  }
  else if (brikke == 5){
    startsted5();
  }

    //Skal legge brikke på bordet
 
  for (pos = 110; pos >= 80; pos -= 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);
  for (pos = 93; pos >= 61; pos -= 1) { 

    servo1.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }    
  for (pos = 0; pos <= 89; pos += 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  } 
  for (pos = 90; pos <= 176; pos += 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }

delay(2000);

  //Startposisjon
  for (pos = 80; pos >= 65; pos -= 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 89; pos >= 67; pos -= 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);  
  for (pos = 176; pos >= 90; pos -= 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 70; pos >= 0; pos -= 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }  

  for (pos = 61; pos <= 180; pos += 1) { 

    servo1.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }

  for (pos = 65; pos <= 90; pos += 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  
}
else if (dataval == 1)
{
  if (brikke == 1){
    startsted1();
  }
  else if (brikke == 2){
    startsted2();
  }

  else if (brikke == 3){
    startsted3();
  }

  else if (brikke == 4){
    startsted4();
  }
  else if (brikke == 5){
    startsted5();
  }
    //Skal legge brikke på bordet

  for (pos = 110; pos >= 80; pos -= 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }   
  delay(1000);  
  for (pos = 93; pos >= 51; pos -= 1) { 

    servo1.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  for (pos = 0; pos <= 115; pos += 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
 } 
  delay(1000);

  for (pos = 90; pos <= 180; pos += 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(1000);

     delay(2000);

    
// Startposisjon

  for (pos = 80; pos >= 18; pos -= 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }  
  delay(1000);


  for (pos = 115; pos >= 103; pos -= 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  
  delay(1000);

  
  for (pos = 18; pos >= 3; pos -= 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  
  delay(1000);
  for (pos = 180; pos >= 90; pos -= 1) { 

    servo2.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }
  delay(2000);  



   for (pos = 103; pos >= 0; pos -= 1) { 

    servo3.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }  

  for (pos = 51; pos <= 180; pos += 1) { 

    servo1.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }

  for (pos = 3; pos <= 90; pos += 1) { 

    servo4.write(pos);// tell servo to go to position in variable "pos"
    delay(15); // waits 15ms for the servo to reach the position
  }

}
}
}
