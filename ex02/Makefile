# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/01 01:25:50 by mfunyu            #+#    #+#              #
#    Updated: 2021/10/15 23:37:53 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= test
CXX		:= clang++
CXXFLAGS:= -Wall -Wextra -Werror

SRCS	:= Account.cpp \
			tests.cpp
OBJS	:= $(SRCS:.cpp=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all

##############################

TESTER	:= cpp00-ex02_diff.sh

${TESTER}	:
	curl -O https://raw.githubusercontent.com/mfunyu/tester_cpp-module/main/cpp00-ex02_diff.sh

test	: ${TESTER}
	chmod 755 ${TESTER}
	./${TESTER}

