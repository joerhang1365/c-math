#ifndef FRACTION_H
#define FRACTION_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * Fraction: contains a numerator and a denominator.
 *
 * Formula: a / b
 */

typedef struct 
{
   int numerator;
   int denominator;
} fraction;

void fraction_create(fraction *f, int numerator, int denominator);
fraction fraction_add(fraction a, fraction b);
fraction fraction_subtract(fraction a, fraction b);
fraction fraction_multiply(fraction a, fraction b);
fraction fraction_divide(fraction a, fraction b);
fraction fraction_reciprocal(fraction f);
double fraction_toDouble(fraction f);
void fraction_simplify(fraction *f);
char* fraction_toString(fraction f);
bool fraction_equals(fraction a, fraction b);

#endif
