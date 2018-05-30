#ifndef OSCILLATOR_H
#define OSCILLATOR_H

#include "constants.h"
#include "wavetable.h"

#include <stdint.h>
#include <stdlib.h>

typedef struct oscillator {
  wavetable *wt;
  float freq;
  float table_step_counter;
  float table_step_rate;
} oscillator;

oscillator* oscillator_init(wavetable *wt);
void oscillator_set_freq(oscillator *osc, float freq);
uint8_t oscillator_gen_sample(oscillator *osc);

#endif /* OSCILLATOR_H */