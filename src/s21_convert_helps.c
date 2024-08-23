#include "s21_decimal.h"

s21_decimal get_powten_decimal(int index) { return decimal_ten_powers[index]; }

s21_decimal s21_float_string_to_decimal(char *str) {
  s21_decimal res;
  s21_decimal_init(&res);
  int index_str = 6;
  char *ptr = str;
  int scale = scale_from_str(str);
  while (*ptr) {
    if (*ptr == '.') {
      ++ptr;
      continue;
    } else if (*ptr >= '0' && *ptr <= '9') {
      s21_decimal tmp;
      s21_decimal_init(&tmp);
      s21_mul(s21_decimal_get_from_char(*ptr), get_powten_decimal(index_str),
              &tmp);
      s21_add(res, tmp, &res);
      --index_str;
      ++ptr;
    } else {
      break;
    }
  }
  scale -= 6;
  if (scale > 0) {
    s21_mul(res, get_powten_decimal(scale), &res);
  } else if (scale < 0) {
    if (scale < -28) {
      s21_div(res, get_powten_decimal(28), &res);
      scale += 28;
    }
    s21_div(res, get_powten_decimal(-scale), &res);
  }

  return res;
}

s21_decimal s21_decimal_get_from_char(char c) {
  s21_decimal res;

  switch (c) {
    case '0':
      s21_decimal_init(&res);
      break;
    case '1':
      s21_decimal_init(&res);
      res.bits[0] = 1;
      break;
    case '2':
      s21_from_int_to_decimal(2, &res);
      break;
    case '3':
      s21_from_int_to_decimal(3, &res);
      break;
    case '4':
      s21_from_int_to_decimal(4, &res);
      break;
    case '5':
      s21_from_int_to_decimal(5, &res);
      break;
    case '6':
      s21_from_int_to_decimal(6, &res);
      break;
    case '7':
      s21_from_int_to_decimal(7, &res);
      break;
    case '8':
      s21_from_int_to_decimal(8, &res);
      break;
    case '9':
      s21_from_int_to_decimal(9, &res);
      break;
  }

  return res;
}

int scale_from_str(char *str) {
  int res = 0;
  char *ptr = str;

  while (*ptr) {
    if (*ptr == 'E') {
      ++ptr;
      res = strtol(ptr, NULL, 10);
      break;
    }
    ++ptr;
  }

  return res;
}