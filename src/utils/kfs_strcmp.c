/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kfs_strcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aimustaev <aimustaev@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 01:22:32 by aimustaev         #+#    #+#             */
/*   Updated: 2023/04/04 01:22:33 by aimustaev        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int kfs_strcmp(const char *s1, const char *s2)
{
	int i;

	if (!s1 || !s2)
		return (-1);
	i = 0;
	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0')
			return (0);
		i++;
	}
	if (s1[i] > s2[i])
	{
		return 1;
	}
	else if (s1[i] < s2[i])
	{
		return -1;
	}
	return 0;
}
