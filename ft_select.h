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

typedef struct  s_select
{
    char **args;
}               t_select;                   

void    clear_str();
void    print_select_args(t_select *s_stuff);