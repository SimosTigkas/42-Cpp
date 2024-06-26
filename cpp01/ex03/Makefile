NAME=unnecessaryviolence

C_FLAGS = -Wall -Wextra -std=c++98 -Werror

SRC = \
	Weapon \
	HumanA \
	HumanB

SRC_CPP = $(addsuffix .cpp, $(SRC))
SRC_HPP = $(addsuffix .hpp, $(SRC))

OBJ = $(addsuffix .o, $(SRC))

all: $(NAME)

$(NAME): main.cpp $(SRC_CPP) $(SRC_HPP) $(OBJ)
	c++ $(C_FLAGS) $(SRC_CPP) main.cpp -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re