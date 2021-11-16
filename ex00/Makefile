# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/29 14:53:57 by mfunyu            #+#    #+#              #
#    Updated: 2021/11/16 14:21:43 by mfunyu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:= a.out
SRCS	:= main.cpp \
			Animal.cpp \
			Dog.cpp \
			Cat.cpp

CXX		:= clang++
CXXFLAGS:= -Wall -Wextra -Werror -std=c++98 -pedantic -MMD -MP
OBJS_DIR:= objs/
OBJS	:= $(addprefix $(OBJS_DIR), $(SRCS:.cpp=.o))
DEPS	:= $(OBJS:.o=.d)

.PHONY	: all clean fclean re

all	: $(NAME)

-include $(DEPS)

$(NAME)	: $(OBJS_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

$(OBJS_DIR)%.o : %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(OBJS_DIR):
	@-mkdir $@

clean	:
	$(RM) -R $(OBJS_DIR)

fclean	: clean
	$(RM) $(NAME) $(W_NAME)

re		: fclean all

# ---------------------------------------------------------------------------- #

.PHONY	: wrong

W_NAME	:= wrong.out
W_SRCS	:= wrong_main.cpp \
			WrongAnimal.cpp \
			WrongCat.cpp

VPATH	:= ./wrong/
W_OBJS	:= $(addprefix $(OBJS_DIR), $(W_SRCS:.cpp=.o))

wrong	: $(W_NAME)

$(W_NAME): $(OBJS_DIR) $(W_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(W_OBJS)