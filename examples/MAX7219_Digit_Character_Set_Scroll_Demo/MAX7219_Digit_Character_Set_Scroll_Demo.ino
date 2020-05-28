/*
    MAX7219 Display - Scrolling Character Set
    Version 1 - 29th June 2020

    Pin connections
    Name      Arduino     ESP8266/Wemos D1    MAX7219 7 Segment display
    -----     -------     -------             -------------------------
              +5V         5V**                VCC
              GND         GND                 GND
    DIN       D11/MOSI    GPIO13 (D7)         DIN
    CS        *D7/SS      *GPIO15 (D8)        CS
    CLK       D13/SCK     GPIO14 (D5)         CLK -
    Martin Rowan
*/

#include <SPI.h>
#include <MAX7219_Digits.h>

#define MAX7219_CS 15                  // CS pin used on Wemos, adjust as needed

MAX7219_Digit My_Display(MAX7219_CS); // Make an instance of MAX7219_Digit called My_Display and set CS pin

int Char_1 = 0;
int Char_2 = 0;
int Char_3 = 0;
int Char_4 = 0;

void setup()
{
  Serial.begin(115200);
  Serial.println("Hello");

  My_Display.Begin();
  My_Display.Brightness(8);
}


void loop()
{
  Serial.println(Char_4);
  My_Display.Display_Text(1, Char_1, Char_2, Char_3, Char_4, 0b0000); // (Display_Line, Char_1, Char_2, Char_3, Char_4, 0b0000)
  Char_1 = Char_2;
  Char_2 = Char_3;
  Char_3 = Char_4;
  // change
  Char_4++;
  if (Char_4 > 34) {
    Char_4 = 0; //reset
  }
  delay(1000);
}
