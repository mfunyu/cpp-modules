NAME	:= a.out
CXX		:= clang++
INCLUDE	:= -I.
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic-errors -MMD -MP $(INCLUDE)

SRCS	:= main.cpp
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
	@-mkdir $@


clean	:
	$(RM) -R $(OBJS_DIR)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

# ---------------------------------------------------------------------------- #

.PHONY	: test

FILE	:= getTypeName.hpp

ifdef TEST
CXXFLAGS += -D TEST
endif

test	: $(FILE)
	make TEST=1

$(FILE)	:
	curl -O https://raw.githubusercontent.com/mfunyu/cpp-module-07/test/ex02/getTypeName.hpp