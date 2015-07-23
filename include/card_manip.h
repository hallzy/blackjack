#ifndef CARD_MANIP_H
#define CARD_MANIP_H

#include "typedefs.h"


void set_cards(player_t*);
const char* get_string_value(card_value_t);
const char* get_string_suit(card_suit_t);
void create(player_t*, char*);

#endif // CARD_MANIP_H
