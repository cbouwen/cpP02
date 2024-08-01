NAME = ex00
FLAGS = -Werror -Wall -Wextra -std=c++98
CC = c++
SRC = main.cpp Fixed.cpp

all : $(NAME)

$(NAME): megaphone.cpp
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

clean:
	$(RM)$(NAME)

fclean:clean

re: clean all

.PHONY: all clean fclean re