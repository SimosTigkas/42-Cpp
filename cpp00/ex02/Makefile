NAME = account

C_FLAGS = -Wall -Wextra -Werror

SRC = Account

SRC_HPP = $(addsuffix .hpp, $(SRC))
SRC_CPP = $(addsuffix .cpp, $(SRC))
OBJ = $(addsuffix .o, $(SRC))

all: $(NAME)

$(NAME): tests.cpp $(SRC_CPP) $(SRC_HPP)
	c++ $(C_FLAGS) $(SRC_CPP) tests.cpp -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re