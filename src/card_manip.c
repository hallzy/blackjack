#include <stdlib.h>
#include <string.h>

#include "card_manip.h"
#include "prng.h"
#include "definitions.h"


// This array will get populated with the cards that get drawn
// Initialized to all x's so that they are not null.
// The first thing that is done with this array is that it is compared, so
// having null elements will cause a seg fault.
static char* usedCards[2*MAX_NUM_CARDS] = {
  "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x",
  "x", "x", "x", "x", "x", "x", "x", "x", "x", "x", "x"
};

// The corresponding string to display for each of the above values
// This is used in conjunction with the values enum to easily print card values
// to the user.
static const char* CARD_VALUE[] = {
  "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"
};


// The corresponding string to display for each of the above suits
// This is used in conjunction with the suits enum to easily print card suits
// to the user.
static const char* CARD_SUIT[] = {
  "Hearts", "Diamonds", "Clubs", "Spades"
};


// Function Definitions:

// Returns the string of the card value for display purposes
const char* get_string_value(card_value_t value) {
  return CARD_VALUE[value];
}

// Returns the string of the card suit for display purposes
const char* get_string_suit(card_suit_t suit) {
  return CARD_SUIT[suit];
}



// This is equivalent to giving the player a card.
// It also checks that the card that has been randomly generated has not been
// given out yet, and if it has, it generates a new card.
void set_cards(player_t* player) {
  card_value_t value;
  card_suit_t suit;
  // This will be used to hold the string of the card name in order to check if
  // it has already been used.
  char* concat = (char *)malloc(11);
  int i;
  // If the generated card has already been used this will be set to true
  bool isDuplicate;

  do {
    isDuplicate = false;
    value = prng(VALUE);
    suit = prng(SUIT);

    // Get the string to search for
    strcpy(concat, (char*)get_string_value(value));
    strcat(concat, " ");
    strcat(concat, (char*)get_string_suit(suit));

    for (i = 0; i < 2*MAX_NUM_CARDS; i++) {
      // if the current index has not been filled
      // fill it with concat
      // "x" is the default value for every element of this array
      if (strcmp(usedCards[i], "x") == 0) {
        // add concat to used cards
        usedCards[i] = concat;
        break;
      }
      // if the new card is the same as a card that is already drawn
      // Set a flag and break out of the for loop
      if (strcmp(concat, usedCards[i]) == 0) {
          isDuplicate = true;
          break;
      }
    }
    // Do not leave this loop until we find a unique card
  } while (isDuplicate);

  if (player->total_cards < MAX_NUM_CARDS) {
    player->cards[player->total_cards].value = value;
    player->cards[player->total_cards].suit = suit;
    player->total_cards++;
  }
}

void create(player_t* player, char* name) {
  player->total_cards = 0;
  player->owner = name;

  // Initialize Cards
  set_cards(player);
  set_cards(player);
}

