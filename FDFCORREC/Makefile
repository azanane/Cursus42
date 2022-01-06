# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azanane <azanane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/03 08:31:26 by azanane           #+#    #+#              #
#    Updated: 2022/01/06 13:01:10 by azanane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END=$'\x1b[0m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
BLUE=$'\x1b[34m

LST_SRCS		=	main.c ft_wireframe.c put_col.c \

LST_OBJS		=	${LST_SRCS:.c=.o}

SRCS = $(addprefix sources/,$(LST_SRCS))
OBJS = $(addprefix .objects/,$(LST_OBJS))

INCLUDES	=	includes/fdf.h

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror 

LIBX	    = -Llibmlx -lmlx -framework OpenGL -framework AppKit

NAME		=	fdf

RM			=	rm -f

all:		${NAME}

.objects/%.o:		sources/%.c ${INCLUDES}
			mkdir -p .objects
			@${CC} ${CFLAGS} -I includes -I libmlx -c $< -o $@
			@echo "${BLUE}[BUILD]${END} $@"

${NAME}:	${OBJS} ${INCLUDES} Makefile
			make -C ./libmlx
			gcc ${LIBX} ${OBJS} -I includes -I libmlx get_next_line/*.c sources/utils/*.c -o $@
			@echo "${GREEN}[CREATE]${END} ${NAME}"

clean:
			@${RM} ${OBJS}
			# make clean -C ./libmlx
			@echo "${RED}[DELETE]${END} *.o"

fclean:		clean
			@${RM} ${NAME} fdf
			@echo "${RED}[DELETE]${END} ${NAME}"

re:			fclean all

.PHONY: 	all clean fclean re