/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:41:09 by anpicard          #+#    #+#             */
/*   Updated: 2025/09/28 12:21:14 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.class.hpp"
#include <iostream>
#include <iomanip>

Contact::Contact(void) {
    // Constructor
}

Contact::~Contact(void) {
    // Destructor
}

void Contact::setFirstName(const std::string &firstName) {
    this->firstName = firstName;
}

void Contact::setLastName(const std::string &lastName) {
    this->lastName = lastName;
}

void Contact::setNickname(const std::string &nickname) {
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber) {
    this->phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string &darkestSecret) {
    this->darkestSecret = darkestSecret;
}

std::string Contact::getFirstName(void) const {
    return this->firstName;
}

std::string Contact::getLastName(void) const {
    return this->lastName;
}

std::string Contact::getNickname(void) const {
    return this->nickname;
}

std::string Contact::getPhoneNumber(void) const {
    return this->phoneNumber;
}

std::string Contact::getDarkestSecret(void) const {
    return this->darkestSecret;
}

bool Contact::isEmpty(void) const {
    return (this->firstName.empty() && this->lastName.empty() && 
            this->nickname.empty() && this->phoneNumber.empty() && 
            this->darkestSecret.empty());
}

void Contact::displayContact(void) const {
    std::cout << "First Name: " << this->firstName << std::endl;
    std::cout << "Last Name: " << this->lastName << std::endl;
    std::cout << "Nickname: " << this->nickname << std::endl;
    std::cout << "Phone Number: " << this->phoneNumber << std::endl;
    std::cout << "Darkest Secret: " << this->darkestSecret << std::endl;
}


