#include <stdio.h>

#include "card_manip.h"
#include "gameplay.h"
#include "prints.h"
#include "scoring.h"

void playPlayersTurn(player_t* player) {
  char choice;
  // Show the players card
  print_card(player);
  do {
    printf("\n(h)it or (s)tay? ");
    // Note the space before %c, which consumes the newline character after
    // hitting enter
    scanf(" %c", &choice);
    printf("\n");

    // If player hits, give them a new card and show the players current hand.
    if (choice == 'h' || choice == 'H') {
      set_cards(player);
      print_card(player);

      // After a hit, if the player has more than 21 then exit because they
      // lost.
      if (getScore(player) > 21) {
        return;
      }
    }
    // if they hit, loop and do it again to see of they want to hit or stay
    // again.
  } while (choice == 'h' || choice == 'H');
}


void playDealersTurn(player_t* dealer) {
  // Hit for the dealer and get score and compare with player - dealer hits when
  // hand is < 17
  while (getScore(dealer) < 17) {
    set_cards(dealer);
  }

}

void determineWinner(player_t* player, player_t* dealer) {
  // Print the final hands and figure out who won.
  printFinalHands(player, dealer);
  if (getScore(player) > 21) {
    printf("You Bust!\nDealer Wins!\n");
  }
  else if (getScore(dealer) > 21) {
    printf("The dealer bust, so you win!\n");
  }
  else if (getScore(dealer) == getScore(player)) {
    printf("Its a draw.\n");
  }
  else if (getScore(dealer) > getScore(player)) {
    printf("You Lost, %d to %d\n", getScore(player), getScore(dealer));
  }
  else {
    printf("You Won, %d to %d\n", getScore(player), getScore(dealer));
  }
}
