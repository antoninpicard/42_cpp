/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anpicard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 12:40:40 by anpicard          #+#    #+#             */
/*   Updated: 2025/07/24 13:05:52 by anpicard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
private:
	std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
public:
	void setFirstName(std::string fname);
	void setlastName(std::string lname);
	void setnickname(std::string nname);
	void setphoneNumber(std::string pnumber);
	void setdarkestSecret(std::string dsecret);

	void getFirstName();
	void getlastName();
	void getnickname();
	void getphoneNumber();
	void getdarkestSecret();

	Contact(void);
	~Contact(void);
};


#endif