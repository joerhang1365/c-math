#include "functions.h"

/*
 * Linear Function
 */

void linear_create(linear *line, double slope, double y_intercept)
{
   line->slope = slope;
   line->y_intercept = y_intercept;
}

linear linear_add(linear a, linear b)
{
   linear line;
   if(a.slope != b.slope)
   {
      printf("ERROR: lines are not parellel. They cannot be added.\n");
   }
   linear_create(&line, a.slope + b.slope, a.y_intercept + b.y_intercept);
   return line;
}

linear linear_subtract(linear a, linear b)
{
   linear line;
   if(a.slope != b.slope)
   {
      printf("ERROR: lines are not parellel. They cannot be subracted\n");
   }
   linear_create(&line, a.slope - b.slope, a.y_intercept - b.y_intercept);
   return line;
}

void linear_transform(linear *line, double y_transform)
{
   line->y_intercept += y_transform; 
}

void linear_rotate(linear *line, double slope)
{
   line->slope = slope;
}

void linear_reflect(linear *line)
{
   line->slope *= -1;

}
void linear_invert(linear *line)
{
   linear_create(line, -1 * line->y_intercept / line->slope, 1 / line->slope);
}

double linear_intersection(linear a, linear b)
{
   return (b.y_intercept - a.y_intercept) / (a.slope - b.slope); 
}

double linear_slope(double x1, double x2, double y1, double y2)
{
   return (y1 - y2) / (x1 - x2);
}

double linear_yIntercept(double x, double y, double slope)
{
   return -1 * slope * x + y;
}

char* linear_toString(linear line)
{
   static char equation[100];

   if (line.y_intercept > 0 && line.slope != 0)
   {
      sprintf(equation, "y = %1fx + %1f", line.slope, line.y_intercept);
   }
   else if (line.y_intercept < 0 && line.slope != 0)
   {
      sprintf(equation, "y = %1fx - %1f", line.slope, fabs(line.y_intercept));
   }
   else if (line.y_intercept == 0 && line.slope != 0)
   {
      sprintf(equation, "y = %1fx", line.slope);
   }
   else
   {
      sprintf(equation, "y = %1f", line.y_intercept);
   }

   return equation;
}

bool linear_isParallel(linear a, linear b)
{
   return a.slope == b.slope;
}

bool linear_isPerpendicular(linear a, linear b)
{
   return a.slope == 1 / b.slope;
}

/*
 * Quadratic Function
 */

void quadratic_create(quadratic *q, double a, double b, double c)
{
   q->a = a;
   q->b = b;
   q->c = c;
}

quadratic quadratic_add(quadratic a, quadratic b)
{
   quadratic sum = {a.a + b.a, a.b + b.b, a.c + b.c};
   return sum;
}

quadratic quadratic_subtract(quadratic a, quadratic b)
{
   quadratic difference = {a.a - b.a, a.b - b.b, a.c - b.c};
   return difference;
}

double *quadratic_roots(quadratic q)
{
   static double roots[2];

   roots[0] = (-1 * q.b + sqrtf(q.b * q.b - 4 * q.a * q.c)) / (2 * q.a);
   roots[1] = (-1 * q.b - sqrtf(q.b * q.b - 4 * q.a * q.c)) / (2 * q.a);

   return roots;
}

double *quadratic_vertex(quadratic q)
{
   static double vertex[2];

   vertex[0] = (-1 * q.b) / (2 * q.a);
   vertex[1] = q.a * powf(vertex[0], 2) + q.b * vertex[0] + q.c;

   return vertex;
}

char* quadratic_toString(quadratic q)
{
   static char equation[100];
   char temp[20];

   if(q.a != 0)
   {
      sprintf(temp, "%1fx^2", q.a);
      strcat(equation, temp);
   }

   if(q.b > 0)
   {
      sprintf(temp, " + %1fx", q.b);
      strcat(equation, temp);
   }
   else if(q.b < 0)
   {
      sprintf(temp, " - %1fx", fabs(q.b));
      strcat(equation, temp);
   }

   if(q.c > 0)
   {
      sprintf(temp, " + %1f", q.c);
      strcat(equation, temp);
   }
   else if(q.c < 0)
   {
      sprintf(temp, " - %1f", fabs(q.c));
      strcat(equation, temp);
   }

   return equation;
}

bool quadratic_isOpenUp(quadratic q)
{
   return q.a > 0;
}

bool quadratic_isEqual(quadratic a, quadratic b)
{
   return a.a == b.a && a.b == b.b && a.c == b.c;
}

