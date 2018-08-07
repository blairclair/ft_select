/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 08:47:35 by agrodzin          #+#    #+#             */
/*   Updated: 2018/08/06 08:47:38 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libft/printf_functions/ft_printf.h"
#include <termcap.h>
#include <sys/ioctl.h>
#include <termios.h>
#define LEFT (unsigned)ft_atoi("4479771d")
#define RIGHT (unsigned)ft_atoi("4414235d")
#define UP (unsigned)ft_atoi("4283163d")
#define DOWN (unsigned)ft_atoi("4348699d")
#define SPACE (unsigned)ft_atoi("4479776d")
#define SPACE2 (unsigned)ft_atoi("4414240d")

typedef struct  s_select
{
    char    **args;
    int     row_len;
    int     col_len;
    int     pos;
    int     *selected;
}               t_select;                   

void    clear_scr();
void    print_select_args(t_select *s_stuff);
int     get_row_col(t_select *s_stuff);
int     get_left(char *ap, t_select *s_stuff);
int     get_right(char *ap, t_select *s_stuff);
int     get_space(char *ap, t_select *s_stuff);
void    reprint_args(int i, t_select *s_stuff, char *ap);