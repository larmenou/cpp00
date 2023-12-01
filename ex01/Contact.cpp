/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:53:38 by larmenou          #+#    #+#             */
/*   Updated: 2023/11/30 15:53:52 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	return ;
}

Contact::~Contact(void)
{
	return ;
}

void	Contact::set(std::string _f_name, std::string _l_name, std::string _nickname,
					std::string _number, std::string _secret, int _index)
{
	this->_f_name = _f_name;
	this->_l_name = _l_name;
	this->_nickname = _nickname;
	this->_index = _index;
	this->_number = _number;
	this->_secret = _secret;
}

int	Contact::get_index()
{
	return (this->_index);
}

std::string	Contact::get_f_name() const
{
	return (this->_f_name);
}

std::string	Contact::get_l_name() const
{
	return (this->_l_name);
}

std::string	Contact::get_nickname() const
{
	return (this->_nickname);
}

std::string	Contact::get_number() const
{
	return (this->_number);
}

std::string	Contact::get_secret() const
{
	return (this->_secret);
}
