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

#include <stdlib.h>

#include "initialization.h"
#include "card_manip.h"

player_t* getDealer() {
  static bool       isDealerInitialized = false;
  static player_t*  dealer;

  if (!isDealerInitialized) {
    dealer = malloc(sizeof(player_t));
    isDealerInitialized = true;
  }
  return dealer;
}


player_t* getPlayer() {
  static bool        isPlayerInitialized = false;
  static player_t*   player;

  if (!isPlayerInitialized) {
    player = malloc(sizeof(player_t));
    isPlayerInitialized = true;
  }
  return player;
}


char* get_drawn_card_string() {
  static bool    is_card_initialized = false;
  static char*   drawn_card_string;

  if (!is_card_initialized) {
    drawn_card_string = (char*)malloc(3*sizeof(char));
    is_card_initialized = true;
  }
  return drawn_card_string;
}


void initialize_helper(player_t* player_arg, char* name) {
  player_arg->total_cards   = 0;
  player_arg->owner         = name;

  // Initialize Cards
  deal_card(player_arg);
  deal_card(player_arg);
}


void initialize_player() {
  initialize_helper(getPlayer(), "Player");
}


void initialize_dealer() {
  initialize_helper(getDealer(), "Dealer");
}


void freeAll() {
#ifndef TESTING
  player_t* dealer = getDealer();
  free(dealer);
  dealer = NULL;

  player_t* player = getPlayer();
  free(player);
  player = NULL;
#endif // TESTING

  char* drawn_card_string = get_drawn_card_string();
  free(drawn_card_string);
  drawn_card_string = NULL;
}
