NAME=FlagTrap

C_FLAGS = -Wall -Wextra -Werror

SRC = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp main.cpp

INC = ClapTrap.hpp ScavTrap.hpp FlagTrap.hpp

OBJ = $(SRC:.cpp=.o)

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