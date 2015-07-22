#include <stdio.h>

#include "prints.h"
#include "card_manip.h"
#include "scoring.h"

void print_card(player_t* player) {
  int i;
  printf("%s:\n============\n", player->owner);

  for (i = 0; i < player->total_cards; i++) {
    printf("%s of %s\n", get_string_value(player->cards[i].value), get_string_suit(player->cards[i].suit));
  }

  printf("the Score is: %d\n", getScore(player));

}

void printFinalHands(player_t* player1, player_t* player2) {
  printf("\n\n\n");
  print_card(player1);
  print_card(player2);
  printf("\n\n");
}

