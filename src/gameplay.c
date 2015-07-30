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

#include <stdio.h>

#include "card_manip.h"
#include "gameplay.h"
#include "prints.h"
#include "scoring.h"
#include "initialization.h"

static bool dealer_needs_more_points() {
  return getScore(getDealer()) < 17;
}

bool player_busts() {
  return getScore(getPlayer()) > 21;
}

static bool dealer_busts() {
  return getScore(getDealer()) > 21;
}

static bool isDraw() {
  return getScore(getDealer()) == getScore(getPlayer());
}

static bool dealerWins() {
  return getScore(getDealer()) > getScore(getPlayer());
}

static bool playerWins() {
  return getScore(getDealer()) < getScore(getPlayer());
}

void playPlayersTurn() {
  player_t*   player = getPlayer();
  char        choice;

  show_hand(player);
  do {
    printf("\n(h)it or (s)tay? ");

    // Note the space before %c, which consumes the newline character after
    // hitting enter
    scanf(" %c", &choice);
    printf("\n");

    if (choice == 'h' || choice == 'H') {
      deal_card(player);
      show_hand(player);

      if (player_busts()) {
        return;
      }
    }
  } while (choice == 'h' || choice == 'H');
}


void playDealersTurn() {
  while (dealer_needs_more_points()) {
    deal_card(getDealer());
  }
}


void determineWinner() {
  player_t* player = getPlayer();
  player_t* dealer = getDealer();

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
