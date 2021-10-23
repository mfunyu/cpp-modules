# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/17 18:28:42 by mfunyu            #+#    #+#              #
#    Updated: 2021/10/23 15:13:43 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= replace
CXX		:= clang++
CXXFLAGS:= -Wall -Wextra -Werror

SRCS	:= main.cpp \
			replace.cpp
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
