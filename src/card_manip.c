#include <stdlib.h>
#include <string.h>

#include "card_manip.h"
#include "definitions.h"
#include "prng.h"


// to prevent memory leaks, each card value and suit is saved as a 1 character
// string so that it will fully fill the usedCards array. To print this
// information to the user we need another function for printing

// This array will get populated with the cards that get drawn
// Initialized to all x's so that they are not null.
// The first thing that is done with this array is that it is compared, so
// having null elements will cause a seg fault.
static char* usedCards[2*MAX_NUM_CARDS] = {
  "xx", "xx", "xx", "xx", "xx", "xx", "xx", "xx", "xx", "xx", "xx",
  "xx", "xx", "xx", "xx", "xx", "xx", "xx", "xx", "xx", "xx", "xx"
};

// The corresponding string to display for each of the above values
// This is used in conjunction with the values enum to easily print card values
// to the user.
static const char* CARD_VALUE[] = {
  "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K", "A"
};


// The corresponding string to display for each of the above suits
// This is used in conjunction with the suits enum to easily print card suits
// to the user.
static const char* CARD_SUIT[] = {
  "H", "D", "C", "S"
};


// Function Definitions:

// Returns the string of the card value for display purposes
const char* get_string_value(card_value_t value) {
  return CARD_VALUE[value];
}

// This is used to display to the user. The only string character that is not as
// it should be displayed is the 10, so check for it, otherwise print the string
// that already exists.
const char* get_string_for_print_value(card_value_t value) {
  if (strcmp(get_string_value(value), "T") == 0) {
    return "10";
  }
  else {
    return get_string_value(value);
  }
}

// Returns the string of the card suit for display purposes
const char* get_string_suit(card_suit_t suit) {
  return CARD_SUIT[suit];
}


// This is used to display to the user. The only string character that is not as
// it should be displayed is the 10, so check for it, otherwise print the string
// that already exists.
const char* get_string_for_print_suit(card_suit_t suit) {
  if (strcmp(get_string_suit(suit), "H") == 0) {
    return "Hearts";
  }
  else if (strcmp(get_string_suit(suit), "D") == 0) {
    return "Diamonds";
  }
  else if (strcmp(get_string_suit(suit), "C") == 0) {
    return "Clubs";
  }
  else {
    return "Spades";
  }
}

// This is equivalent to giving the player a card.
// It also checks that the card that has been randomly generated has not been
// given out yet, and if it has, it generates a new card.
void set_cards(player_t* player) {
  card_value_t value;
  card_suit_t suit;
  // This will be used to hold the string of the card name in order to check if
  // it has already been used.
  char* concat;
  int i;
  // If the generated card has already been used this will be set to true
  bool isDuplicate;

  do {
    isDuplicate = false;
    value = card_value_prng();
    suit = card_suit_prng();
    concat = (char*)malloc(strlen(get_string_value(value))+strlen(get_string_suit(suit))+2);

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
  free(concat);
}

