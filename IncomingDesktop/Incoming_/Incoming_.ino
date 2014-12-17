/*
  Incoming!
*/

#include <MeggyJrSimple.h>    // RequiYellow code, line 1 of 2

//int color = random(8);

struct Point
{
  int x;
  int y;
  int color;
};

Point p1 = {1, 7, (random(6)+1)};
Point p2 = {3, 7, (random(6)+1)};
Point p3 = {5, 7, (random(6)+1)};
Point myPoints[3] = {p1,p2,p3};

void setup()
{
  MeggyJrSimpleSetup();
  Serial.begin(9600);
}

void loop()              // run over and over again
{
  /*
  Draw the damn boxes at the top with random colors for each one
  Write code for cursor that only moves at bottom between four slots
  Write in slots for cursor to move around in
  Write in code for "up", which pushes selected colors into 
  */
  DrawBox();
  DisplaySlate();
}

void DrawBox()
{
  for (int i = 0; i < 4; i++)
  {
    DrawPx(myPoints[i].x,myPoints[i].y,myPoints[i].color);
    DrawPx(myPoints[i].x+1,myPoints[i].y,myPoints[i].color);
  }
}
