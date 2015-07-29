/*
 *
 *  Author: Steven Hall
 *
 */

#include <stdlib.h>
#include <time.h>

#include "initialization.h"
#include "gameplay.h"
#include "scoring.h"
#include "typedefs.h"



int main(void) {
  srand(time(NULL));

  // Initialize
  // Give dealer their 2 cards
  initialize_dealer();
  // Give player their 2 cards
  initialize_player();

  // Allow the player to hit or stand as he chooses
  playPlayersTurn();

  // Dealer only plays if player has not bust.
  if (!player_busts()) {
    // Now it is the dealers turn
    playDealersTurn();
  }

  determineWinner();

  freeAll();
  return 0;
}
