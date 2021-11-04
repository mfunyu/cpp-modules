NAME	:= a.out
CXX		:= clang++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic-errors

SRCS	:= main.cpp \
			Bureaucrat.cpp \
			Form.cpp \
			Intern.cpp \
			PresidentialPardonForm.cpp \
			RobotomyRequestForm.cpp \
			ShrubberyCreationForm.cpp
OBJS_DIR:= objs/
OBJS	:= $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))

.PHONY	: all clean fclean re

all	: $(NAME)

$(NAME)	: $(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(OBJS_DIR)%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJS_DIR):
	@mkdir $@

clean	:
	$(RM) -R $(OBJS_DIR)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all