NAME=span

C_FLAGS = -Wall -Wextra -Werror

SRC = main.cpp, Span.cpp

INC = Span.hpp

OBJ = $(SRC:.cpp=.o)

EMOJI_COMPILE = 🛠️
EMOJI_RUN = 🚀
EMOJI_DONE = ✅
EMOJI_CLEANING = 🧹

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[33m~~~~START~~~~\033[0m"
	@c++ $(C_FLAGS) $(OBJ) -o $(NAME)
	@echo "\033[34mCompilation: DONE! $(EMOJI_DONE)"
	@echo "Let's test the program!\033[0m $(EMOJI_RUN)"

%.o: %.cpp $(INC)
	@c++ $(C_FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "\033[34mREMOVE: .o files\033[0m $(EMOJI_CLEANING)"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[34mREMOVE: $(NAME)\033[0m $(EMOJI_CLEANING)"
	@echo "\033[31m~~~~THE END~~~~\033[0m"

re: fclean all

.PHONY: all clean fclean re