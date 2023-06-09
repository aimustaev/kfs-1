/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kfs_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimustaev <aimustaev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:13:48 by aimustaev         #+#    #+#             */
/*   Updated: 2023/04/04 01:16:00 by aimustaev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/kernel.h"

char *kfs_itoa(int n, char *str)
{
    int nb;
    size_t i;
    size_t len;

    nb = n;
    len = kfs_intlen(n);
    kfs_memset(str, 0, len + 1);

    if (nb < 0)
    {
        nb = -nb;
    }

    i = len - 1;

    if (nb == 0)
    {
        str[i] = '0';
        return;
    }

    while (nb != 0)
    {
        str[i--] = (nb % 10) + '0';
        nb = nb / 10;
    }

    if (n < 0)
    {
        str[i] = '-';
    }

    return str;
}
