#include "nac_oscillator.h"

void nac_wavetable_init(nac_wavetable *wt) {
  wt->length = 128;

  // for now, just a square wave
  wt->data = malloc(sizeof(uint8_t) * wt->length);
  for (int i = 0; i < wt->length/2; i++) {
    wt->data[i] = 0xFF;
  }
  for (int j = wt->length/2; j < wt->length; j++) {
    wt->data[j] = 0x00;
  }
}

void nac_wavetable_clean(nac_wavetable *wt) {
  free(wt->data);
}

void nac_oscillator_init(nac_oscillator *osc) {
  osc->wt = malloc(sizeof(nac_wavetable));
  nac_wavetable_init(osc->wt);
  osc->table_step_counter = 0;
  nac_oscillator_set_freq(osc, 261.63); // middle c
}

void nac_oscillator_clean(nac_oscillator *osc) {
  nac_wavetable_clean(osc->wt);
}

void nac_oscillator_set_freq(nac_oscillator *osc, float freq) {
  osc->freq = freq;
  float samples_per_sec = (float)SAMPLE_RATE / osc->freq;
  osc->table_step_rate = (float)osc->wt->length / samples_per_sec;
}

uint8_t nac_oscillator_gen_sample(nac_oscillator *osc) {
  osc->table_step_counter += osc->table_step_rate;
  int table_index = (int)osc->table_step_counter % osc->wt->length;
  return osc->wt->data[table_index];
}