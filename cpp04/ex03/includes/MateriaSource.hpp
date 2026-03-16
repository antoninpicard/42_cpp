/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 10:05:00 by anpicard          #+#    #+#             */
/*   Updated: 2026/02/13 10:10:33 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource {
private:
    AMateria* _templates[4];

public:
    MateriaSource();
    MateriaSource(const MateriaSource& other);
    MateriaSource& operator=(const MateriaSource& other);
    ~MateriaSource();

    void learnMateria(AMateria* m);
    AMateria* createMateria(std::string const & type);
};

#endif
