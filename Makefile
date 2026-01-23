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
SRC 		:= $(SRC_DIR)/ft_printf.c 					\
			   $(SRC_DIR)/ft_print_str.c				\
			   $(SRC_DIR)/ft_print_ptr.c				\
			   $(SRC_DIR)/ft_print_int.c				\
			   $(SRC_DIR)/ft_print_uint.c				\
			   $(SRC_DIR)/ft_print_hex.c				\
			   $(SRC_DIR)/ft_print_percent.c			\
			   $(SRC_DIR)/ft_process_specifier.c		\
			   $(SRC_DIR)/ft_print_char.c

BONUS_SRC 	:= $(SRC_DIR)/ft_parse_flags_bonus.c					\
			   $(SRC_DIR)/ft_process_specifier_bonus.c				\
			   $(SRC_DIR)/ft_print_char_bonus.c						\
			   $(SRC_DIR)/ft_print_hex_bonus.c						\
			   $(SRC_DIR)/ft_print_int_bonus.c						\
			   $(SRC_DIR)/ft_print_percent_bonus.c					\
			   $(SRC_DIR)/ft_print_str_bonus.c						\
			   $(SRC_DIR)/ft_print_uint_bonus.c						\
			   $(SRC_DIR)/ft_printf_bonus.c							

INCLUDES	:= -I$(INCLUDE_DIR) -I$(LIB)
OBJ 		:= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
BONUS_OBJ	:= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(BONUS_SRC))
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

bonus : .bonus

.bonus : $(BONUS_OBJ) $(LIBFT)
	cp $(LIBFT) $(NAME)
	$(AR) $(AR_FLAGS) $(NAME) $(BONUS_OBJ)
	@touch .bonus

clean :
	$(RM) $(OBJ) $(BONUS_OBJ) .bonus
	$(MAKE) -C $(LIB) clean

fclean : clean
	$(RM) $(NAME)
	$(RM) -r $(OBJ_DIR)
	$(MAKE) -C $(LIB) fclean

re : fclean all

.PHONY: all clean fclean re
