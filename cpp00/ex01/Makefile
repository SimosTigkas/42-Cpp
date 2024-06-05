NAME = phonebook

C_FLAGS = -Wall -Werror -std=c++98 -Werror

SRC = \
	Phonebook \
	Contact \

SRC_HPP = $(addsuffix .hpp, $(SRC))
SRC_CPP = $(addsuffix .cpp, $(SRC))
OBJ = $(addsuffix .o, $(SRC))

all: $(NAME)

$(NAME): main.cpp $(SRC_HPP) $(SRC_CPP)
	c++ $(C_FLAGS) $(SRC_CPP) -I$(INC) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re