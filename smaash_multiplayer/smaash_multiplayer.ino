#include <elapsedMillis.h>


#include <Wire.h>

const int MPU_addr=0x68; int16_t AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

int minVal=265; int maxVal=402;

double x; double y; double z;

int previousylevel = 0;
int currentylevel =0;
const int Sensor1 = A0; 
const int Sensor2 = A1;
const int Sensor3 = A2;
const int Sensor4 = A3;
const int Sensor5 = A4;
const int Sensor6 = A5;
const int Sensor7 = A6;
const int Sensor8 = A7;
const int Sensor9 = A8;
const int Sensor10 = A9;
const int Sensor11 = A10;
const int Sensor12 = A11;




float delta_pie1 = 0;
float delta_pie2 = 0;
float delta_pie3 = 0;
float delta_pie4 = 0;
float delta_pie5 = 0;
float delta_pie6 = 0;
float delta_pie7 = 0;
float delta_pie8 = 0;
float delta_pie9 = 0;
float delta_pie10 = 0;
float delta_pie11 = 0;
float delta_pie12 = 0;

const int threshold_delta_pie = 100;

float currentpie1 = 0;
float currentpie2 = 0;
float currentpie3 = 0;
float currentpie4 = 0;
float currentpie5 = 0;
float currentpie6 = 0;
float currentpie7 = 0;
float currentpie8 = 0;
float currentpie9 = 0;
float currentpie10 = 0;
float currentpie11 = 0;
float currentpie12 = 0;

float previouspie1 =0;
float previouspie2 =0;
float previouspie3 =0;
float previouspie4 =0;
float previouspie5 =0;
float previouspie6 =0;
float previouspie7 =0;
float previouspie8 =0;
float previouspie9 =0;
float previouspie10 =0;
float previouspie11 =0;
float previouspie12 =0;
int score=0;
elapsedMillis timeElapsed;
elapsedMillis timeElapsed2;
unsigned int sensor_interval = 1000;
void setup() {{
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
Wire.write(0x6B); Wire.write(0);
Wire.endTransmission(true); 
  
  for (int pin = 3; pin <= 53; pin++)
  {
  pinMode(pin,OUTPUT);
  }
 
}

while (true) {
  if (timeElapsed2<= 30000)
  {
  for (int pin = 3; pin<=53; pin++)
  {
    digitalWrite(pin,HIGH);
   
  }
  Wire.beginTransmission(MPU_addr); 
Wire.write(0x3B); Wire.endTransmission(false);
Wire.requestFrom(MPU_addr,14,true); 
AcX=Wire.read()<<8|Wire.read(); 
AcY=Wire.read()<<8|Wire.read(); AcZ=Wire.read()<<8|Wire.read();
int xAng = map(AcX,minVal,maxVal,-90,90); 
int yAng = map(AcY,minVal,maxVal,-90,90); 
int zAng = map(AcZ,minVal,maxVal,-90,90);

x= RAD_TO_DEG * (atan2(-yAng, -zAng)+PI); y= RAD_TO_DEG * (atan2(-xAng, -zAng)+PI); z= RAD_TO_DEG * (atan2(-yAng, -xAng)+PI);

//Serial.print("AngleX= "); Serial.println(x);
/*float y_angle = 0;
for (int i=1 ; i<=10000; i++)
{ y_angle += y; }*/


//y = y_angle/10000;
int hammer_color =0;
//Serial.print("AngleY= "); 
//Serial.println(y);
if (150<y && y<220||0<y && y<30)
  {//Serial.println("red");
  hammer_color = 0;}
 else //if( 60<y && y<100||230<y && y<270)
   {//Serial.println("green");
   hammer_color=1;}
   int pickme = random(22,56);
  int color_led = 3;
  if (pickme == 54)
  {pickme == 3;
  color_led = 0;}
  else if(pickme == 55)
  {pickme == 3;
  color_led =0;}
  else if (pickme % 3 == 0)
  {pickme = pickme;
  if(pickme==39)
  {pickme=36;}
  else if(pickme==48)
  {pickme=45;}
  else if (pickme==51)
  {pickme=42;}
  color_led = 0;}
  else if (pickme % 3 == 1)
  {pickme = pickme;
  if (pickme ==22)
  {pickme = 4;}
  else if(pickme==40)
  {pickme =37;}
  else if (pickme==52)
  {pickme = 46;}
  else if (pickme == 49)
  {pickme = 43;}
  else
  {pickme = pickme;}
  color_led = 1;}
  else if (pickme%3 == 2)
  {pickme = random(0,2);
  if (pickme==0)
  {pickme = random(8,20);
  if (pickme == 18)
  {pickme=3;
  color_led = 0;}
  else if (pickme == 19)
  {pickme=3;
  color_led = 0;}
  else
  {pickme=pickme*3;
  color_led = 0;
  if(pickme==39)
  {pickme=36;}
  else if(pickme==48)
  {pickme=45;}
  else if (pickme==51)
  {pickme=42;}}}
  else
  {pickme = random(7,19);
  if (pickme == 18)
  {pickme = 4;
  color_led = 1;}
  else 
  {pickme = pickme*3+1;
  if (pickme ==22)
  {pickme = 4;}
  else if(pickme==40)
  {pickme =37;}
  else if (pickme==52)
  {pickme = 46;}
  else if (pickme == 49)
  {pickme = 43;}
  else
  {pickme = pickme;}
  color_led = 1;}}}
  digitalWrite(pickme,LOW);
  
  timeElapsed = 0;
  previouspie1 = analogRead(Sensor1);
  previouspie2 = analogRead(Sensor2);
  previouspie3 = analogRead(Sensor3);
   previouspie4 = analogRead(Sensor4);
   previouspie5 = analogRead(Sensor5);
   previouspie6 = analogRead(Sensor6);
   previouspie7 = analogRead(Sensor7);
   previouspie8 = analogRead(Sensor8);
   previouspie9 = analogRead(Sensor9);
   previouspie10 = analogRead(Sensor10);
   previouspie11 = analogRead(Sensor11);
   previouspie12 = analogRead(Sensor12);
   
  
  while(timeElapsed <= sensor_interval)
  {
  currentpie1 = analogRead(Sensor1);
  currentpie2= analogRead(Sensor2);
  currentpie3 = analogRead(Sensor3);
  currentpie4 = analogRead(Sensor4);
 currentpie5 = analogRead(Sensor5);
 currentpie6 = analogRead(Sensor6);
 currentpie7 = analogRead(Sensor7);
 currentpie8 = analogRead(Sensor8);
 currentpie9 = analogRead(Sensor9);
 currentpie10 = analogRead(Sensor10);
 currentpie11 = analogRead(Sensor11);
 currentpie12 = analogRead(Sensor12);
  
  delta_pie1 = currentpie1-previouspie1;
  delta_pie2 = currentpie2-previouspie2;
  delta_pie3 = currentpie3-previouspie3;
  delta_pie4 = currentpie4-previouspie4;
  delta_pie5 = currentpie5-previouspie5;
  delta_pie6 = currentpie6-previouspie6;
  delta_pie7 = currentpie7-previouspie7;
  delta_pie8 = currentpie8-previouspie8;
  delta_pie9 = currentpie9-previouspie9;
  delta_pie10 = currentpie10-previouspie10;
  delta_pie11 = currentpie11-previouspie11;
  delta_pie12 = currentpie12-previouspie12;

  if(delta_pie1>=threshold_delta_pie || delta_pie2>=threshold_delta_pie || delta_pie3>=threshold_delta_pie ||delta_pie4>=threshold_delta_pie ||delta_pie5>=threshold_delta_pie ||delta_pie6>=threshold_delta_pie ||delta_pie7>=threshold_delta_pie ||delta_pie8>=threshold_delta_pie ||delta_pie9>=threshold_delta_pie ||delta_pie10>=threshold_delta_pie ||delta_pie11>=threshold_delta_pie ||delta_pie12>=threshold_delta_pie)
  {break;}
  
  }
  //Serial.println(pickme);
  //Serial.println(delta_pie3);
  //Serial.println(delta_pie2);
  //Serial.println(delta_pie1);
  //delay(3000);
  if (pickme==3||pickme==4)
      {if (delta_pie1 >= threshold_delta_pie)
            {if (hammer_color == color_led)
                {digitalWrite(pickme,HIGH);
                  
                  Serial.println("correct");
                  score+=4;
                  continue;
                }
            }
      }
  else if (pickme==6||pickme==22) 
  {if (delta_pie2 >= threshold_delta_pie)
            {if (hammer_color == color_led)
                {digitalWrite(pickme,HIGH);
                  
                  Serial.println("correct");
                  score+=4;
                  continue;
                }
            }
      } 
  else if (pickme==24||pickme==25) 
  {if (delta_pie3 >= threshold_delta_pie)
            {if (hammer_color == color_led)
                {digitalWrite(pickme,HIGH);
                 
                  Serial.println("correct");
                  score+=4;
                  continue;
                }
            }
      }

      else if (pickme==27||pickme==28) 
  {if (delta_pie4 >= threshold_delta_pie)
            {if (hammer_color == color_led)
                {digitalWrite(pickme,HIGH);
                
                  Serial.println("correct");
                  score+=4;
                  continue;
                }
            }
      }
       else if (pickme==30||pickme==31) 
  {if (delta_pie5 >= threshold_delta_pie)
            {if (hammer_color == color_led)
                {digitalWrite(pickme,HIGH);
                 
                  Serial.println("correct");
                  score+=4;
                  continue;
                }
            }
      } 
       else if (pickme==33||pickme==34) 
  {if (delta_pie6 >= threshold_delta_pie)
            {if (hammer_color == color_led)
                {digitalWrite(pickme,HIGH);
                
                  Serial.println("correct");
                  score+=4;
                  continue;
                }
            }
      } 
       else if (pickme==36||pickme==37) 
  {if (delta_pie7 >= threshold_delta_pie)
            {if (hammer_color == color_led)
                {digitalWrite(pickme,HIGH);
                 
                  Serial.println("correct");
                  score+=4;
                  continue;
                }
            }
      } 
       else if (pickme==39||pickme==40) 
  {if (delta_pie8 >= threshold_delta_pie)
            {if (hammer_color == color_led)
                {digitalWrite(pickme,HIGH);
                 
                  Serial.println("correct");
                 score+=4;
                  continue;
                }
            }
      } 
       else if (pickme==42||pickme==43) 
  {if (delta_pie9 >= threshold_delta_pie)
            {if (hammer_color == color_led)
                {digitalWrite(pickme,HIGH);
                 
                  Serial.println("correct");
                  score+=4;
                  continue;
                }
            }
      } 
       else if (pickme==45||pickme==46) 
  {if (delta_pie10 >= threshold_delta_pie)
            {if (hammer_color == color_led)
                {digitalWrite(pickme,HIGH);
                 
                  Serial.println("correct");
                  score+=4;
                  continue;
                }
            }
      } 
       else if (pickme==48||pickme==49) 
  {if (delta_pie11 >= threshold_delta_pie)
            {if (hammer_color == color_led)
                {digitalWrite(pickme,HIGH);
                 
                  Serial.println("correct");
                  score+=4;
                  continue;
                }
            }
      } 
       else if (pickme==51||pickme==52) 
  {if (delta_pie12 >= threshold_delta_pie)
            {if (hammer_color == color_led)
                {digitalWrite(pickme,HIGH);
                 
                  Serial.println("correct");
                  score+=4;
                  continue;
                }
            }
      } 
       
  
  /*Serial.print("1   "); Serial.println(delta_pie1);
  Serial.print("2   "); Serial.println(delta_pie2);
  Serial.print("3   "); Serial.println(delta_pie3);
  Serial.print("4   "); Serial.println(delta_pie4);
  Serial.print("5   "); Serial.println(delta_pie5);
  Serial.print("6   "); Serial.println(delta_pie6);
  Serial.print("7   "); Serial.println(delta_pie7);
  Serial.print("8   "); Serial.println(delta_pie8);
  Serial.print("9   "); Serial.println(delta_pie9);
  Serial.print("10   "); Serial.println(delta_pie10);
  Serial.print("11   "); Serial.println(delta_pie11);
  Serial.print("12   "); Serial.println(delta_pie12);
  Serial.println("xxxxxxxxxxxxxxxxxxxxxx");*/
  Serial.println("noattempt");
  
  delay(500);
  digitalWrite(pickme,HIGH);
  score-=1;
  
  }
  else
  {Serial.println("game over");
  Serial.println(score);}
}
}
