TARGET = push_swap
SRCDIR = ./srcs
SRCS = $(addprefix $(SRCDIR)/, check.c create_list.c list_utils.c main.c push_list.c put_error.c r_rotate_list.c rotate_list.c sort_large_list.c sort_small_list.c swap_list.c)
OBJS = $(patsubst $(SRCDIR)/%.c, ./%.o, $(SRCS))
INCDIR = $(SRCDIR)
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIBDIR = ./libft
LIBFT = $(addprefix $(LIBDIR)/, libft.a)

all:	$(TARGET)

$(TARGET):	$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(TARGET)

$(OBJS):	$(SRCS) $(INCDIR)
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