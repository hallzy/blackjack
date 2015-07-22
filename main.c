#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_CARDS 11
#define VALUE true
#define SUIT false

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

// The corresponding string to display for each of the above values
const char* CARD_VALUE[] = {
  "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"
};


// The suits that are available
typedef enum card_suit {
  hearts,
  diamonds,
  clubs,
  spades
} card_suit_t;

// The corresponding string to display for each of the above suits
const char* CARD_SUIT[] = {
  "Hearts", "Diamonds", "Clubs", "Spades"
};

// Returns the string of the card value for display purposes
const char* print_value(card_value_t value) {
  return CARD_VALUE[value];
}

// Returns the string of the card suit for display purposes
const char* print_suit(card_suit_t suit) {
  return CARD_SUIT[suit];
}

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
  unsigned int score;
} player_t;

// definition of bool type
typedef enum bool {false, true} bool;

// Set the value and suit of the card for the specified player
// Make sure the player does not have more than 11 cards
//
// @return: true if total cards is <= 11
// @return: false if total cards is > 11
bool set_cards(player_t* player, card_value_t value, card_suit_t suit) {
  if (player->total_cards < MAX_NUM_CARDS) {
    player->cards[player->total_cards].value = value;
    player->cards[player->total_cards].suit = suit;
    player->total_cards++;
    return true;
  }
  return false;
}

int getScore(player_t* player) {
  int score = 0;
  int i;
  for (i = 0; i < player->total_cards; i++) {
    // if the card is less than a jack, add 2 to the value of the card to
    // compensate for the enum
    if (player->cards[i].value < jack) {
      score += player->cards[i].value + 2;
    }
    // Jack, queen king are each worth 10
    else if (player->cards[i].value < ace) {
      score += 10;
    }
    // it is an ace
    else {
      if (score + 11 > 21) {
        score += 1;
      }
      else {
        score += 11;
      }
    }
  }
  return score;
}


void print_card(player_t* player) {
  int i;
  printf("%s:\n============\n", player->owner);

  for (i = 0; i < player->total_cards; i++) {
    printf("%s of %s\n", print_value(player->cards[i].value), print_suit(player->cards[i].suit));
  }

  printf("the Score is: %d\n", getScore(player));

}

int prng(bool value_or_suit) {
  if (value_or_suit == VALUE) {
    // Can be 0 to 12
    return rand() % 13;
  }
  else {
    // Can be 0 to 3
    return rand() % 4;
  }
}

void create(player_t* player) {
  player->total_cards = 0;

  // Initialize Cards
  // TODO: check that a card is not assigned more than once.
  set_cards(player, prng(VALUE), prng(SUIT));
  set_cards(player, prng(VALUE), prng(SUIT));
}

int main(void) {
  char choice;
  player_t* dealer = malloc(sizeof(player_t));
  player_t* player = malloc(sizeof(player_t));

  srand(time(NULL));

  create(dealer);
  dealer->owner = "Dealer";

  create(player);
  player->owner = "Player";
  print_card(player);
  do {
    printf("\n(h)it or (s)tay? ");
    // Note the space before %c, which consumes the newline character after
    // hitting enter
    scanf(" %c", &choice);
    printf("\n");

    if (choice == 'h' || choice == 'H') {
      set_cards(player, prng(VALUE), prng(SUIT));
      print_card(player);
    }
  } while (choice == 'h' || choice == 'H');

  if (getScore(player) > 21) {
    printf("You Bust!\nDealer Wins!\n");
    return 0;
  }

  // TODO
  // Hit for the dealer and get score and compare with player - dealer hits when
  // hand is < 17

  /* print_card(dealer); */

  return 0;
}
