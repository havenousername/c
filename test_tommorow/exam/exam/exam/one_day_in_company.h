employee one_day_in_company(employee e)
{
  employee *em = (employee *)malloc(sizeof(e) * 4);
  em->salary = e.salary;
  em->number_of_days = e.number_of_days;
  strcpy(em->name, e.name);
  em->number_of_days++;
  if (em->number_of_days % 365 == 0)
  {
    em->salary += e.salary * 0.05;
  }
  return *em;
};
