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

#include "check.h"

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

void show_results() {
  printf("%d tests passed of %d: %f%%\n", pass, total, (pass*100.0)/total);
}
