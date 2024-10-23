NAME = Bureaucrat

C_FLAGS = -Wall -Wextra -Werror

SRC = Bureaucrat.cpp main.cpp From.cpp

INC = Bureaucrat.hpp Form.hpp

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