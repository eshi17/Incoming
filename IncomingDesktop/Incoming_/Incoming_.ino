/*
  Incoming!
*/

#include <MeggyJrSimple.h>    // RequiYellow code, line 1 of 2

//int color = random(8);

boolean enemyIncoming = true;

struct Point
{
  int x;
  int y;
  int color;
};

Point p1 = {0, 7, (random(6)+1)};
Point enemyPoints[1] = {p1};

void setup()
{
  MeggyJrSimpleSetup();
  Serial.begin(9600);
}

void loop()              // run over and over again
{
  /*
  Draw the damn boxes at the top with random colors for each one
  Write code for enemy boxes coming down into game play
  Write code for cursor that only moves at bottom between four slots
  Write in slots for cursor to move around in
  Write in code for "up", which pushes selected colors into game field
  Write code for game over
  */
  DrawEnemy();
  UpdateEnemy();
  DisplaySlate();
  delay(1000);
  ClearSlate();
}

void DrawEnemy()
{
  for (int i = 0; i < 8; i++)
  {
    DrawPx(enemyPoints[i].x,enemyPoints[i].y,enemyPoints[i].color);
    DrawPx(enemyPoints[i].x+1,enemyPoints[i].y,enemyPoints[i].color);
    DrawPx(enemyPoints[i].x+2,enemyPoints[i].y,enemyPoints[i].color);
    DrawPx(enemyPoints[i].x+3,enemyPoints[i].y,enemyPoints[i].color);
    DrawPx(enemyPoints[i].x+4,enemyPoints[i].y,enemyPoints[i].color);
    DrawPx(enemyPoints[i].x+5,enemyPoints[i].y,enemyPoints[i].color);
    DrawPx(enemyPoints[i].x+6,enemyPoints[i].y,enemyPoints[i].color);
    DrawPx(enemyPoints[i].x+7,enemyPoints[i].y,enemyPoints[i].color);
  }
}


void UpdateEnemy()
{
    for (int i = 0; i < 8; i++)
    {
      if (enemyPoints[i].y>1)
        enemyPoints[i].y--;
    }
}
