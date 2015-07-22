#ifndef GAMEPLAY_H
#define GAMEPLAY_H

#include "typedefs.h"

void playPlayersTurn(player_t*);

void playDealersTurn(player_t*);

void determineWinner(player_t*, player_t*);

#endif // GAMEPLAY_H
