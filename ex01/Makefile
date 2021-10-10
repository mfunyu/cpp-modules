# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/01 01:25:50 by mfunyu            #+#    #+#              #
#    Updated: 2021/10/11 01:08:36 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= phonebook
CXX		:= clang++
CXXFLAGS:= -Wall -Wextra -Werror

SRCS	:= phonebook.cpp \
			add.cpp \
			search.cpp \
			contact.cpp
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

