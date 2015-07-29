#include <stdlib.h>

#include "initialization.h"
#include "card_manip.h"

player_t* getDealer() {
  static bool isDealerInitialized = false;
  static player_t* dealer;

  if (!isDealerInitialized) {
    dealer = malloc(sizeof(player_t));
    isDealerInitialized = true;
  }

  return dealer;
}

player_t* getPlayer() {
  static bool isPlayerInitialized = false;
  static player_t* player;

  if (!isPlayerInitialized) {
    player = malloc(sizeof(player_t));
    isPlayerInitialized = true;
  }

  return player;
}

void initialize_helper(player_t* player_arg, char* name) {
  /* player_arg = malloc(sizeof(player_t)); */
  player_arg->total_cards = 0;
  player_arg->owner = name;

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
  player_t* dealer = getDealer();
  player_t* player = getPlayer();

  free(dealer);
  free(player);
  dealer = NULL;
  player = NULL;
}
