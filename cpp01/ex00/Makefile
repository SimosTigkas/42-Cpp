NAME=zombie

C_FLAGS = -Wall -Werror -std=c++98 -Werror

SRC = \
	Zombie \
	newZombie \
	randomChump

INC = Zombie

SRC_HPP = $(addsuffix .hpp, $(INC))

SRC_CPP = $(addsuffix .cpp, $(SRC))

OBJ = $(addsuffix .o, $(SRC))

all: $(NAME)

$(NAME): main.cpp $(SRC_CPP) $(SRC_HPP)
	c++ $(C_FLAGS) $(SRC_CPP) main.cpp -o $(NAME) -I$(INC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re