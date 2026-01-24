/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 11:30:42 by anpicard          #+#    #+#             */
/*   Updated: 2025/10/21 10:29:22 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <string>

class PhoneBook
{
private:
    Contact contact[8];
    int currentIndex;
    int totalContacts;
public:
    PhoneBook();
    ~PhoneBook();
    void setContact(Contact newContact, int index);
    int    add();
    int    search();
};


#endif