/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   netwhat_utils.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: al-humea <al-humea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 15:24:25 by al-humea          #+#    #+#             */
/*   Updated: 2021/04/06 15:25:01 by al-humea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NETWHAT_UTILS_H
# define NETWHAT_UTILS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct ip_infos
{
	int		subnet[4];
	int		broadcast[4];
	int		referenceable;
} ip_infos;

/* CIDR */
int		cidr_modulo(int	modulo);
void	cidr_subnet(int	*subnet_mask, int cidr);

/* BROADCAST */
void	broadcast_ip(int *broadcast, int *ip, int *sbmk);

/* IP_MASK*/
void	read_ip(int	*ip);
void	store_ip_infos(ip_infos *current, int *ip, int cidr);

#endif