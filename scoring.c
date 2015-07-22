#include "scoring.h"

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
