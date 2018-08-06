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

typedef struct  s_select
{
    char **args;
}               t_select;                   

void    clear_str();