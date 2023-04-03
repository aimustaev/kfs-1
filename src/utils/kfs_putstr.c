/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kfs_putstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimustaev <aimustaev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:22:28 by aimustaev         #+#    #+#             */
/*   Updated: 2023/04/04 01:22:28 by aimustaev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/kernel.h"

void kfs_putstr(t_terminal *term, const char *data)
{
	kfs_write(term, data, kfs_strlen(data));
}
