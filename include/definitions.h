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

#ifndef DEFINITIONS_H
#define DEFINITIONS_H

// No one in blackjack can exceed 11 cards because it is impossible to stay
// below 21 with more than 11 cards
#define MAX_NUM_CARDS_PER_PERSON 11

// These are used for prng to see if it should be generating a random number for
// a card value or suit
#define VALUE true
#define SUIT false

#define NUM_OF_CARD_VALUES 13
#define NUM_OF_CARD_SUITS 4

#endif // DEFINITIONS_H
