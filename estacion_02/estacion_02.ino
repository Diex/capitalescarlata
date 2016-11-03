// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library
#include "Perlin.h"

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PINA            6

// How many NeoPixels are attached to the Arduino?
#define NPX_A      32

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel station = Adafruit_NeoPixel(NPX_A, PINA, NEO_GRB + NEO_KHZ800);

int delayval = 25; // delay for half a second
int buffer[NPX_A];
static double i = 0;
double pv;


void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code
  Serial.begin(115200);
  station.begin();

}

void loop() {
  i += 0.005;

  for (int y = 0; y < NPX_A; y++) {
    pv = pnoise((double) y , 0 , i);
    int value = (int) (pv * 1000);
    int id = (int) map(value, -1000, 1000, 0, 255);
    buffer[y] = lut[id];

  }


 for(int i=0; i < station.numPixels(); i++) {
       station.setPixelColor(i, buffer[i],buffer[i],buffer[i]);        //turn every third pixel off

      }
       station.show();      

//  delay(100);
}
