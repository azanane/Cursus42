# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: azanane <azanane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 10:58:35 by azanane           #+#    #+#              #
#    Updated: 2022/01/14 17:51:21 by azanane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

END=$'\x1b[0m
RED=$'\x1b[31m
GREEN=$'\x1b[32m
BLUE=$'\x1b[34m

SRCS		=	./ft_atoi.c ./ft_calloc.c ./ft_isalpha.c ./ft_isdigit.c ./ft_itoa.c\
      			./ft_memcmp.c ./ft_memmove.c ./ft_putchar_fd.c ./ft_putnbr_fd.c \
				./ft_split.c ./ft_strjoin.c ./ft_calloc.c ./ft_strnstr.c \
				./ft_strmapi.c ./ft_strtrim.c ./ft_tolower.c ./ft_strlcpy.c \
				./ft_bzero.c ./ft_isalnum.c ./ft_isascii.c ./ft_isprint.c \
				./ft_memchr.c ./ft_memcpy.c ./ft_memset.c ./ft_putendl_fd.c \
				./ft_putstr_fd.c ./ft_strchr.c ./ft_striteri.c ./ft_strlcat.c \
				./ft_strlen.c ./ft_strncmp.c ./ft_strrchr.c ./ft_substr.c \
				./ft_toupper.c ./ft_strdup.c ./ft_strmapi.c ./ft_striteri.c \
				./ft_putendl_fd.c ./ft_putendl_fd.c ./ft_putstr_fd.c \
				./ft_putnbr_fd.c ./ft_putchar_fd.c ./ft_atol.c \

OBJS		=	${SRCS:.c=.o}

INCLUDES	=	./libft.h

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

NAME		=	libft.a

RM			=	rm -f

all:		${NAME}

%.o:		%.c ${INCLUDES}
			@${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
			@echo "${BLUE}[BUILD]${END} ${<:.c=.o}"

${NAME}:	${OBJS} ${INCLUDES}
			@ar rcs ${NAME} ${OBJS}
			@echo "${GREEN}[CREATE]${END} ${NAME}"

clean:
			@${RM} ${OBJS}
			@echo "${RED}[DELETE]${END} *.o"

fclean:		clean
			@${RM} ${NAME}
			@echo "${RED}[DELETE]${END} ${NAME}"

re:			fclean all

.PHONY: 	all clean fclean re
