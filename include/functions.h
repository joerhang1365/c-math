#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

/*
 * Linear: a function that extends infinitely in two directions. It is
 * defined by a set of points that satify a linear equation.
 *
 * Formulas:
 * slope-intercept form (y = mx + b)
 * point-slope form (y - y1 = m(x - x1)).
 */

typedef struct 
{
   double slope;
   double y_intercept;
} linear;

void linear_create(linear *line, double slope, double y_intercept);
linear linear_add(linear a, linear b);
linear linear_subtract(linear a, linear b);
void linear_transform(linear *line, double y_transform);
void linear_rotate(linear *line, double slope);
void linear_reflect(linear *line);
void linear_invert(linear *line);
double linear_intersection(linear a, linear b);
double linear_slope(double x1, double x2, double y1, double y2);
double linear_yIntercept(double x, double y, double slope);
char* linear_toString(linear line);
bool linear_isParallel(linear a, linear b);
bool linear_isPerpendicular(linear a, linear b);

/*
 * Quadratic: this function looks like a U and has three components.
 * 
 * Formula: ax^2 + bx + c;
 */

typedef struct 
{
   double a;
   double b;
   double c;
} quadratic;

void quadratic_create(quadratic *q, double a, double b, double c);
quadratic quadratic_add(quadratic a, quadratic b);
quadratic quadratic_subtract(quadratic a, quadratic b);
double *quadratic_roots(quadratic q);
double *quadratic_vertex(quadratic q);
char* quadratic_toString(quadratic q);
bool quadratic_isOpenUp(quadratic q);
bool quadratic_isEqual(quadratic a, quadratic b);

#endif
