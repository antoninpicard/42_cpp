/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:48:33 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/11 10:48:33 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"
# include <string>

class HumanB {

private:
	std::string _name;
	Weapon* _weapon;

public:
	HumanB(std::string name);
	~HumanB(void);
	
	void setWeapon(Weapon& weapon);
	void attack(void) const;
};

#endif
