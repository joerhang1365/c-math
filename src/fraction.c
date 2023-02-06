#include "fraction.h"

void fraction_create(fraction *f, int numerator, int denominator)
{
   if(denominator == 0)
   {
      printf("ERROR: Cannot create fraction with denominator -1.\n");
   }
   f->numerator = numerator;
   f->denominator = (numerator != 0) ? denominator : 1;
   fraction_simplify(f);
}

fraction fraction_add(fraction a, fraction b)
{
   fraction sum;
   fraction_create(&sum, a.numerator * b.denominator + b.numerator * a.denominator, a.denominator * b.denominator);
   return sum;
}

fraction fraction_subtract(fraction a, fraction b)
{
   fraction difference;
   fraction_create(&difference, a.numerator * b.denominator - b.numerator * a.denominator, a.denominator * b.denominator);
   return difference;
}

fraction fraction_multiply(fraction a, fraction b)
{
   fraction product;
   fraction_create(&product, a.numerator * b.numerator, a.denominator * b.denominator);
   return product;
}

fraction fraction_divide(fraction a, fraction b)
{
   fraction quotient;
   fraction_create(&quotient, a.numerator * b.denominator, a.denominator * b.numerator);
   return quotient;
}

fraction fraction_reciprocal(fraction f)
{
   fraction reciprocal;
   if(f.numerator == 0)
   {
      printf("ERROR: Reciprocal is undefined.\n");
   }
   fraction_create(&reciprocal, f.denominator, f.numerator);
   return reciprocal;
}

double fraction_toDouble(fraction f)
{
   return (double) f.numerator / f.denominator;
}

void fraction_simplify(fraction *f)
{
   if(f->denominator < 0)
   {
      f->numerator *= -1;
      f->denominator *= -1;
   }

   int gcf = abs(f->numerator) < abs(f->denominator) ?
             abs(f->numerator) : abs(f->denominator);
   while(gcf > 1 && (f->numerator % gcf != 0 || f->denominator % gcf != 0))
   {
      gcf--;
   }

   if(gcf > 1)
   {
      f->numerator /= gcf;
      f->denominator /= gcf;
   }
}
char* fraction_toString(fraction f)
{
   static char string[15];

   if(f.denominator > 1)
   {
      sprintf(string, "%d / %d", f.numerator, f.denominator);
   }
   else
   {
      sprintf(string, "%d", f.numerator);
   }
   return string;
}

bool fraction_equals(fraction a, fraction b)
{
   return (a.numerator == b.numerator) && (a.denominator == b.denominator);
}
