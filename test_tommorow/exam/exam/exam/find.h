// #include "struct.h"
#include <string.h>

employee *find_employee(employee e[], int size, char name[])
{
  int i = 0;
  while (i < size)
  {
    if (strcmp(e[i].name, name) == 0)
    {
      return (e + i);
    }
    i++;
  }
  return NULL;
};
