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

#include "scoring.h"

#define VALUE_OF_FACE_CARDS 10
// Find a combination of the aces that will give the highest possible score
// without going over 21
// Start with all aces being 11 points added onto the current score. If it is
// over 21 then make of the aces a 1, etc until a solution is found.
// If it turns out that even with all the aces being a 1 that it goes over 21,
// solution_found is false and the player busts
static int find_valid_ace_combination(int num_aces, int score) {
  int i;
  bool solution_found = false;
  for (i = 0; i <= num_aces; i++) {
    if ( ((num_aces-i)*11)+i+score <= 21) {
      score += ((num_aces-i)*11)+i;
      solution_found = true;
      break;
    }
  }
  // If a solution to the above cannot be found, give the aces all values of 1,
  // and the player has busted.
  if (!solution_found) {
    score += num_aces;
  }
  return score;
}

int getScore(player_t* player) {
  int score = 0;
  int i;
  int num_aces = 0;

  // Check all the players cards
  for (i = 0; i < player->total_cards; i++) {
    // if the card is less than a jack, add 2 to the value of the card to
    // compensate for the enum
    // ex. 2 has a value from the enum as 0, so add 2 to get a score of 2
    if (player->cards[i].value < jack) {
      score += player->cards[i].value + 2;
    }
    // Jack, queen king are each worth 10
    else if (player->cards[i].value < ace) {
      score += VALUE_OF_FACE_CARDS;
    }
    // it is an ace
    // Cont the number of aces so that we can add them properly.
    // aces are more tricky because they can be 2 different values
    else {
      num_aces++;
    }
  }

  score = find_valid_ace_combination(num_aces, score);

  return score;
}

