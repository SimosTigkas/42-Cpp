NAME = nowwearetalking

C_FLAGS = -Wall -Wextra -Werror

SRC = \
	Fixed \
	main

INC = Fixed

SRC_CPP = $(patsubst %, %.cpp, $(SRC))
SRC_HPP = $(patsubst %, %.h, $(INC))
OBJ = $(patsubst %, %.o, $(SRC))

all: $(NAME)

$(NAME): $(OBJ)
	c++ $(C_FLAGS) $(OBJ) -o $(NAME) -I $(INC)

%.o: %.cpp
	c++ $(C_FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re