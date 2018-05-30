#include "oscillator.h"

oscillator* oscillator_init(wavetable *wt) {
  oscillator *osc = malloc(sizeof(oscillator));
  osc->wt = wt;
  osc->table_step_counter = 0;
  oscillator_set_freq(osc, 261.63); // middle c
  return osc;
}

void oscillator_set_freq(oscillator *osc, float freq) {
  osc->freq = freq;
  float samples_per_sec = (float)SAMPLE_RATE / osc->freq;
  osc->table_step_rate = (float)osc->wt->length / samples_per_sec;
}

uint8_t oscillator_gen_sample(oscillator *osc) {
  osc->table_step_counter += osc->table_step_rate;
  int table_index = (int)osc->table_step_counter % osc->wt->length;
  return osc->wt->data[table_index];
}