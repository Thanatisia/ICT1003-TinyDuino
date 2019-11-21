/*
 * Simple Watch 2
 *
 * Demonstrates the use of the Arduino Time library to make a simple digital watch
 * In this we write functions to set time and date and learn how to use the buttons
 * Also learn Arduino 'switch' and 'for' statements/commands
 *
 * Uses Arduino Time library http://playground.arduino.cc/code/time  
 * Maintained by Paul Stoffregen https://github.com/PaulStoffregen/Time
 *
 * This code is for the TinyScreen+ board by TinyCircuits used by O Watch http://tiny-circuits.com 
 *
 * This example is created by O Watch on 6 March 2016 http://theowatch.com 
 * 
*/

#include <TinyScreen.h> //include TinyScreen library
#include <TimeLib.h> //include the Arduino Time library


TinyScreen display = TinyScreen(0); //Create the TinyScreen object

void setup()
{
  display.begin();                            //Initializes TinyScreen board
  display.setFlip(1);                         //Flips the TinyScreen rightside up for O Watch
  display.on();                               //Turns TinyScreen display on
  display.fontColor(TS_8b_White,TS_8b_Black); //Set the font color, font background
  display.setBrightness(10);                  //Set display brightness 0 - 15
  
  display.setFont(liberationSansNarrow_8ptFontInfo);
  display.setCursor(5,7);
  //just for testing 
  display.print("Huat ah");

  //initialize random seed for 4d program
  randomSeed(analogRead(0));
  
}

void loop()
{
  //range of cases to choose from
  int rando = 0;
  rando = random(1, 11);
  //Switch statement to select part of code to run based on button selection
  switch (display.getButtons()) 
  {

    //Run quotes function if lower left button detected
    case TSButtonLowerLeft:{
      display.on();
      display.setFont(liberationSans_8ptFontInfo);

      //rng for quotes      
      switch(rando){
        case 1:
        display.setCursor(5,45);
        display.print("Got buy got hope");
        delay(1000);
        display.clearScreen();
        break;

        case 2:
        display.setCursor(5,45);
        display.print("No buy no hope");
        delay(1000);
        display.clearScreen();
        break;

        case 3:
        display.setCursor(5,45);
        display.print("50/50 win or lose");
        delay(1000);
        display.clearScreen();
        break;

        case 4:
        display.setCursor(5,45);
        display.print("4D 4 Lyfe");
        delay(1000);
        display.clearScreen();
        break;

        case 5:
        display.setCursor(5,45);
        display.print("Next time will win");
        delay(1000);
        display.clearScreen();
        break;

        case 6:
        display.setCursor(5,45);
        display.print("Get rich overnight");
        delay(1000);
        display.clearScreen();
        break;

        case 7:
        display.setCursor(5,45);
        display.print("Gamble = Invest");
        delay(1000);
        display.clearScreen();
        break;

        case 8:
        display.setCursor(5,45);
        display.print("$1 become $1m");
        delay(1000);
        display.clearScreen();
        break;

        case 9:
        display.setCursor(5,45);
        display.print("Loser's quit");
        delay(1000);
        display.clearScreen();
        break;

        case 10:
        display.setCursor(5,45);
        display.print("One win will do");
        delay(1000);
        display.clearScreen();
        break; 
        
      }
   break;
      
   }//run 4d number generator if bottom right button detected
   case TSButtonLowerRight:{
      //random num from 1 to 9999
      int num = random(10000);

      //print the result
      display.on();
      display.setFont(liberationSans_8ptFontInfo);
      display.setCursor(5,45);

      //padding for numbers from 100 to 999
      if (num < 1000 && num > 99) {
        display.print("0");
        display.print(num);

      //padding for numbers from 10 to 99
      } else if (num < 100 && num > 9){
        display.print("00");
        display.print(num);

      //padding for numbers below 10
      } else if (num < 10) {
        display.print("000");
        display.print(num);

      //4 digit numbers dont need padding
      } else {
        display.print(num);
      }
      delay(1000);
      display.clearScreen();
      break;
  }
  break;
}
}
