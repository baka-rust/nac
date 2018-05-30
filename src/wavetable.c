#include "wavetable.h"

wavetable* wavetable_init(int32_t length) {
  wavetable *wt = malloc(sizeof(wavetable));
  wt->length = length;
  wt->data = malloc(sizeof(uint8_t) * wt->length);
  return wt;
}

void wavetable_fill_square(wavetable *wt) {
  for (int i = 0; i < wt->length/2; i++) {
    wt->data[i] = 0xFF;
  }
  for (int j = wt->length/2; j < wt->length; j++) {
    wt->data[j] = 0x00;
  }
}