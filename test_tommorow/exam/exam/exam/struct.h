struct employee
{
  char name[20];
  int salary;
  int number_of_days;
};

enum position
{
  Intern = 0,
  Software_Developer = 3,
  Master_Developer = 5,
  Senior_Developer = 10,
};

typedef struct employee employee;