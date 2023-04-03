/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kfs_memset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimustaev <aimustaev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:14:04 by aimustaev         #+#    #+#             */
/*   Updated: 2023/04/04 01:15:54 by aimustaev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/types.h"

void *kfs_memset(void *b, int c, size_t len)
{
	size_t i;

	i = 0;
	while (i < len)
	{
		((char *)(b))[i] = c;
		i++;
	}
	return b;
}
