# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: umeneses <umenses@student.42.fr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/17 15:36:56 by umeneses          #+#    #+#              #
#    Updated: 2025/01/29 19:32:48 by umeneses         ###   ########.fr        #
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
SRC_FILES				+= 02.arg_validation.c
SRC_FILES				+= 03.parsing.c
SRC_FILES				+= 04.clear_and_error_manager.c
SRC_FILES				+= 05.mutex_handlers.c
SRC_FILES				+= 06.pthread_handlers.c
SRC_FILES				+= 07.table_philo_init.c
SRC_FILES				+= 08.dinner_manager.c
SRC_FILES				+= 09.getters_setters.c
SRC_FILES				+= 10.synchronizers.c
SRC_FILES				+= 11.printer_with_mutex.c
SRC_FILES				+= 12.dinner_routines.c
SRC_FILES				+= 13.monitor.c
SRC_FILES				+= ft_atoi_long.c
SRC_FILES				+= ft_gettime.c
SRC_FILES				+= ft_is_digit.c
SRC_FILES				+= ft_is_space.c
SRC_FILES				+= ft_precise_usleep.c
SRC_FILES				+= ft_safe_malloc.c
SRC_FILES				+= ft_strlen.c

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
		@echo "##############  in a spagetti dinner with chopsticks  ##############"
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
					@echo "Hit $(RESET)./$(NAME) $(YELLOW)adding a few arguments:"
					@echo "\n$(RESET)./$(NAME) $(CYAN)total_PHILOS $(RED)timeto_DIE $(PURPLE)timeto_EAT $(BLUE)timeto_SLEEP $(GREEN)how_many_MEALS_perPhilo"
					@echo "\n$(YELLOW)Here is a minimal example to run:		$(RESET) ./$(NAME) $(CYAN)5 $(RED)800 $(PURPLE)200 $(BLUE)200"
					@echo "$(YELLOW)Or a complex version with $(GREEN)how_many_meals$(YELLOW):	$(RESET) ./$(NAME) $(CYAN)5 $(RED)800 $(PURPLE)200 $(BLUE)200 $(GREEN)7 "
					@echo "\n$(RESET)Let's test the Threads!\n"

endef

define				instructions_bonus
					@echo "Welcome to my Philosophers BONUS version!"
					@echo "Hit $(RESET)./$(NAME_BONUS) $(YELLOW)adding a few arguments:"
					@echo "\n$(RESET)./$(NAME_BONUS) $(CYAN)total_PHILOS $(RED)timeto_DIE $(PURPLE)timeto_EAT $(BLUE)timeto_SLEEP $(GREEN)how_many_MEALS_perPhilo"
					@echo "\n$(YELLOW)Here is a minimal example to run:		$(RESET) ./$(NAME_BONUS) $(CYAN)5 $(RED)800 $(PURPLE)200 $(BLUE)200"
					@echo "$(YELLOW)Or a complex version with $(GREEN)how_many_meals$(YELLOW):	$(RESET) ./$(NAME) $(CYAN)5 $(RED)800 $(PURPLE)200 $(BLUE)200 $(GREEN)7 "
					@echo "\n$(RESET)Let's test the Threads!\n"
endef

ifdef				WITH_BONUS
	NAME			= $(NAME_BONUS)
	OBJS_FILES		= $(OBJS_FILES_BONUS)
	OBJS_ALL		= $(OBJS_ALL_BONUS)
	project_title	= $(project_title_bonus)
	instructions	= $(instructions_bonus)
endif

define				bonus
					$(MAKE) WITH_BONUS=TRUE --no-print-directory
endef

define				args_to_test
	7 3010 1000 100 5
endef

ifdef				IN_DEBUG_MODE
CFLAGS				= $(DEBUGFLAGS)
endif

ifdef				WITH_SANITIZE_THREAD
CFLAGS				= $(DEBUGFLAGS) -fsanitize=thread
endif

ifdef				WITH_SANITIZE_ADDRESS
CFLAGS				= $(DEBUGFLAGS) -fsanitize=address
endif

define				debug_mode_on
					@echo "$(PURPLE)\nDebug mode is $(YELLOW)ON$(RESET)\n"
					$(MAKE) IN_DEBUG_MODE=TRUE --no-print-directory
endef

define				sanitize_thread
					@echo "$(PURPLE)\nDebug with $(YELLOW)SANITIZE=THREAD$(RESET)\n"
					$(MAKE) WITH_SANITIZE_THREAD=TRUE --no-print-directory
endef

define				sanitize_address
					@echo "$(PURPLE)\nDebug with $(YELLOW)SANITIZE=ADDRESS$(RESET)\n"
					$(MAKE) WITH_SANITIZE_ADDRESS=TRUE --no-print-directory
endef

# **************************************************************************** #
#								COMPILATION									   #
# **************************************************************************** #

AUTHOR		= umeneses
CC			= cc
DEBUGFLAGS	= -Wall -Wextra -Werror -g3						# Debug
CFLAGS		= -Wall -Wextra -Werror -g -pedantic			# ISO C and C++ standards
LFLAGS		= -march=native									# User's CPU Architecture Optimization
OPTIMIZE	= -Ofast -flto									# Maximum Optimization
CPPFLAGS	= $(addprefix -I, $(HEADERS)) -MMD -MP			# Track Changes in User Dependencies
PTHREAD		= -pthread										# POSIX Threads
NOWRITEFLAG	= -Wno-unused-result							# Ignore Unused Return Values of write()
COMP_OBJS	= $(CC) $(CFLAGS) $(OPTIMIZE) $(CPPFLAGS) $(PTHREAD) $(NOWRITEFLAG) -c $< -o $@
COMP_EXE	= $(CC) $(CFLAGS) $(OPTIMIZE) $(CPPFLAGS) $(PTHREAD) $(LFLAGS) $(OBJS_ALL) -o $(NAME)

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

help:			all
				$(call instructions)

re:				fclean all

go:				re
				./$(NAME) $(call args_to_test)

gdb:			re
				gdb --tui \
				-ex 'b main' \
				-ex 'set detach-on-fork off' \
				-ex 'info inferiors' \
				-ex 'set args $(call args_to_test)' \
				-ex 'run' ./$(NAME)
#				-ex 'run > /dev/null 2>&1' ./$(NAME)

val:			re
				valgrind \
				--leak-check=full \
				--track-origins=yes \
				--trace-children=yes \
				--track-fds=yes \
				--show-reachable=yes ./$(NAME) $(call args_to_test)

hel:			re
				valgrind \
				--tool=helgrind ./$(NAME) $(call args_to_test)
#				--read-var-info=yes ./$(NAME) $(call args_to_test)
# documentation: https://valgrind.org/docs/manual/hg-manual.html

drd:			re
				valgrind \
				--tool=drd \
				--read-var-info=yes ./$(NAME) $(call args_to_test)
# documentation: https://valgrind.org/docs/manual/drd-manual.html

sani_t:			fclean
				$(call sanitize_thread)
				./$(NAME) $(call args_to_test)
				

sani_a:			fclean
				$(call sanitize_address)
				./$(NAME) $(call args_to_test)

debug:			fclean
				$(call debug_mode_on)
				./$(NAME) $(call args_to_test)

.PHONY:			all clean fclean help re bonus go gdb val hel drd sani_t sani_a debug
