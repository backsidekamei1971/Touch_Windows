/*
 Name:		TouchTest.ino
 Created:	2019-12-25 12:52:14 AM
 Author:	Michael
*/

// the setup function runs once when you press reset or power the board

#include <Arduino.h>

#include <SPI.h>

#include <Adafruit_GFX.h>
#include <Waveshare4InchTftShield.h>

// Assign human-readable names to some common 16-bit color values:
#define	BLACK   0x0000
#define	BLUE    0x001F
#define	RED     0xF800
#define	GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

int j=0;

namespace
{
    Waveshare4InchTftShield Waveshield;
}

void setup() 
{
    SPI.begin();
    Waveshield.begin();

    Waveshield.setRotation(1);
    Waveshield.setTextSize(2);
    Waveshield.print("Let's Draw!");

    Waveshield.setRotation(0);

    Waveshield.fillRect(0, 0, 80, 80, YELLOW); 
    Waveshield.setCursor(5,5);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("CLEAR");

    Waveshield.fillRect(0, 80, 80, 80, MAGENTA);
    Waveshield.fillRect(0, 160, 80, 80, GREEN);
    Waveshield.fillRect(80,0,88,80, WHITE);
    Waveshield.fillRect(160, 0, 80, 80, BLUE);
}

int i = 0;

// the loop function runs over and over again until power down or reset
void loop()
{
    Waveshield.setRotation(0);
    //  Get raw touchscreen values.
    TSPoint p = Waveshield.getPoint();

    //  Remaps raw touchscreen values to screen co-ordinates.  Automatically handles
    //  rotation!
    Waveshield.normalizeTsPoint(p);



    //  Now that we have a point in screen co-ordinates, draw something there.
   // Waveshield.fillCircle(p.x, p.y, 3, BLUE);

    Waveshield.setRotation(1);
    Waveshield.setCursor(5,25);
    Waveshield.setTextColor(WHITE);
    Waveshield.print("x=");
    Waveshield.print(p.x);
    Waveshield.print("  y=");
    Waveshield.print(p.y);
delay(100);
    Waveshield.setCursor(5,25);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("x=");
    Waveshield.print(p.x);
    Waveshield.print("  y=");
    Waveshield.print(p.y);

    Waveshield.setRotation(0);

    if (p.x <= 80 && p.y <= 80 && p.x > 0 ) {
    Waveshield.fillScreen(BLACK);

    Waveshield.setRotation(1);
    Waveshield.setTextSize(2);
    Waveshield.setCursor(5,5);
    Waveshield.setTextColor(WHITE);
    Waveshield.print("Let's Draw!");

    Waveshield.setRotation(0);
    Waveshield.fillRect(0, 0, 80, 80, YELLOW); 

    Waveshield.setRotation(0);
    Waveshield.setCursor(5,5);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("CLEAR");
    Waveshield.fillRect(0, 80, 80, 80, MAGENTA);
    Waveshield.fillRect(0, 160, 80, 80, GREEN);
    Waveshield.fillRect(80, 0, 80, 80, WHITE);
    Waveshield.fillRect(160, 0, 80, 80, BLUE);
    }

    if (p.x <= 80 && p.y <= 160 && p.x > 0 && p.y >= 80 ) {
    Waveshield.fillScreen(BLACK);

        Waveshield.setRotation(0);
    Waveshield.fillRect(0, 0, 80, 80, YELLOW); 

    Waveshield.setRotation(0);
    Waveshield.setCursor(5,5);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("CLEAR");
    Waveshield.fillRect(0, 80, 80, 80, MAGENTA);
    Waveshield.fillRect(0, 160, 80, 80, GREEN);
    Waveshield.fillRect(80, 0, 80, 80, WHITE);
    Waveshield.fillRect(160, 0, 80, 80, BLUE);

    Waveshield.fillRect(0, 80, 80, 80, MAGENTA);
    Waveshield.fillCircle(200, 200, 40, MAGENTA);
    Waveshield.fillCircle(200, 400, 40, MAGENTA);
    }

    if (p.x <= 80 && p.y <= 240 && p.x > 0 && p.y >= 160 ) {
    Waveshield.fillScreen(BLACK);

        Waveshield.setRotation(0);
    Waveshield.fillRect(0, 0, 80, 80, YELLOW); 

    Waveshield.setRotation(0);
    Waveshield.setCursor(5,5);
    Waveshield.setTextSize(2);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("CLEAR");
    Waveshield.fillRect(0, 80, 80, 80, MAGENTA);
    Waveshield.fillRect(0, 160, 80, 80, GREEN);
    Waveshield.fillRect(80, 0, 80, 80, WHITE);
    Waveshield.fillRect(160, 0, 80, 80, BLUE);

    Waveshield.fillRect(0, 160, 80, 80, GREEN);
    Waveshield.fillCircle(200, 200, 40, GREEN);
    Waveshield.fillCircle(200, 400, 40, GREEN);
    }

    if (p.x <= 160 && p.y <= 80 && p.x > 80 && p.y >= 0 ) {
   // Waveshield.fillRect(80, 0, 80, 80, WHITE);
   //Waveshield.fillCircle(200, 200, 40, WHITE);
   // Waveshield.fillCircle(200, 400, 40, WHITE);
    Waveshield.fillRect(100, 100, 400, 400, WHITE);
    Waveshield.setRotation(1);
    Waveshield.fillRect(60, 230, 100, 50, CYAN);

    Waveshield.setCursor(50, 150);
    Waveshield.setTextColor(BLACK);
    Waveshield.setTextSize(3);
    Waveshield.print("Si is Wonderful!");

    Waveshield.setTextSize(2);
    Waveshield.setCursor(100, 250);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("OK");
    Waveshield.setCursor(200, 250);
    Waveshield.fillRect(185, 230, 100, 50, CYAN);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("Cancel");
    }
    if (p.x <= 295 && p.y <= 300 && p.x > 235 && p.y >= 200 ){
        
        Waveshield.setRotation(1);



        if(j==2){

      Waveshield.setCursor(70, 150);
      Waveshield.setTextColor(WHITE);
      Waveshield.setTextSize(3);
      Waveshield.print("Sustainable!");
        }

      
      Waveshield.setTextSize(3);
      Waveshield.setCursor(50, 150);
      Waveshield.setTextColor(WHITE);
      Waveshield.print("Si is Wonderful!");
      Waveshield.setCursor(30, 150);
      Waveshield.setTextColor(BLACK);
      Waveshield.print("Let`s Start WWIII !");
      j=1;

    }
      if (p.x <= 295 && p.y <= 450 && p.x > 235 && p.y >= 350 ){  
     Waveshield.setRotation(1);

        if(j==1){
      Waveshield.setCursor(30, 150);
      Waveshield.setTextColor(WHITE);
      Waveshield.setTextSize(3);
      Waveshield.print("Let`s Start WWIII !");    
        }

      
      Waveshield.setTextSize(3);
      Waveshield.setCursor(50, 150);
      Waveshield.setTextColor(WHITE);
      Waveshield.print("Si is Wonderful!");
      Waveshield.setCursor(70, 150);
      Waveshield.setTextColor(BLACK);
      Waveshield.print("Sustainable!");
      j=2;
      }

      Waveshield.setRotation(0);
    if (p.x <= 240 && p.y <= 80 && p.x > 160 && p.y >= 0 ) {
     
    Waveshield.fillScreen(BLACK);

    Waveshield.fillRect(0, 0, 80, 80, YELLOW); 
    Waveshield.setRotation(0);
    Waveshield.setCursor(5,5);
    Waveshield.setTextSize(2);
    Waveshield.setTextColor(BLACK);
    Waveshield.print("CLEAR");
    Waveshield.fillRect(0, 80, 80, 80, MAGENTA);
    Waveshield.fillRect(0, 160, 80, 80, GREEN);
    Waveshield.fillRect(80, 0, 80, 80, WHITE);
    Waveshield.fillRect(160, 0, 80, 80, BLUE);

    Waveshield.fillRect(90, 370, 20, 80, RED);
    Waveshield.fillRect(90, 280, 20, 80, MAGENTA);
    Waveshield.fillRect(90, 190, 20, 80, YELLOW);
    Waveshield.fillRect(90, 100, 20, 80, GREEN);

    Waveshield.fillRect(120, 370, 20, 80, RED);
    Waveshield.fillRect(120, 280, 20, 80, MAGENTA);
    Waveshield.fillRect(120, 190, 20, 80, YELLOW);
    Waveshield.fillRect(120, 100, 20, 80, GREEN);

    Waveshield.fillRect(150, 370, 20, 80, RED);
    Waveshield.fillRect(150, 280, 20, 80, MAGENTA);
    Waveshield.fillRect(150, 190, 20, 80, YELLOW);
    Waveshield.fillRect(150, 100, 20, 80, GREEN);

    Waveshield.fillRect(280, 230, 20, 80, WHITE);

    Waveshield.fillCircle(190, 230, 9, WHITE);

    }
    }
