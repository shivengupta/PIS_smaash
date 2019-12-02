//score,timer, arduino-1 correct hit and vice versa, marking +4-1

import processing.serial.*;
Serial myPort;

int screen=0;
int tripar=90;
int score1p=0;
int scorem1=0;
int scorem2=0;
String s1="";
PImage logo;
PImage bgpic;
void setup() {
  fullScreen();
  myPort = new Serial(this,"COM11",9600);   //check for com port
  myPort.bufferUntil('\n');

  logo = loadImage("logo.PNG");
  bgpic = loadImage("bgpic.png");
}

void serialEvent(Serial myPort) {
  s1 = myPort.readStringUntil('\n');
}

void draw() {
  if (screen==0)                                                                                                                      // screen 0
  {                                                                                                                                    //start screen
    background(255);
    image(logo, width*0.35, height*0.1);
    fill(250, 0, 0);
    triangle(width/2+tripar, height*0.69, width/2-tripar, height*0.69+tripar, width/2-tripar, height*0.69-tripar);
    if (mousePressed && mouseX>(width/2-tripar) && mouseX<(width/2+tripar) && mouseY<height*0.69+tripar && mouseY>height*0.69-tripar)
    {
      delay(40);
      screen=1;
    }
  } else if (screen==1)                                                                                                                  // screen 1
  {                                                                                                                                    //choose no of players
    image(bgpic, 0, 0);
    textSize(40);
    fill(0);
    text("Single Player", width*0.44, height/3);
    text("Multi Player", width*0.445, 2*height/3);
    textSize(20);
    text("Back", width*0.05, height*0.9);
    if (mousePressed && width*0.05<mouseX && mouseX<width*0.05+100 && height*0.9-100<mouseY && mouseY<height*0.9)
    {                                                                                                                                 //back button to main screen
      delay(40);
      screen=0;
    } else if (mousePressed && (width*0.44)<mouseX && mouseX<(width*0.56) && ((height/3)-height*0.028)<mouseY && mouseY<(height/3))
    {                                                                                                                                 //singleplayer
      delay(40);
      //myPort.write('0');
      screen=4;
    } else if (mousePressed && width*0.44<mouseX && mouseX<width*0.56 && 2*height/3-height*0.028<mouseY && mouseY<2*height/3)
    {                                                                                                                                  //multiplayer
      delay(40);
      //myPort.write('1');
      screen=5;
    }
  } else if (screen==4)
  {                                                                                                                                     //singleplayer play area
    image(bgpic, 0, 0);
    textSize(20);
    text("Back", width*0.05, height*0.1);
    textSize(40);
    text("Single Player", width*0.44, height/3);
    String[] m1 = match(s1, "correct");   //check scoring with arduino
    String[] m2 = match(s1, "noattempt");
    if (m1 != null){
    score1p = score1p + 4;
    //text(score1p,width/2,height/2);
    delay(300);
  }
  else if(m2 != null){
    score1p = score1p+4;
    //text(score,width/2,height/2);
    delay(2500);
  }
    text("Score :  " + score1p, width*0.46, height*0.45);
    if (mousePressed && width*0.05<mouseX && mouseX<width*0.05+100 && height*0.1-100<mouseY && mouseY<height*0.1)
    {                                                                                                                               //back button to main screen
      delay(40);
      screen=1;
    } else if (mousePressed && mouseX>width*0.9 && mouseY>height*0.9)
    {                                                                                                                   // test for screen 6 ie singleplayer game over, only for testing
      delay(40);
      screen=6;
    }
  } else if (screen==5)
  {                                                                                                                                      //multiplayer play area
    image(bgpic, 0, 0);
    textSize(20);
    text("Back", width*0.05, height*0.1);
    textSize(40);
    text("Multi Player", width*0.445, height*3);
    //text("Player 1", width*0.33, height*0.4);
    //text("Player 2", width*0.66, height*0.4);
    text("score:"+score1p, width*0.42, height*0.52);
    //text(score1p, width*0.33+10, height*0.52);
    String[] m1 = match(s1, "correct");   //check scoring with arduino
    String[] m2 = match(s1, "noattempt");
    String[] m = match(s1,"gameover");
    if (m1 != null){
    score1p = score1p + 4;
    text(score1p,width/2,height/2);
    delay(300);}
  
  else if(m2 != null){
    score1p = score1p +4;
    text(score1p,width/2,height/2);
    delay(2500);
  }
    //text(scorem2, width*0.67+10, height*0.52);
    if (mousePressed && width*0.05<mouseX && mouseX<width*0.05+100 && height*0.1-100<mouseY && mouseY<height*0.1)
    {                                                                                                                               //back button to main screen
      delay(40);
      screen=1;
    } else if (/*mousePressed && mouseX>width*0.9 && mouseY>height*0.9*/m!=null)
    {                                                                                                               // test for screen 7 ie multiplayer game over, only for testing
      delay(40);
      screen=7;
    }
  } else if (screen==6)
  {                                                                                                                                   // game over single player
    image(bgpic, 0, 0);
    textSize(25);                     
    text("Menu", width*0.05, height*0.1);
    textSize(70);
    text("Game Over", width*0.4, height*0.26);
    textSize(45);
    text("Play Again", width*0.45, height*0.86);
    if (mousePressed && width*0.05<mouseX && mouseX<width*0.05+100 && height*0.1-100<mouseY && mouseY<height*0.1)
    {                                                                                                                              // button to screen 1 aka menu
      delay(40);
      screen=1;
    } else if (mousePressed && mouseX>width*0.45 && mouseX<width*0.45+250 && mouseY<height*0.86 && mouseY>height*0.86-60)
    {
      delay(40);
      screen=4;
    }
  } else if (screen==7)
  {                                                                                                                                         // game over multi
    image(bgpic, 0, 0);
    textSize(20);
    text("Menu", width*0.05, height*0.1);
    textSize(70);
    text("Game Over", width*0.4, height*0.26);
    textSize(45);
    text("Play Again", width*0.45, height*0.86);
    if (mousePressed && width*0.05<mouseX && mouseX<width*0.05+100 && height*0.1-100<mouseY && mouseY<height*0.1)
    {                                                                                                                                  // button to screen 1 aka menu
      delay(40);
      screen=1;
    } else if (mousePressed && mouseX>width*0.45 && mouseX<width*0.45+250 && mouseY<height*0.86 && mouseY>height*0.86-60)
    {
      delay(40);
      screen=5;
    }
  }
}
