NAME := libft.a
FILE_BONUS := .bonus
CC := cc
C_FLAGS := -Wall -Wextra -Werror
AR := ar
AR_FLAGS := -rcs
INCLUDES := libft.h
SRC :=  ft_atoi.c ft_bzero.c ft_calloc.c ft_isalpha.c 				\
		ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c 		\
		ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c 				\
		ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c 	\
		ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c 		\
		ft_strdup.c ft_striteri.c ft_strjoin.c ft_strlen.c 			\
		ft_strlcpy.c ft_strlcat.c ft_strmapi.c ft_strrchr.c 		\
		ft_strtrim.c ft_substr.c ft_toupper.c ft_tolower.c 			\
		ft_strncmp.c ft_strnstr.c
OBJ := $(SRC:.c=.o)

BONUS_SRC := $(SRC) ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c 		\
					ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c	 	\
					ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c
BONUS_OBJ := $(BONUS_SRC:.c=.o)

RM := rm -f

all : $(NAME)

$(NAME) : $(OBJ)
	$(AR) $(AR_FLAGS) $@ $^

%.o : %.c $(INCLUDES)
	$(CC) $(C_FLAGS) -c -o $@ $<

bonus : $(FILE_BONUS)
   
$(FILE_BONUS) : $(BONUS_OBJ)
	$(AR) $(AR_FLAGS) $(NAME) $(BONUS_OBJ) 
	touch $(FILE_BONUS) 

clean :
	$(RM) $(OBJ) $(BONUS_OBJ) $(FILE_BONUS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re
