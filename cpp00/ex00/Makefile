NAME = megaphone
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = megaphone.cpp

COLOUR_GREEN=\033[1;32m
COLOUR_END=\033[0m

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(COLOUR_GREEN) >> $(NAME) is ready to use $(COLOUR_END)"

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

%.o : %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@