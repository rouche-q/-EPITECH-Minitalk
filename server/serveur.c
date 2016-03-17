/*
** serveur.c for serveurs in /home/rouche_q/rendu/PSU_2015_minitalk
** 
** Made by quentin rouchet
** Login   <rouche_q@epitech.net>
** 
** Started on  Tue Feb  2 18:03:45 2016 quentin rouchet
** Last update Thu Feb 18 05:58:16 2016 Rouchet
*/

#include "../sources/minitalk.h"

int	pid_c;

void	decal_bit_pid(int bit)
{
  static int place;
  static int c;

  c = c + (bit << place);
  place++;
  if (place == 32)
    {
      pid_c = c;
      c = 0;
      place = 0;
      printf("%d\n", pid_c);
      kill(SIGUSR1,pid_c);
    }
}


void	decal_bit(int bit)
{
  static int place;
  static char c;

  c = c + (bit << place);
  place++;
  if (place == 8)
    {
      my_putchar(c);
      c = 0;
      place = 0;
      kill(SIGUSR1,pid_c);
    }
}

void	get_signal(int	sig)
{
  if (sig == SIGUSR1)
    decal_bit(0);
  if (sig == SIGUSR2)
    decal_bit(1);
}

void	get_signal_pid(int sig)
{
  if (sig == SIGUSR1)
    decal_bit_pid(0);
  if (sig == SIGUSR2)
    decal_bit_pid(1);
}

int	main()
{
  pid_t	pid;
  int	i;

  pid_c = 0;
  i = 0;
  pid = getpid();
  my_putstr("My PID is :");
  my_putnbr(pid);
  my_putchar('\n');
  while (i < 32)
    {
      signal(SIGUSR1, get_signal_pid);
      signal(SIGUSR2, get_signal_pid);
      i++;
      pause();
    }
  while (i >= 32)
    {
      signal(SIGUSR1, get_signal);
      signal(SIGUSR2, get_signal);
      pause();
    }
  return (0);
}
