# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/01 01:25:50 by mfunyu            #+#    #+#              #
#    Updated: 2021/10/05 21:37:34 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= megaphone
CXX		:= clang++
CXXFLAGS:= -Wall -Wextra -Werror

SRCS	:= megaphone.cpp
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

