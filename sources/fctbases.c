/*
** fctbases.c for fctbases in /home/rouche_q/rendu/PSU_2015_minitalk
** 
** Made by quentin rouchet
** Login   <rouche_q@epitech.net>
** 
** Started on  Tue Feb  2 18:08:24 2016 quentin rouchet
** Last update Sun Feb 21 06:42:07 2016 Rouchet
*/

#include "minitalk.h"

int	my_putchar(char c)
{
  write(1, &c, 1);
  return (0);
}

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while(str[i])
    {
      my_putchar(str[i]);
      i++;
    }
  return (0);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0 ;
  while(str[i])
    i++;
  return (i);
}

int     my_putnbr(int n)
{
  int i;
  int j;
  int y;

  i = 1;
  y = 0;
  j = 0;
  if (n < 0)
    {
      n = n * -1;
      my_putchar('-');
    }
  while (i < n)
    i = i * 10;
  while (i > 1)
    {
      i = i / 10;
      j = (n / i) % 10;
      my_putchar(j + 48);
      y = y + 1;
    }
  return (0);
}
