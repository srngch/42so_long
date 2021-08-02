# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 01:47:18 by sarchoi           #+#    #+#              #
#    Updated: 2021/08/02 17:10:56 by sarchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c) \
	$(wildcard libft/*.c)
SRCS_MANDATORY = main.c
SRCS_BONUS = main_bonus.c \
	$(wildcard *_bonus.c)
OBJS = $(SRCS:.c=.o)
OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
GCH  = $(wildcard *.gch)

LIBFT = libft

MLX = mlx
MLX_FLAGS = -lmlx
# MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lz

red:=$(shell tput setaf 1)
reset:=$(shell tput sgr0)

all: $(NAME)
	$(info $(red)******** all ********$(reset))

$(NAME): $(OBJS) $(OBJS_MANDATORY)
	$(info $(red)******** NAME ********$(reset))
	make -C $(MLX)
	install_name_tool -change libmlx.dylib $(CURDIR)/mlx/libmlx.dylib so_long
	$(CC) $(CFLAGS) -o $@ $^ -L $(MLX) $(MLX_FLAGS)

bonus: $(OBJS) $(OBJS_BONUS)
	$(info $(red)******** bonus ********$(reset))
	make all -C $(MLX)
	install_name_tool -change libmlx.dylib ./mlx/libmlx.dylib so_long
	$(CC) $(CFLAGS) -o $@ $^ -L $(MLX) $(MLX_FLAGS)

%.o: %.c
	$(info $(red)******** $(@) $(<) ********$(reset))
	$(CC) $(CFLAGS) -c $< -o $@ -I $(MLX)

clean:
	$(info $(red)******** clean ********$(reset))
# make clean -C ./$(LIBFT)
	make clean -C $(MLX)
	rm -f $(OBJS) $(OBJS_MANDATORY) $(OBJS_BONUS) $(GCH)

fclean: clean
	$(info $(red)******** fclean ********$(reset))
# make fclean -C ./$(LIBFT)
	rm -f $(NAME)

re: fclean all
	$(info $(red)******** re ********$(reset))

.PHONY: all clean fclean re
