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

#include <stdlib.h>
#include <string.h>

#include "card_manip.h"
#include "initialization.h"
#include "definitions.h"
#include "prng.h"


// having null elements will cause a seg fault.
static char* usedCards[] = {
  "xx", "xx", "xx", "xx", "xx", "xx", "xx", "xx", "xx", "xx", "xx",
  "xx", "xx", "xx", "xx", "xx", "xx", "xx", "xx", "xx", "xx", "xx"
};

// Used to populate the usedCards array
static const char* CARD_VALUE[] = {
  "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"
};


// Used to populate the usedCards array
static const char* CARD_SUIT[] = {
  "H", "D", "C", "S"
};


const char* get_string_value(card_value_t value) {
  return CARD_VALUE[value];
}


const char* get_string_for_print_value(card_value_t value) {
  if (value == ten) {
    return "10";
  }
  else {
    return get_string_value(value);
  }
}


const char* get_string_suit(card_suit_t suit) {
  return CARD_SUIT[suit];
}


const char* get_string_for_print_suit(card_suit_t suit) {
  if (suit == hearts) {
    return "Hearts";
  }
  else if (suit == diamonds) {
    return "Diamonds";
  }
  else if (suit == clubs) {
    return "Clubs";
  }
  else {
    return "Spades";
  }
}


static bool is_random_card_string_duplicate() {
  int i;
  for (i = 0; i < 2*MAX_NUM_CARDS_PER_PERSON; i++) {
    if (strcmp(get_drawn_card_string(), usedCards[i]) == 0) {
      return true;
    }
  }
  return false;
}

static void add_drawn_card_to_used_cards_arr() {
  int i;
  for (i = 0; i < 2*MAX_NUM_CARDS_PER_PERSON; i++) {
    if (strcmp(usedCards[i], "x") == 0) {
      usedCards[i] = get_drawn_card_string();
      return;
    }
  }
}

static void generate_random_card_string(card_value_t value, card_suit_t suit) {
  char* drawn_card_string = get_drawn_card_string();

  strcpy(drawn_card_string, (char*)get_string_value(value));
  strcat(drawn_card_string, (char*)get_string_suit(suit));
}

static void give_card_to_player(player_t* player, card_value_t value, card_suit_t suit) {
  player->cards[player->total_cards].value = value;
  player->cards[player->total_cards].suit = suit;
  player->total_cards++;
}

void deal_card(player_t* player) {
  card_value_t value;
  card_suit_t suit;

  do {
    value = card_value_prng();
    suit = card_suit_prng();
    generate_random_card_string(value, suit);
  } while (is_random_card_string_duplicate());

  add_drawn_card_to_used_cards_arr();

  give_card_to_player(player, value, suit);
}

