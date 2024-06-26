NAME = Harl

C_FLAGS = -Wall -Wextra -std=c++98 -Werror

SRC = Harl main
INC = Harl

SRC_CPP = $(addsuffix .cpp, $(SRC))
SRC_HPP = $(addsuffix .h, $(INC))
OBJ = $(addsuffix .o, $(SRC))

all: $(NAME)

$(NAME): $(SRC_CPP) $(OBJ)
	c++ $(C_FLAGS) $(SRC_CPP) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re