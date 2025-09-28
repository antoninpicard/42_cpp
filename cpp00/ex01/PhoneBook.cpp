/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:41:12 by anpicard          #+#    #+#             */
/*   Updated: 2025/09/28 08:58:16 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>

PhoneBook::PhoneBook(void) : _contactCount(0), _nextIndex(0) {
    // Constructor
}

PhoneBook::~PhoneBook(void) {
    // Destructor
}

std::string PhoneBook::_getInput(const std::string &prompt) const {
    std::string input;
    
    do {
        std::cout << prompt;
        if (!std::getline(std::cin, input)) {
            std::cout << std::endl << "EOF detected. Exiting..." << std::endl;
            exit(0);
        }
        if (input.empty())
            std::cout << "Field cannot be empty. Please try again." << std::endl;
    } while (input.empty());
    
    return input;
}

std::string PhoneBook::_truncateString(const std::string &str) const {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    }
    return str;
}

void PhoneBook::addContact(void) {
    Contact newContact;
    
    std::cout << "Adding a new contact..." << std::endl;
    
    newContact.setFirstName(this->_getInput("Enter first name: "));
    newContact.setLastName(this->_getInput("Enter last name: "));
    newContact.setNickname(this->_getInput("Enter nickname: "));
    newContact.setPhoneNumber(this->_getInput("Enter phone number: "));
    newContact.setDarkestSecret(this->_getInput("Enter darkest secret: "));
    
    this->_contacts[this->_nextIndex] = newContact;
    this->_nextIndex = (this->_nextIndex + 1) % 8;
    
    if (this->_contactCount < 8)
        this->_contactCount++;
        
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::displayContacts(void) const {
    if (this->_contactCount == 0) {
        std::cout << "No contacts available." << std::endl;
        return;
    }
    
    std::cout << std::right << std::setw(10) << "Index" << "|";
    std::cout << std::right << std::setw(10) << "First Name" << "|";
    std::cout << std::right << std::setw(10) << "Last Name" << "|";
    std::cout << std::right << std::setw(10) << "Nickname" << std::endl;
    
    for (int i = 0; i < this->_contactCount; i++) {
        std::cout << std::right << std::setw(10) << i << "|";
        std::cout << std::right << std::setw(10) << this->_truncateString(this->_contacts[i].getFirstName()) << "|";
        std::cout << std::right << std::setw(10) << this->_truncateString(this->_contacts[i].getLastName()) << "|";
        std::cout << std::right << std::setw(10) << this->_truncateString(this->_contacts[i].getNickname()) << std::endl;
    }
}

void PhoneBook::searchContact(void) const {
    if (this->_contactCount == 0) {
        std::cout << "No contacts available." << std::endl;
        return;
    }
    
    this->displayContacts();
    
    std::string input;
    int index;
    
    std::cout << "Enter the index of the contact to display: ";
    if (!std::getline(std::cin, input)) {
        std::cout << std::endl << "EOF detected. Exiting..." << std::endl;
        exit(0);
    }
    
    std::stringstream ss(input);
    if (!(ss >> index) || !ss.eof()) {
        std::cout << "Invalid index format." << std::endl;
        return;
    }
    
    if (index < 0 || index >= this->_contactCount) {
        std::cout << "Index out of range." << std::endl;
        return;
    }
    
    std::cout << std::endl;
    this->_contacts[index].displayContact();
}