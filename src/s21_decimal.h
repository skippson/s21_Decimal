#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "s21_helper.h"

#ifndef S21_DECIMAL_H
#define S21_DECIMAL_H

#define MAX 0xffffffff
#define SIGN 2147483648U
#define SCALE 3
#define OK 0
#define ERR_OVERFLOW 1
#define ERR_UNDERFLOW 2
#define ERR_ZERO_DIV 3
#define true 1
#define false 0
#define MAX_FLOAT_TO_CONVERT 79228157791897854723898736640.0f
#define MIN_FLOAT_TO_CONVERT \
  0.00000000000000000000000000010000000031710768509710513471352647538147514756461109f
#define MINUS 0b10000000000000000000000000000000
typedef int bool;

typedef struct {
  int bits[4];
} s21_decimal;

typedef struct {
  int bits[8];
} s21_big_decimal;

// Сложение двух decimal
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Вычитание двух decimal
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Умножение двух decimal
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Деление двух decimal
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);

// Меньше
int s21_is_less(s21_decimal decimal1, s21_decimal decimal2);

// Меньше или равно
int s21_is_less_or_equal(s21_decimal decimal1, s21_decimal decimal2);

// Больше
int s21_is_greater(s21_decimal decimal1, s21_decimal decimal2);

// Больше или равно
int s21_is_greater_or_equal(s21_decimal decimal1, s21_decimal decimal2);

// Равно
int s21_is_equal(s21_decimal decimal1, s21_decimal decimal2);

// Не равно
int s21_is_not_equal(s21_decimal decimal1, s21_decimal decimal2);

// Перевод из int
int s21_from_int_to_decimal(int src, s21_decimal *dst);

// Перевод из float
int s21_from_float_to_decimal(float src, s21_decimal *dst);

// Перевод в int
int s21_from_decimal_to_int(s21_decimal src, int *dst);

// Перевод в float
int s21_from_decimal_to_float(s21_decimal src, float *dst);

// Округляет указанное Decimal число до ближайшего целого числа в сторону
// отрицательной бесконечности.
int s21_floor(s21_decimal value, s21_decimal *result);

// Округляет Decimal до ближайшего целого числа.
int s21_round(s21_decimal value, s21_decimal *result);

// Возвращает целые цифры указанного Decimal числа; любые дробные цифры
// отбрасываются, включая конечные нули.
int s21_truncate(s21_decimal value, s21_decimal *result);

// Возвращает результат умножения указанного Decimal на -1.
int s21_negate(s21_decimal value, s21_decimal *result);

#endif