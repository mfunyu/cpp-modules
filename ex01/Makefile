# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/12 23:45:01 by mfunyu            #+#    #+#              #
#    Updated: 2021/10/27 22:09:35 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= a.out
CXX		:= clang++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic-errors

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

.PHONY	: test

../difftest.sh	:
	curl https://raw.githubusercontent.com/mfunyu/cpp-module-02/test/difftest.sh > ../difftest.sh
	chmod 755 ../difftest.sh

../ex01_expected.txt:
	curl https://raw.githubusercontent.com/mfunyu/cpp-module-02/test/ex01_expected.txt > ../ex01_expected.txt

test	: ../difftest.sh ../ex01_expected.txt
	cd ../ && ./difftest.sh 1
