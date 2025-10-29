NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c\
		hex_functions.c\
		num_related_functions.c\
		str_related_functions.c\

BONUS = ft_printf_bonus.c\
		c_and_s_format.c\
		str_functions.c\
		num_format.c\
		num_functions.c\
		num_helper_one.c\
		num_helper_two.c\
		u_num_format.c\
		new_hex_functions.c\
		p_address_format.c\
		p_address_helper_one.c\
		x_hex_lower_format.c\
		x_hex_lower_helper_one.c\
		x_hex_lower_helper_two.c\
		x_hex_upper_format.c\
		x_hex_upper_helper_one.c\
		x_hex_upper_helper_two.c\
		percent_case.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)


# bonus: $(OBJS) $(BONUS_OBJS)
# 	ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

bonus: $(BONUS_OBJS)
	ar rcs $(NAME) $(BONUS_OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	rm -f $(OBJS) $(BONUS_OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all  clean fclean re