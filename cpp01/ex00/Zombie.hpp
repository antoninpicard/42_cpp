/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:16:30 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/11 10:16:30 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie {

private:
	std::string _name;

public:
	Zombie(std::string name);
	~Zombie(void);
	
	void announce(void);
};

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

#endif
