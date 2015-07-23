/*
 *
 *  Author: Steven Hall
 *
 */

#include <stdlib.h>
#include <time.h>

#include "typedefs.h"
#include "prints.h"
#include "gameplay.h"
#include "card_manip.h"



int main(void) {
  player_t* dealer = malloc(sizeof(player_t));
  player_t* player = malloc(sizeof(player_t));

  srand(time(NULL));

  // Initialize
  create(dealer);
  dealer->owner = "Dealer";

  create(player);
  player->owner = "Player";

  print_card(player);

  playPlayersTurn(player);

  playDealersTurn(dealer);

  determineWinner(player, dealer);

  free(player);
  free(dealer);
  return 0;
}
