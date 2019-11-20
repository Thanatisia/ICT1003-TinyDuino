#include <TinyScreen.h>
#include <SPI.h>

#define MAX_HUNGER 10

uint8_t hunger = MAX_HUNGER;

// Last time status was updated
unsigned long previousMillis = 0;

// Number of milliseconds in an interval of 10 minutes to update
const unsigned long interval = 600000;

/*
 * Updates status
 * Decrements hunger if interval has passed
 * Variables previousMillis and hunger passed in by reference
 */
void updateStatus(unsigned long *previousMillis, uint8_t *hunger, const unsigned long interval);


void setup()
{

}

void loop()
{
  updateStatus(&previousMillis, &hunger, interval);
}


void updateStatus(unsigned long *previousMillis, uint8_t *hunger, const unsigned long interval)
{
  unsigned long currentMillis = millis();
  if (currentMillis - *previousMillis >= interval)
  {
    *previousMillis = currentMillis;
    *hunger = max(0, *hunger - 1);
  }
}
