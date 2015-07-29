#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "typedefs.h"

void playPlayersTurn();
void playDealersTurn();
bool player_busts();
bool dealer_busts();
bool isDraw();
bool dealerWins();
bool playerWins();
void determineWinner();

#endif // GAMEPLAY_H

