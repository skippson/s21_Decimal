#ifndef S21_HELPER_H
#define S21_HELPER_H

#include "s21_decimal.h"

static const s21_decimal decimal_ten_powers[39] = {
    [0] = {{0x1, 0x0, 0x0, 0x0}},
    [1] = {{0xA, 0x0, 0x0, 0x0}},
    [2] = {{0x64, 0x0, 0x0, 0x0}},
    [3] = {{0x3E8, 0x0, 0x0, 0x0}},
    [4] = {{0x2710, 0x0, 0x0, 0x0}},
    [5] = {{0x186A0, 0x0, 0x0, 0x0}},
    [6] = {{0xF4240, 0x0, 0x0, 0x0}},
    [7] = {{0x989680, 0x0, 0x0, 0x0}},
    [8] = {{0x5F5E100, 0x0, 0x0, 0x0}},
    [9] = {{0x3B9ACA00, 0x0, 0x0, 0x0}},
    [10] = {{0x540BE400, 0x2, 0x0, 0x0}},
    [11] = {{0x4876E800, 0x17, 0x0, 0x0}},
    [12] = {{0xD4A51000, 0xE8, 0x0, 0x0}},
    [13] = {{0x4E72A000, 0x918, 0x0, 0x0}},
    [14] = {{0x107A4000, 0x5AF3, 0x0, 0x0}},
    [15] = {{0xA4C68000, 0x38D7E, 0x0, 0x0}},
    [16] = {{0x6FC10000, 0x2386F2, 0x0, 0x0}},
    [17] = {{0x5D8A0000, 0x1634578, 0x0, 0x0}},
    [18] = {{0xA7640000, 0xDE0B6B3, 0x0, 0x0}},
    [19] = {{0x89E80000, 0x8AC72304, 0x0, 0x0}},
    [20] = {{0x63100000, 0x6BC75E2D, 0x5, 0x0}},
    [21] = {{0xDEA00000, 0x35C9ADC5, 0x36, 0x0}},
    [22] = {{0xB2400000, 0x19E0C9BA, 0x21E, 0x0}},
    [23] = {{0xF6800000, 0x2C7E14A, 0x152D, 0x0}},
    [24] = {{0xA1000000, 0x1BCECCED, 0xD3C2, 0x0}},
    [25] = {{0x4A000000, 0x16140148, 0x84595, 0x0}},
    [26] = {{0xE4000000, 0xDCC80CD2, 0x52B7D2, 0x0}},
    [27] = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x0}},
    [28] = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x0}},
    [29] = {{0xA0000000, 0x6D7217CA, 0x431E0FAE, 0x1}},
    [30] = {{0x40000000, 0x4674EDEA, 0x9F2C9CD0, 0xC}},
    [31] = {{0x80000000, 0xC0914B26, 0x37BE2022, 0x7E}},
    [32] = {{0x0, 0x85ACEF81, 0x2D6D415B, 0x4EE}},
    [33] = {{0x0, 0x38C15B0A, 0xC6448D93, 0x314D}},
    [34] = {{0x0, 0x378D8E64, 0xBEAD87C0, 0x1ED09}},
    [35] = {{0x0, 0x2B878FE8, 0x72C74D82, 0x134261}},
    [36] = {{0x0, 0xB34B9F10, 0x7BC90715, 0xC097CE}},
    [37] = {{0x0, 0xF436A0, 0xD5DA46D9, 0x785EE10}},
    [38] = {{0x0, 0x98A2240, 0x5A86C47A, 0x4B3B4CA8}}};

s21_decimal get_powten_decimal(int index);
s21_decimal s21_float_string_to_decimal(char *str);
s21_decimal s21_decimal_get_from_char(char c);
int scale_from_str(char *str);
void setScale(s21_decimal *value, int scale);
int getScale(s21_decimal value);
void setSign(s21_decimal *value, int sign);
int getSign(s21_decimal value);
void setBit(s21_decimal *decimal, int bit, int val);
int getBit(s21_decimal value, int bit);
void setbigScale(s21_big_decimal *value, int scale);
int getbigScale(s21_big_decimal value);
void setbigSign(s21_big_decimal *value, int sign);
int getbigSign(s21_big_decimal value);
void setbigBit(s21_big_decimal *big_decimal, int bit, int val);
int getbigBit(s21_big_decimal value, int bit);
void bitwise_add(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result);
void bitwise_sub(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result);
s21_big_decimal shift_left(s21_big_decimal value, int val_shift);
s21_big_decimal bigInit();
void s21_decimal_init(s21_decimal *dst);
void normalization(s21_big_decimal *value_1, int norm_val);
int is_mantis_less(s21_big_decimal decimal1, s21_big_decimal decimal2);
s21_big_decimal bigConvert(s21_decimal value_1);
void bitwise_mul(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result);
int is_mantis_equal(s21_big_decimal decimal1, s21_big_decimal decimal2);
bool s21_decimal_is_zero(s21_decimal dst);
void s21_decimal_get_inf(s21_decimal *dst);
void s21_decimal_get_zero(s21_decimal *dst);
bool s21_big_decimal_zero(s21_big_decimal dst);
void make_null_big_decimal(s21_big_decimal *dec);
void bitwise_div(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result, int *err);
s21_big_decimal shift_ten(s21_big_decimal value_1);
void div_help(s21_big_decimal *tmp1, s21_big_decimal *tmp2, int *scale,
              s21_big_decimal *change_res, s21_big_decimal *final_res, int *err,
              s21_big_decimal *tmp_res, s21_big_decimal *left);

void div_without_left(s21_big_decimal value_1, s21_big_decimal value_2,
                      s21_big_decimal *result);
void make_scale_less(s21_big_decimal *res_big);
void check_scale_and_mantis(s21_big_decimal *res_big, int *scale, int *sign,
                            int *err);
void make_zero(s21_decimal *dec);
s21_decimal smallInit();

#endif
