NAME = megaphone

C_FLAGS = -Wall -Wextra -Werror

SRC = megaphone

SRC_CPP = $(addsuffix .cpp, $(SRC))
OBJ = $(addsuffix .o, $(SRC))

all: $(NAME)

$(NAME): $(SRC_CPP)
	c++ $(C_FLAGS) $(SRC_CPP) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re