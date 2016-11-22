
#include <Servo.h>

#include "servo.h"

Servo leftservo;                    
Servo rightservo;                   

//Variables

//Figure 8
/*bool turnleft = 0;
bool turnright = 0;
int turn = 0;*/


//Square Dance
/*int count = 0;
bool change = 0;*/

//Touch
int touch = 0;  //at the front

//Wall Sensors
int left = 0;
int right = 0;

//Line sensor
int first = 0;
int second = 0;
int fourth = 0;
int fifth = 0;
int seventh = 0;
int eighth = 0;

//Additional
int gotarticuno = 0;
int lastsense = 0;
int side = 0;

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
    //Reading for line sensor  Port E
    first = digitalRead(18);       //PE0 
    second = digitalRead(27);      //PE1
    fourth = digitalRead(28);     //PE2
    fifth = digitalRead(29);      //PE3
    seventh = digitalRead(5);     //PE4 
    eighth = digitalRead(6);      //PE5

    touch = digitalRead(8);  //PA5  touch sensor

    //Reading for wall sensor PD2 and PD3 white for voltage and red for signal
    left = analogRead(25);
    right = analogRead(26);   
       //Serial.println(side);

    // Checking line sensor value
    /*Serial.print("1: ");
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
    delay(2000);*/
    
    
    //Checking wall sensor value
    //Serial.println(left);
    //delay(200);
    //Serial.print(  '\t');
    //Serial.println(right);
   
    
    //Competition Code              
    //IR SENSOR
   while(side == 0){
      if((left > 2500)){     
         side = 1;
         forward();
         delay(500);  
      }
      else{
        side = 2;
        forward();
        delay(500);
      }
    }
    //Line Following
    if(side == 1){        //on right field
    
    if((first == 1 || second == 1) && (seventh == 1 || eighth == 1)){
        turnLeft(); 
        delay(200);
    }
    else if(seventh == 1 || eighth == 1)
      {
        turnLeft();
      }
      else if(fourth == 1 && fifth == 1)
    {
      forward();
    }
    else if(first == 1 || second == 1)
      {
        turnRight();
      }
    
    else
    {
      forward();
    }          
    if(left > 3000){    //start the hardcoding
      
    }

    }
    else if(side == 2){  //on left field
     if((first == 1 || second == 1) && (seventh == 1 || eighth == 1)){
      turnRight();
      delay(200);
     }
     else if(first == 1 || second == 1)
      {
       turnRight();
      }
      else if(fourth == 1 && fifth == 1)
    {
      forward();
    }
     else if(seventh == 1 || eighth == 1)
      {
        turnLeft();
      }
      
     
     else
    {
      forward();
    }
  }
}

    

 
