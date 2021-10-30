# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 14:53:57 by mfunyu            #+#    #+#              #
#    Updated: 2021/10/30 18:04:23 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= a.out
SRCS	:= main.cpp \
			Animal.cpp \
			Dog.cpp \
			Cat.cpp

CXX		:= clang++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic
OBJ_DIR	:= objs/
OBJS	:= $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

.PHONY	: all clean fclean re

all	: $(NAME)

$(NAME)	: $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJ_DIR)%.o : %.cpp $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJ_DIR):
	@mkdir $@

clean	:
	$(RM) $(OBJS) $(W_OBJS)

fclean	: clean
	$(RM) $(NAME) $(W_NAME)

re		: fclean all


####################################

.PHONY	: wrong

W_NAME	:= wrong.out
W_SRCS_DIR:= ./Wrong/
W_SRCS	:= wrong_main.cpp \
			WrongAnimal.cpp \
			WrongCat.cpp

VPATH	:= $(W_SRCS_DIR)
W_OBJS	:= $(addprefix $(OBJ_DIR), $(W_SRCS:.cpp=.o))

wrong	: $(W_OBJS)
	$(CXX) $(CXXFLAGS) -o $(W_NAME) $^

$(OBJ_DIR)%.o : %.cpp $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -o $@ -c $<