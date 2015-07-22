/*
 *
 *  Author: Steven Hall
 *
 */

// Does not yet cover the case where you get an ace early, then get high cards
// and decide to change the value of the ace to 1 instead of 11. The value that
// the Ace is assigned when it is drawn is the value it will carry until the end
// for now.

// TODO: check that a card is not assigned more than once.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM_CARDS 11
#define VALUE true
#define SUIT false

// This array will get populated with the cards that get drawn
char* usedCards[2*MAX_NUM_CARDS] = {};

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
} player_t;

// definition of bool type
typedef enum bool {false, true} bool;

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

// Set the value and suit of the card for the specified player
// Make sure the player does not have more than 11 cards
void set_cards(player_t* player) {
  card_value_t value = prng(VALUE);
  card_suit_t suit = prng(SUIT);

  if (player->total_cards < MAX_NUM_CARDS) {
    player->cards[player->total_cards].value = value;
    player->cards[player->total_cards].suit = suit;
    player->total_cards++;
  }
}

int getScore(player_t* player) {
  int score = 0;
  int i;
  int num_aces = 0;
  bool solution_found = false;

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
      num_aces++;
    }
  }

  // Find a combination of the aces that will give the highest possible score
  // without going over 21
  for (i = 0; i <= num_aces; i++) {
    if ( ((num_aces-i)*11)+i+score <= 21) {
      score += ((num_aces-i)*11)+i;
      solution_found = true;
    }
  }

  // If a solution to the above cannot be found, give the aces all values of 1,
  // and the player has busted.
  if (!solution_found) {
    score += num_aces;
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


void create(player_t* player) {
  player->total_cards = 0;

  // Initialize Cards
  set_cards(player);
  set_cards(player);
}

void printFinalHands(player_t* player1, player_t* player2) {
  printf("\n\n\n");
  print_card(player1);
  print_card(player2);
  printf("\n\n");
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
      set_cards(player);
      print_card(player);

      if (getScore(player) > 21) {
        printFinalHands(player, dealer);
        printf("You Bust!\nDealer Wins!\n");
        return 0;
      }
    }
  } while (choice == 'h' || choice == 'H');

  // Hit for the dealer and get score and compare with player - dealer hits when
  // hand is < 17
  while (getScore(dealer) < 17) {
    set_cards(dealer);
  }

  // Print the final hands and figure out who won.
  printFinalHands(player, dealer);
  if (getScore(dealer) > 21) {
    printf("The dealer bust, so you win!\n");
  }
  else if (getScore(dealer) == getScore(player)) {
    printf("Its a draw.\n");
  }
  else if (getScore(dealer) > getScore(player)) {
    printf("You Lost, %d to %d\n", getScore(player), getScore(dealer));
  }
  else {
    printf("You Won, %d to %d\n", getScore(player), getScore(dealer));
  }

  /* print_card(dealer); */

  return 0;
}
