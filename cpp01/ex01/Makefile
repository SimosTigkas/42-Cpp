NAME=zombieHorde

C_FLAGS = -Wall -Werror -std=c++98 -Werror

SRC = \
	main \
	Zombie \
	zombieHorde

INC = Zombie

SRC_HPP = $(addsuffix .hpp, $(INC))
SRC_CPP = $(addsuffix .cpp, $(SRC))
OBJ = $(addsuffix .o, $(SRC))

all: $(NAME)

$(NAME): $(SRC_CPP) $(SRC_HPP) $(OBJ)
	c++ $(C_FLAGS) $(SRC_CPP) -o $(NAME) -I$(INC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re