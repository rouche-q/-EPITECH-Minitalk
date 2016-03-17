/*
** pid_client.c for pid_client in /home/rouche-q/rendu/PSU_2015_minitalk/client
** 
** Made by Rouchet
** Login   <rouche-q@rouche-q-HP-EliteBook-840-G2>
** 
** Started on  Thu Feb 18 03:16:17 2016 Rouchet
** Last update Thu Feb 18 05:51:56 2016 Rouchet
*/

#include "../sources/minitalk.h"

int	get_send(int pid)
{
  int	pid_c;
  
  pid_c = getpid();
  send_pid(pid_c, pid);
  return (0);
}

int	send_pid(int c, int pid)
{
  int	i;
  int comp;

  i = 0;
  while (i < 32)
    {
      usleep(1000);
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
