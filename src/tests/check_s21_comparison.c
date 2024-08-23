#include "check_s21_comparison.h"

// typedef struct testcase {
//   s21_decimal a;
//   s21_decimal b;
//   int res;
// } testcase;

START_TEST(test_equal) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(0, &test_value_1);
  s21_from_int_to_decimal(0, &test_value_2);
  ck_assert_int_eq(s21_is_equal(test_value_1, test_value_2), 1);
  ck_assert_int_eq(s21_is_not_equal(test_value_1, test_value_2), 0);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(711996, &test_value_1);
  s21_from_int_to_decimal(701995, &test_value_2);
  ck_assert_int_eq(s21_is_equal(test_value_1, test_value_2), 0);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(19993, &test_value_1);
  s21_from_int_to_decimal(-6739, &test_value_2);
  ck_assert_int_eq(s21_is_equal(test_value_1, test_value_2), 0);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(-9993, &test_value_1);
  s21_from_int_to_decimal(-9993, &test_value_2);
  ck_assert_int_eq(s21_is_equal(test_value_1, test_value_2), 1);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(11881, &test_value_1);
  s21_from_int_to_decimal(11881, &test_value_2);
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2), 1);
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2), 1);
}
END_TEST

START_TEST(test_greater) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(111, &test_value_1);
  s21_from_int_to_decimal(111, &test_value_2);
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2), 1);

  s21_decimal test_value = {{0, 0, 0, 0}};
  s21_decimal test_value1 = {{5, 0, 0, 65536}};
  test_value1.bits[0] = 111;
  ck_assert_int_eq(s21_is_greater(test_value1, test_value), 1);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(19993, &test_value_1);
  s21_from_int_to_decimal(-6739, &test_value_2);
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2), 1);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(-19993, &test_value_1);
  s21_from_int_to_decimal(6739, &test_value_2);
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2), 0);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(6739, &test_value_1);
  s21_from_int_to_decimal(19993, &test_value_2);
  ck_assert_int_eq(s21_is_greater(test_value_1, test_value_2), 0);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(711996, &test_value_1);
  s21_from_int_to_decimal(711995, &test_value_2);
  ck_assert_int_eq(s21_is_greater(test_value_1, test_value_2), 1);
}
END_TEST

START_TEST(test_greater_equal) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(111, &test_value_1);
  s21_from_int_to_decimal(111, &test_value_2);
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2), 1);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(19993, &test_value_1);
  s21_from_int_to_decimal(-6739, &test_value_2);
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2), 1);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(-19993, &test_value_1);
  s21_from_int_to_decimal(6739, &test_value_2);
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2), 0);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(6739, &test_value_1);
  s21_from_int_to_decimal(19993, &test_value_2);
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2), 0);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(711996, &test_value_1);
  s21_from_int_to_decimal(711995, &test_value_2);
  ck_assert_int_eq(s21_is_greater_or_equal(test_value_1, test_value_2), 1);
}
END_TEST

START_TEST(test_less) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(111, &test_value_1);
  s21_from_int_to_decimal(111, &test_value_2);
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2), 0);

  s21_decimal test_value = {{0, 0, 0, 0}};
  s21_decimal test_value1 = {{5, 0, 0, 65536}};
  test_value1.bits[0] = 111;
  ck_assert_int_eq(s21_is_less(test_value1, test_value), 0);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(19993, &test_value_1);
  s21_from_int_to_decimal(-6739, &test_value_2);
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2), 0);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(-19993, &test_value_1);
  s21_from_int_to_decimal(6739, &test_value_2);
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2), 1);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(6739, &test_value_1);
  s21_from_int_to_decimal(19993, &test_value_2);
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2), 1);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(711996, &test_value_1);
  s21_from_int_to_decimal(711995, &test_value_2);
  ck_assert_int_eq(s21_is_less(test_value_1, test_value_2), 0);
}
END_TEST

START_TEST(test_less_or_equal) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(111, &test_value_1);
  s21_from_int_to_decimal(111, &test_value_2);
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2), 1);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(19993, &test_value_1);
  s21_from_int_to_decimal(-6739, &test_value_2);
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2), 0);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(-19993, &test_value_1);
  s21_from_int_to_decimal(6739, &test_value_2);
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2), 1);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(6739, &test_value_1);
  s21_from_int_to_decimal(19993, &test_value_2);
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2), 1);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(711996, &test_value_1);
  s21_from_int_to_decimal(711995, &test_value_2);
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2), 0);
}
END_TEST

START_TEST(test_is_not_equal) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_from_int_to_decimal(0, &test_value_1);
  s21_from_int_to_decimal(0, &test_value_2);
  ck_assert_int_eq(s21_is_equal(test_value_1, test_value_2), 1);
  ck_assert_int_eq(s21_is_not_equal(test_value_1, test_value_2), 0);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(711996, &test_value_1);
  s21_from_int_to_decimal(701995, &test_value_2);
  ck_assert_int_eq(s21_is_not_equal(test_value_1, test_value_2), 1);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(19993, &test_value_1);
  s21_from_int_to_decimal(-6739, &test_value_2);
  ck_assert_int_eq(s21_is_not_equal(test_value_1, test_value_2), 1);

  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(-9993, &test_value_1);
  s21_from_int_to_decimal(-9993, &test_value_2);
  ck_assert_int_eq(s21_is_not_equal(test_value_1, test_value_2), 0);

  s21_decimal_init(&test_value_1);
  s21_decimal_init(&test_value_2);

  s21_from_int_to_decimal(11881, &test_value_1);
  s21_from_int_to_decimal(11881, &test_value_2);
  ck_assert_int_eq(s21_is_not_equal(test_value_1, test_value_2), 0);
  ck_assert_int_eq(s21_is_less_or_equal(test_value_1, test_value_2), 1);
}
END_TEST

Suite *test_compare_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Compare");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_equal);
  tcase_add_test(tc_core, test_greater);
  tcase_add_test(tc_core, test_greater_equal);
  tcase_add_test(tc_core, test_less);
  tcase_add_test(tc_core, test_is_not_equal);
  tcase_add_test(tc_core, test_less_or_equal);
  suite_add_tcase(s, tc_core);

  return s;
}

int test_compare() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = test_compare_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}
