#ifndef CARD_MANIP_H
#define CARD_MANIP_H

#include "typedefs.h"


void set_cards(player_t*);
const char* get_string_value(card_value_t);
const char* get_string_suit(card_suit_t);
const char* get_string_for_print_value(card_value_t);
const char* get_string_for_print_suit(card_suit_t);
void initialize_player(player_t*);
void initialize_dealer(player_t*);

#endif // CARD_MANIP_H
