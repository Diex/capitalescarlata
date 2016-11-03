// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PINA            6
#define PINB1           7
#define PINB2           8
#define PINC            9
#define PIND            10

// How many NeoPixels are attached to the Arduino?
#define NPX_A      72
#define NPX_B      64
#define NPX_C      78
#define NPX_D      78

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel ruteA = Adafruit_NeoPixel(NPX_A, PINA, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ruteB1 = Adafruit_NeoPixel(NPX_B, PINB1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ruteB2 = Adafruit_NeoPixel(NPX_B, PINB2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ruteC = Adafruit_NeoPixel(NPX_C, PINC, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel ruteD = Adafruit_NeoPixel(NPX_D, PIND, NEO_GRB + NEO_KHZ800);

Adafruit_NeoPixel * rutes[] = {&ruteA, &ruteB1, &ruteB2, &ruteC, &ruteD};
int delayval = 25; // delay for half a second

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code
 for(int i = 0; i < 5; i++)
   rutes[i]->begin();
 
}

void loop() {
 for(int i = 0; i < 5; i++){

   for(int led = 0; led < NPX_D; led ++){
     rutes[i]->clear();
     rutes[i]->setPixelColor(led, 64,64,64);
     rutes[i]->show();
     delay(delayval);
   }

 }
 
 delay(1000);
  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  for(int i=0;i<0;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
//    pixels.setPixelColor(i, pixels.Color(0,150,0)); // Moderately bright green color.

//    pixels.show(); // This sends the updated pixel color to the hardware.

//    delay(delayval); // Delay for a period of time (in milliseconds).

  }
}
