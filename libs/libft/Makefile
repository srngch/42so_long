CC = gcc
CFLAGS = -Wall -Wextra -Werror

NAME = libft.a
SRCS = ft_strlen.c ft_strnstr.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putnbr_fd.c
SRCS_BONUS = ft_lstnew.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstclear.c
OBJS = ${SRCS:.c=.o}
OBJS_BONUS = ${SRCS_BONUS:.c=.o}

all: $(NAME)

$(NAME): $(OBJS)
	ar -cr $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonus: $(OBJS) $(OBJS_BONUS)
	ar -cr $(NAME) $^

.PHONY: all clean fclean re bonus
