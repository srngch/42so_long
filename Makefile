# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 01:47:18 by sarchoi           #+#    #+#              #
#    Updated: 2021/09/19 03:34:49 by sarchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = srcs/main.c \
	srcs/input.c srcs/states.c srcs/print_shell.c \
	srcs/map.c srcs/map_vaildate.c srcs/map_vaildate2.c \
	srcs/map_utils.c \
	srcs/graphic_init.c 
SRCS_MANDATORY = srcs/graphic_draw.c
SRCS_BONUS = srcs/graphic_draw_bonus.c \
			srcs/graphic_util_bonus.c
OBJS = $(SRCS:.c=.o)
OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT = libft
LIBFT_FLAGS = -L libft -lft

SRCS_GNL = get_next_line/get_next_line_utils.c \
		   get_next_line/get_next_line.c
OBJS_GNL = $(SRCS_GNL:.c=.o)
GNL = get_next_line

MLX = mlx
MLX_FLAGS = -L mlx -lmlx

INC_FLAGS = -I includes/so_long -I includes -I $(LIBFT) -I $(GNL) -I $(MLX) 

green:=$(shell tput setaf 2)
reset:=$(shell tput sgr0)

all:  $(LIBFT) $(MLX) $(NAME)
	$(info $(green)<MAKE> all$(reset))

test: all bonus
	$(info $(green)<MAKE> test$(reset))
	./$(NAME) maps/square.ber

debug: $(SRCS) $(SRCS_MANDATORY) $(SRCS_GNL)
	$(info $(green)<MAKE> debug$(reset))
	$(CC) $(CFLAGS) -g $^ -o $(NAME) $(LIBFT_FLAGS) $(MLX_FLAGS) $(INC_FLAGS)
	install_name_tool -change libmlx.dylib $(CURDIR)/mlx/libmlx.dylib so_long

$(LIBFT):
	@make bonus --silent --directory=$(LIBFT)
	$(info $(green)<MAKE>	Libft - make bonus$(reset))

$(MLX):
	@make --silent --directory=$(MLX)
	$(info $(green)<MAKE>	MinilibX - make$(reset))

$(NAME): $(OBJS) $(OBJS_MANDATORY) $(OBJS_GNL)
	$(info $(green)<MAKE> NAME$(reset))
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_FLAGS) $(MLX_FLAGS)
	install_name_tool -change libmlx.dylib $(CURDIR)/mlx/libmlx.dylib so_long

%.o: %.c
	$(info $(green)******** $(@) $(<) ********$(reset))
	$(CC) $(CFLAGS) -c $< -o $@ $(INC_FLAGS)

bonus: $(OBJS) $(OBJS_BONUS) $(OBJS_GNL)
	$(info $(green)******** bonus ********$(reset))
	$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBFT_FLAGS) $(MLX_FLAGS)
	install_name_tool -change libmlx.dylib ./mlx/libmlx.dylib so_long
	$(info $(green)******** /// ********$(reset))

clean:
	$(info $(green)******** clean ********$(reset))
	@make clean --directory=$(LIBFT)
	$(info $(green)*** Libft - clean ***$(reset))
	@make clean --directory=$(MLX)
	$(info $(green)*** MinilibX - clean ***$(reset))
	rm -f $(OBJS) $(OBJS_MANDATORY) $(OBJS_BONUS)

fclean: clean
	$(info $(green)******** fclean ********$(reset))
	make fclean --directory=$(LIBFT)
	$(info $(green)*** Libft - fclean $(reset))
	rm -f $(NAME)
	rm -rf $(NAME).dSYM

re: fclean all
	$(info $(red)******** re ********$(reset))

.PHONY: all clean fclean re bonus $(LIBFT) $(MLX) $(NAME)
