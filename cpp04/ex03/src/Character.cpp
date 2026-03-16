/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 10:05:00 by anpicard          #+#    #+#             */
/*   Updated: 2026/02/13 10:10:25 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character() : _name("unnamed")
{
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
}

Character::Character(std::string const & name) : _name(name)
{
    for (int i = 0; i < 4; i++) {
        _inventory[i] = NULL;
    }
}

Character::Character(const Character& other) : _name(other._name)
{
    for (int i = 0; i < 4; i++) {
        if (other._inventory[i]) {
            _inventory[i] = other._inventory[i]->clone();
        } else {
            _inventory[i] = NULL;
        }
    }
}

Character& Character::operator=(const Character& other)
{
    if (this != &other) {
        _name = other._name;
        for (int i = 0; i < 4; i++) {
            if (_inventory[i]) {
                delete _inventory[i];
                _inventory[i] = NULL;
            }
        }
        for (int i = 0; i < 4; i++) {
            if (other._inventory[i]) {
                _inventory[i] = other._inventory[i]->clone();
            }
        }
    }
    return *this;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++) {
        if (_inventory[i]) {
            delete _inventory[i];
        }
    }
}

std::string const & Character::getName() const
{
    return _name;
}

void Character::equip(AMateria* m)
{
    if (!m) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!_inventory[i]) {
            _inventory[i] = m;
            return;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4) {
        return;
    }
    if (!_inventory[idx]) {
        return;
    }
    _inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= 4) {
        return;
    }
    if (!_inventory[idx]) {
        return;
    }
    _inventory[idx]->use(target);
}
