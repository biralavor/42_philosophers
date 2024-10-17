# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umeneses@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 15:36:56 by umeneses          #+#    #+#              #
#    Updated: 2024/10/17 16:02:15 by umeneses         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RED				:= \033[0;31m
GREEN			:= \033[0;32m
YELLOW			:= \033[0;33m
BLUE			:= \033[0;34m
PURPLE			:= \033[0;35m
CYAN			:= \033[0;36m
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
#SRC_FILES				+= 02.xxxxx.c

SRC_FILES_ALL			= $(addprefix $(SRC_D), $(SRC_FILES))

OBJ_FILES				= $(addprefix $(BUILD_D), $(SRC_FILES:%.c=%.o))
OBJ_ALL					= $(OBJ_FILES)

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
		@echo "                                                                    "
		@echo "                                                                    "
		@echo "####################################################################"
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
					@echo "Hit ./$(NAME) and add:"
					@echo "number_of_philosophers"
					@echo "time_to_die"
					@echo "time_to_eat"
					@echo "time_to_sleep"
					@echo "number_of_times_each_philosopher_must_eat - OPTIONAL"
					@echo "Similar like this example: ./$(NAME) 5 800 200 200"
					@echo "Or like this one with times_must_eat: ./$(NAME) 5 800 200 200 7"

endef

define				instructions_bonus
					@echo "Welcome to my Philosophers version!"
					@echo "Hit ./$(NAME_BONUS) and add:"
					@echo "number_of_philosophers"
					@echo "time_to_die"
					@echo "time_to_eat"
					@echo "time_to_sleep"
					@echo "number_of_times_each_philosopher_must_eat - OPTIONAL"
					@echo "Similar like this example: ./$(NAME_BONUS) 5 800 200 200"
					@echo "Or like this one with times_must_eat: ./$(NAME_BONUS) 5 800 200 200 7"
endef

ifdef					WITH_BONUS
	NAME				= $(NAME_BONUS)
	OBJS_FILES			= $(OBJS_FILES_BONUS)
	OBJS_ALL			= $(OBJS_ALL_BONUS)
	project_title		= $(project_title_bonus)
	instructions		= $(instructions_bonus)
endif

define					bonus
						$(MAKE) WITH_BONUS=TRUE --no-print-directory
endef

# **************************************************************************** #
#								COMPILATION									   #
# **************************************************************************** #

AUTHOR		= umeneses
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g3
CPPFLAGS	= $(addprefix -I, $(HEADERS)) -MMD -MP
#LDFLAGS		= $(addprefix -L, $(dir $(LIBS)))
LDLIBS		= -lft -ldl -lpthread
COMP_OBJS	= $(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
COMP_EXE	= $(CC) $(CFLAGS) $(OBJS_ALL) $(LDLIBS) -o $(NAME)

# **************************************************************************** #
#								TARGETS										   #
# **************************************************************************** #

all:			$(NAME)

$(BUILD_D)%.o:	%.c
				@$(MKDIR) $(dis $@)
				@$COMP_OBJS)
				@printf "$(CYAN)"
				@echo "$(NAME)	compiling -> $(GREEN) $(notdir $<)""
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
				./$(NAME)

gdb:			all
				gdb --tui -ex 'b main' -ex 'set detach-on-fork off' -ex 'info inferiors' -ex 'run > /dev/null 2>&1' ./$(NAME)

val:			re
				valgrind --leak-check=full --track-origins=yes --trace-children-skip='*/bin/*,*/sbin/*,/usr/bin/*' --trace-children=yes --track-fds=yes --show-reachable=yes ./$(NAME)

.PHONY:			all clean fclean re bonus val gdb