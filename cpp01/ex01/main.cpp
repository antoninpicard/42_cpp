/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:28:40 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/11 10:28:40 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int N = 10;
	Zombie* horde = zombieHorde(N, "Zombie");
	
	for (int i = 0; i < N; i++)
		horde[i].announce();
	
	delete[] horde;
	return 0;
}
