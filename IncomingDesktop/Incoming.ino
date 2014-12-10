/*
  Incoming!
*/

#include <MeggyJrSimple.h>    // RequiYellow code, line 1 of 2.

// Global Variables
int xcoord = 0;
int ycoord = 0; //original location of player
int timer = 1;

void setup()                    // run once, when the sketch starts
{
  MeggyJrSimpleSetup();
  Serial.begin(9600);
}

void loop()                     // run over and over again
{
  timer++; //add one to timer
  if (timer > 20) timer = 1;
  Serial.print("x = ");
  Serial.println(xcoord); //checks x print
  Serial.print("y = ");
  Serial.println(ycoord); //checks y print

  CheckButtonsDown();
  if (Button_Right) //All code that prevents you from walking through walls comes from Brent Uramoto
  {
    if(xcoord < 7)
    {
      xcoord++;
    }
  }
  
  if (Button_Left)
  {
    if(xcoord > 0)
    {
        xcoord--;
    }
  }
  
  if (Button_Up)
  {
  if(ycoord < 7)
      {
        ycoord++;
      }
  }
  
  if (Button_Down)
  {
    if(ycoord > 0)
        {
          ycoord--;
        }
  }

    DrawPx(xcoord,ycoord,Yellow); // Draws player
    DisplaySlate();
    delay(150); //had trouble making it "real time". Compromised both sharks and player so that it moves at an equal speed, although that makes the player a little slow
    ClearSlate();
}
