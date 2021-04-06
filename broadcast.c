/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   broadcast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:24:41 by al-humea          #+#    #+#             */
/*   Updated: 2021/04/06 17:25:52 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "netwhat_utils.h"

void	broadcast_ip(int *broadcast, int *ip, int *sbmk)
{
	int	i;
	int	mlt;
	int	result;

	i = 0;
	mlt = 0;
	result = 0;
	while (i < 4)
	{
		if (sbmk[i] == 255)
			broadcast[i] = ip[i];
		if (sbmk[i] > 0 && sbmk[i] < 255)
		{
			mlt = 256 - sbmk[i];
			while (result <= ip[i])
				result += mlt;
			broadcast[i] = result - 1;
		}
		if (sbmk[i] == 0)
			broadcast[i] = 255;
		i++;
	}
	return ;
}