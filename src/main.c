/*
 *
 *  Author: Steven Hall
 *
 */

#include <stdlib.h>
#include <time.h>

#include "card_manip.h"
#include "gameplay.h"
#include "scoring.h"
#include "typedefs.h"



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

  // Dealer only plays if player has not bust.
  if (getScore(player) <= 21) {
    // Now it is the dealers turn
    playDealersTurn(dealer);
  }

  determineWinner(player, dealer);

  free(player);
  free(dealer);
  return 0;
}
