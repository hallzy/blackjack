#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "typedefs.h"

void playPlayersTurn(player_t*);
void playDealersTurn(player_t*);
bool player_busts(player_t* player);
bool dealer_busts(player_t* dealer);
bool isDraw(player_t* player, player_t* dealer);
bool dealerWins(player_t* player, player_t* dealer);
bool playerWins(player_t* player, player_t* dealer);
void determineWinnerBetween(player_t*, player_t*);

#endif // GAMEPLAY_H

