NAME = megaphone

C_FLAGS = -Wall -Werror -std=c++98 -Werror

SRC = megaphone.cpp

OBJ = $(addsuffix .o, $(SRC))

all: $(NAME)

$(NAME):
	c++ $(C_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re