#include "s21_decimal.h"

int s21_from_int_to_decimal(int src, s21_decimal *dst) {
  bool status = OK;
  if (dst == NULL) {
    status = ERR_OVERFLOW;
  } else {
    s21_decimal_init(dst);
    if (src < 0) {
      src *= -1;
      setSign(dst, 1);
    }
    dst->bits[0] = src;
  }

  return status;
}

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  bool status = OK;
  s21_truncate(src, &src);
  if (src.bits[1] != 0 || src.bits[2] != 0) {
    status = ERR_OVERFLOW;
  } else if (dst == NULL) {
    status = ERR_OVERFLOW;
  } else {
    *dst = src.bits[0];
    if (getSign(src) == 1) {
      *dst *= -1;
    }
  }
  return status;
}

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  bool status = OK;
  bool minus = false;
  if (src < 0) {
    minus = true;
  }
  if (dst == NULL) {
    status = ERR_OVERFLOW;
  } else {
    if (src == 0.0) {
      s21_decimal_init(dst);
    } else if (isinf(src) || isnan(src)) {
      status = ERR_OVERFLOW;
      s21_decimal_get_inf(dst);
      if (signbit(src) != 0) {
        setSign(dst, 1);
      }
    } else if (fabsf(src) > MAX_FLOAT_TO_CONVERT) {
      status = ERR_OVERFLOW;
      s21_decimal_get_inf(dst);
      if (signbit(src) != 0) {
        setSign(dst, 1);
      }
    } else if (fabsf(src) < MIN_FLOAT_TO_CONVERT) {
      status = ERR_OVERFLOW;
      s21_decimal_get_zero(dst);
      if (minus == true) {
        setSign(dst, 1);
      }
    } else {
      s21_decimal_init(dst);
      char res[64];
      sprintf(res, "%.6E", fabsf(src));
      int scale = scale_from_str(res);
      if (scale <= -23) {
        scale += 28;
        sprintf(res, "%.*E", scale, fabsf(src));
      }

      *dst = s21_float_string_to_decimal(res);

      if (minus == true) {
        setSign(dst, 1);
      }
    }
  }

  return status;
}

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  bool status = OK;
  bool minus = getSign(src);
  if (dst == NULL) {
    status = ERR_OVERFLOW;
  } else {
    if (s21_decimal_is_zero(src) == true) {
      if (minus == true) {
        *dst = -0.0;
      } else {
        *dst = 0.0;
      }
    } else {
      double res = 0.0;
      for (int i = 0; i < 96; i++) {
        if (getBit(src, i) != 0) {
          res += pow(2.0, i);
        }
      }
      int scale = getScale(src);
      double res_scale = pow(10, scale);
      res /= res_scale;
      if (minus == true) {
        res *= -1;
      }
      *dst = (float)res;
    }
  }

  return status;
}