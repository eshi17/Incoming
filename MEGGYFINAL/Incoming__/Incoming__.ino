/*
  Incoming!
*/

#include <MeggyJrSimple.h>    // RequiYellow code, line 1 of 2

int enemyPoints[7] = {7}; //y coordinate of enemy array
int colors[100] = {0};
int numEnemies = 1;//number of enemies on screen
int playerPoints[100] = {0};
int numPlayer = 1;
boolean addEnemy = false;
int playerColor = 1;
int timer = 1;
int offset = random(93);

void setup()
{
  MeggyJrSimpleSetup();
  Serial.begin(9600);
  fillColors();
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
  timer++; //add one to timer
    if (timer > 20) timer = 1;
  CheckButtonsDown();
  drawEnemy();
  updateEnemy();
  newEnemy();
  DrawPlayer();
  checkHit();
  DisplaySlate();
  delay(150);
  ClearSlate();
}


void drawEnemy() //draws a single horizontal line of a certain color (out of red, blue, yellow)
{
  for (int i = 0; i < numEnemies; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      DrawPx(j, enemyPoints[i], colors[i + offset]);
    }
  }
}

void updateEnemy()
{
  if (timer % 10 == 0)
  {
    for (int i = 0; i < numEnemies; i++)
    {
      if (enemyPoints[i]>2 && ReadPx(0, enemyPoints[i] - 1) == 0) //if theres nothing below line
      {
        enemyPoints[i]--;//moves line down
        if (enemyPoints[i] == 2)//if enemy has stopped moving, add new enemy
        {
         addEnemy = true;
        }
      }
      if (enemyPoints[i]>2 && ReadPx(0, enemyPoints[i] - 1) != 0) //code from MeggyJr_Moving_Rows.pde; keeps block there if there is a line below
      {
        addEnemy = true;
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
    
  if (Button_Right)       // Change player color
  {    
    playerColor++;      //Increase playerColor by one, which in turns changes the color itself
  }
  
  if (playerColor > 5)
  {
    playerColor = 1; //creates a wrap for the player. Maximum color is blue
  }
  
  if (Button_Left)       // Change player color
  {    
    playerColor--;      //Decrease playerColor by one, which in turns changes the color itself
  }
  
  if (playerColor < 1)
  {
    playerColor = 5; //creates a wrap for the player. Maximum color is blue
  }
  }
}

void checkHit() // Check to see if the playerColor is the same as the colored line right above it.
// If it is the same, then colored enemy line above player dissapears
{
    if (Button_Up)
    {
     if (playerColor == colors[0+offset])
      {
        //copy all values in enemyPoints over by one
        //add a new enemy at the last index in array
        for (int i = 0; i < numEnemies-1; i++)
        {
          enemyPoints[i] = enemyPoints[i+1];//enemy line becomes one above it
        }
        enemyPoints[numEnemies-1] = 7;
        if (offset < 92) //if colors is less than 100
          {
            offset++;//add one to colors (viewing box will move higher)
          }
          else offset = 0;//wrap back to 0
        //copy all values in colors over by one
      }
    }
}
    /*
    if playercolor matches the color in colors[0]
    then shift every element in enemyPoints up by one.
    shift every color in colors up by one.
    {
      if (playerPoints[i]<8)
      playerPoints[i]++;
    }
*/

void fillColors()
{
  // fill array with random numbers from 1 to 5.
  for (int i = 0; i < 100; i++)
  {
    colors[i] = random(5)+1;//generates random colors between 1 and 5
  }
}
