/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cidr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:24:32 by al-humea          #+#    #+#             */
/*   Updated: 2021/04/06 17:25:52 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "netwhat_utils.h"

int		cidr_modulo(int	modulo)
{
	int result;
	int from;

	from = 256;
	result = 0;
	while (modulo-- > 0)
	{
		from /= 2;
		result += from;
	}
	return (result);
}

void	cidr_subnet(int	*subnet_mask, int cidr)
{
	int	i;

	i = 0;
	while (i < (cidr / 8))
	{
		subnet_mask[i] = 255;
		i++;
	}
	if (0 < (cidr % 8))
	{
		subnet_mask[i] = cidr_modulo(cidr % 8);
		i++;
	}
	while (i < 4)
	{
		subnet_mask[i] = 0;
		i++;
	}
}