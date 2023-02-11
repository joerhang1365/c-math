#ifndef DERIVATIVE_H
#define DERIVATIVE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void derivative_constant(char *equation, const char variable);
void derivative_linear(char *equation, const char variable);
void derivative_power(char *equation, const char variable);
void derivative_trigonometric(char *equation, const char variable);

#endif
