/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecavallo <lecavallo@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 12:14:59 by lecavallo         #+#    #+#             */
/*   Updated: 2025/12/23 12:49:03 by lecavallo        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "printf.h"

int main()
{
    int test1, test2;

    printf("Start the test, in this order: %%c %%s %%p %%d %%i %%u %%x %%X %%  \n\n");

    printf("Test for %%c \n");
    printf("CV: %c \n", 'c');
    ft_pritf("MV: %c \n", 'c');

    
    return (1);
}
