# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: estoffel <estoffel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 14:07:13 by estoffel          #+#    #+#              #
#    Updated: 2023/02/22 17:26:38 by estoffel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	containers

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror -Wno-unused -Wno-unused-variable -Wno-unused-parameter -Iincl -g3 -MMD -MP -std=c++98

DEFINE ?=

SRC		+=	map.cpp
SRC		+=	stack.cpp
SRC		+=	vector.cpp

OBJ		:=	$(addprefix ./obj/,$(SRC:%.cpp=%.o))

DEP		=	$(OBJ:%.o=%.d)

RM		=	rm -f

all: $(NAME)

test:
	./test.zsh

-include $(DEP)

./obj/%.o: ./src/%.cpp
	@mkdir -p $(@D)
	$(CC) $(FLAGS) $(DEFINE) -o $@ -c $<

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ)
	@printf "\n"
	@printf "\n"
	@printf "   🌼\033[1;97m C O N T A I N E R S  C R E A T E D  W I T H  S U C C E S S 🌼\e[0m\n"
	@printf "\n"
	@printf "				x\n"
	@printf "\n"
	@printf "		✨	~ \033[1;97mEnora\e[0m ~	✨\n"
	@printf "\n"
	@printf "\n"

clean:
	rm -rf obj/
	@printf "\n"
	@printf "💧\033[1;97m E V E R Y T H I N G  I S  C L E A N E D 💧\e[0m\n"
	@printf "\n"

fclean:
	rm -rf obj/
	$(RM) $(NAME)
	@printf "\n"
	@printf "💧\033[1;97m E V E R Y T H I N G  I S  C L E A N E D 💧\e[0m\n"
	@printf "\n"

re: fclean all

.PHONY: all clean fclean re test