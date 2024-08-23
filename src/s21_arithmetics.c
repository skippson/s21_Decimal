#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  make_zero(result);
  s21_big_decimal value_big_1 = bigConvert(value_1);
  s21_big_decimal value_big_2 = bigConvert(value_2);
  s21_big_decimal res_big = bigInit();
  int err = 0;
  int scale_1 = getScale(value_1);
  int scale_2 = getScale(value_2);
  int scale = scale_1;
  if ((scale_1 - scale_2) <= 0) {
    normalization(&value_big_1, -1 * (scale_1 - scale_2));
    scale = scale_2;
  } else {
    normalization(&value_big_2, (scale_1 - scale_2));
  }
  int sign1 = getSign(value_1);
  int sign2 = getSign(value_2);
  int sign = sign1;

  if ((sign1 && !sign2) || (!sign1 && sign2)) {
    bitwise_add(value_big_1, value_big_2, &res_big);
    if (sign1 == 0) {
      sign = 0;
    }
  } else {
    if (is_mantis_less(value_big_1, value_big_2)) {
      bitwise_sub(value_big_2, value_big_1, &res_big);
      sign = sign2 == 1 ? 0 : 1;
      for (int i = 0; i < 4; i++) {
      }
    } else {
      bitwise_sub(value_big_1, value_big_2, &res_big);
      sign = sign1 == 1 ? 1 : 0;
      for (int i = 0; i < 4; i++) {
      }
    }
  }

  check_scale_and_mantis(&res_big, &scale, &sign, &err);
  if (!err)
    for (int i = 0; i < 3; i++) {
      result->bits[i] |= res_big.bits[i];
    }

  if (!s21_decimal_is_zero(*result)) {
    setScale(result, scale);
    setSign(result, sign);
  }
  return err;
}

void check_scale_and_mantis(s21_big_decimal *res_big, int *scale, int *sign,
                            int *err) {
  s21_big_decimal bit1 = bigInit();
  bit1.bits[0] = 1u;
  s21_big_decimal buff_res_big = *res_big;
  unsigned int low = 0;
  while (*scale > 28) {
    low = (unsigned)res_big->bits[0] % 10u;
    make_scale_less(res_big);
    *scale = *scale - 1;
  }

  if ((((unsigned)res_big->bits[0] % 10) % 2 == 0 && low > 5) ||
      (((unsigned)res_big->bits[0] % 10) % 2 == 1 && low > 4)) {
    bitwise_add(*res_big, bit1, &buff_res_big);
    *res_big = buff_res_big;
  }
  low = 0;

  for (int i = 3; i < 7; i++) {
    while (res_big->bits[i] != 0U && *scale != 0U) {
      low = (unsigned)res_big->bits[0];
      make_scale_less(res_big);
      *scale = *scale - 1;
    }
  }
  if ((((unsigned)res_big->bits[0] % 10) % 2 == 0 && low % 10 > 5) ||
      (((unsigned)res_big->bits[0] % 10) % 2 == 1 && low % 10 > 4)) {
    bitwise_add(*res_big, bit1, &buff_res_big);
    *res_big = buff_res_big;
  }

  for (int i = 3; i < 7; i++) {
    if (res_big->bits[i] != 0U && *sign) {
      *err = 2;

    } else if (res_big->bits[i] != 0U && *sign == 0) {
      *err = 1;
    }
  }
  if (s21_big_decimal_zero(*res_big)) {
    setbigScale(res_big, 0);
    setbigSign(res_big, 0);
    *scale = 0;
    *sign = 0;
  }
}

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  make_zero(result);
  s21_big_decimal value_big_1 = bigConvert(value_1);
  s21_big_decimal value_big_2 = bigConvert(value_2);
  s21_big_decimal res_big = bigInit();
  int err = 0;
  int scale_1 = getScale(value_1);
  int scale_2 = getScale(value_2);
  int scale = scale_1;
  if ((scale_1 - scale_2) <= 0) {
    normalization(&value_big_1, -1 * (scale_1 - scale_2));
    scale = scale_2;
  } else {
    normalization(&value_big_2, (scale_1 - scale_2));
  }
  int sign1 = getSign(value_1);
  int sign2 = getSign(value_2);
  int sign = sign1;
  if ((!sign1 && !sign2) || (sign1 && sign2)) {
    bitwise_add(value_big_1, value_big_2, &res_big);
  } else {
    if (is_mantis_less(value_big_1, value_big_2)) {
      bitwise_sub(value_big_2, value_big_1, &res_big);
      sign = sign2 == 1 ? 1 : 0;

    } else {
      bitwise_sub(value_big_1, value_big_2, &res_big);
      sign = sign1 == 1 ? 1 : 0;
    }
  }
  check_scale_and_mantis(&res_big, &scale, &sign, &err);
  if (!err) {
    for (int i = 0; i < 3; i++) result->bits[i] |= res_big.bits[i];
    setScale(result, scale);
    setSign(result, sign);
  }

  return err;
}

void bitwise_add(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result) {
  *result = bigInit();
  unsigned int boolean = 0;
  for (int i = 0;
       i < 32 * (int)(sizeof(s21_big_decimal) / sizeof(unsigned) - 1); i++) {
    unsigned int res_bit =
        getbigBit(value_1, i) + getbigBit(value_2, i) + boolean;
    boolean = res_bit / 2;
    res_bit %= 2;
    setbigBit(result, i, res_bit);
  }
}

void bitwise_sub(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result) {
  unsigned boolean = 0;
  for (int i = 0;
       i < 32 * (int)(sizeof(s21_big_decimal) / sizeof(unsigned) - 1); i++) {
    int res_bit = getbigBit(value_1, i) - getbigBit(value_2, i) - boolean;
    boolean = (res_bit < 0) ? 1U : 0U;
    res_bit = ((res_bit == -1) || (res_bit == 1)) ? 1U : 0U;
    setbigBit(result, i, (unsigned)res_bit);
  }
}

void normalization(s21_big_decimal *value_1, int norm_val) {
  for (int i = 0; i < norm_val; i++) {
    *value_1 = shift_ten(*value_1);
  }
}

int s21_mul(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result) {  // FAIL
  make_zero(result);
  s21_big_decimal value_big_1 = bigConvert(value_1);
  s21_big_decimal value_big_2 = bigConvert(value_2);
  s21_big_decimal res_big = bigInit();
  int scale_1 = getScale(value_1);
  int scale_2 = getScale(value_2);
  int err = 0;
  int scale = scale_1 + scale_2;
  int sign1 = getSign(value_1);
  int sign2 = getSign(value_2);
  int sign = 0;
  if ((!sign1 && sign2) || (sign1 && !sign2)) {
    sign = 1;
  }
  if (is_mantis_less(value_big_1, value_big_2)) {
    bitwise_mul(value_big_2, value_big_1, &res_big);
  } else {
    bitwise_mul(value_big_1, value_big_2, &res_big);
  }

  check_scale_and_mantis(&res_big, &scale, &sign, &err);
  if (!err) {
    for (int i = 0; i < 3; i++) result->bits[i] |= res_big.bits[i];
  }
  if (!s21_decimal_is_zero(value_1) && !s21_decimal_is_zero(value_2)) {
    setScale(result, scale);
    setSign(result, sign);
  }

  return err;
}

void bitwise_mul(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result) {
  s21_big_decimal res_big = bigInit();
  unsigned int boolean = 0;
  for (int i = 0; i < 32 * 7; i++) {
    if (getbigBit(value_2, 32 * 7 - i - 1) || boolean) {
      boolean++;
      if (getbigBit(value_2, 32 * 7 - i - 1)) {
        // for (int i = 0; i < 7; i++) {
        bitwise_add(*result, value_1, &res_big);
        *result = res_big;
        // result->bits[i] += value_1.bits[i];
        // }
      }
      if (32 * 7 - i - 1 != 0) {
        *result = shift_left(*result, 1);
      }
    }
  }
}

int s21_div(s21_decimal value_1, s21_decimal value_2,
            s21_decimal *result) {  // fixed scal1 < scale2
  make_zero(result);
  s21_big_decimal value_big_1 = bigConvert(value_1);
  s21_big_decimal value_big_2 = bigConvert(value_2);
  s21_big_decimal res_big = bigInit();
  int scale_1 = getScale(value_1);
  int scale_2 = getScale(value_2);
  int err = 0;
  int sign1 = getSign(value_1);
  int sign2 = getSign(value_2);
  if (!s21_decimal_is_zero(value_1)) {
    int sign = 0;
    if ((!sign1 && sign2) || (sign1 && !sign2)) {
      sign = 1;
    }
    while (is_mantis_less(value_big_1, value_big_2)) {
      value_big_1 = shift_ten(value_big_1);
      scale_1++;
    }
    setbigScale(&value_big_1, scale_1);
    int scale = scale_1 - scale_2;
    while (scale_1 - scale_2 < 0) {
      value_big_1 = shift_ten(value_big_1);
      scale_1++;
    }
    setbigScale(&res_big, scale);
    if (!s21_decimal_is_zero(value_1)) {
      bitwise_div(value_big_1, value_big_2, &res_big, &err);
      if (err == 5) err = 0;
      scale = getbigScale(res_big);
      check_scale_and_mantis(&res_big, &scale, &sign, &err);
    }
    if (!err) {
      for (int i = 0; i < 3; i++) result->bits[i] |= res_big.bits[i];
      setScale(result, scale);
      setSign(result, sign);
    }
  }
  return err;
}

void make_scale_less(s21_big_decimal *res_big) {
  s21_big_decimal final_res = bigInit();
  s21_big_decimal ten = bigInit();
  ten.bits[0] = 10u;
  div_without_left(*res_big, ten, &final_res);
  *res_big = final_res;
}

void bitwise_div(s21_big_decimal value_1, s21_big_decimal value_2,
                 s21_big_decimal *result, int *err) {
  unsigned boolean = 0;
  int scale = getbigScale(*result);
  s21_big_decimal tmp1 = value_1;
  s21_big_decimal tmp2 = value_2;
  s21_big_decimal left = bigInit();
  s21_big_decimal change_res = bigInit();
  s21_big_decimal tmp_res = bigInit();
  s21_big_decimal final_res = bigInit();
  s21_big_decimal bit1 = bigInit();
  bit1.bits[0] = 1u;
  tmp_res.bits[0] = 1u;
  if (s21_big_decimal_zero(tmp2)) {
    *err = 3;
  }
  while ((!boolean || s21_big_decimal_zero(left) == false) && !*err) {
    if (boolean != 2) {
      boolean = 1;
    }
    if (is_mantis_less(shift_left(tmp2, 1), tmp1) && boolean != 2) {
      while (is_mantis_less(shift_left(tmp2, 1), tmp1)) {
        tmp2 = shift_left(tmp2, 1);
        tmp_res = shift_left(tmp_res, 1);
      }
      bitwise_sub(tmp1, tmp2, &left);
      tmp1 = left;
      if (is_mantis_less(tmp_res, change_res)) {
        bitwise_add(change_res, tmp_res, &final_res);
      } else {
        bitwise_add(tmp_res, change_res, &final_res);
      }

      change_res = final_res;
    } else if ((is_mantis_equal(tmp2, tmp1) || is_mantis_less(tmp2, tmp1)) &&
               boolean != 2) {
      bitwise_sub(tmp1, tmp2, &left);
      tmp1 = left;
      if (is_mantis_less(bit1, change_res)) {
        bitwise_add(change_res, bit1, &final_res);
      } else {
        bitwise_add(bit1, change_res, &final_res);
      }
      change_res = final_res;
    } else if (is_mantis_less(tmp1, tmp2) || boolean == 2) {
      boolean = 2;
      div_help(&tmp1, &tmp2, &scale, &change_res, &final_res, err, &tmp_res,
               &left);
    }
    tmp2 = value_2;
    tmp_res = bit1;
  }
  *result = final_res;
  setbigScale(result, scale);
}

void div_help(s21_big_decimal *tmp1, s21_big_decimal *tmp2, int *scale,
              s21_big_decimal *change_res, s21_big_decimal *final_res, int *err,
              s21_big_decimal *tmp_res, s21_big_decimal *left) {
  while (is_mantis_less(*tmp1, *tmp2) && *scale < 28) {
    *tmp1 = shift_ten(*tmp1);
    *change_res = shift_ten(*change_res);
    *scale += 1;
  }
  if (is_mantis_less(shift_left(*tmp2, 1), *tmp1)) {
    while (is_mantis_less(shift_left(*tmp2, 1), *tmp1)) {
      *tmp2 = shift_left(*tmp2, 1);
      *tmp_res = shift_left(*tmp_res, 1);
    }
  }
  bitwise_sub(*tmp1, *tmp2, left);
  if (is_mantis_less(*tmp_res, *change_res)) {
    bitwise_add(*change_res, *tmp_res, final_res);
  } else {
    bitwise_add(*tmp_res, *change_res, final_res);
  }
  *change_res = *final_res;
  if (*scale == 28 && !s21_big_decimal_zero(*left)) {
    *err = 5;
  }
  *tmp1 = *left;
}

void div_without_left(s21_big_decimal value_1, s21_big_decimal value_2,
                      s21_big_decimal *result) {
  unsigned boolean = 0;
  s21_big_decimal tmp1 = value_1;
  s21_big_decimal tmp2 = value_2;
  s21_big_decimal left = bigInit();
  s21_big_decimal change_res = bigInit();
  s21_big_decimal tmp_res = bigInit();
  s21_big_decimal final_res = bigInit();
  s21_big_decimal bit1 = bigInit();
  bit1.bits[0] = 1u;
  tmp_res.bits[0] = 1u;

  while ((!boolean || s21_big_decimal_zero(left) == false)) {
    boolean = 1;
    if (is_mantis_less(shift_left(tmp2, 1), tmp1)) {
      while (is_mantis_less(shift_left(tmp2, 1), tmp1)) {
        tmp2 = shift_left(tmp2, 1);
        tmp_res = shift_left(tmp_res, 1);
      }
      bitwise_sub(tmp1, tmp2, &left);
      tmp1 = left;
      if (is_mantis_less(tmp_res, change_res)) {
        bitwise_add(change_res, tmp_res, &final_res);
      } else {
        bitwise_add(tmp_res, change_res, &final_res);
      }

      change_res = final_res;
    } else if ((is_mantis_equal(tmp2, tmp1) || is_mantis_less(tmp2, tmp1))) {
      bitwise_sub(tmp1, tmp2, &left);
      tmp1 = left;
      if (is_mantis_less(bit1, change_res)) {
        bitwise_add(change_res, bit1, &final_res);
      } else {
        bitwise_add(bit1, change_res, &final_res);
      }
      change_res = final_res;
    } else if (is_mantis_less(tmp1, tmp2)) {
      make_null_big_decimal(&left);
    }
    tmp2 = value_2;
    tmp_res = bit1;
  }
  *result = final_res;
}