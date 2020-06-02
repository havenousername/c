#include "struct.h"

int number_of_employees_at( employee e[], int size, int p)
{
  int count = 0;
  int i = 0;
  while (i < size)
  {
    if (p == 10)
    {
      if (e[i].number_of_days / 365 >= p)
      {
        count++;
      }
    }
    if(p == 3){
      if (e[i].number_of_days / 365 == p && e[i].number_of_days / 365 < 5)
      {
        count++;
      }
    }
    if(p == 5){
      if (e[i].number_of_days / 365 >= p && e[i].number_of_days / 365  < 10)
      {
        count++;
      }
    }
    if (p == 0)
    {
      if (e[i].number_of_days / 365 >= p && e[i].number_of_days / 365  < 3)
      {
        count++;
      }
    }
    ++i;
  }
  return count;
};
