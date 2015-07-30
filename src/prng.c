/*
* =============================================================================
*
*   This Source Code Form is subject to the terms of the Mozilla Public
*   License, v. 2.0. If a copy of the MPL was not distributed with this file,
*   You can obtain one at http://mozilla.org/MPL/2.0/.
*
*   Copyright (c) 2015, MPL Steven Hall Hallzy.18@gmail.com
*
* =============================================================================
*/

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

