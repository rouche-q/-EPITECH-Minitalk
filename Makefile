##
## Makefile for makefile in /home/rouche_q/rendu/PSU_2015_minitalk
## 
## Made by quentin rouchet
## Login   <rouche_q@epitech.net>
## 
## Started on  Thu Feb  4 19:03:12 2016 quentin rouchet
## Last update Thu Feb 18 05:40:38 2016 Rouchet
##

CC	=	gcc -o

RM	=	rm -rf

CFLAGS	=	-Wextra -Wall -Werror -pedantic -I.

NAME1	=	client/client

NAME2	=	server/server

SRCS1	=	sources/fctbases.c	\
		sources/my_getnbr.c	\
		client/mainclient.c	\
		client/client.c		\
		client/pid_client.c		\


SRCS2	=	sources/fctbases.c	\
		sources/my_getnbr.c	\
		server/serveur.c

OBJS1	=	$(SRCS1:.c=.o)

OBJS2	=	$(SRCS2:.c=.o)

all	:	$(NAME1) $(NAME2)

$(NAME1):	$(OBJS1)
		$(CC) $(NAME1) $(OBJS1) $(CFLAGS)

$(NAME2):       $(OBJS2)
		$(CC) $(NAME2) $(OBJS2) $(CFLAGS)

clean	:	
		$(RM) $(OBJS1) $(OBJS2)

fclean	:	clean
		$(RM) $(NAME1) $(NAME2)

re	:	fclean all

.PHONY	:	all clean fclean re
