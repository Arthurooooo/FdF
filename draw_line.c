/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:28:06 by argonthi          #+#    #+#             */
/*   Updated: 2019/05/28 18:01:06 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FDF.h"

void draw_line(void* mlx_ptr, void* win_ptr, int x0, int y0, int x1, int y1)
{
 
  int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
  int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1; 
  int err = (dx>dy ? dx : -dy)/2, e2;
 
  while(x0!=x1 || y0!=y1){
    mlx_pixel_put(mlx_ptr, win_ptr, x0, y0, 0x3399FF);
    e2 = err;
    if (e2 >-dx) { err -= dy; x0 += sx; }
    if (e2 < dy) { err += dx; y0 += sy; }
  }

}
 