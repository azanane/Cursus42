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

LST_SRCS		=	ft_check_sort.c ft_error.c ft_index.c ft_kill_malloc.c \
					ft_quote.c main.c operation.c radix.c ft_sort.c \


LST_OBJS		=	${LST_SRCS:.c=.o}

SRCS = $(addprefix sources/,$(LST_SRCS))
OBJS = $(addprefix .objects/,$(LST_OBJS))

INCLUDES	=	includes/push_swp.h

LIB			= libft/libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror 

NAME		=	push_swap

RM			=	rm -f

LFT			= -L libft -lft

all:	 lib ${NAME}

${NAME}:	${OBJS} ${INCLUDES} ${LIB} Makefile
			gcc ${OBJS} -fsanitize=address ${LFT} -I includes -o $@
			@echo "${GREEN}[CREATE]${END} ${NAME}"

lib:
	make -C ./libft

.objects/%.o:		sources/%.c ${INCLUDES}
			mkdir -p .objects
			@${CC} ${CFLAGS} -I includes -c $< -o $@
			@echo "${BLUE}[BUILD]${END} $@"

clean:
			@${RM} ${OBJS}
			make clean -C ./libft
			@echo "${RED}[DELETE]${END} *.o"

fclean:		clean
			@${RM} ${NAME} push_swap
			@echo "${RED}[DELETE]${END} ${NAME}"

re:			fclean all

.PHONY: 	all clean fclean re