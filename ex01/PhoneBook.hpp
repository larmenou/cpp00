/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:50:10 by larmenou          #+#    #+#             */
/*   Updated: 2023/12/01 15:00:18 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <iostream>
# include <cctype>
# include <string>

# include "Contact.hpp"

class PhoneBook
{
	public:
		PhoneBook(void);
		~PhoneBook(void);
		Contact *get_contact();
		
	private:
		Contact _lst[8];
};

#endif