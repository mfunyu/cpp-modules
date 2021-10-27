# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 23:45:01 by mfunyu            #+#    #+#              #
#    Updated: 2021/10/27 12:02:02 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= a.out
CXX		:= clang++
CXXFLAGS:= -Wall -Wextra -Werror

SRCS	:= main.cpp \
			Fixed.cpp
OBJS	:= $(SRCS:.cpp=.o)

.PHONY : all clean fclean re

all : $(NAME)

$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^
clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re	: fclean all


#################

difftest	:
	curl https://raw.githubusercontent.com/mfunyu/cpp-module-02/test/difftest.sh > ../difftest.sh
	curl https://raw.githubusercontent.com/mfunyu/cpp-module-02/test/ex00_expected.txt > ../ex00_expected.txt
	cd ../ && ./difftest 0
