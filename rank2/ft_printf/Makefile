NAME: libftprintf.a
CC: gcc
CFLAGS: -Wall -Wextra -Werror
AR: ar rcs
RM: rm -f
SRCS: ft_printf.c \
	  ft_printf_utils.c \
	  ft_printf_formats.c \
	  ft_printf_formats_2.c \
	  ft_printf_formats_3.c
OBJS: $(SRCS:.c=.o)
all: $(NAME)
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: all clean fclean re
