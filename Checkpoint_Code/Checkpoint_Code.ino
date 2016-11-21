
#include <Servo.h>

#include "servo.h"

Servo leftservo;                    
Servo rightservo;                   

//Variables

//Figure 8
int turnleft = 0;
int turnright = 0;
int turn = 0;
int store = 0;

//Square Dance
int count = 0;
bool change = 0;

//Wall Sensors
int left = 0;
int right = 0;

//Servos
int posleft = 180;                   
int posright = 0;

//Line sensor
int first = 0;
int second = 0;
int fourth = 0;
int fifth = 0;
int seventh = 0;
int eighth = 0;

//Find Object
int turnC = 0;

//Initialization
void setup() 
{ 
  Serial.begin(9600);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(18, INPUT);
  pinMode(27, INPUT);
  pinMode(28, INPUT);
  pinMode(29, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(25, INPUT);
  pinMode(26, INPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  rightservo.attach(23);
  leftservo.attach(24);  // attaches the servo on pin 2 to the servo object 
}

//Going forward
void forward(){ 
     leftservo.write(180);
     rightservo.write(0); 
}

//Turn Right
void turnRight() {
  leftservo.write(180);
  rightservo.write(180);
}

//Turn Left
void turnLeft() {
  leftservo.write(0);
  rightservo.write(0);
}

//Turn hard Left only moving right wheel
void hard_left(){
  leftservo.write(92);
  rightservo.write(0);
}

//Going backward
void reverse() {
  leftservo.write(0);
  rightservo.write(180);
}

//Stop
void Brake(){
  leftservo.write(90);
  rightservo.write(90);
}

//Turn hard right only moving left wheel
void hard_right(){
  leftservo.write(180);
  rightservo.write(90);
}
 
 
void loop() 
{  
    /*Reading for line sensor  Port E
    first = digitalRead(18);        
    second = digitalRead(27);
    fourth = digitalRead(28);
    fifth = digitalRead(29);
    seventh = digitalRead(5);
    eighth = digitalRead(6);*/

    //Reading for wall sensor PD2 and PD3 white for voltage and red for signal
    left = analogRead(26);
    right = analogRead(25);   
   for(int i = 0; i < 480; i ++)
   {
    turnLeft();
    delay(10);
    if(right > 1500)
    {
      turnRight();
      delay(1150);
      forward();
      delay(500);
      i = 0;
    }
    else if (left > 1500)
    {
      turnRight();
      delay(1200);
      forward();
      delay(500);
      i = 0;
    }
   }
   forward();
   delay(1000);
   turnC ++;
   if(turnC == 3)
   {
    turnLeft();
    delay(1200);
    forward();
    delay(1000);
    turnLeft();
    delay(1200);
    turnC == 0;
   }
    /*
    // Checking line sensor value
    Serial.print("1: ");
    Serial.println(first);    //left
     Serial.print("2: ");
    Serial.println(second);
     Serial.print("4: ");
    Serial.println(fourth);  //center
     Serial.print("5: ");
    Serial.println(fifth);
     Serial.print("7: ");
    Serial.println(seventh);  //right
     Serial.print("8: ");
    Serial.println(eighth);
    Serial.print("\n");
    delay(2000);
    */


    //Checking wall sensor value
    /*Serial.println(left);
    delay(500);
    Serial.print(  '\t');
    Serial.println(right);*/
   
    
    //Line Sensor Part
    /*if(seventh == 1 || eighth == 1)
    {
      turnLeft();
    }
    else if(first == 1 || second == 1)
    {
      turnRight();
    }
    else if(fourth == 1 && fifth == 1)
    {
      forward();
    }
    else
    {
      forward();
    }*/
    
    //Figure 8
   /* forward();
    delay(150);
    if((left > 1500) && (right < 1500)){ //left sensor sense
      if(turn < 3){
      turnleft = 1;
      digitalWrite(RED_LED, HIGH);
      }
    }
    else if((right > 1500)&&(left < 1500)){ //right sensor sense
       if(turn < 3){
      turnright = 1;
      digitalWrite(GREEN_LED, HIGH);
       }
    }
    if(turn == 3){
        store = turnleft;
        turnleft = turnright;
        turnright = store;
    }
    if(((left < 1500) && (right < 1500)) && ((turnleft == 1) || (turnright == 1))){
        if(turnleft == 1){
          turnleft = 0;
          turnright = 0;
          turnLeft();
          delay(1200);
          Brake();
          //delay(50);
          digitalWrite(RED_LED,LOW);
          turn++;
        }
        else if(turnright == 1){
          turnright = 0;
          turnleft = 0;
          turnRight();
          delay(1100);
          digitalWrite(GREEN_LED, LOW);
          turn++;
          Brake();
          //delay(50);
        }
        if(turn == 3)
        {
          turn == -1;
        }
    }*/


    
    //Square Dance
    /*forward(); 
    if(left > 1400){
        change = 1;
    }
    else if((left < 1400) && (change == 1)){
        count++;
        change = 0;
    }
    else if((right < 1000)&&(count%2 == 0)){
        turnLeft();
        delay(1100);
        Brake();
        delay(50);
     }
    while(count >= 9){
      Brake();
     }*/
  


   //Wall following
   /* if(((front > 900)&&(right > 1900))){   //front 1 right 1
      hard_left();
      delay(10);
    }
    else if((front < 900)&&(right < 1200)){    //front 0 right 0
      turnRight();
      delay(10);
    }
    else if((front < 900)&&(right < 1900)&&(right > 1200)){          //forward
      forward();
      delay(10);
    }
    else if(((front > 900) && (right < 1200))){   //front 1 right 0
      turnLeft();
      delay(10);
    }
     else if((front < 900)&&(right > 1900)){      //front 0 right 1 //getting too close
      turnLeft();   
      delay(10); 
    }*/ 

}
