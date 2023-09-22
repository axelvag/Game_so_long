# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avaganay <avaganay@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 08:46:55 by jrenault          #+#    #+#              #
#    Updated: 2023/02/05 11:57:11 by avaganay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY:     			all $(NAME) clear mkbuild lib mlx clear clean fclean re sanitize

NAME					= so_long 

BUILD_DIR				= build/
	
HEADER_DIR				= header/
HEADER_FILE				= so_long.h
HEADERS_WITH_PATH		= $(addprefix $(HEADER_DIR),$(HEADER_FILE))

DIR						= src/
SRC			 			= 	so_long.c	parsing.c	check.c		init.c		mouv.c \
							win.c		free.c		pathfinding.c	checknumber.c	init2.c	\
							mouv2.c
							
OBJECTS			    	= ${addprefix ${BUILD_DIR},${SRC:.c=.o}}
	
LIBFT					= libft.a
LIB_DIR					= ft_printf/libft/
FT_PRINTF				= libftprintf.a
PRINT_DIR				= ft_printf/
GET_NEXT_LINE			= get_next_line_bonus.a
GNL_DIR					= get_next_line/
	
GCC						= cc
CFLAGS					= -Wall -Wextra -Werror #-g3 -fsanitize=address
SANITIZE				= $(CFLAGS)

RM 						= rm -rf
CLEAR					= clear

MINILIB					= libmlx.a

# MINILIB_DIR				= mlx/
# MAC						= -framework OpenGL -framework AppKit

MINILIB_DIR             = minilibx_linux/                               
LINUX                   = -Lminilibx_linux -lmlx_Linux -lmlx -L/usr/lib -Iminilibx_linux -lXext -lX11 -lm -lz

$(BUILD_DIR)%.o:		$(DIR)%.c ${HEADERS_WITH_PATH}
						mkdir -p $(@D)
						$(GCC) $(CFLAGS) -I$(HEADER_DIR) -I$(PRINT_DIR) -I$(GNL_DIR) -I$(LIB_DIR) -I$(MINILIB_DIR) -c $< -o $@

all: 					clear mkbuild lib minilibx $(HEADER_DIR) $(NAME)
						
mkbuild:
						mkdir -p build

clear:
						$(CLEAR)
						
$(NAME): 				$(OBJECTS) $(LIB_DIR)$(LIBFT) $(PRINT_DIR)$(FT_PRINTF) $(GNL_DIR)$(GET_NEXT_LINE)
						$(GCC) $(CFLAGS) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(PRINT_DIR)$(FT_PRINTF) $(GNL_DIR)$(GET_NEXT_LINE) -L$(MINILIB_DIR) $(LINUX)

sanitize :				lib minilibx $(OBJECTS) $(LIB_DIR)$(LIBFT) $(PRINT_DIR)$(FT_PRINTF) $(GNL_DIR)$(GET_NEXT_LINE)
						$(GCC) $(SANITIZE) $(OBJECTS) -o $(NAME) $(LIB_DIR)$(LIBFT) $(PRINT_DIR)$(FT_PRINTF) $(GNL_DIR)$(GET_NEXT_LINE) -L$(MINILIB_DIR) $(LINUX)

lib:
						make -C $(LIB_DIR)
						make -C $(PRINT_DIR)
						make -C $(GNL_DIR)


minilibx:
						make -C $(MINILIB_DIR)
						
clean:					
						${RM} $(OBJECTS)
						make clean -C $(LIB_DIR)
						make clean -C $(MINILIB_DIR)
						make clean -C $(PRINT_DIR)
						make clean -C $(GNL_DIR)
						${RM} $(BUILD_DIR)

fclean:					clean
						${RM} ${NAME}
						make fclean -C $(LIB_DIR)
						make fclean -C $(PRINT_DIR)
						make fclean -C $(GNL_DIR)

re:						fclean all
						$(MAKE) all