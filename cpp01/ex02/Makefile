NAME=hithisisbrain

C_FLAGS = -Wall -Wextra -std=c++98 -Werror

SRC = main

SRC_CPP = $(addsuffix .cpp, $(SRC))
OBJ = $(addsuffix .o, $(SRC))

all: $(NAME)

$(NAME): main.cpp $(OBJ)
		c++ $(C_FLAGS) main.cpp -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
