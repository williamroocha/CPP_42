NAME = form
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp\
        Bureaucrat.cpp \
		AForm.cpp \
		ShrubberyCreationForm.cpp \

RED=\033[1;31m
GREEN=\033[1;32m
RST=\033[0m

OBJDIR = obj
OBJS = $(SRCS:%.cpp=$(OBJDIR)/%.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN) >> $(NAME) is ready to use $(RST)"

$(OBJDIR)/%.o : %.cpp | $(OBJDIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

clean :
	@rm -rf $(OBJDIR)

fclean : clean
	@rm -rf $(NAME)
	@echo "$(RED) >> $(NAME) is deleted $(RST)"

re : fclean all

val : $(NAME)
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY : all clean fclean re val

