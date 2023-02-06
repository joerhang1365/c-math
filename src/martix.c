#include "matrix.h"

void matrix4_create(matrix4 *m, double *data)
{
   for(int i = 0; i < 16; i++)
   {
      m->data[i] = data[i];
   }
}

matrix4 matrix4_addition(matrix4 a, matrix4 b)
{
   matrix4 sum;
   for(int i = 0; i < 16; i++)
   {
      sum.data[i] = a.data[i] + b.data[i];
   }

   return sum;
}

matrix4 matrix4_multiply(matrix4 m, double scalar)
{
   matrix4 product;
   for(int i = 0; i < 16; i++)
   {
      m.data[i] *= scalar;
   }

   return product;
}

