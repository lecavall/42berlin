TEST: test.out

SRC: libftprintf.a test_ft_printf.c

OBJ: $(SRC:.c = .o)

all: $(TEST)

$(TEST): $(OBJ)
	gcc -Wall -Werror -Wextra 

clean: $(OBJ) 
	rm -f $(OBJ)

fclean: clean $(NAME)
	rm -f $(NAME)

re: fclean
	all