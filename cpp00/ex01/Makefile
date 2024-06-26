NAME = phonebook

C_FLAGS = -Wall -Werror -Werror

SRC = \
	PhoneBook \
	Contact

SRC_HPP = $(addsuffix .hpp, $(SRC))
SRC_CPP = $(addsuffix .cpp, $(SRC))
OBJ = $(addsuffix .o, $(SRC))

all: $(NAME)

$(NAME): main.cpp $(SRC_CPP) $(SRC_HPP)
	c++ $(C_FLAGS) $(SRC_CPP) main.cpp -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all


.PHONY: all clean fclean re