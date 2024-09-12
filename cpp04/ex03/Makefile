NAME=amateria

C_FLAGS = -Wall -Wextra -Werror

SRC = AMateria.cpp Character.cpp Cure.cpp Ice.cpp main.c MateriaSource.cpp

INC = AMateria.hpp Character.hpp Cure.hpp Ice.hpp ICharacter.hpp IMateria.hpp MateriaSource.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(C_FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp $(SRC)
	c++ $(C_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re