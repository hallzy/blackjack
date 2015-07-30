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

#include <stdio.h>

#include "card_manip.h"
#include "initialization.h"
#include "prints.h"
#include "scoring.h"

void show_hand(player_t* player) {
  int i;
  printf("%s:\n============\n", player->owner);

  for (i = 0; i < player->total_cards; i++) {
    printf("%s of %s\n", get_string_for_print_value(player->cards[i].value),
                         get_string_for_print_suit(player->cards[i].suit));
  }
  printf("the Score is: %d\n", getScore(player));
}

void printFinalHands() {
  printf("\n\n\n");
  show_hand(getPlayer());
  show_hand(getDealer());
  printf("\n\n");
}

