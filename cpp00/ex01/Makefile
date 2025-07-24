C++ = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = megaphone

FILES = megaphone.cpp

all:$(NAME)

$(NAME): $(FILES) Makefile
	$(C++) $(FLAGS) $(FILES) -o $(NAME)


clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

.PHONY: all clean fclean re