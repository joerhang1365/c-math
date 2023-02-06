#include <stdio.h>
#include "fraction.h"
#include "functions.h"
#include "vector.h"

int main()
{
   vector3 A;
   vector3 B;
   vector3_create(&A, 209, -535, 437);
   vector3_create(&B, 43, 4354, 45);

   quadratic myFunction;
   quadratic_create(&myFunction, 1, 8, 15);

   double* vertex = quadratic_vertex(myFunction);
   double* roots = quadratic_roots(myFunction);

   printf("Vector A + B = %s\n", vector3_toString(vector3_add(A, B)));
   printf("Dot product of A and B is: %1f\n", vector3_dotProduct(A, B));
   printf("The magnitude of vector A is: %1f\n", vector3_magnitude(A));
   printf("Equation of quadratic is: %s\n", quadratic_toString(myFunction));
   printf("The vertex of myFunction is: (%1f, %1f)\n", vertex[0], vertex[1]);
   printf("The roots of myFunction are %1f and %1f\n", roots[0], roots[1]);

   return 0;
}

