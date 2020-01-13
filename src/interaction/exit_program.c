/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpattij <dpattij@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 02:24:04 by dpattij           #+#    #+#             */
/*   Updated: 2020/01/06 09:53:58 by dpattij          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <interaction.h>
#include <stdlib.h>

void	exit_program(t_draw_obj *drawer)
{
	drawer_destroy(drawer);
	exit(0);
}

int		exit_program_i(t_draw_obj *drawer)
{
	drawer->window_gone = true;
	exit_program(drawer);
	return (0);
}
