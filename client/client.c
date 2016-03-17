/*
** client.c for  in /home/rouche_q/rendu/PSU_2015_minitalk
** 
** Made by quentin rouchet
** Login   <rouche_q@epitech.net>
** 
** Started on  Wed Feb  3 12:49:43 2016 quentin rouchet
** Last update Thu Feb 18 05:43:07 2016 Rouchet
*/

#include "../sources/minitalk.h"

int	verif_pid(int pid)
{
  if (pid >= 1)
    {
      if (kill(pid, 0) == 0)
	{
	  my_putstr("PID exist\n");
	  return (0);
	}
      else
	{
	  my_putstr("PID invalid\n");
	  return (-1);
	}
    }
  else
    {
      my_putstr("PID invalid\n");
      return (-1);
    }
  return (0);
}

int	my_kill1(int pid)
{
  if (kill(pid, SIGUSR1) == -1)
    {
      my_putstr("Error");
      return (-1);
    }
  return (0);
}

int	my_kill2(int pid)
{
  if (kill(pid, SIGUSR2) == -1)
    {
      my_putstr("Error");
      return (-1);
    }
  return (0);
}

void	get_response(int sig)
{
  if (sig == SIGUSR1)
    sig = sig;
}

int	send_letter(char c, int pid)
{
  int	i;
  char comp;

  i = 0;
  while (i < 8  && signal(SIGUSR1,get_response))
    {
      comp = c & 1;
      if (comp == 0)
	my_kill1(pid);
      else if (comp == 1)
	my_kill2(pid);
      c = c >> 1;
      i++;
    }
  return (0);
}

int	split_letter(int pid, char *argv)
{
  int	i;
  
  i = 0;
  while (argv[i])
    {
      if (signal(SIGUSR1,get_response)) 
	send_letter(argv[i], pid);
      i++;
    }
  return (0);
}	
