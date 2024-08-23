#include "tests/check_s21_arithmetics.h"
#include "tests/check_s21_comparison.h"
#include "tests/check_s21_convertions.h"
#include "tests/check_s21_round.h"
#include "tests/check_s21_test.h"

int main() {
  int no_failed = 0;

  no_failed |= test_arithmetics();
  no_failed |= test_compare();
  no_failed |= test_convert();
  no_failed |= test_round();
  no_failed |= test();

  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}