
#include <MeggyJrSimple.h>

int snakeArray = 3; //coordinates of player
int yplayer = 4;
int direction = 0; //possible values are 0, 90, 180, 270
int xapple = random(8); //int marker =3
int yapple = random(8);

struct Point
{
 int x;
 int y;
}

Point p1 = {3, 4};
Point p2 = {4, 4};
Point p3 = {5, 4};
Point snakeArray[64] = 
{
  p1, p2, p3
}

 
  

void setup()

{
  MeggyJrSimpleSetup();
  Serial.begin(9600);
}

void loop()

{
  Serial.print("x is ");
  Serial.println(xplayer);
  Serial.print("y is ");
  Serial.println(yplayer);
  Serial.println();
  
  DrawPx(xplayer, yplayer, Green);
  DrawPx(xapple, yapple, Red);
  DisplaySlate();
  delay(200);
  ClearSlate();
  
  CheckButtonsPress();
  if (Button_Right) 
  {
    direction = 90;
  }
  
  if (Button_Left) 
  {
    direction = 270;
  }
  
  if (Button_Up)
  { 
    direction = 0;
  }

  if (Button_Down) 
  {
    direction = 180;
  }
 
  if (direction == 0) yplayer++;
  if (direction == 90) xplayer++;
  if (direction == 180) yplayer--;
  if (direction == 270) xplayer--;
  if (xplayer > 7 ) xplayer = 0;
  if (yplayer > 7 ) yplayer = 0;
  if (xplayer < 0 ) xplayer = 7;
  if (yplayer < 0 ) yplayer = 7;
  
  if (xapple == xplayer)
  {
    if (yapple == yplayer)
      {
        xapple = random(8);
        yapple = random (8);
      }
  }
       
}

void drawSnake()

{
  for (int i=0; i<marker; i++);
    {
      DrawPx(snakeArray[i].x,snakeArray[i].y,Red);
    }
  

  
  
  
  /*
  Draw player./draw snek
  DisplaySlate.
  delay(100).
  Check Buttons.
  Update Direction if a button is pressed.
  Update player coordinates based on direction.
  Correct for wrap. 
  */

