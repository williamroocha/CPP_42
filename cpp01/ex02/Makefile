NAME = HiThisIsBrain
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp 

RED=\033[1;31m
GREEN=\033[1;32m
RST=\033[0m

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo -e "$(GREEN) >> $(NAME) is ready to use $(RST)"

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)
	@echo -e "$(RED) >> $(NAME) is deleted $(RST)"

re : fclean all

%.o : %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@