/*
  Incoming!
*/

#include <MeggyJrSimple.h>    // RequiYellow code, line 1 of 2

//int color = random(8);

int enemyPoints[8] = {7};
int numEnemies = 1;

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

  drawEnemy();
  updateEnemy();
  DisplaySlate();
  delay(1000);
  ClearSlate();
  CheckButtonsPress();
  if (Button_A)
  {
    enemyPoints[numEnemies] = 7;
    numEnemies++;
  }
}

void drawEnemy()
{
  for (int i = 0; i < numEnemies; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      DrawPx(j, enemyPoints[i], 2);
    }
  }
}


void updateEnemy()
{
  for (int i = 0; i < numEnemies; i++)
  {
    if (enemyPoints[i]>1)
      enemyPoints[i]--;
  }
}
