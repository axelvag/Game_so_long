# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/14 16:49:57 by avaganay          #+#    #+#              #
#    Updated: 2023/01/15 14:24:07 by avaganay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS =	get_next_line_bonus.c    get_next_line_utils_bonus.c

OBJS = ${SRCS:.c=.o}

CC = gcc

HEAD = includes

FLAGS = -Wall -Wextra -Werror

NAME = get_next_line_bonus.a

LIB = ar rc

LLIB = ranlib

RM = rm -f

.c.o:
	${CC} ${FLAGS} -I${HEAD} -c $< -o ${<:.c=.o}


all:    ${NAME} Makefile

${NAME}:   ${OBJS}
	${LIB} ${NAME} ${OBJS}
	${LLIB} ${NAME}

clean:
	${RM} ${OBJS}

fclean:        clean
	${RM} ${NAME}

re:        fclean all

.PHONY: all clean fclean re

