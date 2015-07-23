/*
 *
 *  Author: Steven Hall
 *
 */

#include <stdlib.h>
#include <time.h>

#include "typedefs.h"
#include "gameplay.h"
#include "card_manip.h"



int main(void) {
  player_t* dealer = malloc(sizeof(player_t));
  player_t* player = malloc(sizeof(player_t));

  srand(time(NULL));

  // Initialize
  // Give dealer their 2 cards
  create(dealer, "Dealer");
  // Give player their 2 cards
  create(player, "Player");

  // Allow the player to hit or stand as he chooses
  playPlayersTurn(player);
  // Now it is the dealers turn
  playDealersTurn(dealer);

  determineWinner(player, dealer);

  free(player);
  free(dealer);
  return 0;
}
