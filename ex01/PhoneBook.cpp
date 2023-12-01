/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:48:39 by larmenou          #+#    #+#             */
/*   Updated: 2023/12/01 15:00:16 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook(void)
{
	for (int i = 0; i < 8; i++)
	{
		this->_lst[i] = Contact();
	}
	return ;
}

PhoneBook::~PhoneBook(void)
{
	return ;
}

Contact *PhoneBook::get_contact()
{
	return (this->_lst);
}
