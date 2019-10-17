/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argonthi <argonthi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 21:35:11 by argonthi          #+#    #+#             */
/*   Updated: 2019/10/11 16:48:58 by argonthi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

 
char* random_hex(void)
{
    int length;
    int i = 0;
    char hex;
    char static fullhex[8] = "000";
    char str[] = "0123456789ABCDEF";
    /* Seed number for rand() */
    srand((unsigned int) time(0) + getpid() + clock() );
        length = 6;

    while(length--) {

        hex = str[1 + rand() % 16];
        fullhex[i] = hex;
        i++;
        srand(rand());
    }
    return fullhex;
}