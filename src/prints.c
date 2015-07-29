#include <stdio.h>

#include "card_manip.h"
#include "initialization.h"
#include "prints.h"
#include "scoring.h"

// Prints the players hand
void show_hand(player_t* player) {
  int i;
  printf("%s:\n============\n", player->owner);

  for (i = 0; i < player->total_cards; i++) {
    printf("%s of %s\n", get_string_for_print_value(player->cards[i].value), get_string_for_print_suit(player->cards[i].suit));
  }

  printf("the Score is: %d\n", getScore(player));

}

// Reveals everyones final hand.
void printFinalHands() {
  printf("\n\n\n");
  show_hand(getPlayer());
  show_hand(getDealer());
  printf("\n\n");
}

