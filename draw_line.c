/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 15:28:06 by argonthi          #+#    #+#             */
/*   Updated: 2019/10/19 04:02:41 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void draw_line(t_env *env, t_image *img, t_point src, t_point dest)
{

  int dx = fabs(dest.x-src.x), sx = src.x<dest.x ? 1 : -1;
  int dy = fabs(dest.y-src.y), sy = src.y<dest.y ? 1 : -1; 
  int err = (dx>dy ? dx : -dy)/2, e2;

   int nombre_aleatoire;
  char prefix[2] = "0x";
   char *charandom;
  if(!(charandom = (char *)malloc(8)))
  {
    return ;
      }
      charandom = random_hex();
 if(! (charandom = ft_strcat(prefix, charandom)) )
  {
    printf("NOT OKAY");
    return ;

  }
  nombre_aleatoire = strtol(charandom, NULL, 16);
  
  while((int)src.x!=(int)dest.x || (int)src.y!=(int)dest.y){
        pixel_to_image(img, src.x, src.y, PINK);
   // printf("\n");
    e2 = err;
    if (e2 >-dx) { err -= dy; if(src.x != dest.x){src.x += sx; }}
    if (e2 < dy) { err += dx; if(src.y != dest.y){src.y += sy; }}
    
  }
}
 