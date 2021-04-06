/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ip_mask.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:24:46 by al-humea          #+#    #+#             */
/*   Updated: 2021/04/06 16:04:49 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "netwhat_utils.h"

int		power(int	nb, int pow)
{
	int nb_save;

	nb_save = nb;
	while (--pow)
		nb *= nb_save;
	return (nb);
}

void	read_ip(int	*ip)
{
	printf("%d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
	return ;
}

void	display_referenceable(ip_infos *current, int cidr)
{
	int	i;

	i = 0;
	printf("%d.%d.%d.%d - %d.%d.%d.%d ", current->subnet[0], current->subnet[1],
	current->subnet[2], current->subnet[3] + 1, current->broadcast[0],
	current->broadcast[1], current->broadcast[2], current->broadcast[3] - 1);
	printf("soit %d addresses hôtes possibles.\n\n", (power(2, (32 - cidr)) - 2));
	return ;
}

void	store_ip_infos(ip_infos *current, int *ip, int cidr)
{
	int i;
	int sbmk[4];

	i = 0;
	cidr_subnet(sbmk, cidr);
	printf("ip		=	");
	read_ip(ip);
	printf("subnet mask	=	");
	read_ip(sbmk);
	while (i < 4)
	{
		current->subnet[i] = ip[i] & sbmk[i];
		i++;
	}
	i = 0;
	broadcast_ip(current->broadcast, ip, sbmk);
}

int	main(void)
{
	int	ip[4];
	int	cidr;
	ip_infos *current;

	current = malloc(sizeof(ip_infos));
	current->broadcast[0] = 0;
	current->subnet[0] = 0;
	current->referenceable = 0;
//	printf("\e[1;1H\e[2J");
	printf("Entrez l'ip	=	");
	scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
	printf("CIDR		=	");
	scanf("%d", &cidr);
	write(1, "\n", 1);
	store_ip_infos(current ,ip, cidr);
	write(1, "\n", 1);
	printf("Addresse de sous réseau	=	");
	read_ip(current->subnet);
	printf("Addresse de broadcast	=	");
	read_ip(current->broadcast);
	printf("Addresses référençables	=	");
	display_referenceable(current, cidr);
	free(current);
	return (0);
}