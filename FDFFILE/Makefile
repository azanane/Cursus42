# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azanane <azanane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 08:31:26 by azanane           #+#    #+#              #
#    Updated: 2022/01/03 17:48:17 by azanane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END=$'\x1b[0m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
BLUE=$'\x1b[34m

SRCS		=	./main.c ./ft_wireframe.c ./ft_split.c ./ft_atoi.c \
				./ft_atoi_b.c \

OBJS		=	${SRCS:.c=.o}

INCLUDES	=	./fdf.h

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror 

LIBX	    = -Llibmlx -lmlx -framework OpenGL -framework AppKit

NAME		=	libfdf

RM			=	rm -f

all:		${NAME}

%.o:		%.c ${INCLUDES}
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
			@echo "${BLUE}[BUILD]${END} ${<:.c=.o}"

${NAME}:	${OBJS} ${INCLUDES}
			@ar rcs ${NAME} ${OBJS}
			@echo "${GREEN}[CREATE]${END} ${NAME}"

run:		${NAME}
			gcc ${LIBX} ${OBJS} get_next_line/*.c -o fdf

clean:
			@${RM} ${OBJS}
			@echo "${RED}[DELETE]${END} *.o"

fclean:		clean
			@${RM} ${NAME}
			@echo "${RED}[DELETE]${END} ${NAME}"

re:			fclean all run

.PHONY: 	all clean fclean re