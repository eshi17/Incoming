/*
  Incoming!
*/

#include <MeggyJrSimple.h>    // RequiYellow code, line 1 of 2

int enemyPoints[100] = {7}; //y coordinate of enemy array
int colors[100] = {1,3,5,7};
int numEnemies = 1;//number of enemies on screen
int playerPoints[100] = {0};
int numPlayer = 1;
boolean addEnemy = false;
int playerColor = 1;

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
  CheckButtonsDown();
  drawEnemy();
  updateEnemy();
  newEnemy();
  DrawPlayer();
  updatePlayer();
  newPlayer();
  DisplaySlate();
  delay(500);
  ClearSlate();
}


void drawEnemy()
{
  for (int i = 0; i < numEnemies; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      DrawPx(j, enemyPoints[i], colors[i]);
    }
  }
}

void updateEnemy()
{
  for (int i = 0; i < numEnemies; i++)
  {
    if (enemyPoints[i]>1 && ReadPx(0, enemyPoints[i] - 1) == 0) //moves line down if theres nothing below it
    {
      enemyPoints[i]--;
      if (enemyPoints[i] == 1)
        addEnemy = true;
    }
      if (ReadPx(0, enemyPoints[i] - 1) != 0) //code from MeggyJr_Moving_Rows.pde; keeps block there if there is a line below
      {
        if (numEnemies < 7)
        {
          enemyPoints[numEnemies] = 8;
          numEnemies++;
        }
      }
  }
}

void newEnemy()
{
  if (addEnemy == true && numEnemies < 7)
  {
      enemyPoints[numEnemies] = 7;
      numEnemies++;
      addEnemy = false;
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
  }
}

void updatePlayer()
{
  for (int i = 0; i < numPlayer; i++)
  {
    if (Button_Up)
    {
      if (playerPoints[i]<8)
      playerPoints[i]++;
    }
  }
}

void newPlayer()
{
  for (int i = 0; i < numPlayer; i++)
  if (playerPoints[i] == 1)
  {
    playerPoints[numPlayer] = 0;
    numPlayer++;
  }
}


