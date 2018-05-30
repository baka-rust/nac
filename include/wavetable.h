#ifndef WAVETABLE_H
#define WAVETABLE_H

#include <stdint.h>
#include <stdlib.h>

typedef struct wavetable {
  uint8_t *data;
  int32_t length;
} wavetable;

wavetable* wavetable_init(int32_t length);
void wavetable_fill_square(wavetable *wt);

#endif /* WAVETABLE_H */