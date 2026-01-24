/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 10:05:00 by anpicard          #+#    #+#             */
/*   Updated: 2026/01/24 10:05:00 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : type("unknown")
{
}

AMateria::AMateria(std::string const & type) : type(type)
{
}

AMateria::AMateria(const AMateria& other) : type(other.type)
{
}

AMateria& AMateria::operator=(const AMateria& other)
{
    if (this != &other) {
        // Don't copy the type as per subject requirements
        (void)other;
    }
    return *this;
}

AMateria::~AMateria()
{
}

std::string const & AMateria::getType() const
{
    return type;
}

void AMateria::use(ICharacter& target)
{
    (void)target;
    std::cout << "AMateria use called (should be overridden)" << std::endl;
}
