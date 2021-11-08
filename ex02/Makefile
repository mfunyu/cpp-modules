NAME	:= test
CXX		:= clang++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic-errors -MMD -MP

SRCS	:= Account.cpp \
			tests.cpp
OBJS_DIR:= objs/
OBJS	:= $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))
DEPS	:= $(OBJS:.o=.d)

.PHONY	: all clean fclean re

all	: $(NAME)

-include $(DEPS)

$(NAME)	: $(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(OBJS_DIR)%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJS_DIR):
	@mkdir $@

clean	:
	$(RM) -R $(OBJS_DIR)

fclean	: clean
	$(RM) $(NAME) $(TESTER) *.log

re	: fclean all

##############################

.PHONY	: tester

TESTER	:= cpp00-ex02_diff.sh

$(TESTER)	:
	curl -O https://raw.githubusercontent.com/mfunyu/tester_cpp-module/main/cpp00-ex02_diff.sh
	@chmod 755 $@

tester	: $(NAME) $(TESTER)
	./$(TESTER)
