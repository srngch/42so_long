# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 01:47:18 by sarchoi           #+#    #+#              #
#    Updated: 2021/08/20 19:47:20 by sarchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c) $(wildcard get_next_line/*.c) $(wildcard srcs/*.c)
SRCS_MANDATORY = main.c
SRCS_BONUS = main_bonus.c \
	$(wildcard *_bonus.c)
OBJS = $(SRCS:.c=.o)
OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
GCH  = $(wildcard *.gch)

LIBFT = libft
LIBFT_FLAGS = -L libft -lft

MLX = mlx
MLX_FLAGS = -L mlx -lmlx
# MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit -lz

green:=$(shell tput setaf 2)
reset:=$(shell tput sgr0)

all:  $(LIBFT) $(MLX) $(NAME)
	$(info $(green)******** all ********$(reset))

test: all
	$(info )
	$(info $(green)***********************$(reset))
	./$(NAME) maps/subject_minimal.ber
# $(info $(green)***********************$(reset))
# ./$(NAME) maps/subject_minimal.txt

debug: $(OBJS) $(OBJS_MANDATORY)
	$(info $(green)******** debug ********$(reset))
	$(CC) $(CFLAGS) -g -o $(NAME) $^ $(LIBFT_FLAGS) $(MLX_FLAGS) -I includes -I $(MLX) -I $(LIBFT)
	install_name_tool -change libmlx.dylib $(CURDIR)/mlx/libmlx.dylib so_long

$(LIBFT):
	$(info $(green)*** Compiling Libft..$(reset))
	@make bonus -s -C $(LIBFT)

$(MLX):
	$(info $(green)*** Compiling MinilibX..$(reset))
	@make -s -C $(MLX)

$(NAME): $(OBJS) $(OBJS_MANDATORY)
	$(info $(green)******** NAME ********$(reset))
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT_FLAGS) $(MLX_FLAGS)
	install_name_tool -change libmlx.dylib $(CURDIR)/mlx/libmlx.dylib so_long

%.o: %.c
	$(info $(green)******** $(@) $(<) ********$(reset))
	$(CC) $(CFLAGS) -c $< -o $@ -I includes -I $(MLX) -I $(LIBFT)

bonus: $(OBJS) $(OBJS_BONUS)
	$(info $(green)******** bonus ********$(reset))
	$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBFT_FLAGS) $(MLX_FLAGS)
	install_name_tool -change libmlx.dylib ./mlx/libmlx.dylib so_long

clean:
	$(info $(green)******** clean ********$(reset))
	make clean -C $(LIBFT)
	make clean -C $(MLX)
	rm -f $(OBJS) $(OBJS_MANDATORY) $(OBJS_BONUS) $(GCH)

fclean: clean
	$(info $(green)******** fclean ********$(reset))
	make fclean -C $(LIBFT)
	rm -f $(NAME)

re: fclean all
	$(info $(red)******** re ********$(reset))

.PHONY: all clean fclean re bonus $(LIBFT) $(MLX) $(NAME)
