#ifndef INITIALIZATION_H
#define INITIALIZATION_H

#include "typedefs.h"

player_t* getDealer();
player_t* getPlayer();
void initialize_helper(player_t*, char*);
void initialize_player();
void initialize_dealer();
void freeAll();

#endif //INITIALIZATION_H
