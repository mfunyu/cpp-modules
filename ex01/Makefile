# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/01 01:25:50 by mfunyu            #+#    #+#              #
#    Updated: 2021/10/12 00:19:22 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= phonebook
CXX		:= clang++
CXXFLAGS:= -Wall -Wextra -Werror

SRCS	:= main.cpp \
			PhoneBook_add.class.cpp \
			PhoneBook_search.class.cpp \
			Contact.class.cpp
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

