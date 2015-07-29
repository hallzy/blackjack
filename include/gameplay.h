#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "typedefs.h"

void playPlayersTurn();
static bool dealer_needs_more_points();
void playDealersTurn();
bool player_busts();
static bool dealer_busts();
static bool isDraw();
static bool dealerWins();
static bool playerWins();
void determineWinner();

#endif // GAMEPLAY_H

