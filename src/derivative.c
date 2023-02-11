#include "derivative.h"

void derivative_constant(char *equation, const char variable)
{
   sprintf(equation, "0");
}

void derivative_linear(char *equation, const char variable)
{
   char *parse = strtok(equation, &variable);
   if (parse != "")
   {
      sprintf(equation, parse);
   }
   else
   {
      sprintf(equation, "1");
   }
}

void derivative_power(char *equation, const char variable)
{
   char *parse = strstr(equation, "^");
   unsigned int length = strlen(parse);

   // Removes '^' from the parse
   char powerString[length];
   for(int i = 1; i < length; i++)
   {
      powerString[i - 1] = parse[i];
   }
   powerString[length - 1] = '\0';

   int power = atoi(powerString);

   sprintf(equation, "%d%c^%d", power, variable, power - 1);
}

void derivative_trigonometric(char *equation, const char variable)
{
   char *parse = strtok(equation, &variable);
   
   if(strcmp(parse, "sin") == 0)
   {
      sprintf(equation, "cos%c", variable);
   }
   else if(strcmp(parse, "tan") == 0)
   {
      sprintf(equation, "sec^2%c", variable);
   }
   else if(strcmp(parse, "sec") == 0)
   {
      sprintf(equation, "sec%ctan%c", variable, variable);
   }
   else if(strcmp(parse, "cos") == 0)
   {
      sprintf(equation, "-sin%c", variable);
   }
   else if(strcmp(parse, "cot") == 0)
   {
      sprintf(equation, "-csc^2%c", variable);
   }
   else if(strcmp(parse, "csc") == 0)
   {
      sprintf(equation, "-csc%ccot%c", variable, variable);
   }
   else
   {
      printf("ERROR: cannot find trigonometric function in equation"); 
   }
}
