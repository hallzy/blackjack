#include <stdlib.h> // for rand

#include "definitions.h"
#include "prng.h"

int card_value_prng() {
  // Will generate a random card value
  // Can be 0 to 12
  return rand() % NUM_OF_CARD_VALUES;
}

int card_suit_prng() {
  // Will generate a random suit
  // Can be 0 to 3
  return rand() % NUM_OF_CARD_SUITS;
}

