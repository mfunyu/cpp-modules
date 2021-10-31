# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 14:53:57 by mfunyu            #+#    #+#              #
#    Updated: 2021/10/31 22:10:07 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= a.out
SRCS	:= main.cpp \
			AMateria.cpp \
			Cure.cpp \
			Ice.cpp \
			Character.cpp \
			MateriaSource.cpp

CXX		:= clang++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic -Wshadow
OBJ_DIR	:= objs/
OBJS	:= $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

.PHONY	: all clean fclean re

all	: $(NAME)

$(NAME)	: $(OBJ_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(OBJ_DIR)%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ_DIR):
	@mkdir $@

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all
