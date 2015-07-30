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
