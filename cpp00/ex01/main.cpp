/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:30:39 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/21 10:30:08 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <iostream>
#include <string>

int main(void)
{
    PhoneBook phonebook;
    while (true)
    {
        std::string str;

        
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, str);
        if (!std::cin)
            return (1);
        if (str == "ADD")
        {
            if (phonebook.add() == 1)
                return (1);
        }
        else if (str == "SEARCH")
        {
            if (phonebook.search() == 1)
                return (1);
        }
        else if (str == "EXIT")
            return (0);
    }
    return (1);
}