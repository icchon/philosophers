NAME := philo
CC := cc
INCDIR := ./includes/
C_FLAGS := -Wall -Wextra -Werror
INC_FLAGS :=  -I$(INCDIR)

CORE_FILES := action.c philo_thread.c struct_fork.c take_fork.c monitor_thread.c print_log.c struct_info.c time.c philo_status.c release_fork.c struct_philosopher.c validate.c
CORE_SRCS := $(addprefix core/,$(CORE_FILES))

UTILS_FILES := ft_atoi.c ft_isdigit.c ft_isint.c ft_issign.c ft_isspace.c ft_strlen.c
UTILS_SRCS := $(addprefix utils/,$(UTILS_FILES))

FILES := main.c $(UTILS_SRCS) $(CORE_SRCS)
SRCS := $(addprefix src/,$(FILES))

OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(CC) $(C_FLAGS) $(INC_FLAGS) $(OBJS) -o $@ -lpthread 

.c.o: 
	$(CC) $(C_FLAGS) $(INC_FLAGS) -c $< -o $@ 

clean: 
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re 