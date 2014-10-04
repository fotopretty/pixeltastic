#include "Arduino.h"
#include <Adafruit_NeoPixel.h>

#ifndef SEGMENT_MODELS
#define SEGMENT_MODELS

extern Adafruit_NeoPixel led_strip; /* FIXME temporary global */

// Spot class: Everything is derived from this static spot

class Spot {
 public:

  // Variables
  double   _position;
  double   speed;
  double   amplitude;
  double   offset;
  uint8_t  _width;
  uint32_t color;

  double   start_position;
  uint8_t  start_width;
  uint32_t start_color;

  uint32_t tick_start;

  // Constructor
  Spot (double, uint8_t, uint32_t);

  // Methods
  virtual void update ();
  double percent ();

  // Setters
  double   position (double  );
  double   position ();

  uint8_t  width (uint8_t );
  uint8_t  width ();

  //uint32_t color    (uint32_t);

};



// Circler draws itself in a loop along your strip or around the circle

class Circler : public Spot {
 public:

  // Constructor
  Circler (double, uint8_t, uint32_t);

  // Methods
  void update ();
};



// Wobbler uses a sin wave to move back and forth

class Wobbler : public Spot {
 public:

  // Constructor
  Wobbler (double, uint8_t, uint32_t);

  // Methods
  void update ();
};



// Pulsar uses a sin wave to fade in and out

class Pulsar : public Spot {
 public:

  // Constructor
  Pulsar (double, uint8_t, uint32_t);

  // Methods
  void update ();
};



// Grower uses a sin wave to grow and shrink width

class Grower : public Spot {
 public:

  // Constructor
  Grower (double, uint8_t, uint32_t);

  // Methods
  void update ();
};


// Colortron grabs random colors each cycle and has fluid width

class Colortron : public Spot {
 public:

  // Constructor
  Colortron (uint8_t, uint32_t);

  // Methods
  void update ();
};



// Warper picks random locations each cycle

class Warper : public Spot {
 public:

  // Constructor
  Warper ();

  // Methods
  void update ();
};

#endif
