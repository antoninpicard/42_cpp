# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anpicard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/04 13:17:48 by anpicard          #+#    #+#              #
#    Updated: 2026/01/27 12:55:10 by anpicard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



#	MAKEFLAGS
MAKEFLAGS 				+=		 		--no-print-directory


#	COLORS
ERASE					:=				\033[2K\r
BLUE					:=				\033[34m
YELLOW					:=				\033[33m
GREEN					:=				\033[32m
RED						:=				\033[31m
END						:=				\033[0m


#	EXECUTABLE
NAME					:=				polymorphism


#	COMPILERS
CXX						:=				c++


#	PROJECT DIRECTORIES
DIR_OBJS				:=				.objs
DIR_DEPS				:=				.deps


#	FLAGS
FLAGS					:=				-Wall -Wextra -Werror -g3
DEPFLAGS				:=				-MMD -MP
CXXFLAGS				:=				$(FLAGS) $(DEPFLAGS) -std=c++98


#	SOURCES AND HEADERS
SRCS					:=				Animal.cpp Cat.cpp Dog.cpp main.cpp WrongAnimal.cpp WrongCat.cpp 

INCS					:=				Animal.hpp Cat.hpp Dog.hpp WrongAnimal.hpp WrongCat.hpp 


#	OBJECTS AND DEPENDENCIES
OBJS					:=				$(addprefix $(DIR_OBJS)/, $(notdir $(SRCS:.cpp=.o)))
DEPS					:=				$(addprefix $(DIR_DEPS)/, $(notdir $(SRCS:.cpp=.d)))



#	ALL RULE
.PHONY:			all
all:
											@if $(MAKE) -q $(NAME); then \
												printf "$(YELLOW)$(NAME) > Nothing to be done$(END)\n"; \
											else \
												$(MAKE) ${NAME}; \
											fi; 


#	COMPILE MAIN RULE
$(DIR_OBJS)/%.o:						%.cpp Makefile
											@mkdir -p $(DIR_OBJS) $(DIR_DEPS)
											@$(CXX) $(CXXFLAGS) -c $< -o $@
											@mv $(DIR_OBJS)/$(notdir $(basename $@)).d $(DIR_DEPS)/ 2>/dev/null || true
											@printf "$(BLUE)$(NAME) > Compiling : $(END)$<\n"


#	LINKING
${NAME}:								${OBJS}
											@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
											@printf "$(GREEN)$(NAME) > Done Compiling : $(END)$@\n"


#	INCLUDE DEPENDENCIES FILES
-include	$(DEPS)


#	CLEAN RULE
.PHONY:			clean
clean:
											@if [ ! -d $(DIR_OBJS) ] && [ ! -d $(DIR_DEPS) ]; then \
												printf "$(RED)$(NAME) > Nothing to clean $(END)\n"; \
											else \
												[ -d $(DIR_OBJS) ] && \
													rm -rf $(DIR_OBJS) && \
													printf "$(RED)$(NAME) > Done deleting : $(END)$(DIR_OBJS)\n"; \
												[ -d $(DIR_DEPS) ] && \
													rm -rf $(DIR_DEPS) && \
													printf "$(RED)$(NAME) > Done deleting : $(END)$(DIR_DEPS)\n"; \
											fi; true

#	FCLEAN RULE
.PHONY:			fclean
fclean:			clean
											@if [ -f $(NAME) ]; then \
												rm -rdf $(NAME); \
												printf "$(RED)$(NAME) > Done deleting : $(END)$(NAME)\n"; \
											fi;


#	REBUILD RULE
.PHONY:			re
re:				fclean	all


.PHONY:			run
run:			all
				@./$(NAME)
