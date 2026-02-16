/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signalflag_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 16:13:11 by jericard          #+#    #+#             */
/*   Updated: 2025/11/11 16:13:12 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_signalflag(const char *str)
{
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	while (str[i] && !(str[i] >= '0' && str[i] <= '9') && str[i] != '.')
	{
		if (ft_typeverify(str[i]))
			break ;
		if (str[i] == ' ' && !flag)
			flag = 1;
		else if (str[i] == '+')
			flag = 2;
		else if (str[i] == '#')
			flag += 10;
		i++;
	}
	return (flag);
}
