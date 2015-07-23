#include <stdlib.h> // for rand

#include "prng.h"
#include "definitions.h"

int prng(bool value_or_suit) {
  if (value_or_suit == VALUE) {
    // Can be 0 to 12
    return rand() % NUM_OF_CARD_VALUES;
  }
  else {
    // Can be 0 to 3
    return rand() % NUM_OF_CARD_SUITS;
  }
}

