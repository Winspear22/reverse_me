/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   level3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adnen <adnen@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/13 01:34:39 by adnen             #+#    #+#             */
/*   Updated: 2026/03/13 01:34:51 by adnen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;
    
    char input[24];
    write(1, "Please enter key: ", 18);
    if (scanf("%23s", input) == 1)
    {
        // 1. Vérification du préfixe "42"
        if (input[0] != '4' || input[1] != '2')
        {
            printf("Nope.\n");
            return (1);
        }

        char secret[9];
        memset(secret, 0, 9);
        secret[0] = '*'; // Initialisation avec l'étoile
        
        int i = 2; // On commence après le "42"
        int j = 1;
        char tmp[4];

        // 2. La moulinette (même principe que le level 2)
        while (j < 8)
        {
            tmp[0] = input[i];
            tmp[1] = input[i + 1];
            tmp[2] = input[i + 2];
            tmp[3] = '\0';
            secret[j] = (char)atoi(tmp);
            i += 3;
            j++;
        }
        secret[8] = '\0';

        // 3. Le verdict
        if (strcmp(secret, "********") == 0)
            write(1, "Good job.\n", 10);
        else
            write(1, "Nope.\n", 6);
    }
    return (0);
}