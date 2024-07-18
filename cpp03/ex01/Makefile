NAME=ScavTrap

C_FLAGS = -Wall -Wextra -Werror

SRC = ClapTrap ScavTrap main

INC = ClapTrap ScavTrap

SRC_CPP = $(addsuffix .cpp, $(SRC))
SRC_HPP = $(addsuffix .hpp, $(INC))
OBJ = $(addsuffix .o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(C_FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(SRC_HPP)
	c++ $(C_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re