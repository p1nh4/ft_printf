NAME 		:= libftprintf.a
CC			:= cc
C_FLAGS 	:= -Wall -Wextra -Werror -gdwarf-4
AR			:= ar
AR_FLAGS	:= -rcs
SRC_DIR		:= src
OBJ_DIR		:= obj
LIB			:= lib
LIBFT		:= $(LIB)/libft.a
INCLUDE_DIR := include
SRC 		:= $(SRC_DIR)/ft_printf.c 			\
			   $(SRC_DIR)/ft_print_str.c		\
			   $(SRC_DIR)/ft_print_ptr.c		\
			   $(SRC_DIR)/ft_print_int.c		\
			   $(SRC_DIR)/ft_print_uint.c		\
			   $(SRC_DIR)/ft_print_num_rev.c	\
			   $(SRC_DIR)/ft_print_hex.c		\
			   $(SRC_DIR)/ft_print_percent.c	\
			   $(SRC_DIR)/ft_printf_conv.c		\
			   $(SRC_DIR)/ft_print_char.c
INCLUDES	:= -I$(INCLUDE_DIR) -I$(LIB)
OBJ 		:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
RM := rm -f

all : $(LIBFT) $(NAME)

$(NAME) : $(OBJ)
	cp $(LIBFT) $(NAME)
	$(AR) $(AR_FLAGS) $@ $^

$(LIBFT) :
	$(MAKE) -C $(LIB)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(C_FLAGS) $(INCLUDES) -c -o $@ $<

clean :
	$(RM) $(OBJ)
	$(MAKE) -C $(LIB) clean

fclean : clean
	$(RM) $(NAME)
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIB) fclean

re : fclean all

.PHONY: all clean fclean re




