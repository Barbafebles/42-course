int  ft_atoi(const char *str)
{
  int  c;
  int  s;
  int  res;

  c = 0;
  s = 0;
  res = 0;
  while (str[c] == 32 || str[c] == 10 || str[c] == 9 || str[c] == 11 || str[c] == 12 || str[c] == 13)
    c++;
  if(str[c] == '-' || str[c] == '+')
  {
    if(str[c] == '-')
      s = -1;
    c++;
  }
  while (str[c] >= '0' && str[c] <= '9')
    {
      res = (res * 10) + (str[c] - '0');
      c++;
    }
  return (res * s);
  }
