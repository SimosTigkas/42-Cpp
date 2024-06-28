NAME=bsp

C_FLAGS = -Wall -Wextra -Werror

SRC = \
	Fixed \
	main \
	bcp \
	Point

INC = \
	Fixed \
	Point

SRC_CPP = $(addsuffix .cpp, $(SRC))
SRC_HPP = $(addsuffix .h, $(INC))
OBJ = $(addsuffix .o, $(SRC))

all: $(NAME)

$(NAME): $(SRC_CPP) $(OBJ)
	c++ $(C_FLAGS) $(SRC_CPP) -o $(NAME) -I $(SRC_HPP)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re