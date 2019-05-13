/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 08:47:35 by agrodzin          #+#    #+#             */
/*   Updated: 2018/08/16 11:48:24 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H
# include "libft/libft.h"
# include <sys/stat.h>
# include "libft/printf_functions/ft_printf.h"
# include <termcap.h>
# include <sys/ioctl.h>
# include <termios.h>
# include <signal.h>
# define LEFT 0x445B1B
# define RIGHT 0x435B1B
# define SPACE 0x20
# define ENTER1 0xA
# define DEL 0x7F
# define DEL2 0x7E335B1B
# define ESCAPE 0x1B
# define RED   "\x1B[31m"
# define GREEN   "\x1B[32m"
# define BLUE  "\x1B[34m"
# define RESET "\x1B[0m"

typedef struct		s_select
{
	char			**args;
	int				row_len;
	int				col_len;
	int				pos;
	int				*selected;
	int				wc;
	int				wpc;
	struct termios	oldterm;
	struct termios	*old2;
}					t_select;

t_select			g_s_stuff;

void				clear_scr();
void				print_select_args(t_select *g_s_stuff);
int					get_left(t_select *g_s_stuff);
int					get_right(t_select *g_s_stuff);
int					get_space(t_select *g_s_stuff);
void				reprint_args(int i, t_select *g_s_stuff);
int					get_enter(t_select *g_s_stuff);
int					get_del(t_select *g_s_stuff);
void				rep2(t_select *g_s_stuff);
int					first_print(t_select *g_s_stuff);
void				sigrab();
void				reset_term();
int					initialize_select(t_select *g_s_stuff, char **argv,
										int argc);
int					gla(char **argv);
void				set_environ();
#endif
