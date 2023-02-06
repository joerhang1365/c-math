#ifndef MATRIX_H
#define MATRIX_H

typedef struct
{
   double *data;
} matrix4;

void matrix4_create(matrix4 *m, double *data);
matrix4 matrix4_addition(matrix4 a, matrix4 b);
matrix4 matrix4_multiply(matrix4 m, double scalar);

#endif
