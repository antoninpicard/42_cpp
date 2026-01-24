/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 10:40:21 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/11 10:41:22 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>
#include <string>

int main(void)
{
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;
    std::cout << "Adresse de la variable brain:     " << &brain << std::endl;
    std::cout << "Adresse contenue dans stringPTR:  " << stringPTR << std::endl;
    std::cout << "Adresse de stringREF:             " << &stringREF << std::endl;
    std::cout << std::endl;
    std::cout << "Valeur de brain:                  " << brain << std::endl;
    std::cout << "Valeur pointée par stringPTR:     " << *stringPTR << std::endl;
    std::cout << "Valeur pointée par stringREF:     " << stringREF << std::endl;
    return (0);
}