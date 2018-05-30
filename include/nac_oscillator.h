#ifndef NAC_OSCILLATOR_H
#define NAC_OSCILLATOR_H

#include <stdint.h>
#include <stdlib.h>

#define SAMPLE_RATE   44100
#define CHANNELS      1
#define FRAME_SIZE    1024

#define GLOBAL_GAIN   .5

typedef struct nac_wavetable {
  uint8_t *data;
  int32_t length;
} nac_wavetable;

typedef struct nac_oscillator {
  nac_wavetable *wt;
  float freq;
  float table_step_counter;
  float table_step_rate;
} nac_oscillator;

void nac_wavetable_init(nac_wavetable *wt);
void nac_wavetable_clean(nac_wavetable *wt);

void nac_oscillator_init(nac_oscillator *osc);
void nac_oscillator_clean(nac_oscillator *osc);
void nac_oscillator_set_freq(nac_oscillator *osc, float freq);
uint8_t nac_oscillator_gen_sample(nac_oscillator *osc);

#endif /* NAC_OSCILLATOR_H */