NAME = ex02
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \

RED = \033[1;31m
GREEN = \033[1;32m
RST = \033[0m

OBJDIR = obj
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

# Rule for building the executable
all: $(NAME)

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN) >> $(NAME) is ready to use $(RST)"

# Rule for building object files
$(OBJDIR)/%.o: %.cpp | $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "$(GREEN) >> Compiled $< successfully $(RST)"

# Create the object directory if it doesn't exist
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Cleaning rules
clean:
	@rm -rf $(OBJDIR)
	@echo "$(RED) >> Object files cleaned $(RST)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED) >> $(NAME) is deleted $(RST)"

re: fclean all

# Valgrind testing rule
val: $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re val
