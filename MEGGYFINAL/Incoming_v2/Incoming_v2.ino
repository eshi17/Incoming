/*
  WhiteBox
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

void setup()
{
  MeggyJrSimpleSetup();
  Serial.begin(9600);
}

void loop()              // run over and over again
{
  CheckButtonsPress();
  drawEnemy();
  whiteLine();
  DrawPlayer();
  checkHit();
  DisplaySlate();
  delay(300);
  ClearSlate();
}


void drawEnemy() //draws a single horizontal line of a certain color (out of red, orange, yellow, green, blue, purple)
{
  for (int r = 0; r < 8; r++)
  {
    if (lineLevel == 1)
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
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      DrawPx(j, 0, playerColor);
    }
    
  if (Button_Right)       // Change player color
  {    
    playerColor = playerColor + 1;      //Increase playerColor by one, which in turns changes the color itself
  }
  
  if (playerColor > 6)
  {
    playerColor = 1; //creates a wrap for the player. Maximum color is blue
  }
  
  if (Button_Left)       // Change player color
  {    
    playerColor = playerColor - 1;      //Decrease playerColor by one, which in turns changes the color itself
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
    DrawPx(x, y, White);
  }
}

void checkHit() // Check to see if the playerColor is the same as the colored line right above it.
// If it is the same, then colored enemy line above player dissapears
{
    if (Button_A)
    {
      if (ReadPx(0, 7) == 1 && playerColor == enemyRed)
        {
          Tone_Start(ToneA6,50);
          lineLevel = 3;
        }
      }
    if (Button_A)
    {
      if (ReadPx(0, 7) == 2 && playerColor == enemyOrange)
      {
        Tone_Start(ToneA6,50);
        lineLevel = 6;
      }
    }
    if (Button_A)
    {
      if (ReadPx(0, 7) == 3 && playerColor == enemyYellow)
      {
        Tone_Start(ToneA6,50);
        lineLevel = 5;
      }
    }
    if (Button_A)
    {
      if (ReadPx(0, 7) == 4 && playerColor == enemyGreen)
      {
        Tone_Start(ToneA6,50);
        lineLevel = 2;
      }
    }
    if (Button_A)
    {
      if (ReadPx(0, 7) == 5 && playerColor == enemyBlue)
      {
        Tone_Start(ToneA6,50);
        lineLevel = 4;
      }
    }
    if (Button_A)
    {
      if (ReadPx(0, 7) == 6 && playerColor == enemyPurple)
      {
        Tone_Start(ToneA6,50);
        lineLevel = 1;
      }
    }
}
