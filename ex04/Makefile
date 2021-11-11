# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/17 18:28:42 by mfunyu            #+#    #+#              #
#    Updated: 2021/11/11 15:13:50 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= replace
CXX		:= clang++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic-errors -MMD -MP

SRCS	:= main.cpp \
			Replace.cpp
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
	$(RM) -R $(OBJS_DIR) *.replace */*.replace */*/*.replace

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

# ---------------------------------------------------------------------------- #

.PHONY	: test

TESTER	:= ./tester_cpp01/test.sh

$(TESTER):
	git clone github.com:mfunyu/tester_cpp01.git

test	: $(NAME) $(TESTER)
	@$(RM) *.replace */*.replace */*/*.replace
	$(TESTER)
