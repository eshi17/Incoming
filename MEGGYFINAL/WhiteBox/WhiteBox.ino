/*
  Incoming!
*/

#include <MeggyJrSimple.h>    // RequiYellow code, line 1 of 2

int lineLevel = 1;
int playerColor = 1;
int enemyRed = Red;
int enemyOrange = Orange;
int enemyYellow = Yellow;
int enemyGreen = Green;
int enemyBlue = Blue;
int enemyPurple = Violet;
int playerPoints[100] = {0};//player y coord
int numPlayer = 1;
int ycoord = 6; //timer y coord
int timer = 1;

void setup()
{
  MeggyJrSimpleSetup();
  Serial.begin(9600);
}

void loop()              // run over and over again
{
  timer++; //add one to timer
  if (timer > 20) timer = 1;
  CheckButtonsDown();
  drawEnemy();
  whiteLine();
  DrawPlayer();
  checkHit();
  countdown();
  DisplaySlate();
  delay(150);
}


void drawEnemy() //draws a single horizontal line of a certain color (out of red, orange, yellow, green, blue, purple)
{
  for (int r = 0; r < 8; r++)
  {
    if (lineLevel == 1)//(same for all colors)if linelevel == [#], draw line [color]
    {
      DrawPx(r, 7, enemyRed);
    }
  }
  for (int o = 0; o < 8; o++)
  {
    if (lineLevel == 2)
    {
      DrawPx(o, 7, enemyOrange);
    }
  }
  for (int y = 0; y < 8; y++)
  {
    if (lineLevel == 3)
    {
      DrawPx(y, 7, enemyYellow);
    }
  }
  for (int g = 0; g < 8; g++)
  {
    if (lineLevel == 4)
    {
      DrawPx(g, 7, enemyGreen);
    }
  }
  for (int b = 0; b < 8; b++)
  {
    if (lineLevel == 5)
    {
      DrawPx(b, 7, enemyBlue);
    }
  }
  for (int p = 0; p < 8; p++)
  {
    if (lineLevel == 6)
    {
      DrawPx(p, 7, enemyPurple);
    }
  }
}
    
void DrawPlayer()
{
  for (int i = 0; i < numPlayer; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      DrawPx(j, playerPoints[i], playerColor);
    }
    
  if (Button_Right)       // Change player color
  {    
    playerColor++;      //Increase playerColor by one, which in turns changes the color itself
  }
  
  if (playerColor > 6)
  {
    playerColor = 1; //creates a wrap for the player. Maximum color is blue
  }
  
  if (Button_Left)       // Change player color
  {    
    playerColor--;      //Decrease playerColor by one, which in turns changes the color itself
  }
  
  if (playerColor < 1)
  {
    playerColor = 6; //creates a wrap for the player. Maximum color is blue
  }
  }
}

void whiteLine()
{
  for (int x = 0; x < 8; x++)
  {
    for (int y = 1; y < 7; y++)
    DrawPx(x, y, White); // background
  }
}

void checkHit() // Check to see if the playerColor is the same as the colored line right above it.
// If it is the same, then colored enemy line above player dissapears
{
    if (Button_A)
    {
      if (ReadPx(0, 7) == 1 && playerColor == enemyRed) //if the point (0,7) is red, and the playercolor is red, and the a button is pressed (similar for everything else)
        {
          Tone_Start(ToneA6,50); //create noise
          SetAuxLEDsBinary(B01000000); //add light
          ycoord = 6;//timer returns to original position
          lineLevel = 3;//color turns yellow
        }
      }
    if (Button_A)
    {
      if (ReadPx(0, 7) == 2 && playerColor == enemyOrange)
      {
        Tone_Start(ToneA6,50);
        SetAuxLEDsBinary(B01111100);
        ycoord = 6;
        lineLevel = 6;
      }
    }
    if (Button_A)
    {
      if (ReadPx(0, 7) == 3 && playerColor == enemyYellow)
      {
        Tone_Start(ToneA6,50);
        SetAuxLEDsBinary(B01100000);
        ycoord = 6;
        lineLevel = 5;
      }
    }
    if (Button_A)
    {
      if (ReadPx(0, 7) == 4 && playerColor == enemyGreen)
      {
        Tone_Start(ToneA6,50);
        SetAuxLEDsBinary(B01111000);
        ycoord = 6;
        lineLevel = 2;
      }
    }
    if (Button_A)
    {
      if (ReadPx(0, 7) == 5 && playerColor == enemyBlue)
      {
        Tone_Start(ToneA6,50);
        SetAuxLEDsBinary(B01110000);
        ycoord = 6;
        lineLevel = 4;
      }
    }
    if (Button_A)
    {
      if (ReadPx(0, 7) == 6 && playerColor == enemyPurple)
      {
        Tone_Start(ToneA6,50);
        SetAuxLEDsBinary(B01111110);
        ycoord = 6;
        lineLevel = 6;
      }
    }
    if (lineLevel == 6)
    {
      Tone_Start(ToneB5,50);
      SetAuxLEDsBinary(B00000000);
      ycoord = 6;
      lineLevel = 1;
    }
}

void countdown()
{
  for (int i = 0; i < 8; i++)
  DrawPx(i, ycoord, Dark);
  if (timer % 3 == 0) //timer moves down every three turns
    {
      ycoord--;
    }
    
    if (ycoord == 1)//if timer reaches 1, everything resets
    {
      Tone_Start(ToneB5,50);
      SetAuxLEDsBinary(B00000000);
      ycoord = 6;
      lineLevel = 1;
    }
  }
