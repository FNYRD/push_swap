/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signalflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jericard <jericard@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 12:25:32 by jericard          #+#    #+#             */
/*   Updated: 2025/12/30 12:25:34 by jericard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
