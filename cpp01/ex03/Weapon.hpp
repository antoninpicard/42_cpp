/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:48:33 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/11 10:48:33 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

class Weapon {

private:
	std::string _type;

public:
	Weapon(std::string type);
	~Weapon(void);
	
	const std::string& getType(void) const;
	void setType(std::string type);
};

#endif
