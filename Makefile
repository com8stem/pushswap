TARGET = push_swap
SRCS = *.c
OBJS = $(SRCS:.c=.o)
CC = clang
CFLAGS = -Wall -Wextra -Werror
LIBDIR = ./libft
LIBFT = ./libft/libft.a

all:	$(TARGET)

$(TARGET):	$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(TARGET)

$(OBJS):	$(SRCS)
	$(CC) $(CFLAGS) -c $(SRCS)

$(LIBFT):
	make -C $(LIBDIR)

clean:
	rm -rf $(OBJS)
	make clean -C $(LIBDIR)

fclean:	clean
	rm -rf $(TARGET)
	make fclean -C $(LIBDIR)

re: fclean all

.PHONY: all clean fclean re