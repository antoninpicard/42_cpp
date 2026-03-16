C++ = c++
FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = megaphone

SOURCES = megaphone.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(C++) $(FLAGS) $(OBJECTS) -o $(NAME)

%.o: %.cpp Makefile
	$(C++) $(FLAGS) -c $< -o $@


clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re