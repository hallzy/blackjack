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

#ifndef CARD_MANIP_H
#define CARD_MANIP_H

#include "typedefs.h"


const char* get_string_value(card_value_t);
const char* get_string_suit(card_suit_t);
const char* get_string_for_print_value(card_value_t);
const char* get_string_for_print_suit(card_suit_t);
void deal_card(player_t*);

#ifdef TESTING
bool is_deal_card_duplicate_test(card_value_t, card_suit_t);
#endif //TESTING

#endif // CARD_MANIP_H
