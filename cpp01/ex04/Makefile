NAME = sedIsForLosers

C_FLAGS = -Wall -Wextra -Werror

SRC = main

SRC_CPP = $(addsuffix .cpp, $(SRC))
OBJ = $(addsuffix .o, $(SRC))

all: $(NAME)

$(NAME): $(SRC_CPP) $(OBJ)
	c++ $(C_FLAGS) $(SRC_CPP) -o $(NAME)

clean:
	rm -f $(OBJ) text.txt.replace

fclean: clean
	rm -f $(NAME) 

re: fclean all

.PHONY: all clean fclean re
