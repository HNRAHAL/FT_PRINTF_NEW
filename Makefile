NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c\
		hex_functions.c\
		num_related_functions.c\
		str_related_functions.c\

BONUS = c_format.c\
		d_and_i_format.c\
		new_hex_functions.c\
		hex_lower_helper_one.c\
		hex_upper_helper_one.c\
		num_functions.c\
		number_helper_one.c\
		number_helper_two.c\
		p_format.c\
		s_format.c\
		str_functions.c\
		u_format.c\
		x_lower_format.c\
		X_upper_format.c\
		ft_printf_bonus.c

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

.PHONY: all bonus clean fclean re