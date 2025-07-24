/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 10:06:18 by anpicard          #+#    #+#             */
/*   Updated: 2025/07/24 11:09:02 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av) {
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	for (int i = 1; av[i] ; i++)
	{
		for (int j = 0; av[i][j] ; j++)
		{
			if (av[i][j] >= 'a' || av[i][j] >= 'z')
			{
				std::cout << (char)toupper(av[i][j]);
			}
			else
				std::cout << av[i][j];
		}
	}
	std::cout << std::endl;
	return (0);
}