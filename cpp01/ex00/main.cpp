/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:16:30 by anpicard          #+#    #+#             */
/*   Updated: 2026/01/15 11:02:20 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie* heapZombie = newZombie("Foo");
	heapZombie->announce();
	delete heapZombie;

	randomChump("Bar");
	return (0);
}
