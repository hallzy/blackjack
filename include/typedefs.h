#ifndef TYPEDEFS_H
#define TYPEDEFS_H

#include "definitions.h"

// definition of bool type
typedef enum bool {false, true} bool;

// The values that can be held by each card
typedef enum card_value {
  two,
  three,
  four,
  five,
  six,
  seven,
  eight,
  nine,
  ten,
  jack,
  queen,
  king,
  ace
} card_value_t;


// The suits that are available
typedef enum card_suit {
  hearts,
  diamonds,
  clubs,
  spades
} card_suit_t;


// Each card has a value and suit
typedef struct card_s {
  card_value_t value;
  card_suit_t suit;
} card_t;

// Each player has an identity, and a certain amount of cards
typedef struct player {
  char* owner;
  unsigned int total_cards;
  card_t cards[MAX_NUM_CARDS];
} player_t;

#endif // TYPEDEFS_H
