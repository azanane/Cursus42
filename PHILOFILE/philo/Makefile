# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azanane <azanane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 14:27:59 by azanane           #+#    #+#              #
#    Updated: 2022/02/01 15:32:39 by azanane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END=$'\x1b[0m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
BLUE=$'\x1b[34m

LST_SRCS		=	ft_atoi.c ft_isdigit.c ft_putchar_fd.c ft_putstr_fd.c \
					philo.c take_fork.c ft_thread.c \

LST_OBJS		=	${LST_SRCS:.c=.o}

SRCS = $(addprefix ,$(LST_SRCS))
OBJS = $(addprefix .objects/,$(LST_OBJS))

INCLUDES	=	philo.h

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror 

NAME		=	philo

RM			=	rm -f

all:	 ${NAME}

${NAME}:	${OBJS} ${INCLUDES} Makefile
			gcc ${OBJS} -fsanitize=address -I includes -o $@
			@echo "${GREEN}[CREATE]${END} ${NAME}"

.objects/%.o:		%.c ${INCLUDES}
			mkdir -p .objects
			@${CC} ${CFLAGS} -I includes -c $< -o $@
			@echo "${BLUE}[BUILD]${END} $@"

clean:
			@${RM} ${OBJS}
			@echo "${RED}[DELETE]${END} *.o"

fclean:		clean
			@${RM} ${NAME}
			@echo "${RED}[DELETE]${END} ${NAME}"

re:			fclean all

.PHONY: 	all clean fclean re