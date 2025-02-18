NAME := philo
CC := cc
INCDIR := ./includes/
C_FLAGS := -Wall -Wextra -Werror
LIBFT_DIR := ./libft/
LIBFT_ARCH := $(addsuffix libft.a, $(LIBFT_DIR))
INC_FLAGS :=  -I$(INCDIR) -I$(LIBFT_DIR)

SRCS := $(shell find ./src -name "*.c" -o -name "*.c")
OBJS := $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_ARCH)
	$(CC) $(C_FLAGS) $(INC_FLAGS) $(OBJS) $(LIBFT_ARCH) -o $@ -lpthread 

$(LIBFT_ARCH):
	make -C $(LIBFT_DIR)

.c.o: 
	$(CC) $(C_FLAGS) $(INC_FLAGS) -c $< -o $@ 

clean: 
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re 