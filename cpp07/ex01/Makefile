NAME=iter

C_FLAGS = -Wall -Wextra -Werror

SRC = main.cpp

INC = iter.hpp

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[33m~~~~START~~~~\033[0m"
	@c++ $(C_FLAGS) $(OBJ) -o $(NAME)
	@echo "\033[34mCompilation: DONE!"
	@echo "Let's test the program!\033[0m"

%.o: %.cpp $(INC)
	@c++ $(C_FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "\033[34mREMOVE: .o files\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[34mREMOVE: $(NAME)\033[0m"
	@echo "\033[31m~~~~THE END~~~~\033[0m"

re: fclean all

.PHONY: all clean fclean re