/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrodzin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:01:55 by agrodzin          #+#    #+#             */
/*   Updated: 2018/08/16 08:54:06 by agrodzin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	clear_scr(void)
{
	char	buf2[30];
	char	*ap;
	char	*clearstr;

	ap = buf2;
	clearstr = tgetstr("cl", &ap);
	ft_putstr_fd(clearstr, 0);
}
