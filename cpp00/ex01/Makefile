NAME = phonebook
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
	   Contact.cpp\
	   PhoneBook.cpp

GREEN=\033[1;32m
RED=\033[1;31m
RST=\033[0m

OBJS = $(SRCS:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN) >> $(NAME) is ready to use $(RST)"

clean :
	@rm -rf $(OBJS)

fclean : clean
	@rm -rf $(NAME)
	@echo "$(RED) >> $(NAME) is deleted $(RST)"

re : fclean all

%.o : %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@
