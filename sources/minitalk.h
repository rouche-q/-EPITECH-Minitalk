/*
** h.h for exemple in /home/rouche_q/sources
** 
** Made by quentin rouchet
** Login   <rouche_q@epitech.net>
** 
** Started on  Tue Dec 15 17:32:44 2015 quentin rouchet
** Last update Thu Feb 18 05:53:58 2016 Rouchet
*/

#ifndef MINTALK_H_
# define MINITALK_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/types.h> 
#include <unistd.h>
#include <signal.h>
#include <unistd.h>

int     my_putchar(char c);
int     my_putstr(char *str);
int     my_strlen(char *str);
int     my_putnbr(int n);
int     verif_pid(pid_t pid);
int     only_nbr(char *str);
int     my_getnbr(char *a);
int     verif_pid(int pid);
int     send_letter(char c, int pid);
int     split_letter(int pid, char *argv);
void    get_signal(int pid);
int	my_kill1(int pid);
int	my_kill2(int pid);
void	decal_bit_pid(int bit);
void	get_signal_pid(int sig);
void	get_response(int sig);
int	get_send(int pid);
int	send_pid(int c, int pid);

#endif 
