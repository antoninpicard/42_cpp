/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 10:05:00 by anpicard          #+#    #+#             */
/*   Updated: 2026/02/13 10:10:39 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++) {
        _templates[i] = NULL;
    }
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    for (int i = 0; i < 4; i++) {
        if (other._templates[i]) {
            _templates[i] = other._templates[i]->clone();
        } else {
            _templates[i] = NULL;
        }
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
    if (this != &other) {
        // Delete old _templates
        for (int i = 0; i < 4; i++) {
            if (_templates[i]) {
                delete _templates[i];
                _templates[i] = NULL;
            }
        }
        // Copy new _templates
        for (int i = 0; i < 4; i++) {
            if (other._templates[i]) {
                _templates[i] = other._templates[i]->clone();
            }
        }
    }
    return *this;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++) {
        if (_templates[i]) {
            delete _templates[i];
        }
    }
}

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m) {
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!_templates[i]) {
            _templates[i] = m;
            return;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++) {
        if (_templates[i] && _templates[i]->getType() == type) {
            return _templates[i]->clone();
        }
    }
    return NULL;
}
