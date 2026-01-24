/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:48:33 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/11 10:48:33 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include "Weapon.hpp"
# include <string>

class HumanA {

private:
	std::string _name;
	Weapon& _weapon;

public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA(void);
	
	void attack(void) const;
};

#endif
