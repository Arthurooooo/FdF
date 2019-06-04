/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:07:08 by argonthi          #+#    #+#             */
/*   Updated: 2019/05/28 16:00:02 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <mlx.h>
# include "GNL/get_next_line.h"
# include "libft/libft.h"
# include "draw_line.c"
# define BLUE 0x3399FF

void    draw_line(void* mlx_ptr, void* win_ptr, int x0, int y0, int x1, int y1);

#endif
