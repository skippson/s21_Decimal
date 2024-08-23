#include "s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  bool status = OK;
  if (result == NULL) {
    status = ERR_OVERFLOW;
  } else {
    float tmp = 0;
    s21_from_decimal_to_float(value, &tmp);
    tmp = floorf(tmp);
    s21_from_float_to_decimal(tmp, result);
  }

  return status;
}

int s21_truncate(s21_decimal value,
                 s21_decimal *result) {  // fixed check on bits[0] < 10
  s21_big_decimal val1 = bigConvert(value);
  s21_big_decimal val2 = bigInit();
  s21_big_decimal res_big = bigInit();
  val2.bits[0] = 10u;
  int res = 0;
  if (result) {
    int scale = getScale(value);
    int sign = getSign(value);
    for (int i = 0; i < scale; i++) {
      // printf("val %u %u %u", val1.bits[0], val1.bits[1], val1.bits[2]);
      if ((unsigned)val1.bits[0] < 10u && val1.bits[1] == 0 &&
          val1.bits[2] == 0) {
        // printf("f\n");
        make_null_big_decimal(&val1);
      } else {
        // printf("s\n");
        div_without_left(val1, val2, &res_big);
        val1 = res_big;
      }
    }
    for (int i = 0; i < 3; i++) {
      result->bits[i] = val1.bits[i];
    }
    setScale(result, 0);
    setSign(result, sign);
  } else {
    res = 1;
  }
  return res;
}

int s21_round(s21_decimal value, s21_decimal *result) {  // fixed
  s21_big_decimal val1 = bigConvert(value);
  s21_big_decimal val2 = bigInit();
  s21_big_decimal res_big = bigInit();
  int scale = getScale(value);
  int sign = getSign(value);
  val2.bits[0] = 10u;
  for (int i = 0; i < scale; i++) {
    if (i == scale - 1) {
      div_without_left(val1, val2, &res_big);
      unsigned int remainder = (unsigned)val1.bits[0] % 10;
      // printf("remainder %u\n", remainder);
      if (remainder >= 5u) {
        //   if ((unsigned)res_big.bits[0] + 1u < (unsigned)res_big.bits[0]) {
        //     if ((unsigned)res_big.bits[1] + 1u < (unsigned)res_big.bits[1]) {
        //       res_big.bits[2] += 1u;
        //     } else {
        //       res_big.bits[1] += 1u;
        //     }
        //   } else {
        //     res_big.bits[0] += 1u;
        //   }
        val2.bits[0] = 1u;
        bitwise_add(res_big, val2, &res_big);
      }
    } else {
      div_without_left(val1, val2, &res_big);
    }
    val1 = res_big;
  }

  for (int i = 0; i < 4; i++) {
    result->bits[i] = val1.bits[i];
  }
  setSign(result, sign);
  setScale(result, 0);

  return 0;
}

int s21_negate(s21_decimal value, s21_decimal *result) {  // FIXED
  if (s21_decimal_is_zero(value) == false) {
    int value_sign = getSign(value);
    *result = value;
    if (value_sign == 1) {
      setSign(result, 0);
    } else {
      setSign(result, 1);
    }
  }
  return 0;
}