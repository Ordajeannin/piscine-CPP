/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajeannin <ajeannin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:39:16 by ajeannin          #+#    #+#             */
/*   Updated: 2024/04/25 16:14:58 by ajeannin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

/*
 * flux, "standard c in/out/error"
 * std::cin
 * std::cout
 * std::cerr
*/

/*
 * Boucle for
 * for (init variable, jusqu a, incrementation)
 * for (variable, cond. de sortie, incrementation de la variable)
*/

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		for (int i = 1; i < ac; i++)
		{
			for (int j = 0; av[i][j] != '\0'; j++)
				std::cout << (char) std::toupper(av[i][j]);
			if (i < ac - 1)
				std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}
