#include <stdio.h>

//Compiler version gcc 6.3.0

int main()
{
  int c = 0;

  while ((c = getchar()) != EOF)
  {
    
    if (c == '\\')
    {
      putchar('\\');
      putchar('\\');
    }
    if (c == '\n')
    {
      putchar('\\');
      putchar('n');
    }
    if (c == '\t')
    {
      putchar('\\');
      putchar('t');
    }
    if (c == '\b')
    {
      putchar('\\');
      putchar('b');
    }
    putchar(c);
  }
  return 0;
}