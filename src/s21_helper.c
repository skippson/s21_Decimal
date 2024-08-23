#include "s21_decimal.h"

int is_mantis_equal(s21_big_decimal decimal1, s21_big_decimal decimal2) {
  int res = 1;
  for (int i = 0; i < 7; i++) {
    if (decimal1.bits[i] == decimal2.bits[i]) {
      continue;
    } else {
      res = 0;
    }
  }
  return res;
}

int is_mantis_less(s21_big_decimal decimal1, s21_big_decimal decimal2) {
  int res = 0;
  for (int i = 0; i < 7; i++) {
    if (decimal1.bits[i] == decimal2.bits[i]) {
      continue;
    } else {
      res = (unsigned)decimal1.bits[i] < (unsigned)decimal2.bits[i] ? 1 : 0;
    }
  }
  return res;
}

int getSign(s21_decimal value) {
  int result = (int)(((unsigned)value.bits[3] >> 31) & 1u);
  return result;
}

void setSign(s21_decimal *value, int sign) {
  if (sign) {
    value->bits[3] = 2147483648U | value->bits[3];
  } else {
    value->bits[3] = value->bits[3] & ~(2147483648U);
  }
}

int getScale(s21_decimal value) {
  setSign(&value, 0);
  (value.bits[3]) >>= 16;
  int scale = value.bits[3] & 0b1000000000011111;
  return scale;
}

void setScale(s21_decimal *value, int scale) {
  int sign = getSign(*value);
  if (scale >= 0 && scale <= 28) {
    value->bits[3] = 0;
    scale <<= 16;
    value->bits[3] |= scale;
  }
  if (sign) setSign(value, 1);
}

int getBit(s21_decimal value, int bit) {
  return (value.bits[bit / 32] & (1u << (bit - 32 * (bit / 32)))) > 0;
}

void setBit(s21_decimal *decimal, int bit, int val) {
  if (getBit(*decimal, bit) && val == 0) {
    decimal->bits[bit / 32] &= ~(1u << 31 | 1 << (bit - 32 * (bit / 32)));
  } else if (!getBit(*decimal, bit) && val == 1) {
    decimal->bits[bit / 32] |= 1 << (bit - 32 * (bit / 32));
  }
}

int getbigSign(s21_big_decimal value) {
  int result = !!(value.bits[3] & (1u));
  return result;
}

void setbigSign(s21_big_decimal *value, int sign) {
  if (sign) {
    value->bits[3] = 1 | value->bits[3];
  } else {
    value->bits[3] = value->bits[3] >> 1 << 1;
  }
}

int getbigScale(s21_big_decimal value) {
  int scale = (value.bits[7] & 2147483647) >> 16;
  return scale;
}

void setbigScale(s21_big_decimal *value, int scale) {
  int sign = getbigSign(*value);
  if (scale >= 0 && scale <= 28) {
    value->bits[7] = 0;
    scale <<= 16;
    value->bits[7] |= scale;
  }
  if (sign) setbigSign(value, 1);
}

int getbigBit(s21_big_decimal value, int bit) {
  return (value.bits[bit / 32] & (1u << (bit - 32 * (bit / 32)))) > 0;
}

void setbigBit(s21_big_decimal *big_decimal, int bit, int val) {
  if (getbigBit(*big_decimal, bit) && val == 0) {
    big_decimal->bits[bit / 32] &= ~(1u << 31 | 1 << (bit - 32 * (bit / 32)));
  } else if (!getbigBit(*big_decimal, bit) && val == 1) {
    big_decimal->bits[bit / 32] |= 1 << (bit - 32 * (bit / 32));
  }
}

s21_big_decimal shift_left(s21_big_decimal value, int val_shift) {
  unsigned boolean = 0;
  for (int i = 0; i < 7; i++) {
    unsigned tmp = value.bits[i];

    value.bits[i] <<= val_shift;
    value.bits[i] |= boolean;
    boolean = (tmp >> (32 - val_shift));
  }
  return value;
}

s21_big_decimal bigInit() {
  s21_big_decimal dec = {{0, 0, 0, 0, 0, 0, 0, 0}};
  return dec;
}
s21_decimal smallInit() {
  s21_decimal dec = {{0, 0, 0, 0}};
  return dec;
}

void make_zero(s21_decimal *dec) {
  for (int i = 0; i < 4; i++) {
    dec->bits[i] = 0u;
  }
}

s21_big_decimal bigConvert(s21_decimal value_1) {
  s21_big_decimal big = {{value_1.bits[0], value_1.bits[1], value_1.bits[2], 0,
                          0, 0, 0, value_1.bits[3]}};
  return big;
}

void s21_decimal_init(s21_decimal *dst) {
  dst->bits[0] = 0;
  dst->bits[1] = 0;
  dst->bits[2] = 0;
  dst->bits[3] = 0;
}

bool s21_decimal_is_zero(s21_decimal dst) {
  bool status = false;
  if (dst.bits[0] == 0 && dst.bits[1] == 0 && dst.bits[2] == 0) {
    status = true;
  }
  return status;
}

bool s21_big_decimal_zero(s21_big_decimal dst) {
  bool status = false;
  if (dst.bits[0] == 0 && dst.bits[1] == 0 && dst.bits[2] == 0 &&
      dst.bits[3] == 0 && dst.bits[4] == 0 && dst.bits[5] == 0 &&
      dst.bits[6] == 0) {
    status = true;
  }
  return status;
}

void make_null_big_decimal(s21_big_decimal *dec) {
  for (int i = 0; i < 8; i++) {
    dec->bits[i] = 0;
  }
}

s21_big_decimal shift_ten(s21_big_decimal value_1) {
  bitwise_add(shift_left(value_1, 3), shift_left(value_1, 1), &value_1);
  return value_1;
}

void s21_decimal_get_inf(s21_decimal *dst) {
  dst->bits[0] = 0xFFFFFFFF;
  dst->bits[1] = 0xFFFFFFFF;
  dst->bits[2] = 0xFFFFFFFF;
  dst->bits[3] = 0xFFFFFFFF;
}

void s21_decimal_get_zero(s21_decimal *dst) {
  dst->bits[0] = 0;
  dst->bits[1] = 0;
  dst->bits[2] = 0;
  dst->bits[3] = 0;
}