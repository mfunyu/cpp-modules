# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/27 12:52:10 by mfunyu            #+#    #+#              #
#    Updated: 2021/10/28 16:55:23 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= a.out
CXX		:= clang++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic-errors

SRCS	:= main.cpp \
			ClapTrap.cpp
OBJS	:= $(SRCS:.cpp=.o)

.PHONY	: all clean fclean re

all	: $(NAME)

$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all