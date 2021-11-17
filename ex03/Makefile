# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 14:53:57 by mfunyu            #+#    #+#              #
#    Updated: 2021/11/17 20:43:14 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= a.out
SRCS	:= main.cpp \
			Character.cpp \
			AMateria.cpp \
			Cure.cpp \
			Ice.cpp \
			MateriaSource.cpp

VPATH	:= character/ materia/ materia_src/
CXX		:= clang++
INCLUDES:= -I character -I materia -I materia_src
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic $(INCLUDES)
OBJ_DIR	:= objs/
OBJS	:= $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

.PHONY	: all clean fclean re

all	: $(NAME)

$(NAME)	: $(OBJ_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(OBJ_DIR)%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ_DIR):
	@-mkdir $@

clean	:
	$(RM) $(OBJS)

fclean	: clean
	$(RM) $(NAME)

re		: fclean all

leak	: $(NAME)
	leaks -q --atExit -- ./$(NAME)

debug	:
	$(CXX) $(CXXFLAGS) -fsanitize=address -o $(NAME) $(SRCS)

# ---------------------------------------------------------------------------- #

.PHONY	: test

ifdef TEST
CXXFLAGS += -D TEST
endif

test	:
	make TEST=1