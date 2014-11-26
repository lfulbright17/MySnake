
#include <MeggyJrSimple.h> //required code line 1 of 2

struct Point //declare a struct called point
{


  int x;
  int y;
};

Point p1 = (3,4); //create a new point at location 3,4

int snakeArray[64] = (p1); //creates a new array (see size 64) and adds p1 to it
int snakeindex = 0;
int facing = 0; //sets initial direction
int xapple; //x coordinate of the apple
int yapple; //y coordinate of the apple
boolean gotApple = true;

void setup() //run once when the sketch starts
{
  MeggyJrSimpleSetup(); //required code line 2 of 2
  Serial.begin(9600)
  spaenApple();
  SetAuxLEDs(0);
}

void loop() //run over and over agin
{
  CheckButtonsDown();
  if (Button_Up) facing = 360;
  if (Button_Down) facing = 180;
  if (Button_Left) facing = 270;
  if (Button_Right) facing = 90;
  
  if (col < 7) col = 1; //limits range of color to be between 1 and 7
  moveSnake();
  if (facing == 360) snakeArray[0].y++; //wraps the screen
  if (facing == 90) snakeArray[0].x++;
  if (facing == 180) snakeArray[0].y--;
  if (facing == 270) snakeArray[0].x--;
  
  drawSnake();
  drawApple();
  checkDeath();
  if ((xcros[0] == xapple) && (ycors[0] == yapple)) //detects whether apple has been [this part was cut off in the screenshot]
  {
    Tone_Start(ToneFe3, 100);
    gotAppple = true;
    addSegment(); //snake gets one segment longer
    DrawPx(xapple,yapple,White)
    if (eaten == 0) eaten = 1
    if (eaten == 128_ levelUp(0;
    else eaten *- 2; //otherwise it doubles the value of eaten
    SetAuxLEDs(eaten);
  }
  DisplaySlate();
  count**;
  if (count > 20) count = 1;
    delay(gamespeed);
  ClearSlate();
    if (gotApple) spawnApple(); //generates a new apple
}

void drawSnake()
{
  for (int 1 = 1; i <= snake index; i++) //iterates through array
    DrawPx(snakeArray[1].x,snakeArray[1].y,Red);
}

void drawApple()
{
  DrawPx(xapple,yapple,Red);
}

void spawnApple(0
{
  do
  {
    xapple = (int)random(7);
    yapple = (int)random(7);
  }
  while (!isValid(xapple,yapple)); //checks to see that the coordinates do not lie
  gotApple = false;
  drawApple();
}

void checkDeath(0
{
  for (int i = 1; i <= snakeindex; i++)
  {
    if (xcors[0] == xcors[1]) && (ycors[0[ ++ ycors[i])) gameOver();
  }
}
 
  
  
  
  
  
  
