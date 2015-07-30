/* #define TESTING */

#include <stdio.h>

#include "card_manip.h"
#include "typedefs.h"
#include "initialization.h"


static int pass = 0;
static int total = 0;

void check_bool_equal(int id, bool expected, bool actual) {
  total++;
  if (expected == actual) {
    pass++;
  }
  else {
    printf("Test Case %d Failed\n", id);
  }
}


int main() {
  check_bool_equal(1, false, is_deal_card_duplicate_test(two, spades));
  check_bool_equal(2, false, is_deal_card_duplicate_test(two, clubs));
  check_bool_equal(3, false, is_deal_card_duplicate_test(three, clubs));
  check_bool_equal(4, true, is_deal_card_duplicate_test(two, spades));
  check_bool_equal(5, true, is_deal_card_duplicate_test(two, clubs));
  check_bool_equal(6, false, is_deal_card_duplicate_test(ace, spades));

  printf("%d tests passed of %d: %f%%\n", pass, total, (pass*100.0)/total);

  freeAll();
  return 0;
}
