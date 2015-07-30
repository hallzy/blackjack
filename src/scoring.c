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

// Find a combination of the aces that will give the highest possible score
// without going over 21
static int find_valid_ace_combination(int num_aces, int score) {
  int  i;
  bool solution_found = false;

  for (i = 0; i <= num_aces; i++) {
    if ( ((num_aces-i)*HIGH_ACE_SCORE)+(i*LOW_ACE_SCORE)+score <= 21) {
      score += ((num_aces-i)*HIGH_ACE_SCORE)+(i*LOW_ACE_SCORE);
      solution_found = true;
      break;
    }
  }
  if (!solution_found) {
    score += num_aces*LOW_ACE_SCORE;
  }
  return score;
}


int getScore(player_t* player) {
  int i;
  int score     = 0;
  int num_aces  = 0;

  // Check all the players cards
  for (i = 0; i < player->total_cards; i++) {
    if (player->cards[i].value < jack) {
      score += player->cards[i].value + ENUM_OFFSET;
    }
    else if (player->cards[i].value < ace) {
      score += VALUE_OF_FACE_CARDS;
    }
    else {
      num_aces++;
    }
  }
  score = find_valid_ace_combination(num_aces, score);

  return score;
}

