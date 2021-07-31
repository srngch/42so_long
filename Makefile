# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sarchoi <sarchoi@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/01 01:47:18 by sarchoi           #+#    #+#              #
#    Updated: 2021/08/01 02:14:27 by sarchoi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = $(wildcard *.c) \
	$(wildcard libft/*.c)
SRCS_MANDATORY = ./main.c
SRCS_BONUS = ./main_bonus.c \ 
	$(wildcard *_bonus.c)
OBJS = $(SRCS:.c=.o)
OBJS_MANDATORY = $(SRCS_MANDATORY:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
GCH  = $(wildcard *.gch)

LIBFT = libft

MLX = mlx
MLX_FLAGS = -lmlx -lXext -lX11 -framework OpenGL -framework AppKit -lz -L ./mlx -I ./mlx 


all: $(NAME)

$(NAME): $(OBJS) $(OBJS_MANDATORY)
# make all -C ./$(LIBFT)
	make all -C ./$(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $^ $(MLX_FLAGS)

bonus: $(OBJS) $(OBJS_BONUS)
# make all -C ./$(LIBFT)
	make all -C ./$(MLX)
	$(CC) $(CFLAGS) -o $(NAME) $^ $(MLX_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(MLX)

clean:
# make clean -C ./$(LIBFT)
	make clean -C ./$(MLX)
	rm -f $(OBJS) $(OBJS_MANDATORY) $(OBJS_BONUS) $(GCH)

fclean: clean
# make fclean -C ./$(LIBFT)
	make fclean -C ./$(MLX)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
