/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kfs_strlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimustaev <aimustaev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:22:34 by aimustaev         #+#    #+#             */
/*   Updated: 2023/04/04 01:22:35 by aimustaev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/types.h"

size_t kfs_strlen(const char *str)
{
    size_t len = 0;
    while (str[len])
        len++;
    return len;
}
