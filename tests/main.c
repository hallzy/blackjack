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
