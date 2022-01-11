# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mda-silv <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 17:31:07 by mda-silv          #+#    #+#              #
#    Updated: 2022/01/11 17:31:08 by mda-silv         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS		+= --quiet

NAME		     = container

INCS			 = containers/map.hpp containers/set.hpp containers/stack.hpp \
					containers/vector.hpp \
					incs/compare.hpp incs/enable_if.hpp incs/is_integral.hpp \
					incs/iterator.hpp incs/iterator_traits.hpp \
					incs/pair.hpp incs/rbt_iter.hpp incs/red_black_tree.hpp \
					incs/reverse_iterator.hpp incs/utils.hpp

SRCS			= srcs/main.cpp

OBJS			= ${SRCS:%.cpp=%.o}

OBJS_DIR		= objs

CPP 			= clang++

CFLAGS			= -Wall -Wextra -Werror -std=c++98 -fsanitize=address

RM				= rm -rf

DEL			= \033[1;35m\033[1;47m
SUCCESS		= \033[1;32m\033[1;44m

all:			$(NAME)

$(NAME):		$(OBJS) $(INCS)
				$(CPP) $(CFLAGS) $(OBJS) -o $(NAME)
				mv $(OBJS) $(OBJS_DIR)
				@echo "${SUCCESS}compiled file\n"	

%.o:%.cpp 		$(INCS)
				$(CPP) $(CFLAGS) $(INCS)
				$(CPP) -g $(CFLAGS) -c $< -o $@
				@mkdir $(OBJS_DIR)
				mv containers/*.gch $(OBJS_DIR)
				mv incs/*.gch $(OBJS_DIR)


clean:
			$(RM) $(OBJS_DIR) srcs/*.o incs/*.gch containers/*.gch
			@echo "${DEL}###### Deleting ######\n"
	
fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)

.PHONY:		all clean fclean re