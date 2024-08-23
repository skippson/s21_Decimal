#include "check_s21_arithmetics.h"

#include "../s21_decimal.h"
#define DATA_INTS 3

// void decimal_to_str(s21_decimal d, char *str) {
//   for (int i = 0; i < DATA_INTS + 1; i++) {
//     snprintf(str, 100, "%08x",
//              d.bits[i]);  // snprintf(buf1, 100, "%.6E", tmp_fl);
//     str += 8;
//     if (i != DATA_INTS) {
//       snprintf(str, 100, "|");
//       str++;
//     }
//   }
// }

// typedef struct testcase {
//   s21_decimal a;
//   s21_decimal b;
//   s21_decimal c;
//   int code;
// } testcase;

START_TEST(test_add) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result_int;
  s21_from_int_to_decimal(1899999, &test_value_1);
  s21_from_int_to_decimal(100001, &test_value_2);
  s21_add(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 2000000);

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(199421, &test_value_1);
  s21_from_int_to_decimal(-4433, &test_value_2);
  s21_add(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 199421 + (-4433));

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(-199421, &test_value_1);
  s21_from_int_to_decimal(4433, &test_value_2);
  s21_add(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, -199421 + 4433);

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(-199421, &test_value_1);
  s21_from_int_to_decimal((-4433), &test_value_2);
  s21_add(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (-199421) + (-4433));

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(467, &test_value_1);
  s21_from_int_to_decimal(3668, &test_value_2);
  s21_add(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 467 + 3668);

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(467, &test_value_1);
  s21_from_int_to_decimal(-3668, &test_value_2);
  s21_add(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 467 + (-3668));

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(-467, &test_value_1);
  s21_from_int_to_decimal(3668, &test_value_2);
  s21_add(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, -467 + 3668);

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(-467, &test_value_1);
  s21_from_int_to_decimal(-3668, &test_value_2);
  s21_add(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (-467) + (-3668));

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  s21_decimal test_value_3 = {{123453u, 654u, 0xFFFFFFFF, 80000000}};
  s21_decimal test_value_4 = {{123456u, 654u, 0xFFFFFFFF, 80000000}};
  s21_add(test_value_3, test_value_4, &result_dec);
}
END_TEST

START_TEST(test_sub) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result_int;
  s21_from_int_to_decimal(1899999, &test_value_1);
  s21_from_int_to_decimal(100001, &test_value_2);
  s21_sub(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 1899999 - 100001);

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(1899999, &test_value_1);
  s21_from_int_to_decimal(-100001, &test_value_2);
  s21_sub(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 1899999 - (-100001));

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(-1899999, &test_value_1);
  s21_from_int_to_decimal(100001, &test_value_2);
  s21_sub(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (-1899999) - 100001);

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(-1899999, &test_value_1);
  s21_from_int_to_decimal(-100001, &test_value_2);
  s21_sub(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (-1899999) - (-100001));

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(1994214, &test_value_1);
  s21_from_int_to_decimal(77443333, &test_value_2);
  s21_sub(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 1994214 - 77443333);

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(1994214, &test_value_1);
  s21_from_int_to_decimal(-77443333, &test_value_2);
  s21_sub(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 1994214 - (-77443333));

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(-1994214, &test_value_1);
  s21_from_int_to_decimal(77443333, &test_value_2);
  s21_sub(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, -1994214 - 77443333);

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(-1994214, &test_value_1);
  s21_from_int_to_decimal(-77443333, &test_value_2);
  s21_sub(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (-1994214) - (-77443333));

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(19999445, &test_value_1);
  s21_from_int_to_decimal(6, &test_value_2);
  s21_sub(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 19999445 - 6);
}
END_TEST

START_TEST(test_mul) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result_int;
  s21_from_int_to_decimal(18999, &test_value_1);
  s21_from_int_to_decimal(1001, &test_value_2);
  s21_mul(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (18999 * 1001));

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(18999, &test_value_1);
  s21_from_int_to_decimal(-1001, &test_value_2);
  s21_mul(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (18999 * (-1001)));

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(-18999, &test_value_1);
  s21_from_int_to_decimal(1001, &test_value_2);
  s21_mul(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (-18999 * 1001));

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(-18999, &test_value_1);
  s21_from_int_to_decimal(-1001, &test_value_2);
  s21_mul(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, ((-18999) * (-1001)));

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(191, &test_value_1);
  s21_from_int_to_decimal(57443, &test_value_2);
  s21_mul(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 191 * 57443);

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(191, &test_value_1);
  s21_from_int_to_decimal(-57443, &test_value_2);
  s21_mul(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 191 * (-57443));

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(-191, &test_value_1);
  s21_from_int_to_decimal(57443, &test_value_2);
  s21_mul(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, -191 * 57443);

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(-191, &test_value_1);
  s21_from_int_to_decimal(-57443, &test_value_2);
  s21_mul(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, ((-191) * (-57443)));
}
END_TEST

START_TEST(test_divmod) {
  s21_decimal test_value_1 = {{0, 0, 0, 0}};
  s21_decimal test_value_2 = {{0, 0, 0, 0}};
  s21_decimal result_dec = {{0, 0, 0, 0}};
  int result_int;
  s21_from_int_to_decimal(100000, &test_value_1);
  s21_from_int_to_decimal(1000, &test_value_2);
  s21_div(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (100000 / 1000));

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(456800, &test_value_1);
  s21_from_int_to_decimal(456800, &test_value_2);
  s21_div(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, 1);

  result_dec.bits[0] = 0;
  result_dec.bits[1] = 0;
  result_dec.bits[2] = 0;
  result_dec.bits[SCALE] = 0;
  test_value_1.bits[SCALE] = 0;
  test_value_2.bits[SCALE] = 0;
  s21_from_int_to_decimal(8900, &test_value_1);
  s21_from_int_to_decimal(2, &test_value_2);
  s21_div(test_value_1, test_value_2, &result_dec);
  s21_from_decimal_to_int(result_dec, &result_int);
  ck_assert_int_eq(result_int, (8900 / 2));
  s21_decimal test_value_12 = {{0, 0, 0, 0}};
  s21_decimal test_value_22 = {{0, 0, 0, 0}};
  // s21_decimal result_dec2 = {{0, 0, 0, 0}};
  // int result_int2;
  s21_from_int_to_decimal(100000, &test_value_12);
  s21_from_int_to_decimal(1000, &test_value_22);
  // s21_mod(test_value_12, test_value_22, &result_dec2);
  // s21_from_decimal_to_int(result_dec2, &result_int2);
  // ck_assert_int_eq(result_int2, (100000 % 1000));

  // result_dec2.bits[0] = 0;
  // result_dec2.bits[1] = 0;
  // result_dec2.bits[2] = 0;
  // result_dec2.bits[SCALE] = 0;
  test_value_12.bits[SCALE] = 0;
  test_value_22.bits[SCALE] = 0;
  s21_from_int_to_decimal(1, &test_value_12);
  s21_from_int_to_decimal(3, &test_value_22);
  // s21_mod(test_value_12, test_value_22, &result_dec2);
  // s21_from_decimal_to_int(result_dec2, &result_int2);
  // ck_assert_int_eq(result_int2, (1 % 3));
}
END_TEST
START_TEST(test_s21_add_1) {
  // s21_decimal tmp;
  s21_decimal num1 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};    // 0
  s21_decimal num2 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};    // 0
  s21_decimal result = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};  // 0
  int ret = s21_add(num1, num2, &num1);
  ck_assert_int_eq(num1.bits[0], result.bits[0]);
  ck_assert_int_eq(num1.bits[1], result.bits[1]);
  ck_assert_int_eq(num1.bits[2], result.bits[2]);
  ck_assert_int_eq(num1.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test_s21_add_2) {
  // s21_decimal tmp;
  s21_decimal num1 = {
      {0x00000001, 0x00000000, 0x00000000, 0x800E0000}};  // -0.00000000000001
  s21_decimal num2 = {
      {0x00000006, 0x00000000, 0x00000000, 0x000F0000}};  // 0.000000000000006
  s21_decimal result = {
      {0x00000004, 0x00000000, 0x00000000, 0x800F0000}};  // -0.000000000000004
  int ret = s21_add(num1, num2, &num1);
  ck_assert_int_eq(num1.bits[0], result.bits[0]);
  ck_assert_int_eq(num1.bits[1], result.bits[1]);
  ck_assert_int_eq(num1.bits[2], result.bits[2]);
  ck_assert_int_eq(num1.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test_s21_add_3) {
  s21_decimal tmp;
  s21_decimal num1 = {{0x00000019, 0x00000000, 0x00000000, 0x00010000}};  // 2.5
  s21_decimal num2 = {{0x00000064, 0x00000000, 0x00000000, 0x00000000}};  // 100
  s21_decimal result = {
      {0x00000401, 0x00000000, 0x00000000, 0x00010000}};  // 102.5
  int ret = s21_add(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test_s21_add_4) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x00000183, 0x00000000, 0x00000000, 0x00020000}};  // 3.87
  s21_decimal num2 = {
      {0x00004DA6, 0x00000000, 0x00000000, 0x00020000}};  // 198.78
  s21_decimal result = {
      {0x00004F29, 0x00000000, 0x00000000, 0x00020000}};  // 202.65
  int ret = s21_add(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_add_5) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x14490831, 0x00048E23, 0x00000000, 0x00070000}};  // 128218122.2172721
  s21_decimal num2 = {
      {0x164214B7, 0x00000028, 0x00000000, 0x00040000}};  // 17217212.1271
  s21_decimal result = {
      {0x0669F309, 0x00052ABA, 0x00000000, 0x00070000}};  // 145435334.3443721
  int ret = s21_add(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_add_6) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x77D5E3AA, 0x0000011C, 0x00000000, 0x00060000}};  // 1221781.218218
  s21_decimal num2 = {
      {0x00212155, 0x00000000, 0x00000000, 0x00070000}};  // 0.2171221
  s21_decimal result = {
      {0xAE7C05F9, 0x00000B1C, 0x00000000, 0x00070000}};  // 1221781.4353401
  int ret = s21_add(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_add_7) {  // strange
  s21_decimal tmp;
  s21_decimal num1 = {{0x80000000, 0x80000000, 0x80000000,
                       0x801C0000}};  // -3.9614081266355540835774234624
  s21_decimal num2 = {{0x80000000, 0x80000000, 0x80000000,
                       0x801C0000}};  // -3.9614081266355540835774234624
  s21_decimal result = {{0x4CCCCCCC, 0xB3333333, 0x19999999,
                         0x801B0000}};  // -7.922816253271108167154846925
  int ret = s21_add(num1, num2, &tmp);
  float tmp_fl;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  float res_fl;
  s21_from_decimal_to_float(result, &res_fl);
  char buf1[512];
  char buf2[512];
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", res_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_add_8) {  // strange
  s21_decimal tmp;
  s21_decimal num1 = {{0x80000000, 0x80000000, 0x80000000,
                       0x000E0000}};  // 396140812663555.40835774234624
  s21_decimal num2 = {{0x80000000, 0x80000000, 0x80000000,
                       0x000E0000}};  // 396140812663555.40835774234624
  s21_decimal result = {{0x4CCCCCCC, 0xB3333333, 0x19999999,
                         0x000D0000}};  // 792281625327110.8167154846925
  int ret = s21_add(num1, num2, &tmp);
  float tmp_fl;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  float res_fl;
  s21_from_decimal_to_float(result, &res_fl);
  char buf1[512];
  char buf2[512];
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", res_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_add_9) {
  s21_decimal tmp;
  s21_decimal num1 = {{0x00000001, 0x00000000, 0x00000000,
                       0x001C0000}};  // 0.0000000000000000000000000001
  s21_decimal num2 = {{0x00000001, 0x00000000, 0x00000000,
                       0x001C0000}};  // 0.0000000000000000000000000001
  s21_decimal result = {{0x00000002, 0x00000000, 0x00000000,
                         0x001C0000}};  // 0.0000000000000000000000000002
  int ret = s21_add(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_add_10) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x00000000, 0x00000000, 0x00000000, 0x000E0000}};  // 0.00000000000000
  s21_decimal num2 = {{0x00000000, 0x00000000, 0x00000000,
                       0x001C0000}};  // 0.0000000000000000000000000000
  s21_decimal result = {{0x00000000, 0x00000000, 0x00000000,
                         0x00000000}};  // 0.0000000000000000000000000000
  int ret = s21_add(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_add_11) {
  s21_decimal tmp;
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x00010000}};  // 7922816251426433759354395033.5
  s21_decimal num2 = {{0x00000005, 0x00000000, 0x00000000, 0x00010000}};  // 0.5
  s21_decimal result = {{0x9999999A, 0x99999999, 0x19999999,
                         0x00000000}};  // 7922816251426433759354395034
  int ret = s21_add(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_add_12) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x1422CF6C, 0x000001FC, 0x00000000, 0x80030000}};  // -2182181212.012
  s21_decimal num2 = {
      {0xF96C01C5, 0x0007B6B6, 0x00000000, 0x800B0000}};  //-21712.21821882821
  s21_decimal result = {{0x3015EDC5, 0xD46A37C7, 0x0000000B,
                         0x800B0000}};  //-2182202924.23021882821
  int ret = s21_add(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_add_13) {  // strange
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x79353447, 0x00000004, 0x00000000, 0x00010000}};  // 1921339911.1
  s21_decimal num2 = {{0xD927FFFF, 0xE1003B28, 0x00000004,
                       0x00140000}};  // 0.89999999999999999999
  s21_decimal result = {{0x9F3FFFFF, 0x563581D8, 0x3E14F385,
                         0x00130000}};  // 1921339912.0000000000000000000
  int ret = s21_add(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_add_14) {  // strange
  s21_decimal tmp;
  s21_decimal num1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x00000000}};  // 79228162514264337593543950334
  s21_decimal num2 = {
      {0x00000031, 0x00000000, 0x00000000, 0x00020000}};  // 0.49
  s21_decimal result = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF,
                         0x00000000}};  // 79228162514264337593543950334
  int ret = s21_add(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_add_15) {  // strange
  s21_decimal tmp;
  s21_decimal num1 = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x00000000}};  // 79228162514264337593543950334
  s21_decimal num2 = {
      {0x00000033, 0x00000000, 0x00000000, 0x00020000}};  // 0.51
  s21_decimal result = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF,
                         0x00000000}};  // 79228162514264337593543950335
  int ret = s21_add(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_add_16) {
  s21_decimal tmp;
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x00000000}};  // 79228162514264337593543950335
  s21_decimal num2 = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};  // 1
  int ret = s21_add(num1, num2, &tmp);
  ck_assert_int_eq(ret, 1);
}
END_TEST
START_TEST(test_s21_add_17) {
  s21_decimal tmp;
  s21_decimal num1 = {{0xFF642CF2, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x80000000}};  //-79228162514264337593533738226
  s21_decimal num2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x80080000}};  // -792281625142643375935.43950335
  int ret = s21_add(num1, num2, &tmp);
  ck_assert_int_eq(ret, 2);
}
END_TEST

START_TEST(test_s21_sub_1) {
  s21_decimal tmp;
  s21_decimal num1 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};    // 0
  s21_decimal num2 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};    // 0
  s21_decimal result = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};  // 0
  int ret = s21_sub(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST

START_TEST(test_s21_sub_2) {
  s21_decimal tmp;
  s21_decimal num1 = {{0x00000019, 0x00000000, 0x00000000, 0x00010000}};  // 2.5
  s21_decimal num2 = {{0x00000019, 0x00000000, 0x00000000, 0x00010000}};  // 2.5
  s21_decimal result = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};  // 0
  int ret = s21_sub(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_sub_3) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x00000001, 0x00000000, 0x00000000, 0x800E0000}};  // -0.00000000000001
  s21_decimal num2 = {
      {0x00000006, 0x00000000, 0x00000000, 0x000F0000}};  //  0.000000000000006
  s21_decimal result = {
      {0x00000010, 0x00000000, 0x00000000, 0x800F0000}};  // -0.000000000000016
  int ret = s21_sub(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_sub_4) {
  s21_decimal tmp;
  s21_decimal num1 = {{0x00000019, 0x00000000, 0x00000000, 0x00010000}};  // 2.5
  s21_decimal num2 = {{0x00000064, 0x00000000, 0x00000000, 0x00000000}};  // 100
  s21_decimal result = {
      {0x000003CF, 0x00000000, 0x00000000, 0x80010000}};  // -97.5
  int ret = s21_sub(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_sub_5) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x00000183, 0x00000000, 0x00000000, 0x00020000}};  // 3.87
  s21_decimal num2 = {
      {0x00004DA6, 0x00000000, 0x00000000, 0x00020000}};  // 198.78
  s21_decimal result = {
      {0x00004C23, 0x00000000, 0x00000000, 0x80020000}};  // -194.91
  int ret = s21_sub(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_sub_6) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x14490831, 0x00048E23, 0x00000000, 0x00070000}};  // 128218122.2172721
  s21_decimal num2 = {
      {0x164214B7, 0x00000028, 0x00000000, 0x00040000}};  // 17217212.1271
  s21_decimal result = {
      {0x22281D59, 0x0003F18C, 0x00000000, 0x00070000}};  // 111000910.0901721
  int ret = s21_sub(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_sub_7) {
  s21_decimal tmp;
  s21_decimal num1 = {{0x80000000, 0x80000000, 0x80000000,
                       0x801C0000}};  // -3.9614081266355540835774234624
  s21_decimal num2 = {{0x80000000, 0x80000000, 0x80000000,
                       0x801C0000}};  // -3.9614081266355540835774234624
  s21_decimal result = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};  // 0
  int ret = s21_sub(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_sub_8) {
  s21_decimal tmp;
  s21_decimal num1 = {{0x000F4240, 0x00000000, 0x00000000,
                       0x001C0000}};  // 0.0000000000000000000001000000
  s21_decimal num2 = {{0x000186A0, 0x00000000, 0x00000000,
                       0x00140000}};  // 0.00000000000000100000
  s21_decimal result = {{0x4E635DC0, 0x00000918, 0x00000000,
                         0x801C0000}};  // -0.0000000000000009999999000000
  int ret = s21_sub(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_sub_9) {
  s21_decimal tmp;
  s21_decimal num1 = {{0x80000000, 0x80000000, 0x80000000,
                       0x00000000}};  // 39614081266355540835774234624
  s21_decimal num2 = {
      {0x00000000, 0x00000000, 0x00000000, 0x000A0000}};  // 0.0000000000
  s21_decimal result = {{0x80000000, 0x80000000, 0x80000000,
                         0x00000000}};  // 39614081266355540835774234624
  int ret = s21_sub(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_sub_10) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x1422CF6C, 0x000001FC, 0x00000000, 0x80030000}};  // -2182181212.012
  s21_decimal num2 = {
      {0xF96C01C5, 0x0007B6B6, 0x00000000, 0x800B0000}};  // -21712.21821882821
  s21_decimal result = {{0x3D3DEA3B, 0xD45ACA59, 0x0000000B,
                         0x800B0000}};  // -2182159499.79378117179
  int ret = s21_sub(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_sub_11) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x0001869F, 0x00000000, 0x00000000, 0x00050000}};  // 0.99999
  s21_decimal num2 = {
      {0x00000001, 0x00000000, 0x00000000, 0x00050000}};  // 0.00001
  s21_decimal result = {
      {0x0001869E, 0x00000000, 0x00000000, 0x00050000}};  // 0.99998
  int ret = s21_sub(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_sub_12) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x0098967E, 0x00000000, 0x00000000, 0x80060000}};  // -9.999998
  s21_decimal num2 = {
      {0x00000002, 0x00000000, 0x00000000, 0x80060000}};  // -0.000002
  s21_decimal result = {
      {0x0098967C, 0x00000000, 0x00000000, 0x80060000}};  // -9.999996
  int ret = s21_sub(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_sub_13) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x000000CF, 0x00000000, 0x00000000, 0x00010000}};  // 20.7
  s21_decimal num2 = {{0x00003F86, 0x00000000, 0x00000000,
                       0x00160000}};  // 0.0000000000000000016262
  s21_decimal result = {{0x035FC07A, 0x7E1382FF, 0x00002BD5,
                         0x00160000}};  // 20.6999999999999999983738
  int ret = s21_sub(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_sub_14) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x00000190, 0x00000000, 0x00000000, 0x80000000}};  // -400
  s21_decimal num2 = {
      {0x00000190, 0x00000000, 0x00000000, 0x80000000}};  // -400
  s21_decimal result = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};  // 0
  int ret = s21_sub(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_sub_15) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x10C2F579, 0x00000000, 0x00000000, 0x80050000}};  // -2812.12281
  s21_decimal num2 = {
      {0x10C44951, 0x00000000, 0x00000000, 0x80030000}};  // -281299.281
  s21_decimal result = {
      {0x7BE9AE2B, 0x00000006, 0x00000000, 0x00050000}};  // 278487.15819
  int ret = s21_sub(num1, num2, &tmp);
  ck_assert_int_eq(tmp.bits[0], result.bits[0]);
  ck_assert_int_eq(tmp.bits[1], result.bits[1]);
  ck_assert_int_eq(tmp.bits[2], result.bits[2]);
  ck_assert_int_eq(tmp.bits[3], result.bits[3]);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_sub_16) {
  s21_decimal tmp;
  s21_decimal num1 = {{0x00000001, 0x00000000, 0x00000000, 0x00000000}};  // 1
  s21_decimal num2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x80000000}};  //-79228162514264337593543950335
  int ret = s21_sub(num1, num2, &tmp);
  ck_assert_int_eq(ret, 1);
}
END_TEST
START_TEST(test_s21_sub_17) {
  s21_decimal tmp;
  s21_decimal num1 = {{0x00000001, 0x00000000, 0x00000000, 0x80000000}};  // -1
  s21_decimal num2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x00000000}};  // 79228162514264337593543950335
  int ret = s21_sub(num1, num2, &tmp);
  ck_assert_int_eq(ret, 2);
}
END_TEST

START_TEST(test_s21_mul_1) {
  s21_decimal result1 = {{0, 0, 0, 0}};
  s21_decimal result2 = {{0, 0, 0, 0}};
  s21_decimal case_full1 = {{123, 321, -2147483648, 0}};
  s21_decimal case_full2 = {{123, 321, -2147483648, 0}};
  s21_decimal case_max = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  int res_mul = -1;
  s21_decimal case_d = {{0, 0, 0, 0}};
  res_mul = s21_mul(case_d, case_max, &result1);
  ck_assert_int_eq(res_mul, 0);
  s21_decimal max = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0}};
  res_mul = s21_mul(max, max, &result1);
  ck_assert_int_eq(res_mul, 1);
  int res_ful1 = 0;
  int res_ful2 = 0;
  res_ful1 = s21_mul(case_full1, case_full2, &result1);
  ck_assert_int_eq(res_ful1, 1);
  res_ful2 = s21_mul(case_full1, case_full2, &result2);
  setBit(&result2, 127, 1);
  ck_assert_int_eq(res_ful2, 1);
}
END_TEST
START_TEST(test_s21_mul_2) {
  s21_decimal decimal_1 = smallInit();
  s21_decimal decimal_2 = smallInit();
  s21_decimal result = smallInit();

  decimal_1.bits[0] = 1256;
  decimal_2.bits[0] = 1000;

  s21_decimal true_result = smallInit();

  true_result.bits[0] = 1256000;

  int status = s21_mul(decimal_1, decimal_2, &result);
  int true_status = 0;

  ck_assert_int_eq(1, s21_is_equal(result, true_result));
  ck_assert_int_eq(status, true_status);
}
END_TEST
START_TEST(test_s21_mul_3) {
  s21_decimal decimal_1 = smallInit();
  s21_decimal decimal_2 = smallInit();
  s21_decimal result = smallInit();

  decimal_1.bits[2] = 4294967295U;

  decimal_2.bits[0] = 2;

  int status = s21_mul(decimal_1, decimal_2, &result);
  int true_status = 1;

  ck_assert_int_eq(status, true_status);
}
END_TEST
START_TEST(test_s21_mul_4) {
  s21_decimal decimal_1 = smallInit();
  s21_decimal decimal_2 = smallInit();
  s21_decimal result = smallInit();

  decimal_1.bits[0] = MAX;
  decimal_1.bits[1] = MAX;
  decimal_1.bits[2] = 2147483647u;

  decimal_2.bits[0] = 2;

  s21_decimal true_result = smallInit();

  true_result.bits[0] = 4294967294u;
  true_result.bits[1] = 4294967295u;
  true_result.bits[2] = 4294967295u;

  int status = s21_mul(decimal_1, decimal_2, &result);
  int true_status = 0;

  ck_assert_int_eq(1, s21_is_equal(result, true_result));
  ck_assert_int_eq(status, true_status);
}
END_TEST
START_TEST(test_s21_mul_5) {
  s21_decimal tmp;
  s21_decimal num1 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};    // 0
  s21_decimal num2 = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};    // 0
  s21_decimal result = {{0x00000000, 0x00000000, 0x00000000, 0x00000000}};  // 0
  int ret = s21_mul(num1, num2, &tmp);
  char buf1[512];
  char buf2[512];
  float tmp_fl;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  float result_fl;
  s21_from_decimal_to_float(result, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_mul_6) {
  s21_decimal tmp;
  s21_decimal num1 = {{0x0000000F, 0x00000000, 0x00000000, 0x00010000}};  // 1.5
  s21_decimal num2 = {{0x00000002, 0x00000000, 0x00000000, 0x00000000}};  // 2
  s21_decimal result = {
      {0x0000001E, 0x00000000, 0x00000000, 0x00010000}};  // 3.0
  int ret = s21_mul(num1, num2, &tmp);
  char buf1[512];
  char buf2[512];
  float tmp_fl;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  float result_fl;
  s21_from_decimal_to_float(result, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_mul_7) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x00000001, 0x00000000, 0x00000000, 0x000F0000}};  // 0.000000000000001
  s21_decimal num2 = {
      {0x540BE400, 0x00000002, 0x00000000, 0x00000000}};  // 10000000000
  s21_decimal result = {
      {0x540BE400, 0x00000002, 0x00000000, 0x000F0000}};  // 0.000010000000000
  int ret = s21_mul(num1, num2, &tmp);
  char buf1[512];
  char buf2[512];
  float tmp_fl;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  float result_fl;
  s21_from_decimal_to_float(result, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_mul_8) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0xC4D5AAEC, 0x00000025, 0x00000000, 0x00060000}};  // 162216.127212
  s21_decimal num2 = {
      {0x0000033B, 0x00000000, 0x00000000, 0x00040000}};  // 0.0827
  s21_decimal result = {
      {0xDE3F2864, 0x00007A02, 0x00000000, 0x000A0000}};  // 13415.2737204324
  int ret = s21_mul(num1, num2, &tmp);
  char buf1[512];
  char buf2[512];
  float tmp_fl;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  float result_fl;
  s21_from_decimal_to_float(result, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_mul_9) {
  s21_decimal tmp;
  s21_decimal num1 = {{0x74489B46, 0x11C6B4C4, 0x00000000,
                       0x00050000}};  // 12809098998909.89894
  s21_decimal num2 = {
      {0x0005C187, 0x00000000, 0x00000000, 0x000F0000}};  // 0.000000000377223
  s21_decimal result = {{0x17B7A7EA, 0xB5E7B4AF, 0x00006651,
                         0x00140000}};  // 4831.88675166578880784362
  int ret = s21_mul(num1, num2, &tmp);
  char buf1[512];
  char buf2[512];
  float tmp_fl;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  float result_fl;
  s21_from_decimal_to_float(result, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_mul_10) {
  s21_decimal tmp;
  s21_decimal num1 = {{0xA4C194B9, 0xDF05E1A3, 0x000786BE,
                       0x00050000}};  // 90987987978798797979.37337
  s21_decimal num2 = {{0x000003DD, 0x00000000, 0x00000000, 0x00000000}};  // 989
  s21_decimal result = {{0x7FDB8EB5, 0x99B8B533, 0x1D138F63,
                         0x00050000}};  // 89987120111032011201600.26293
  int ret = s21_mul(num1, num2, &tmp);
  char buf1[512];
  char buf2[512];
  float tmp_fl;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  float result_fl;
  s21_from_decimal_to_float(result, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_mul_11) {
  s21_decimal tmp;
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x80000000}};  // -79228162514264337593543950335
  s21_decimal num2 = {{0x00000001, 0x00000000, 0x00000000, 0x80000000}};  // -1
  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                         0x00000000}};  // 79228162514264337593543950335
  int ret = s21_mul(num1, num2, &tmp);
  char buf1[512];
  char buf2[512];
  float tmp_fl;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  float result_fl;
  s21_from_decimal_to_float(result, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_mul_12) {  // STRANGE
  s21_decimal tmp;
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x00000000}};  // 79228162514264337593543950335
  s21_decimal num2 = {{0x00000005, 0x00000000, 0x00000000, 0x00010000}};  // 0.5
  s21_decimal result = {{0xFFFFFFFF, 0xFFFFFFFF, 0x7FFFFFFF,
                         0x00000000}};  // 39614081257132168796771975168
  int ret = s21_mul(num1, num2, &tmp);
  char buf1[512];
  char buf2[512];
  float tmp_fl;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  float result_fl;
  s21_from_decimal_to_float(result, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_mul_13) {
  s21_decimal tmp;
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x00000000}};  // 79228162514264337593543950335
  s21_decimal num2 = {
      {0x00000159, 0x00000000, 0x00000000, 0x00040000}};  // 0.0345
  s21_decimal result = {{0x851EB852, 0x1EB851EB, 0x5851EB85,
                         0x00010000}};  // 2733371606742119646977266286.6
  int ret = s21_mul(num1, num2, &tmp);
  char buf1[512];
  char buf2[512];
  float tmp_fl;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  float result_fl;
  s21_from_decimal_to_float(result, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_mul_14) {  // strange
  s21_decimal tmp;
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x00000000}};  // 79228162514264337593543950335
  s21_decimal num2 = {{0x04000001, 0xC308736A, 0x02E87669,
                       0x001B0000}};  // 0.900000000000000000000000001
  s21_decimal result = {{0x666666B4, 0x66666666, 0xE6666666,
                         0x00000000}};  // 71305346262837903834189555381
  int ret = s21_mul(num1, num2, &tmp);
  char buf1[512];
  char buf2[512];
  float tmp_fl;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  float result_fl;
  s21_from_decimal_to_float(result, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_mul_15) {
  s21_decimal tmp;
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x000F0000}};  // 79228162514264.337593543950335
  s21_decimal num2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x800F0000}};  // -79228162514264.337593543950335
  s21_decimal result = {{0x096EE456, 0x359A3B3E, 0xCAD2F7F5,
                         0x80010000}};  // -6277101735386680763835789423.0
  int ret = s21_mul(num1, num2, &tmp);
  char buf1[512];
  char buf2[512];
  float tmp_fl;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  float result_fl;
  s21_from_decimal_to_float(result, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_mul_16) {
  s21_decimal tmp;
  s21_decimal num1 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x80180000}};  // -79228.162514264337593543950335
  s21_decimal num2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x00180000}};  // 79228.162514264337593543950335
  s21_decimal result = {{0x096EE456, 0x359A3B3E, 0xCAD2F7F5,
                         0x80130000}};  // -6277101735.3866807638357894230
  int ret = s21_mul(num1, num2, &tmp);
  char buf1[512];
  char buf2[512];
  float tmp_fl;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  float result_fl;
  s21_from_decimal_to_float(result, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_mul_17) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x0098967F, 0x00000000, 0x00000000, 0x00070000}};  // 0.9999999
  s21_decimal num2 = {
      {0x0D01C1BA, 0x00000000, 0x00000000, 0x00010000}};  // 21821893.8
  s21_decimal result = {
      {0x81D21746, 0x0007C0B0, 0x00000000, 0x00080000}};  // 21821891.61781062
  int ret = s21_mul(num1, num2, &tmp);
  char buf1[512];
  char buf2[512];
  float tmp_fl;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  float result_fl;
  s21_from_decimal_to_float(result, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_mul_18) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x0000036C, 0x00000000, 0x00000000, 0x00110000}};  // 0.00000000000000876
  s21_decimal num2 = {
      {0x3E41371C, 0x01632A10, 0x00000000, 0x80040000}};  // -9996986598458.7548
  s21_decimal result = {{0x072893D0, 0xBF53EF95, 0x00000004,
                         0x80150000}};  // -0.087573602602498692048
  int ret = s21_mul(num1, num2, &tmp);
  char buf1[512];
  char buf2[512];
  float tmp_fl;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  float result_fl;
  s21_from_decimal_to_float(result, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_mul_19) {  // strange
  s21_decimal tmp;
  s21_decimal num1 = {{0x2110991F, 0x1ED3CC02, 0x00000023, 0x000E0000}};
  s21_decimal num2 = {{0xC092569D, 0x00000C41, 0x00000000, 0x00100000}};
  s21_decimal result = {{0x92DF46D0, 0x3DDA088A, 0x1C360358, 0x00180000}};
  int ret = s21_mul(num1, num2, &tmp);
  char buf1[512];
  char buf2[512];
  float tmp_fl;
  s21_from_decimal_to_float(tmp, &tmp_fl);
  float result_fl;
  s21_from_decimal_to_float(result, &result_fl);
  snprintf(buf1, 100, "%.6E", tmp_fl);
  snprintf(buf2, 100, "%.6E", result_fl);
  ck_assert(strcmp(buf1, buf2) == 0);
  ck_assert_int_eq(ret, 0);
}
END_TEST
START_TEST(test_s21_mul_20) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x00000010, 0x00000000, 0x00000000, 0x80010000}};  // -1.6
  s21_decimal num2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x00000000}};  // 79228162514264337593543950335
  int ret = s21_mul(num1, num2, &tmp);
  ck_assert_int_eq(ret, 2);
}
END_TEST
START_TEST(test_s21_mul_21) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x00000069, 0x00000000, 0x00000000, 0x00010000}};  // 10.5
  s21_decimal num2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x00000000}};  // 79228162514264337593543950335
  int ret = s21_mul(num1, num2, &tmp);
  ck_assert_int_eq(ret, 1);
}
END_TEST
START_TEST(test_s21_mul_22) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x0000000B, 0x00000000, 0x00000000, 0x80010000}};  // -1.1
  s21_decimal num2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x80000000}};  //-79228162514264337593543950335
  int ret = s21_mul(num1, num2, &tmp);
  ck_assert_int_eq(ret, 1);
}
END_TEST
START_TEST(test_s21_mul_23) {
  s21_decimal tmp;
  s21_decimal num1 = {
      {0x0000006A, 0x00000000, 0x00000000, 0x00010000}};  // 10.6
  s21_decimal num2 = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF,
                       0x80000000}};  //-79228162514264337593543950335
  int ret = s21_mul(num1, num2, &tmp);
  ck_assert_int_eq(ret, 2);
}
END_TEST

START_TEST(test_s21_div_1) {
  s21_decimal decimal_1 = smallInit();
  s21_decimal decimal_2 = smallInit();
  s21_decimal result = smallInit();
  decimal_1.bits[0] = 65536;
  decimal_2.bits[0] = 2;
  s21_decimal true_result = smallInit();

  true_result.bits[0] = 32768;
  int status = s21_div(decimal_1, decimal_2, &result);
  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(result, true_result));
  ck_assert_int_eq(status, true_status);
}
END_TEST
START_TEST(test_s21_div_2) {
  s21_decimal decimal_1 = smallInit();
  s21_decimal decimal_2 = smallInit();
  s21_decimal result = smallInit();
  decimal_1.bits[0] = 9;
  decimal_1.bits[3] = 65536;
  decimal_2.bits[0] = 6;
  decimal_2.bits[3] = 65536;
  s21_decimal true_result = smallInit();

  true_result.bits[0] = 15;
  true_result.bits[3] = 65536;
  int status = s21_div(decimal_1, decimal_2, &result);
  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(result, true_result));
  ck_assert_int_eq(status, true_status);
}
END_TEST
START_TEST(test_s21_div_3) {  // strange
  s21_decimal decimal_1 = smallInit();
  s21_decimal decimal_2 = smallInit();
  s21_decimal result = smallInit();

  decimal_1.bits[0] = 14;
  decimal_1.bits[3] = 65536;
  decimal_2.bits[0] = 9;
  decimal_2.bits[3] = 65536;

  s21_decimal true_result;
  true_result.bits[0] = 3280877794u;
  true_result.bits[1] = 1621842184u;
  true_result.bits[2] = 843268356;
  true_result.bits[3] = 1835008;
  int status = s21_div(decimal_1, decimal_2, &result);
  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(result, true_result));
  ck_assert_int_eq(status, true_status);
}
END_TEST
START_TEST(test_s21_div_4) {  // strange
  s21_decimal decimal_1 = smallInit();
  s21_decimal decimal_2 = smallInit();
  s21_decimal result = smallInit();

  decimal_1.bits[0] = 14;
  decimal_1.bits[3] = 65536;
  decimal_2.bits[0] = 9;
  decimal_2.bits[3] = 65536 + MINUS;

  s21_decimal true_result;
  true_result.bits[0] = 3280877794u;
  true_result.bits[1] = 1621842184u;
  true_result.bits[2] = 843268356u;
  true_result.bits[3] = 1835008 + MINUS;
  int status = s21_div(decimal_1, decimal_2, &result);
  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(result, true_result));
  ck_assert_int_eq(status, true_status);
}
END_TEST

START_TEST(test_s21_div_5) {
  s21_decimal decimal_1 = smallInit();
  s21_decimal decimal_2 = smallInit();
  s21_decimal result = smallInit();
  decimal_1.bits[0] = 2814903;
  decimal_1.bits[3] = 65536;
  decimal_2.bits[0] = 0;
  decimal_2.bits[3] = 65536 + MINUS;
  int status = s21_div(decimal_1, decimal_2, &result);
  int true_status = 3;
  ck_assert_int_eq(status, true_status);
}
END_TEST
START_TEST(test_s21_div_6) {
  s21_decimal decimal_1 = smallInit();
  s21_decimal decimal_2 = smallInit();
  s21_decimal result = smallInit();
  decimal_1.bits[0] = 0;
  decimal_1.bits[3] = 65536;
  decimal_2.bits[0] = 4578783;
  s21_decimal true_result;
  true_result.bits[0] = 0;
  true_result.bits[1] = 0;
  true_result.bits[2] = 0;
  true_result.bits[3] = 0;
  int status = s21_div(decimal_1, decimal_2, &result);
  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(result, true_result));
  ck_assert_int_eq(status, true_status);
}
END_TEST
START_TEST(test_s21_div_7) {
  s21_decimal decimal_1 = smallInit();
  s21_decimal decimal_2 = smallInit();
  s21_decimal result;

  decimal_2.bits[0] = 4294967294u;
  decimal_2.bits[1] = 4294967295u;
  decimal_2.bits[2] = 4294967295u;
  decimal_1.bits[0] = 1;
  decimal_1.bits[3] = 1179648;

  int status = s21_div(decimal_1, decimal_2, &result);
  int true_status = 0;
  ck_assert_int_eq(status, true_status);
}
END_TEST
START_TEST(test_s21_div_8) {
  s21_decimal decimal_1 = smallInit();
  s21_decimal decimal_2 = smallInit();
  s21_decimal result = {{0, 0, 0, 0}};
  decimal_1.bits[0] = 4294967295u;
  decimal_1.bits[1] = 4294967295u;
  decimal_1.bits[2] = 4294967295u;
  decimal_1.bits[3] = 1179648;
  decimal_2.bits[0] = 1;
  decimal_2.bits[3] = 1179648;

  int status = s21_div(decimal_1, decimal_2, &result);
  s21_decimal true_result = {{0, 0, 0, 0}};

  true_result.bits[0] = 4294967295u;
  true_result.bits[1] = 4294967295u;
  true_result.bits[2] = 4294967295u;
  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(result, true_result));
  ck_assert_int_eq(status, true_status);
}
END_TEST
START_TEST(test_s21_div_9) {
  s21_decimal decimal_1 = smallInit();
  s21_decimal decimal_2 = smallInit();
  s21_decimal result;

  decimal_1.bits[0] = 1996679748u;
  decimal_1.bits[1] = 4232406046u;
  decimal_1.bits[2] = 151016884;
  decimal_1.bits[3] = 2148335616u;

  decimal_2.bits[0] = 2671657829u;
  decimal_2.bits[1] = 165868194;
  decimal_2.bits[2] = 0;
  decimal_2.bits[3] = 327680;

  s21_decimal true_result;
  true_result.bits[0] = 178532910;
  true_result.bits[1] = 4081246736u;
  true_result.bits[2] = 2119837296u;
  true_result.bits[3] = 2149253120u;

  int status = s21_div(decimal_1, decimal_2, &result);
  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(result, true_result));
  ck_assert_int_eq(status, true_status);
}
END_TEST
START_TEST(test_s21_div_11) {
  s21_decimal decimal_1 = smallInit();
  s21_decimal decimal_2 = smallInit();
  s21_decimal result = smallInit();

  decimal_1.bits[0] = 6;
  decimal_1.bits[1] = 0;
  decimal_1.bits[2] = 0;
  decimal_1.bits[3] = 65536;

  decimal_2.bits[0] = 6;
  decimal_2.bits[1] = 0;
  decimal_2.bits[2] = 0;
  decimal_2.bits[3] = 0;

  s21_decimal true_result = smallInit();

  true_result.bits[0] = 1;
  true_result.bits[1] = 0;
  true_result.bits[2] = 0;
  true_result.bits[3] = 65536;

  int status = s21_div(decimal_1, decimal_2, &result);
  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(result, true_result));
  ck_assert_int_eq(status, true_status);
}
END_TEST
START_TEST(test_s21_div_12) {
  s21_decimal decimal_1 = smallInit();
  s21_decimal decimal_2 = smallInit();
  s21_decimal result = smallInit();

  decimal_1.bits[0] = 6;
  decimal_1.bits[1] = 0;
  decimal_1.bits[2] = 0;
  decimal_1.bits[3] = 0;

  decimal_2.bits[0] = 6;
  decimal_2.bits[1] = 0;
  decimal_2.bits[2] = 0;
  decimal_2.bits[3] = 65536;

  s21_decimal true_result = smallInit();

  true_result.bits[0] = 10;
  true_result.bits[1] = 0;
  true_result.bits[2] = 0;
  true_result.bits[3] = 0;

  int status = s21_div(decimal_1, decimal_2, &result);
  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(result, true_result));
  ck_assert_int_eq(status, true_status);
}
END_TEST
START_TEST(test_s21_div_10) {
  s21_decimal decimal_1 = smallInit();
  s21_decimal decimal_2 = smallInit();
  s21_decimal result = smallInit();

  decimal_1.bits[0] = 1188260494u;
  decimal_1.bits[1] = 2547073670u;
  decimal_1.bits[2] = 423;
  decimal_1.bits[3] = 786432;

  decimal_2.bits[0] = 1658453339u;
  decimal_2.bits[1] = 2896612263u;
  decimal_2.bits[2] = 67010;
  decimal_2.bits[3] = 786432;

  s21_decimal true_result = smallInit();

  true_result.bits[0] = 2998137794u;
  true_result.bits[1] = 614149364;
  true_result.bits[2] = 3426771;
  true_result.bits[3] = 1835008;

  int status = s21_div(decimal_1, decimal_2, &result);
  int true_status = 0;
  ck_assert_int_eq(1, s21_is_equal(result, true_result));
  ck_assert_int_eq(status, true_status);
}
END_TEST

Suite *s21_arithmetics_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("S21 Arithmetics");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_s21_add_1);
  tcase_add_test(tc_core, test_s21_add_2);
  tcase_add_test(tc_core, test_s21_add_3);
  tcase_add_test(tc_core, test_s21_add_4);
  tcase_add_test(tc_core, test_s21_add_5);
  tcase_add_test(tc_core, test_s21_add_6);
  tcase_add_test(tc_core, test_s21_add_7);
  tcase_add_test(tc_core, test_s21_add_8);
  tcase_add_test(tc_core, test_s21_add_9);
  tcase_add_test(tc_core, test_s21_add_10);
  tcase_add_test(tc_core, test_s21_add_11);
  tcase_add_test(tc_core, test_s21_add_12);
  tcase_add_test(tc_core, test_s21_add_13);
  tcase_add_test(tc_core, test_s21_add_14);
  tcase_add_test(tc_core, test_s21_add_15);
  tcase_add_test(tc_core, test_s21_add_16);
  tcase_add_test(tc_core, test_s21_add_17);

  tcase_add_test(tc_core, test_s21_sub_1);
  tcase_add_test(tc_core, test_s21_sub_2);
  tcase_add_test(tc_core, test_s21_sub_3);
  tcase_add_test(tc_core, test_s21_sub_4);
  tcase_add_test(tc_core, test_s21_sub_5);
  tcase_add_test(tc_core, test_s21_sub_6);
  tcase_add_test(tc_core, test_s21_sub_7);
  tcase_add_test(tc_core, test_s21_sub_8);
  tcase_add_test(tc_core, test_s21_sub_9);
  tcase_add_test(tc_core, test_s21_sub_10);
  tcase_add_test(tc_core, test_s21_sub_11);
  tcase_add_test(tc_core, test_s21_sub_12);
  tcase_add_test(tc_core, test_s21_sub_13);
  tcase_add_test(tc_core, test_s21_sub_14);
  tcase_add_test(tc_core, test_s21_sub_15);
  tcase_add_test(tc_core, test_s21_sub_16);
  tcase_add_test(tc_core, test_s21_sub_17);

  tcase_add_test(tc_core, test_s21_mul_1);
  tcase_add_test(tc_core, test_s21_mul_2);
  tcase_add_test(tc_core, test_s21_mul_3);
  tcase_add_test(tc_core, test_s21_mul_4);
  tcase_add_test(tc_core, test_s21_mul_5);
  tcase_add_test(tc_core, test_s21_mul_6);
  tcase_add_test(tc_core, test_s21_mul_7);
  tcase_add_test(tc_core, test_s21_mul_8);
  tcase_add_test(tc_core, test_s21_mul_9);
  tcase_add_test(tc_core, test_s21_mul_10);
  tcase_add_test(tc_core, test_s21_mul_11);
  tcase_add_test(tc_core, test_s21_mul_12);
  tcase_add_test(tc_core, test_s21_mul_13);
  tcase_add_test(tc_core, test_s21_mul_14);
  tcase_add_test(tc_core, test_s21_mul_15);
  tcase_add_test(tc_core, test_s21_mul_16);
  tcase_add_test(tc_core, test_s21_mul_17);
  tcase_add_test(tc_core, test_s21_mul_18);
  tcase_add_test(tc_core, test_s21_mul_19);
  tcase_add_test(tc_core, test_s21_mul_20);
  tcase_add_test(tc_core, test_s21_mul_21);
  tcase_add_test(tc_core, test_s21_mul_22);
  tcase_add_test(tc_core, test_s21_mul_23);
  tcase_add_test(tc_core, test_s21_div_1);
  tcase_add_test(tc_core, test_s21_div_2);
  tcase_add_test(tc_core, test_s21_div_3);
  tcase_add_test(tc_core, test_s21_div_4);
  tcase_add_test(tc_core, test_s21_div_5);
  tcase_add_test(tc_core, test_s21_div_6);
  tcase_add_test(tc_core, test_s21_div_7);
  tcase_add_test(tc_core, test_s21_div_8);
  tcase_add_test(tc_core, test_s21_div_9);
  tcase_add_test(tc_core, test_s21_div_10);
  tcase_add_test(tc_core, test_s21_div_11);
  tcase_add_test(tc_core, test_s21_div_12);

  tcase_add_test(tc_core, test_add);
  tcase_add_test(tc_core, test_sub);
  tcase_add_test(tc_core, test_mul);
  tcase_add_test(tc_core, test_divmod);
  suite_add_tcase(s, tc_core);

  return s;
}

int test_arithmetics() {
  int no_failed = 0;

  Suite *s;
  SRunner *runner;

  s = s21_arithmetics_suite();
  runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);
  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);

  return no_failed;
}
