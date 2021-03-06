#include "constants.h"
#include "wavetable.h"
#include "oscillator.h"

#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

oscillator *osc;

void fill_audio(void* userdata, uint8_t* stream, int len) {
  if (len == 0) {
    return;
  }

  for (int i = 0; i < len; i++) {
    stream[i] = oscillator_gen_sample(osc) * GLOBAL_GAIN;
  }
}

int main(int argc, char *argv[]) {
  SDL_AudioSpec wanted;

  wanted.freq = SAMPLE_RATE;
  wanted.format = AUDIO_U8;
  wanted.channels = CHANNELS;
  wanted.samples = FRAME_SIZE;
  wanted.callback = fill_audio;
  wanted.userdata = NULL;

  if (SDL_OpenAudio(&wanted, NULL) < 0) {
    printf("Couldn't open audio: %s\n", SDL_GetError());
    return -1;
  }

  wavetable *wt = wavetable_init(128);
  wavetable_fill_square(wt);

  osc = oscillator_init(wt);

  SDL_PauseAudio(false);
  SDL_Delay(500);
  SDL_PauseAudio(true);

  return 0;

}