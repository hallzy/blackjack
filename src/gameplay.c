#include <stdio.h>

#include "card_manip.h"
#include "gameplay.h"
#include "prints.h"
#include "scoring.h"
#include "initialization.h"

void playPlayersTurn() {
  player_t* player = getPlayer();
  char choice;
  // Show the players card
  show_hand(player);
  do {
    printf("\n(h)it or (s)tay? ");
    // Note the space before %c, which consumes the newline character after
    // hitting enter
    scanf(" %c", &choice);
    printf("\n");

    // If player hits, give them a new card and show the players current hand.
    if (choice == 'h' || choice == 'H') {
      set_cards(player);
      show_hand(player);

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


void playDealersTurn() {
  // Hit for the dealer and get score and compare with player - dealer hits when
  // hand is < 17
  while (getScore(getDealer()) < 17) {
    set_cards(getDealer());
  }

}

bool player_busts() {
  return getScore(getPlayer()) > 21;
}

bool dealer_busts() {
  return player_busts(getDealer());
}

bool isDraw() {
  return getScore(getDealer()) == getScore(getPlayer());
}

bool dealerWins() {
  return getScore(getDealer()) > getScore(getPlayer());
}

bool playerWins() {
  return getScore(getDealer()) < getScore(getPlayer());
}

void determineWinner() {
  player_t* player = getPlayer();
  player_t* dealer = getDealer();
  // Print the final hands and figure out who won.
  printFinalHands();
  if (player_busts()) {
    printf("You Bust!\nDealer Wins!\n");
  }
  else if (dealer_busts()) {
    printf("The dealer bust, so you win!\n");
  }
  else if (isDraw()) {
    printf("Its a draw.\n");
  }
  else if (dealerWins()) {
    printf("You Lost, %d to %d\n", getScore(player), getScore(dealer));
  }
  else if (playerWins()) {
    printf("You Won, %d to %d\n", getScore(player), getScore(dealer));
  }
  else {
    printf("Error. We should never get here\n");
  }
}
