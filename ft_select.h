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

#ifndef FT_SELECT_H
# define FT_SELECT_H
#include "libft/libft.h"
#include "libft/printf_functions/ft_printf.h"
#include <termcap.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <signal.h>
#define LEFT 0x445B1B
#define RIGHT 0x435B1B
//#define UP 0x415B1B
//#define DOWN 0x425B1B
#define SPACE 0x20
#define ENTER1 0xA
#define DEL 0x7F
#define DEL2 0x7E335B1B
# define ESCAPE 0x1B

int g_rowlen;
int g_collen;
int g_wc;
typedef struct  s_select
{
    char    **args;
    int     row_len;
 //   int     col_len;
    int     pos;
    int     *selected;
  //  int     rn;
   // int     wc;
    struct termios *oldterm;
}               t_select;                   

t_select s_stuff;

void    clear_scr();
void    print_select_args(t_select *s_stuff);
int     get_row_col(t_select *s_stuff);
int     get_left(t_select *s_stuff);
int     get_right(t_select *s_stuff);
int     get_space(t_select *s_stuff);
void    reprint_args(int i, t_select *s_stuff);
int     get_enter(t_select *s_stuff);
int     get_del(t_select *s_stuff);
void    rep2(t_select *s_stuff);

int     first_print(t_select *s_stuff);
void    sigrab();

#endif