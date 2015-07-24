#include <stdlib.h> // for rand

#include "definitions.h"
#include "prng.h"

int prng(bool value_or_suit) {
  // Will generate a random card value
  if (value_or_suit == VALUE) {
    // Can be 0 to 12
    return rand() % NUM_OF_CARD_VALUES;
  }
  // Will generate a random suit
  else {
    // Can be 0 to 3
    return rand() % NUM_OF_CARD_SUITS;
  }
}

