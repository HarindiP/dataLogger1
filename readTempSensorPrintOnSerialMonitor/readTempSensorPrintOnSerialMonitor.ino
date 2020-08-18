/*
  Recording to OpenLog example
  By: Nathan Seidle
  SparkFun Electronics
  Date: February 8th, 2018
  License: This code is public domain but you buy me a beer if you use this and we meet someday (Beerware license).

  This is an example of basic recording to OpenLog using hardware serial. This example is best for users who
  are plugging the OpenLog directly onto the programming connector on an Arduino Pro Mini or Arduino Pro.

  We DON'T recommend this method for beginners. See Example 1 for an easier software serial example. 
  The reason is if you upload a sketch to an Arduino with OpenLog attached then OpenLog will log the 
  uploading of your sketch. This may cause the OpenLog to become reconfigured. No harm will be 
  caused but it can corrupt the log file.

  Connect the following OpenLog to Arduino:
  RXI of OpenLog to TX on Arduino
  VCC to 5V
  GND to GND

  This example records whatever the user Serial.prints(). This is the easiest but NOTE: You cannot
  upload sketches to your Arduino with the OpenLog attached (because of bus contention). Upload this
  sketch first, and then connect the OpenLog to the TX pin on the Arduino.
*/


int sensePin = A0;  //This is the Arduino Pin that will read the sensor output
int sensorInput;    //The variable we will use to store the sensor input
double temp;        //The variable we will use to store temperature in degrees. 



void setup() {
   Serial.begin(9600);

  Serial.println("Example print to OpenLog");
  Serial.println("Anything printed to COM port gets logged!");
  Serial.println("This ones an intergrated model with the uno");
  
}

void loop() {
  // put your main code here, to run repeatedly: 
  sensorInput = analogRead(A0);    //read the analog sensor and store it
  temp = (double)sensorInput / 1024;       //find percentage of input reading
  temp = temp * 5;                 //multiply by 5V to get voltage
  temp = temp - 0.5;               //Subtract the offset 
  temp = temp * 100;               //Convert to degrees 
 
  Serial.print("Current Temperature: ");
  Serial.println(temp);
  
  delay(1000);
}
