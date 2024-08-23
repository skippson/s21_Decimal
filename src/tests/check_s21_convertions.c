#include "check_s21_convertions.h"

void assert_float_eq(float a, float b) { ck_assert(fabs(a - b) < 0.0000001); }

START_TEST(test_float2decimal) {
  float in[] = {
      0.0f,
      123.456f,
      2.718281828f,
      3.141592653f,
      -123.456f,
      -2.718281828f,
      -3.141592653f,
      123456789123456789.12345f,
      79228152514264337593543950336.123456789123456789f,
      1267650600228229401496703205376.0f,  // 2^100
      0.0000000000123456789123f,
      0.5f,
      1.0f,
  };
  const s21_decimal out[] = {
      {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // 0
      {{0x0001e240, 0x00000000, 0x00000000, 0x00030000}},  // 123.456
      {{0x00297a4a, 0x00000000, 0x00000000, 0x00060000}},  // 2.718282
      {{0x002fefd9, 0x00000000, 0x00000000, 0x00060000}},  // 3.141593
      {{0x0001e240, 0x00000000, 0x00000000, 0x80030000}},  // -123.456
      {{0x00297a4a, 0x00000000, 0x00000000, 0x80060000}},  // -2.718282
      {{0x002fefd9, 0x00000000, 0x00000000, 0x80060000}},  // -3.141593
      {{0x351b4000, 0x01b69b4e, 0x00000000, 0x00000000}},  // 123456800000000000
      {{0x6dc00000, 0x99b1e85f, 0xfffffd59,
        0x00000000}},  // 79228150000000000000000000000
      {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},  // ERROR
      {{0x0012d688, 0x00000000, 0x00000000,
        0x00110000}},  // 0.00000000001234568
      {{0x00000005, 0x00000000, 0x00000000, 0x00010000}},  // 0.5
      {{0x00000001, 0x00000000, 0x00000000, 0x00000000}},  // 1

  };
  int codes[] = {
      OK, OK, OK, OK, OK, OK, OK, OK, OK, ERR_OVERFLOW, OK, OK, OK,
  };
  int size = sizeof(in) / sizeof(float);
  for (int i = 0; i < size; i++) {
    s21_decimal res;
    s21_decimal_init(&res);
    int code = s21_from_float_to_decimal(in[i], &res);
    ck_assert_int_eq(code, codes[i]);
    if (code == OK) {
      ck_assert_int_eq(s21_is_equal(res, out[i]), 1);
    }
  }

  int status1 = s21_from_float_to_decimal(1.4, NULL);
  ck_assert_int_eq(status1, 1);

  s21_decimal test;
  s21_decimal_init(&test);
  status1 = s21_from_float_to_decimal(-0, &test);
  ck_assert_int_eq(status1, 0);

  s21_decimal_init(&test);
  status1 = s21_from_float_to_decimal(INFINITY, &test);
  ck_assert_int_eq(status1, 1);

  s21_decimal_init(&test);
  status1 = s21_from_float_to_decimal(NAN, &test);
  ck_assert_int_eq(status1, 1);

  s21_decimal_init(&test);
  status1 = s21_from_float_to_decimal(-INFINITY, &test);
  ck_assert_int_eq(status1, 1);

  s21_decimal_init(&test);
  status1 = s21_from_float_to_decimal(NAN * -1, &test);
  ck_assert_int_eq(status1, 1);

  s21_decimal_init(&test);
  status1 = s21_from_float_to_decimal(
      -89228152514264337593543950336.123456789123456789f, &test);
  ck_assert_int_eq(status1, 1);

  s21_decimal_init(&test);
  status1 = s21_from_float_to_decimal(
      -0.000000000000000000000000000010000000031710768509710513471352647538147514756461109f,
      &test);
  ck_assert_int_eq(status1, 1);

  s21_decimal_init(&test);
  status1 = s21_from_float_to_decimal(
      0.000000000000000000000000000010000000031710768509710513471352647538147514756461109f,
      &test);
  ck_assert_int_eq(status1, 1);

  s21_decimal_init(&test);
  status1 = s21_from_float_to_decimal(
      0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f,
      &test);
  ck_assert_int_eq(status1, 0);
}

END_TEST
START_TEST(test_decimal2float) {
  s21_decimal in[] = {
      {{0x00000005, 0x00000000, 0x00000000, 0x00010000}},
      {{0x00000005, 0x00000000, 0x00000000, 0x80010000}},
  };
  const float out[] = {
      0.5f,
      -0.5f,
  };
  int size = sizeof(in) / sizeof(s21_decimal);
  for (int i = 0; i < size; i++) {
    float res = 0.0f;
    s21_from_decimal_to_float(in[i], &res);
    assert_float_eq(res, out[i]);
  }

  s21_decimal test = {{0x00000005, 0x00000000, 0x00000000, 0x80010000}};
  s21_decimal_init(&test);
  int status1 = s21_from_decimal_to_float(test, NULL);
  ck_assert_int_eq(status1, 1);

  s21_decimal test1 = {{0x0000000, 0x00000000, 0x00000000, 0x80010000}};
  float baz = 0;
  s21_from_decimal_to_float(test1, &baz);
}
END_TEST

START_TEST(test_int2decimal) {
  int in[] = {
      0, 123, 123456789, -123, -123456789,
  };
  const s21_decimal out[] = {
      {{0x00000000, 0x00000000, 0x00000000, 0x00000000}},
      {{0x0000007b, 0x00000000, 0x00000000, 0x00000000}},
      {{0x075bcd15, 0x00000000, 0x00000000, 0x00000000}},
      {{0x0000007b, 0x00000000, 0x00000000, 0x80000000}},
      {{0x075bcd15, 0x00000000, 0x00000000, 0x80000000}},
  };
  int size = sizeof(in) / sizeof(int);
  for (int i = 0; i < size; i++) {
    s21_decimal res;
    s21_decimal_init(&res);
    s21_from_int_to_decimal(in[i], &res);
    ck_assert_int_eq(s21_is_equal(res, out[i]), 1);
  }

  int status = s21_from_int_to_decimal(15, NULL);
  ck_assert_int_eq(status, 1);
}

END_TEST
START_TEST(test_decimal2int) {
  s21_decimal in[] = {
      {{0x00000005, 0x00000000, 0x00000000, 0x00010000}},
      {{0x00000005, 0x00000000, 0x00000000, 0x80010000}},
      {{0x00000005, 0x00000000, 0x00000000, 0x00000000}},
      {{0x00000005, 0x00000000, 0x00000000, 0x80000000}},
      {{0x00000000, 0x00000001, 0x00000000, 0x00000000}},
      {{0x00000001, 0x00000001, 0x00000000, 0x00090000}},
  };
  int out[] = {
      0, 0, 5, -5,
      0,  // err
      4,
  };
  int codes[] = {
      OK, OK, OK, OK, ERR_OVERFLOW, OK,
  };
  int size = sizeof(in) / sizeof(s21_decimal);
  for (int i = 0; i < size; i++) {
    int res = 0;
    int code = s21_from_decimal_to_int(in[i], &res);
    ck_assert_int_eq(code, codes[i]);
    if (code == OK) {
      ck_assert_int_eq(res, out[i]);
    }
  }

  s21_decimal ans = {{15, 0, 15, 0}};
  int ben = 0;
  int status1 = s21_from_decimal_to_int(ans, NULL);
  int status2 = s21_from_decimal_to_int(ans, &ben);

  ck_assert_int_eq(status1, 1);
  ck_assert_int_eq(status2, 1);

  s21_decimal pen = {{15, 0, 0, 0}};
  int status3 = s21_from_decimal_to_int(pen, NULL);
  ck_assert_int_eq(status3, 1);
}

END_TEST

Suite *

test_convert_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Convert");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_float2decimal);
  tcase_add_test(tc_core, test_decimal2float);
  tcase_add_test(tc_core, test_int2decimal);
  tcase_add_test(tc_core, test_decimal2int);
  suite_add_tcase(s, tc_core);

  return s;
}

int test_convert() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = test_convert_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}
