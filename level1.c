/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnen <adnen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 00:26:46 by adnen             #+#    #+#             */
/*   Updated: 2026/03/13 00:41:13 by adnen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    char input[100]; // On crée un tableau fixe (pas besoin de malloc/free)

    (void)argc;
    (void)argv;

    write(1, "Please enter key: ", 18);
    if (scanf("%99s", input) == 1) // Lit ce que tu tapes jusqu'à l'espace/entrée
    {
        if (strcmp(input, "__stack_check") == 0)
		{
			write(1, "Good job.\n", 10);
			return (0);
		}
        else
		{
            write(1, "Nope.\n", 6);
			return (1);
		}
    }
    return (0);
}
