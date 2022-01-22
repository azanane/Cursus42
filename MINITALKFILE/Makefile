# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azanane <azanane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 14:27:59 by azanane           #+#    #+#              #
#    Updated: 2022/01/14 18:04:57 by azanane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END=$'\x1b[0m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
BLUE=$'\x1b[34m

CLIENT		= client

SERVER		= server

LST_SRCS1	=	server.c ft_putchar_fd.c ft_strlen.c \

LST_SRCS2	=	client.c ft_atoi.c \

LST_OBJS1	=	${LST_SRCS1:.c=.o}

LST_OBJS2	=	${LST_SRCS2:.c=.o}

SERV  = $(addprefix .objects/,$(LST_OBJS1))
CLI   = $(addprefix .objects/,$(LST_OBJS2))

INCLUDES	=	includes/server.h includes/client.h includes/utils.h

PRNT		= ft_printf/libftprintf.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror 

RM			=	rm -f

PRT			= ft_printf/ft_printf.h

all:	prf ${SERVER} ${CLIENT} 

${SERVER}:	${SERV} ${INCLUDES} ${PRNT} Makefile
			${CC} ${SERV} -fsanitize=address ${PRT} -I includes -o $@
			echo "${GREEN}[CREATE]${END} ${SERVER}"
			@echo "${GREEN}[CREATE]${END} ${CLIENT}"

${CLIENT}:	${CLI} ${INCLUDES}
	        @${CC} ${CLI} -fsanitize=address -I includes -o $@ 

prf:
	make -C ./ft_printf

.objects/%.o:		sources/%.c ${INCLUDES}
			mkdir -p .objects
			@${CC} ${CFLAGS} -I includes -c $< -o $@
			@echo "${BLUE}[BUILD]${END} $@"

clean:
			@${RM} ${SERV} ${CLI}
			make clean -C ./ft_printf
			@echo "${RED}[DELETE]${END} *.o"

fclean:		clean
			@${RM} ${SERVER} ${CLIENT}
			@echo "${RED}[DELETE]${END} ${SERVER}"
			@echo "${RED}[DELETE]${END} ${CLIENT}"

re:			fclean all

.PHONY: 	all clean fclean re
