/*
** mainclient.c for mainclient in /home/rouche-q/rendu/PSU_2015_minitalk
** 
** Made by Rouchet
** Login   <rouche-q@rouche-q-HP-EliteBook-840-G2>
** 
** Started on  Sat Feb 13 00:31:58 2016 Rouchet
** Last update Thu Feb 18 05:43:53 2016 Rouchet
*/

#include "../sources/minitalk.h"

int	main(int argc, char **argv)
{
  if (argc == 3)
    {
    if (verif_pid(my_getnbr(argv[1])) == -1)
      return (-1);
    get_send(my_getnbr(argv[1]));
    split_letter(my_getnbr(argv[1]), argv[2]);
    }
  else
    return (0);
  return (0);
}
