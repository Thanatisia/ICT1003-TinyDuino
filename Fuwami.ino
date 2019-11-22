#include <Wire.h>
#include <SPI.h>
#include <TinyScreen.h>


#define ALPHA 0xFE
#define BACKGROUND 0x00
#define BACKGROUND_COLOR_TOP 0x1F
//0xE1 light blue
#define SCREEN_WIDTH 96
#define SCREEN_HEIGHT 64

// tiny screen object 
TinyScreen display = TinyScreen(0);

/************************************************
 *  ... CHARACTER SPRITE ALLOCATIONS
 ***********************************************/

//happy
uint8_t SPRITE_BUNNY_XY[2] = {24, 29};
const uint8_t SPRITE_BUNNY_BASE[696] PROGMEM = {ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 255, 255, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 255, 255, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 255, 147, 255, 255, 0, ALPHA, ALPHA, ALPHA, 0, 255, 255, 147, 255, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 255, 255, 147, 255, 0, ALPHA, ALPHA, ALPHA, 0, 255, 147, 255, 255, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 255, 147, 147, 0, ALPHA, ALPHA, ALPHA, 0, 147, 147, 255, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 147, 255, 0, ALPHA, 0, 255, 147, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 147, 255, 0, ALPHA, 0, 255, 147, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 111, 111, 111, 111, 111, 111, 111, 111, 111, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 111, 68, 68, 111, 111, 111, 111, 111, 68, 68, 111, 111, 111, 111, 0, ALPHA, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 111, 68, 219, 68, 111, 111, 111, 111, 111, 68, 219, 68, 111, 111, 111, 111, 0, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 68, 219, 219, 219, 68, 111, 68, 111, 68, 219, 219, 219, 68, 111, 111, 111, 0, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 68, 219, 219, 219, 219, 68, 219, 68, 219, 219, 219, 219, 68, 111, 111, 111, 0, ALPHA, ALPHA, 0, 111, 111, 111, 68, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 68, 111, 111, 111, 0, ALPHA, 0, 111, 111, 111, 68, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 68, 111, 111, 111, 0, ALPHA, 0, 111, 111, 111, 68, 219, 0, 0, 0, 0, 219, 219, 219, 0, 0, 0, 0, 219, 68, 68, 111, 111, 0, ALPHA, 0, 111, 111, 68, 219, 219, 219, 219, 0, 255, 219, 219, 219, 0, 255, 219, 219, 219, 219, 68, 111, 111, 0, ALPHA, ALPHA, 0, 111, 68, 219, 219, 219, 219, 0, 0, 219, 219, 219, 0, 0, 219, 219, 219, 219, 68, 111, 0, ALPHA, ALPHA, ALPHA, ALPHA, 68, 0, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 219, 219, 219, 219, 219, 219, 219, 147, 219, 219, 219, 219, 219, 219, 219, 219, 0, 0, ALPHA, ALPHA, ALPHA, 0, 219, 219, 0, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 0, 219, 219, 0, ALPHA, 0, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 0, 0, 219, 219, 219, 219, 219, 219, 219, 0, 219, 219, 219, 219, 219, 0, 219, 219, 219, 219, 219, 219, 219, 219, 0, 0, 219, 219, 219, 219, 219, 219, 219, 219, 0, 0, 0, 0, 0, 219, 219, 219, 219, 219, 219, 219, 219, 219, 0, ALPHA, 0, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 0, ALPHA, ALPHA, ALPHA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ALPHA, ALPHA};
//regular
const uint8_t SPRITE_BUNNY_POKER[696] PROGMEM = {ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 255, 255, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 255, 255, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 255, 147, 255, 255, 0, ALPHA, ALPHA, ALPHA, 0, 255, 255, 147, 255, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 255, 255, 147, 255, 0, ALPHA, ALPHA, ALPHA, 0, 255, 147, 255, 255, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 255, 147, 147, 0, ALPHA, ALPHA, ALPHA, 0, 147, 147, 255, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 147, 255, 0, ALPHA, 0, 255, 147, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 147, 255, 0, ALPHA, 0, 255, 147, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 111, 111, 111, 111, 111, 111, 111, 111, 111, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 111, 68, 68, 111, 111, 111, 111, 111, 68, 68, 111, 111, 111, 111, 0, ALPHA, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 111, 68, 219, 68, 111, 111, 111, 111, 111, 68, 219, 68, 111, 111, 111, 111, 0, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 68, 219, 219, 219, 68, 111, 68, 111, 68, 219, 219, 219, 68, 111, 111, 111, 0, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 68, 219, 219, 219, 219, 68, 219, 68, 219, 219, 219, 219, 68, 111, 111, 111, 0, ALPHA, ALPHA, 0, 111, 111, 111, 68, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 68, 111, 111, 111, 0, ALPHA, 0, 111, 111, 111, 68, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 68, 111, 111, 111, 0, ALPHA, 0, 111, 111, 111, 68, 219, 0, 0, 0, 0, 219, 219, 219, 0, 0, 0, 0, 219, 68, 68, 111, 111, 0, ALPHA, 0, 111, 111, 68, 219, 219, 219, 219, 0, 255, 219, 219, 219, 0, 255, 219, 219, 219, 219, 68, 111, 111, 0, ALPHA, ALPHA, 0, 111, 68, 219, 219, 219, 219, 0, 0, 219, 219, 219, 0, 0, 219, 219, 219, 219, 68, 111, 0, ALPHA, ALPHA, ALPHA, ALPHA, 68, 0, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 219, 219, 219, 219, 219, 219, 219, 147, 219, 219, 219, 219, 219, 219, 219, 219, 0, 0, ALPHA, ALPHA, ALPHA, 0, 219, 219, 0, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 0, 219, 219, 0, ALPHA, 0, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 0, 0, 219, 219, 219, 219, 219, 219, 219, 0, 0, 0, 0, 0, 0, 0, 219, 219, 219, 219, 219, 219, 219, 219, 0, 0, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 0, ALPHA, 0, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 0, ALPHA, ALPHA, ALPHA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ALPHA, ALPHA};
//sad
const uint8_t SPRITE_BUNNY_HUNGRY[696] PROGMEM = {ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 255, 255, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 255, 255, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 255, 147, 255, 255, 0, ALPHA, ALPHA, ALPHA, 0, 255, 255, 147, 255, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 255, 255, 147, 255, 0, ALPHA, ALPHA, ALPHA, 0, 255, 147, 255, 255, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 255, 147, 147, 0, ALPHA, ALPHA, ALPHA, 0, 147, 147, 255, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 147, 255, 0, ALPHA, 0, 255, 147, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 147, 255, 0, ALPHA, 0, 255, 147, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 111, 111, 111, 111, 111, 111, 111, 111, 111, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 111, 68, 68, 111, 111, 111, 111, 111, 68, 68, 111, 111, 111, 111, 0, ALPHA, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 111, 68, 219, 68, 111, 111, 111, 111, 111, 68, 219, 68, 111, 111, 111, 111, 0, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 68, 219, 219, 219, 68, 111, 68, 111, 68, 219, 219, 219, 68, 111, 111, 111, 0, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 68, 219, 219, 219, 219, 68, 219, 68, 219, 219, 219, 219, 68, 111, 111, 111, 0, ALPHA, ALPHA, 0, 111, 111, 111, 68, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 68, 111, 111, 111, 0, ALPHA, 0, 111, 111, 111, 68, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 68, 111, 111, 111, 0, ALPHA, 0, 111, 111, 111, 68, 219, 0, 0, 0, 0, 219, 219, 219, 0, 0, 0, 0, 219, 68, 68, 111, 111, 0, ALPHA, 0, 111, 111, 68, 219, 219, 219, 219, 0, 255, 219, 219, 219, 0, 255, 219, 219, 219, 219, 68, 111, 111, 0, ALPHA, ALPHA, 0, 111, 68, 219, 219, 219, 219, 0, 0, 219, 219, 219, 0, 0, 219, 219, 219, 219, 68, 111, 0, ALPHA, ALPHA, ALPHA, ALPHA, 68, 0, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 219, 219, 219, 219, 219, 219, 219, 147, 219, 219, 219, 219, 219, 219, 219, 219, 0, 0, ALPHA, ALPHA, ALPHA, 0, 219, 219, 0, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 0, 219, 219, 0, ALPHA, 0, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 0, 0, 219, 219, 219, 219, 219, 219, 219, 219, 0, 0, 0, 0, 0, 219, 219, 219, 219, 219, 219, 219, 219, 219, 0, 0, 219, 219, 219, 219, 219, 219, 219, 0, 219, 219, 219, 219, 219, 0, 219, 219, 219, 219, 219, 219, 219, 219, 0, ALPHA, 0, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 0, ALPHA, ALPHA, ALPHA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ALPHA, ALPHA};
//sleep
const uint8_t SPRITE_BUNNY_SLEEP[696] PROGMEM = {ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 255, 255, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 255, 255, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 255, 147, 255, 255, 0, ALPHA, ALPHA, ALPHA, 0, 255, 255, 147, 255, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 255, 255, 147, 255, 0, ALPHA, ALPHA, ALPHA, 0, 255, 147, 255, 255, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 255, 147, 147, 0, ALPHA, ALPHA, ALPHA, 0, 147, 147, 255, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 147, 255, 0, ALPHA, 0, 255, 147, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 255, 147, 255, 0, ALPHA, 0, 255, 147, 255, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 111, 111, 111, 111, 111, 111, 111, 111, 111, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 0, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 111, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 111, 68, 68, 111, 111, 111, 111, 111, 68, 68, 111, 111, 111, 111, 0, ALPHA, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 111, 68, 219, 68, 111, 111, 111, 111, 111, 68, 219, 68, 111, 111, 111, 111, 0, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 68, 219, 219, 219, 68, 111, 68, 111, 68, 219, 219, 219, 68, 111, 111, 111, 0, ALPHA, ALPHA, ALPHA, 0, 111, 111, 111, 68, 219, 219, 219, 219, 68, 219, 68, 219, 219, 219, 219, 68, 111, 111, 111, 0, ALPHA, ALPHA, 0, 111, 111, 111, 68, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 68, 111, 111, 111, 0, ALPHA, 0, 111, 111, 111, 68, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 68, 111, 111, 111, 0, ALPHA, 0, 111, 111, 111, 68, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 68, 68, 111, 111, 0, ALPHA, 0, 111, 111, 68, 219, 219, 0, 0, 0, 0, 219, 219, 219, 0, 0, 0, 0, 219, 219, 68, 111, 111, 0, ALPHA, ALPHA, 0, 111, 68, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 68, 111, 0, ALPHA, ALPHA, ALPHA, ALPHA, 68, 0, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 0, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 0, 0, 219, 219, 219, 219, 219, 219, 219, 147, 219, 219, 219, 219, 219, 219, 219, 219, 0, 0, ALPHA, ALPHA, ALPHA, 0, 219, 219, 0, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 0, 219, 219, 0, ALPHA, 0, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 0, 0, 219, 219, 219, 219, 219, 219, 219, 0, 0, 0, 0, 0, 0, 0, 219, 219, 219, 219, 219, 219, 219, 219, 0, 0, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 0, ALPHA, 0, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 0, ALPHA, ALPHA, ALPHA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ALPHA, ALPHA};

/************************************************
 *  ... NON-CHARACTER SPRITE ALLOCATIONS
 ***********************************************/

//bed
uint8_t SPRITE_BED_XY[2] = {17, 13};
const uint8_t SPRITE_BED[221] PROGMEM = {ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 36, 36, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 36, 146, 146, 36, ALPHA, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 109, 36, 36, 6, 6, 6, 6, 43, 43, 43, 43, 43, 43, 36, 255, 255, 36, 109, 36, 36, 6, 43, 43, 43, 43, 43, 43, 43, 43, 43, 36, 255, 255, 36, 109, 36, 36, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 36, 255, 255, 36, 36, 36, 36, 43, 43, 43, 43, 43, 43, 43, 43, 43, 43, 36, 255, 36, 146, 146, 36, 36, 43, 43, 6, 6, 6, 6, 6, 6, 6, 6, 6, 36, 36, 146, 146, 36, 36, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 36, 146, 146, 36, 36, 7, 7, 7, 6, 6, 7, 7, 6, 6, 7, 7, 6, 36, 146, 146, 36, 36, 36, 36, 7, 7, 7, 36, 7, 7, 7, 36, 36, 7, 36, 146, 146, 36, 36, 146, 146, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 36, 146, 146, 36, ALPHA, 36, 36, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 36, 36, ALPHA};

//cactus
uint8_t SPRITE_CACTUS_XY[2] = {18, 22};
const uint8_t SPRITE_CACTUS[396] PROGMEM = {ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 86, 86, 49, 49, 86, 49, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 49, 86, 86, 49, 49, 86, 49, 49, ALPHA, ALPHA, 86, 49, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 49, 86, 86, 49, 49, 86, 49, 49, ALPHA, 49, 86, 49, 86, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 49, 86, 86, 49, 49, 86, 49, 49, ALPHA, 49, 86, 49, 86, ALPHA, 49, 49, ALPHA, ALPHA, 49, 86, 86, 49, 49, 86, 49, 49, ALPHA, 49, 86, 49, 86, 86, 85, 49, 49, ALPHA, 49, 86, 86, 49, 49, 86, 49, 49, ALPHA, 85, 86, 49, 86, 85, 86, 49, 49, ALPHA, 49, 86, 86, 49, 49, 86, 49, 49, 86, 86, 85, 49, 86, 49, 86, 49, 49, ALPHA, 49, 86, 86, 49, 49, 86, 49, 49, 85, 85, 49, 85, 86, 49, 86, 85, 49, 49, 49, 86, 86, 49, 49, 86, 49, 49, 85, 85, 85, 86, 85, 49, 85, 86, 85, 85, 49, 86, 86, 49, 49, 86, 49, 49, 85, 85, 85, 85, 49, 49, 49, 85, 85, 85, 49, 86, 86, 49, 49, 86, 49, 49, 49, 49, 49, 49, ALPHA, ALPHA, 49, 49, 49, 49, 49, 86, 86, 49, 49, 86, 49, 49, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 49, 86, 86, 49, 49, 86, 49, 49, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 6, 6, 46, 46, 82, 78, 78, 82, 78, 78, 79, 79, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 6, 6, 6, 6, 79, 79, 79, 79, 79, 79, 79, 79, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 6, 6, 6, 6, 79, 79, 79, 79, 79, 79, 79, 79, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 6, 6, 6, 6, 43, 43, 43, 43, 43, 43, 43, 79, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 6, 6, 6, 43, 43, 43, 43, 43, 43, 43, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 6, 6, 6, 79, 79, 79, 79, 79, 79, 79, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 6, 6, 6, 79, 79, 79, 79, 79, 79, 79, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 6, 6, 6, 79, 79, 79, 79, 79, 79, 79, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, ALPHA, 6, 6, 6, 79, 79, 79, 79, 79, 79, 79, ALPHA, ALPHA, ALPHA, ALPHA};

//carrot
uint8_t SPRITE_CARROT_XY[2] = {5, 9};
const uint8_t SPRITE_CARROT[45] PROGMEM = {85, 85, ALPHA, 85, ALPHA, ALPHA, ALPHA, 85, ALPHA, ALPHA, ALPHA, 6, 43, 43, ALPHA, 43, 43, 43, 6, 43, 43, 43, 43, 43, 6, 43, 6, 43, 43, 43, ALPHA, 43, 43, 43, ALPHA, ALPHA, 6, 6, 43, ALPHA, ALPHA, ALPHA, 43, ALPHA, ALPHA};

//window 
uint8_t SPRITE_WINDOW_XY[2] = {11, 11};
const uint8_t SPRITE_WINDOW[121] PROGMEM = {109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 244, 244, 255, 244, 109, 244, 244, 255, 255, 109, 109, 244, 255, 255, 255, 109, 244, 244, 244, 244, 109, 109, 244, 244, 244, 244, 109, 244, 244, 244, 44, 109, 109, 244, 244, 244, 244, 109, 244, 244, 44, 44, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 244, 244, 244, 244, 109, 244, 244, 244, 73, 109, 109, 85, 85, 85, 85, 109, 85, 85, 81, 81, 109, 109, 85, 85, 85, 85, 109, 85, 85, 85, 81, 109, 109, 85, 81, 81, 81, 109, 85, 85, 85, 85, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109, 109};

/************************************************
 *  ... CONSTANTS
 ***********************************************/

// dont need progmem since we now have lots of extra RAM left due to massive optimisations
const char *WORD_BANK[] = {
	"Got buy got hope",
	"No buy no hope",
	"50/50 win or lose", 
	"4D 4 Lyfe",
	"Next time will win",
	"Get rich overnight",
	"Gamble = Invest",
	"$1 become $1m",
	"Losers quit",
	"One win will do",
	"Got project to do",
	"JUST DO IT",
	"Make things fast",
	"Break things",
	"Just one more",
	"Win big",
	"<3 Prof Steven",
	"<3 Prof Alexander",
	"Learn unlearn ",
	"catalyse change",
	"grounded smth",
	"think thonk"
};

// GAME CONSTANTS (THESE ARE MEASURED IN GAME TICKS, POSITIONS ARE MEASURED IN PIXELS)
const uint8_t CHARACTERXPOS = 43;
const uint8_t CHARACTERYPOS = 15;
const uint16_t HUNGER_INTERVAL = 3000;
const uint16_t SLEEP_INTERVAL = 6000;
const uint8_t TEXT_INTERVAL = 100;
const uint8_t BUNNY_SLEEP_DURATION = 255; // how many ticks the sleeping animation is played for 

const uint8_t TOP_BOTTOM_BOUNDARY = 20;
const int16_t PIXELS_STATUS_BAR = 20; //decides the x-width of status bar

/************************************************
 *  ... UNIVERSAL BUFFERS
 ***********************************************/

char GD_BUFFER[5]; //stores 4d numbers
uint16_t RANDNUM; // stores randon numbers

uint32_t startLoopTime; 
uint32_t endLoopTime;

// GAME STATES, USED TO FIND CORRESPONDING ANIMATIONS
bool IS_IDLE = true;
bool IS_HUNGRY = false;
bool IS_RNG = false;
bool IS_QUOTE = false;
bool IS_SLEEP = false;
bool IS_TIRED = false;

uint8_t STATE = 0; //animation state


// game ticks elapsed, resets upon user feeding/ letting bunny sleep
uint16_t TICKS_ELAPSED_SINCE_FED = 0;
uint16_t TICKS_ELAPSED_SINCE_SLEEP = 0;
uint8_t TICKS_ELAPSED_SINCE_TEXT = 0;
uint8_t TICKS_ELAPSED_SINCE_4D = 0;

int16_t PIXELS_FOR_HUNGER = 20; // controls width of hunger bar currently
uint16_t PIXELS_FOR_SLEEP = 20; // controls width of sleep bar currently

void setup() {
	Wire.begin();
	display.begin();
	display.on();
	display.setFlip(true);
	display.setBrightness(10);	
  	display.fontColor(TS_8b_White,TS_8b_Black); //Set the font color, font background
  	display.setFont(liberationSansNarrow_8ptFontInfo);
	// set the background color for the top section
	display.drawRect(0,  0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - TOP_BOTTOM_BOUNDARY, true, BACKGROUND_COLOR_TOP);	
	//draw the bed
	drawSprite(SPRITE_BED, SPRITE_BED_XY[0], SPRITE_BED_XY[1], CHARACTERXPOS + 33, CHARACTERYPOS + 15);	  
	// draw the default bunny
	drawSprite(SPRITE_BUNNY_POKER, SPRITE_BUNNY_XY[0], SPRITE_BUNNY_XY[1], CHARACTERXPOS, CHARACTERYPOS);  	
	// draw the cactus
	drawSprite(SPRITE_CACTUS, SPRITE_CACTUS_XY[0], SPRITE_CACTUS_XY[1], CHARACTERXPOS - 30, CHARACTERYPOS + 8); // initial sprite is the idle/base state	  
	// draw the window
	drawSprite(SPRITE_WINDOW, SPRITE_WINDOW_XY[0], SPRITE_WINDOW_XY[1], CHARACTERXPOS - 35, CHARACTERYPOS - 10);
	// get a random seed for rng generator
	randomSeed(analogRead(0));
}

// main game loop
void loop() { 

	// for clearing carrot
	if (TICKS_ELAPSED_SINCE_FED >= 5){
		display.drawRect(CHARACTERXPOS + 40, CHARACTERYPOS - 1, SPRITE_CARROT_XY[0], SPRITE_CARROT_XY[1], true, BACKGROUND_COLOR_TOP);
	}
	if (!IS_RNG && !IS_QUOTE){
		drawPeriodStatus();	
		characterAnim();
	}
	if (IS_QUOTE){
		showQuote4d(WORD_BANK, true, &TICKS_ELAPSED_SINCE_TEXT);
	} else if (IS_RNG){
		showQuote4d(WORD_BANK, false, &TICKS_ELAPSED_SINCE_4D);
	}

	startLoopTime = millis();
	updateStatuses();
	endLoopTime = millis();
	if (endLoopTime - startLoopTime < 25) // 33 ms is roughly 30fps
		//delay(33 - endLoopTime + startLoopTime); // delay to make it around 30 fps
		while (millis() - endLoopTime < 25 - endLoopTime + startLoopTime) buttonLoop();
	display.setY(0, SCREEN_HEIGHT-1);
	display.setX(0, SCREEN_WIDTH-1);		
	//display.clearScreen(); // clear the screen
}

// checks character state and decides on what animation to draw
void characterAnim(){
	if ((IS_IDLE || IS_TIRED) && STATE != 0 && !IS_RNG && !IS_SLEEP){ // this is to check the current state and whether it needs to clear the screen	
		//display.clearWindow(CHARACTERXPOS, CHARACTERYPOS, SPRITE_BUNNY_XY[0], SPRITE_BUNNY_XY[1]);
		STATE = 0;		
		drawSprite(SPRITE_BUNNY_POKER, SPRITE_BUNNY_XY[0], SPRITE_BUNNY_XY[1], CHARACTERXPOS, CHARACTERYPOS);
	}
	else if (IS_HUNGRY && STATE !=1 && !IS_SLEEP){
		//display.clearWindow(CHARACTERXPOS, CHARACTERYPOS, SPRITE_BUNNY_XY[0], SPRITE_BUNNY_XY[1]);
		drawSprite(SPRITE_BUNNY_HUNGRY, SPRITE_BUNNY_XY[0], SPRITE_BUNNY_XY[1], CHARACTERXPOS, CHARACTERYPOS);
		STATE = 1;
	}
	else if (IS_RNG && STATE != 2 && !IS_HUNGRY){
		//display.clearWindow(CHARACTERXPOS, CHARACTERYPOS, SPRITE_BUNNY_XY[0], SPRITE_BUNNY_XY[1]);
		drawSprite(SPRITE_BUNNY_BASE, SPRITE_BUNNY_XY[0], SPRITE_BUNNY_XY[1], CHARACTERXPOS, CHARACTERYPOS);
		STATE = 2;
	}
	else if (IS_SLEEP){
		drawSprite(SPRITE_BUNNY_SLEEP, SPRITE_BUNNY_XY[0], SPRITE_BUNNY_XY[1], CHARACTERXPOS, CHARACTERYPOS); 
		STATE = 3;
	}
}
/************************************************
 *  ... CHARACTER LOGIC FUNCTIONS
 ***********************************************/
void updateStatuses(){
	updatePeriodStatus(&TICKS_ELAPSED_SINCE_FED, &HUNGER_INTERVAL, &IS_HUNGRY, &PIXELS_FOR_HUNGER);
	updatePeriodStatus(&TICKS_ELAPSED_SINCE_SLEEP, &SLEEP_INTERVAL, &IS_TIRED, &PIXELS_FOR_SLEEP);
	if (TICKS_ELAPSED_SINCE_SLEEP >= BUNNY_SLEEP_DURATION){
		IS_SLEEP = false;
	}
}

// this updates any periodic status, like sleep, hunger happiness etc. using passing by reference to save stack space.
void updatePeriodStatus(uint16_t * STATUS_TICKER, const uint16_t * INTERVAL, bool * GAME_STATE_TO_UPDATE, int16_t * PIXELS_FOR_X){
	*STATUS_TICKER += 1;
	if (*STATUS_TICKER % (*INTERVAL / PIXELS_STATUS_BAR) == 0){
		*PIXELS_FOR_X = (*PIXELS_FOR_X-1 < 0) ? 0 : *PIXELS_FOR_X-1;
	}
	if (*STATUS_TICKER >= *INTERVAL){
		IS_IDLE = false;
		*GAME_STATE_TO_UPDATE = true;
	} else {
		IS_IDLE = true;
		*GAME_STATE_TO_UPDATE = false;
	}
}


/************************************************
 *  ... PURE GUI FUNCTIONS BELOW
 ***********************************************/

/**	Draws a sprite given by the SpritePtr, Sprites are the bitmap values.
* 	@param SpritePtr The pointer to the bitmap to drawBuff
*	@param sizeX	The width of the sprite in pixels, MUST BE EVEN.
*	@param sizeY	The height of the sprite in pixels, can be even or odd.
*	@param startX	The starting X coordinate you want to draw the sprite at.
*	@param startY	The starting Y coordinate you want to draw the sprite at.
*/
void drawSprite(const uint8_t* SpritePtr, const uint8_t sizeX, const uint8_t sizeY, const uint8_t startX, const uint8_t startY){
	uint8_t drawBuff[sizeX];
	uint16_t pixel;
	uint8_t pixel0;
	uint8_t pixel1;
	display.setX(startX, startX + sizeX-1);
	display.setY(startY, startY + sizeY-1);	
	display.startData();
	for (uint8_t i=0; i< sizeY; i++){	
		for (uint8_t z=0; z< sizeX;){
			//pixel = pgm_read_byte_near(SpritePtr + z + (sizeX * i));
			// use pgm_read_word rather than read_byte since both will take 1 execution cycle anyways to retrieve from flash.
			// by using word, will halve the amount of memory accesses, giving 2x speedup in drawing.
			pixel = pgm_read_word_near(SpritePtr + z + (sizeX * i)); 
			pixel0 = (uint8_t)(pixel >> 8); //casting to short same as bitmask, higher order bytes binary 11111111 00000000 = decimal 65280			
			pixel1 = (uint8_t)(pixel);  //casting to short same as bitmask, lower order bytes binary 00000000 11111111 = decimal 255	
			if (pixel0 != ALPHA){
				drawBuff[z+1] = pixel0; 
			} else {
				drawBuff[z+1] = BACKGROUND_COLOR_TOP;
			}
			if (pixel1 != ALPHA){
				drawBuff[z] = pixel1;
			} else {
				drawBuff[z] = BACKGROUND_COLOR_TOP;
			}
			z+=2;
		}
		display.writeBuffer(drawBuff, sizeX);
	}
	display.endTransfer();
}

// shows Quotes/ RNG
// if isQuote, will use Quote routine, if not will use 4D routine. passing everything by reference to save stack space.
void showQuote4d(const char * WORD_BANKPTR[], bool isQuote, uint8_t * TICKS_ELAPSED_SINCE_X){
	if(*TICKS_ELAPSED_SINCE_X == TEXT_INTERVAL){
		display.setCursor(1, SCREEN_HEIGHT-18);		
		//display.clearScreen();
		display.clearWindow(0, SCREEN_HEIGHT - (TOP_BOTTOM_BOUNDARY - 1), SCREEN_WIDTH-1, SCREEN_HEIGHT-1);
		if (isQuote){
			RANDNUM = random(0, sizeof(WORD_BANK)/sizeof(WORD_BANK[0]));	
			display.println(WORD_BANK[RANDNUM]);
		} else {
			RANDNUM = random(10000);				
			snprintf(GD_BUFFER, 5, "%04d", RANDNUM);
			display.println(GD_BUFFER);
		}	
	}
	if (*TICKS_ELAPSED_SINCE_X !=0){
		display.setX(0, SCREEN_WIDTH - 1);
		
		if(*TICKS_ELAPSED_SINCE_X == 1){
			//display.clearScreen();
			display.clearWindow(0, SCREEN_HEIGHT - (TOP_BOTTOM_BOUNDARY - 1), SCREEN_WIDTH-1, SCREEN_HEIGHT-1);			
			drawSprite(SPRITE_BUNNY_BASE, SPRITE_BUNNY_XY[0], SPRITE_BUNNY_XY[1], CHARACTERXPOS, CHARACTERYPOS);
		}			
		*TICKS_ELAPSED_SINCE_X-=1;
	} else {
		IS_QUOTE = false;
		IS_RNG = false;
	}

}

// draws the status bars for the rabbit
void drawPeriodStatus(){
	display.drawLine(0, SCREEN_HEIGHT - TOP_BOTTOM_BOUNDARY, SCREEN_WIDTH -1, SCREEN_HEIGHT - TOP_BOTTOM_BOUNDARY, TS_8b_White);
	display.setCursor(5, SCREEN_HEIGHT - 10);
	display.println('H');
	display.setCursor(SCREEN_WIDTH - 40, SCREEN_HEIGHT - 10);
	display.println('S');
	//black out the bars first	
	display.drawRect(15, SCREEN_HEIGHT - 5, PIXELS_STATUS_BAR, 4, true, TS_8b_Black);
	display.drawRect(SCREEN_WIDTH - 30, SCREEN_HEIGHT - 5, PIXELS_STATUS_BAR, 4, true, TS_8b_Black);
	if(PIXELS_FOR_HUNGER){ //check is not zero, otherwise the screen will overflow
		display.drawRect(15, SCREEN_HEIGHT - 5, PIXELS_FOR_HUNGER, 4, true, TS_8b_White);
	}
	if (PIXELS_FOR_SLEEP){ //check is not zero, otherwise the screen will overflow
		display.drawRect(SCREEN_WIDTH - 30, SCREEN_HEIGHT - 5, PIXELS_FOR_SLEEP, 4, true, TS_8b_White);
	}
	
}

/************************************************
 *  ... POLLED BUTTON IO
 ***********************************************/

void buttonLoop() {
  	switch (display.getButtons()){
	  	case TSButtonUpperLeft: //sleep button
			TICKS_ELAPSED_SINCE_SLEEP =  0 ; // reset
			PIXELS_FOR_SLEEP = PIXELS_STATUS_BAR;		  
			IS_SLEEP = true;
	  		break;
	  	case TSButtonLowerLeft: // Quotes
			IS_QUOTE = true;
			TICKS_ELAPSED_SINCE_TEXT = TEXT_INTERVAL;
			break;
		case TSButtonUpperRight: //feed button
			TICKS_ELAPSED_SINCE_FED = 0; // reset feed counter
			drawSprite(SPRITE_CARROT, SPRITE_CARROT_XY[0], SPRITE_CARROT_XY[1], CHARACTERXPOS + 40, CHARACTERYPOS - 1); //carrot
			PIXELS_FOR_HUNGER = PIXELS_STATUS_BAR;
			break;
		case TSButtonLowerRight: //rng button
			IS_RNG = true;
			TICKS_ELAPSED_SINCE_4D = TEXT_INTERVAL;	
			break;
  	}
}