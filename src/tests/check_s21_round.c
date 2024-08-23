#include "check_s21_round.h"

typedef struct testcase {
  s21_decimal a;
  s21_decimal floor;
  s21_decimal round;
  s21_decimal truncate;
  s21_decimal negate;
} testcase;

START_TEST(test) {
  testcase tests[] = {
      {
          // 0
          {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
          {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
          {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
          {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
          {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
      },
      {
          // 1.5
          {{0x0000000f, 0x00000000, 0x00000000, 0x00010000}},
          {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},
          {{0x00000002, 0x00000000, 0x00000000, 0x00000000}},
          {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},
          {{0x0000000f, 0x00000000, 0x00000000, 0x80010000}},
      },
      {
          // -1.5
          {{0x0000000f, 0x00000000, 0x00000000, 0x80010000}},
          {{0x00000002, 0x00000000, 0x00000000, 0x80000000}},
          {{0x00000002, 0x00000000, 0x00000000, 0x80000000}},
          {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},
          {{0x0000000f, 0x00000000, 0x00000000, 0x00010000}},
      },
      {
          // 0.3
          {{0x00000003, 0x00000000, 0x00000000, 0x00010000}},
          {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
          {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
          {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
          {{0x00000003, 0x00000000, 0x00000000, 0x80010000}},
      },
      {
          // -0.3
          {{0x00000003, 0x00000000, 0x00000000, 0x80010000}},
          {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},
          {{0x00000000, 0x00000000, 0x00000000, 0x80000000}},
          {{0x00000000, 0x00000000, 0x00000000, 0x80000000}},
          {{0x00000003, 0x00000000, 0x00000000, 0x00010000}},
      },
      {
          // 0.7
          {{0x00000007, 0x00000000, 0x00000000, 0x00010000}},
          {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
          {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},
          {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
          {{0x00000007, 0x00000000, 0x00000000, 0x80010000}},
      },
      {
          // -0.7
          {{0x00000007, 0x00000000, 0x00000000, 0x80010000}},
          {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},
          {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},
          {{0x00000000, 0x00000000, 0x00000000, 0x80000000}},
          {{0x00000007, 0x00000000, 0x00000000, 0x00010000}},
      },
      {
          // 1
          {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},
          {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},
          {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},
          {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},
          {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},
      },
      {
          // -1
          {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},
          {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},
          {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},
          {{0x00000001, 0x00000000, 0x00000000, 0x80000000}},
          {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},
      },

  };
  int size = sizeof(tests) / sizeof(testcase);
  for (int i = 0; i < size; i++) {
    testcase test = tests[i];
    s21_decimal floor;
    s21_decimal round;
    s21_decimal truncate;
    s21_decimal negate;
    int floor_res = s21_floor(test.a, &floor);
    int round_res = s21_round(test.a, &round);
    int truncate_res = s21_truncate(test.a, &truncate);
    int negate_res = s21_negate(test.a, &negate);
    ck_assert_int_eq(floor_res, 0);
    ck_assert_int_eq(round_res, 0);
    ck_assert_int_eq(truncate_res, 0);
    ck_assert_int_eq(negate_res, 0);
  }
}
END_TEST

START_TEST(test2) {
  s21_decimal value1;
  s21_decimal value2;
  s21_decimal negate;
  // s21_decimal round_p;
  // s21_decimal round_m;

  s21_decimal_init(&value1);
  s21_decimal_init(&value2);
  s21_decimal_init(&negate);
  // s21_decimal_init(&round_p);
  // s21_decimal_init(&round_m);

  s21_from_float_to_decimal(1.5, &value1);
  s21_from_float_to_decimal(-1.5, &value2);

  s21_negate(value1, &negate);

  ck_assert_int_eq(negate.bits[3], -2147418112);

  // s21_round(value1, &round_p);
  // s21_round(value2, &round_m);

  // int status = s21_floor(value1, NULL);
  // ck_assert_int_eq(status, 1);
  // status = s21_round(value1, NULL);
  // ck_assert_int_eq(status, 1);

  // status = s21_truncate(value1, NULL);
  // ck_assert_int_eq(status, 1);

  // status = s21_negate(value1, NULL);
  // ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(test3) {
  s21_decimal value = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};  // 0
  s21_decimal result = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal tmp;
  int ret = s21_truncate(value, &tmp);
  ck_assert_int_eq(result.bits[0], tmp.bits[0]);
  ck_assert_int_eq(result.bits[1], tmp.bits[1]);
  ck_assert_int_eq(result.bits[2], tmp.bits[2]);
  ck_assert_int_eq(result.bits[3], tmp.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test4) {
  s21_decimal value = {{0x0000000E, 0x00000000, 0x00000000, 0x00000000}};  // 14
  s21_decimal result = {{0x0000000E, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal tmp;
  int ret = s21_truncate(value, &tmp);
  ck_assert_int_eq(result.bits[0], tmp.bits[0]);
  ck_assert_int_eq(result.bits[1], tmp.bits[1]);
  ck_assert_int_eq(result.bits[2], tmp.bits[2]);
  ck_assert_int_eq(result.bits[3], tmp.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test5) {
  s21_decimal value = {
      {0x00000467, 0x0000007A, 0x00000000, 0x00040000}};  // 52398601.1239
  s21_decimal result = {{0x031F8A09, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal tmp;
  int ret = s21_truncate(value, &tmp);
  ck_assert_int_eq(result.bits[0], tmp.bits[0]);
  ck_assert_int_eq(result.bits[1], tmp.bits[1]);
  ck_assert_int_eq(result.bits[2], tmp.bits[2]);
  ck_assert_int_eq(result.bits[3], tmp.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test6) {
  s21_decimal value = {
      {0x0000000F, 0x00000000, 0x00000000, 0x80010000}};  // -1.5
  s21_decimal result = {{0x00000001, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal tmp;
  int ret = s21_truncate(value, &tmp);
  ck_assert_int_eq(result.bits[0], tmp.bits[0]);
  ck_assert_int_eq(result.bits[1], tmp.bits[1]);
  ck_assert_int_eq(result.bits[2], tmp.bits[2]);
  ck_assert_int_eq(result.bits[3], tmp.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test7) {
  s21_decimal value = {
      {0xFFFFFFFF, 0x00000000, 0x00000000, 0x00060000}};  // 4294.967295
  s21_decimal result = {{0x000010C6, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal tmp;
  int ret = s21_truncate(value, &tmp);
  ck_assert_int_eq(result.bits[0], tmp.bits[0]);
  ck_assert_int_eq(result.bits[1], tmp.bits[1]);
  ck_assert_int_eq(result.bits[2], tmp.bits[2]);
  ck_assert_int_eq(result.bits[3], tmp.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test_negate) {
  s21_decimal value = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};  // 1
  s21_decimal result = {{0x00000001, 0x00000000, 0x00000000, 0x80000000}};
  s21_decimal tmp = {{0, 0, 0, 0}};
  int ret = s21_negate(value, &tmp);
  ck_assert_int_eq(result.bits[0], tmp.bits[0]);
  ck_assert_int_eq(result.bits[1], tmp.bits[1]);
  ck_assert_int_eq(result.bits[2], tmp.bits[2]);
  ck_assert_int_eq(result.bits[3], tmp.bits[3]);
  ck_assert_int_eq(ret, 0);

  s21_decimal value1 = {
      {0x00000001, 0x00000000, 0x00000000, 0x80000000}};  // -1
  s21_decimal result1 = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};
  s21_decimal_init(&tmp);
  ret = s21_negate(value1, &tmp);
  ck_assert_int_eq(result1.bits[0], tmp.bits[0]);
  ck_assert_int_eq(result1.bits[1], tmp.bits[1]);
  ck_assert_int_eq(result1.bits[2], tmp.bits[2]);
  ck_assert_int_eq(result1.bits[3], tmp.bits[3]);
  ck_assert_int_eq(ret, 0);

  s21_decimal value2 = {
      {0xCF5C048C, 0x004D2BEF, 0x00000000, 0x00070000}};  // 2172188218.2812812
  s21_decimal result2 = {{0xCF5C048C, 0x004D2BEF, 0x00000000, 0x80070000}};
  s21_decimal_init(&tmp);
  ret = s21_negate(value2, &tmp);
  ck_assert_int_eq(result2.bits[0], tmp.bits[0]);
  ck_assert_int_eq(result2.bits[1], tmp.bits[1]);
  ck_assert_int_eq(result2.bits[2], tmp.bits[2]);
  ck_assert_int_eq(result2.bits[3], tmp.bits[3]);
  ck_assert_int_eq(ret, 0);

  s21_decimal value3 = {
      {0x00000000, 0x00000001, 0x00000000, 0x80000000}};  // -4294967296
  s21_decimal result3 = {{0x00000000, 0x00000001, 0x00000000, 0x00000000}};
  s21_decimal_init(&tmp);
  ret = s21_negate(value3, &tmp);
  ck_assert_int_eq(result3.bits[0], tmp.bits[0]);
  ck_assert_int_eq(result3.bits[1], tmp.bits[1]);
  ck_assert_int_eq(result3.bits[2], tmp.bits[2]);
  ck_assert_int_eq(result3.bits[3], tmp.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test_round1) {
  s21_decimal tmp = {{0, 0, 0, 0}};
  s21_decimal num = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};     // 0
  s21_decimal result = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};  // 0
  int ret = s21_round(num, &tmp);
  char buf1[512] = {0};
  char buf2[512] = {0};
  float tmp_fl = 0;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  float result_fl = 0;
  s21_from_decimal_to_float(result, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);

  s21_decimal_init(&tmp);
  s21_decimal num1 = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};  // 1
  s21_decimal result1 = {
      {0x00000001, 0x00000000, 0x00000000, 0x00000000}};  // 1
  ret = s21_round(num1, &tmp);
  memset(buf1, '\0', strlen(buf1));
  memset(buf2, '\0', strlen(buf2));
  tmp_fl = 0;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  result_fl = 0;
  s21_from_decimal_to_float(result1, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);

  s21_decimal_init(&tmp);
  s21_decimal num2 = {{0x00000001, 0x00000000, 0x00000000, 0x80000000}};  // -1
  s21_decimal result2 = {
      {0x00000001, 0x00000000, 0x00000000, 0x80000000}};  //-1
  ret = s21_round(num2, &tmp);
  memset(buf1, '\0', strlen(buf1));
  memset(buf2, '\0', strlen(buf2));
  tmp_fl = 0;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  result_fl = 0;
  s21_from_decimal_to_float(result2, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);

  s21_decimal_init(&tmp);
  s21_decimal num3 = {
      {0xCF5C048C, 0x004D2BEF, 0x00000000, 0x00070000}};  // 2172188218.2812812
  s21_decimal result3 = {
      {0x8178F63A, 0x00000000, 0x00000000, 0x00000000}};  // 2172188218
  ret = s21_round(num3, &tmp);
  memset(buf1, '\0', strlen(buf1));
  memset(buf2, '\0', strlen(buf2));
  tmp_fl = 0;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  result_fl = 0;
  s21_from_decimal_to_float(result3, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test_floor) {
  s21_decimal tmp = {{0, 0, 0, 0}};
  s21_decimal num = {{0x00000001, 0x00000000, 0x00000000, 0x80000000}};  // -1
  s21_decimal result = {
      {0x00000001, 0x00000000, 0x00000000, 0x80000000}};  // -1
  int ret = s21_floor(num, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);

  s21_decimal_init(&tmp);
  s21_decimal num1 = {
      {0xCF5C048C, 0x004D2BEF, 0x00000000, 0x00070000}};  // 2172188218.2812812
  s21_decimal result1 = {
      {0x8178F63A, 0x00000000, 0x00000000, 0x00000000}};  // 2172188218
  ret = s21_floor(num1, &tmp);
  char buf1[512] = {0};
  char buf2[512] = {0};
  float tmp_fl = 0;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  float result_fl = 0;
  s21_from_decimal_to_float(result1, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);

  s21_decimal_init(&tmp);
  s21_decimal num2 = {
      {0xFEADBDA2, 0x000001FB, 0x00000000, 0x80060000}};  // -2181821.218210
  s21_decimal result2 = {
      {0x00214ABE, 0x00000000, 0x00000000, 0x80000000}};  //-2181822
  ret = s21_floor(num2, &tmp);
  memset(buf1, '\0', strlen(buf1));
  memset(buf2, '\0', strlen(buf2));
  tmp_fl = 0;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  result_fl = 0;
  s21_from_decimal_to_float(result2, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);

  // s21_decimal_init(&tmp);
  // s21_decimal num3 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
  //                      0x00000000}};  // 79228162514264337593543950335
  // s21_decimal result3 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
  //                         0x00000000}};  // 79228162514264337593543950335
  // ret = s21_floor(num3, &tmp);
  // memset(buf1, '\0', strlen(buf1));
  // memset(buf2, '\0', strlen(buf2));
  // tmp_fl = 0;
  // s21_from_decimal_to_float(tmp, &tmp_fl);
  // result_fl = 0;
  // s21_from_decimal_to_float(result3, &result_fl);
  // sprintf(buf1, "%.6E", tmp_fl);
  // sprintf(buf2, "%.6E", result_fl);
  // ck_assert(strcmp(buf1, buf2) == 0);
  // ck_assert_int_eq(ret, 0);

  s21_decimal_init(&tmp);
  s21_decimal num4 = {{0x000F4240, 0x00002710, 0x00002710,
                       0x80050000}};  // -1844674407800451901.20000
  s21_decimal result4 = {
      {0xB333333E, 0x19999999, 0x00000000, 0x80000000}};  //-1844674407800451902
  ret = s21_floor(num4, &tmp);
  memset(buf1, '\0', strlen(buf1));
  memset(buf2, '\0', strlen(buf2));
  tmp_fl = 0;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  result_fl = 0;
  s21_from_decimal_to_float(result4, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);
}
END_TEST

Suite *test_round_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Round");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test);
  tcase_add_test(tc_core, test2);
  tcase_add_test(tc_core, test3);
  tcase_add_test(tc_core, test4);
  tcase_add_test(tc_core, test5);
  tcase_add_test(tc_core, test6);
  tcase_add_test(tc_core, test7);
  tcase_add_test(tc_core, test_negate);
  tcase_add_test(tc_core, test_round1);
  tcase_add_test(tc_core, test_floor);
  // tcase_add_test(tc_core, test2);
  suite_add_tcase(s, tc_core);

  return s;
}

int test_round() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = test_round_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}
