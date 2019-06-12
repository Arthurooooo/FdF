/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FDF.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 20:07:08 by argonthi          #+#    #+#             */
/*   Updated: 2019/06/07 01:47:39 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <time.h> 
# include "libft/libft.h"
# include "GNL/get_next_line.h"
# include "hex.c"
# include "draw_line.c"
# include <unistd.h>


void    draw_line(void* mlx_ptr, void* win_ptr, int x0, int y0, int x1, int y1);
char*     random_hex(void);

#endif
#define BLUE 0x3399FF
#define PINK 0xf20c64
#define PRPL 0x671c9d
#define YELW 0xe5f928
#define KAKI 0x98af69
