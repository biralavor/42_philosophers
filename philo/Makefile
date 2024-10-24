# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 15:36:56 by umeneses          #+#    #+#              #
#    Updated: 2024/10/23 16:19:20 by umeneses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED				:= \033[0;31m
GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
PURPLE			:= \033[0;35m
CYAN			:= \033[0;36m
ORANGE			:= \033[0;91m
MAGENT			:= \033[0;95m
RESET			:= \033[0m

# **************************************************************************** #
#								PATHS										   #
# **************************************************************************** #

SRC_D					= ./src/
BONUS_D					= ./philo_bonus/
BUILD_D					= ./build/
HEADERS_ADDED			+= $(BONUS_D)headers/
HEADERS					= ./headers/ $(HEADERS_ADDED)

TDD_UTILS_D				= ./_tdd_utils/

# **************************************************************************** #
#								FILES										   #
# **************************************************************************** #

NAME					= philo

SRC_FILES				= 01.main.c
SRC_FILES				+= 02.parsing.c
SRC_FILES				+= 03.pthread_init.c
SRC_FILES				+= ft_atoi.c

SRC_FILES_ALL			= $(addprefix $(SRC_D), $(SRC_FILES))

OBJS_FILES				= $(addprefix $(BUILD_D), $(SRC_FILES_ALL:%.c=%.o))
OBJS_ALL				= $(OBJS_FILES)

# **************************** #
#			BONUS			   #
# **************************** #

NAME_BONUS				= philo_bonus

SRC_FILES_BONUS			= $(SRC_FILES_ALL)

SRC_BONUS_ALL			= $(addprefix $(SRC_BONUS_D), $(SRC_FILES_BONUS))

OBJS_FILES_BONUS		= $(addprefix $(BUILD_D), $(SRC_BONUS_ALL:%.c=%.o))
OBJS_ALL_BONUS			= $(OBJS_FILES_BONUS)

# **************************************************************************** #
#								COMMANDS									   #
# **************************************************************************** #

RM					= rm -rf
MKDIR				= mkdir -p
MV_OBJS				= find . -type f \( -name '.o' -o -name '.a'\) -exec mv {} \

# **************************************************************************** #
#								DEFINES										   #
# **************************************************************************** #

define	project_title
		@printf "$(CYAN)"
		@echo "                                                                    "
		@echo "#########################    WELCOME TO    #########################"
		@echo "                                                                    "
		@echo "              	  _ |_ .| _  _ _  _ |_  _  _ _					   "	
		@echo "              	 |_)| |||(_)_\(_)|_)| |(/_| _\					   "
		@echo "              	 |               |            					   "
		@echo "                                                                    "
		@echo "###########  in a spagetti dinner with chop-stickers  ##############"
		@echo "                                                                    "
		@printf "$(RESET)"
endef

define	project_title_bonus
		@printf "$(YELLOW)"
		@echo "                                                                    "
		@echo "#########################    WELCOME TO    #########################"
		@echo "                                                                    "
		@echo "                                                                    "
		@echo "                                                                    "
		@echo "####################################################################"
		@echo "                                                                    "
		@printf "$(RESET)"
endef

define				instructions
					@echo "Welcome to my Philosophers version!"
					@echo "Hit $(RESET)./$(NAME) $(YELLOW)and add:"
					@echo "$(CYAN)number_of_philosophers $(RED)time_to_die $(PURPLE)time_to_eat $(BLUE)time_to_sleep $(GREEN)nbr_each_philo_must_eat"
					@echo "$(YELLOW)Similar like this example:	$(RESET) ./$(NAME) $(CYAN)5 $(RED)800 $(PURPLE)200 $(BLUE)200"
					@echo "$(YELLOW)Or with $(GREEN)times_must_eat added:	$(RESET) ./$(NAME) $(CYAN)5 $(RED)800 $(PURPLE)200 $(BLUE)200 $(GREEN)7 "

endef

define				instructions_bonus
					@echo "Welcome to my Philosophers version!"
					@echo "Hit $(RESET)./$(NAME_BONUS) $(YELLOW)and add:"
					@echo "$(CYAN)number_of_philosophers $(RED)time_to_die $(PURPLE)time_to_eat $(BLUE)time_to_sleep $(GREEN)nbr_each_philo_must_eat"
					@echo "$(YELLOW)Similar like this example:	$(RESET) ./$(NAME_BONUS) $(CYAN)5 $(RED)800 $(PURPLE)200 $(BLUE)200"
					@echo "$(YELLOW)Or with $(GREEN)times_must_eat added:	$(RESET) ./$(NAME_BONUS) $(CYAN)5 $(RED)800 $(PURPLE)200 $(BLUE)200 $(GREEN)7 "				
endef

ifdef					WITH_BONUS
	NAME				= $(NAME_BONUS)
	OBJS_FILES			= $(OBJS_FILES_BONUS)
	OBJS_ALL			= $(OBJS_ALL_BONUS)
	project_title		= $(project_title_bonus)
	instructions		= $(instructions_bonus)
endif

define		bonus
			$(MAKE) WITH_BONUS=TRUE --no-print-directory
endef

define		args_to_test
			7
endef

# **************************************************************************** #
#								COMPILATION									   #
# **************************************************************************** #

AUTHOR		= umeneses
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
CPPFLAGS	= $(addprefix -I, $(HEADERS)) -MMD -MP
#LDFLAGS		= $(addprefix -L, $(dir $(LIBS)))
LDLIBS		= -ldl
PTHREAD		= -pthread
COMP_OBJS	= $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMP_EXE	= $(CC) $(CFLAGS) $(OBJS_ALL) $(LDLIBS) $(PTHREAD) -o $(NAME)

# **************************************************************************** #
#								TARGETS										   #
# **************************************************************************** #

all: 			$(NAME)

$(BUILD_D)%.o:	%.c
				@$(MKDIR) $(dir $@)
				@$(COMP_OBJS)
				@printf "$(CYAN)"
				@echo "$(NAME)	::	compiling file -> $(GREEN) $(notdir $<)"
				@printf "$(RESET)"

$(NAME):		$(OBJS_ALL)
				@$(COMP_EXE)
				@printf "$(GREEN)"
				@echo "--------------------------------------------------------------------"
				@echo "		$(NAME) READY!"
				@echo "--------------------------------------------------------------------"
				$(call project_title)
				@printf "$(YELLOW)"
				$(call instructions)
				@printf "$(RESET)"

bonus:
				$(call bonus)

clean:
				@printf "$(RED)"
				@echo ">>> Cleaning objects from: $(PURPLE) $(NAME)"
				@$(RM) $(OBJS)
				@$(RM) $(BUILD_D)
				@printf "$(RESET)"

fclean:			clean
				@printf "$(RED)"
				@echo ">>> Cleaning executables from: $(PURPLE) $(NAME)"
				@$(RM) $(NAME)
				@$(RM) $(NAME_BONUS)
				@printf "$(RESET)"

re:				fclean all
				./$(NAME)

go:				all
				./$(NAME) $(call args_to_test)

gdb:			all
				gdb --tui -ex 'b main' -ex 'set detach-on-fork off' -ex 'info inferiors' -ex 'set args $(call args_to_test)' -ex 'run' ./$(NAME)
#				gdb --tui -ex 'b main' -ex 'set detach-on-fork off' -ex 'info inferiors' -ex 'set args $(call args_to_test)' -ex 'run > /dev/null 2>&1' ./$(NAME)

val:			all
				valgrind --leak-check=full --track-origins=yes --trace-children=yes --track-fds=yes --show-reachable=yes ./$(NAME) $(call args_to_test)

.PHONY:			all clean fclean re bonus val gdb go