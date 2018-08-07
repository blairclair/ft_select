CC=gcc
CFLAGS= -Wall -Wextra -Werror -ltermcap
SRCS=libft/ft_putchar.c\
libft/ft_strjoin.c\
libft/ft_strcat.c\
libft/ft_putstr.c\
libft/ft_putnbr.c\
libft/ft_strcmp.c\
libft/ft_toupper.c\
libft/ft_strlen.c\
libft/ft_itoa_base.c\
libft/ft_isdigit.c\
libft/ft_strcpy.c\
libft/ft_isalpha.c\
libft/ft_atoi.c\
libft/ft_strtoupper.c\
libft/ft_bzero.c\
libft/ft_strnew.c\
libft/ft_strdup.c\
libft/ft_memmove.c\
libft/ft_strchr.c\
libft/ft_strncpy.c\
libft/ft_strsplit.c\
libft/ft_memalloc.c\
libft/ft_strtrim.c\
libft/ft_strdel.c\
libft/ft_memcpy.c\
libft/printf_functions/ft_putulong.c\
libft/printf_functions/ft_ltoa_base.c\
libft/printf_functions/ft_ultoa_base.c\
libft/printf_functions/ft_itoa.c\
libft/printf_functions/ft_strrev.c\
libft/printf_functions/parse.c\
libft/printf_functions/flags_1.c\
libft/printf_functions/ft_putnbr_pr.c\
libft/printf_functions/flags2.c\
libft/printf_functions/get_d.c\
libft/printf_functions/get_x.c\
libft/printf_functions/get_x2.c\
libft/printf_functions/get_cs.c\
libft/printf_functions/get_op.c\
libft/printf_functions/get_loc_value.c\
libft/printf_functions/get_num_lets.c\
libft/printf_functions/get_sizes.c\
libft/printf_functions/print_extra_flags.c\
libft/printf_functions/print_extra_stuff.c\
libft/printf_functions/ft_printf.c\
clear_screen.c\
print_args.c\
get_left.c\
get_right.c\
get_space_enter.c\
ft_select.c
NAME=ft_select

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) -c $(SRCS)
	$(CC) $(CFLAGS) -o $(NAME) $(SRCS)
clean:
	/bin/rm -f *.o
	make -C libft/ clean
fclean: clean
	/bin/rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
