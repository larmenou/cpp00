/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:05:49 by larmenou          #+#    #+#             */
/*   Updated: 2023/12/05 12:54:09 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	book;
	std::string	cmd;
	std::string f_name;
	std::string l_name;
	std::string nickname;
	std::string number;
	std::string secret;
	std::string index;
	int			i;
	int			j;
	Contact		*lst;
	
	i = 0;
	lst = book.get_contact();
	std::cout << "Enter one of three commands : ADD, SEARCH, EXIT" << std::endl;
	while (cmd != "EXIT")
	{
		if (!std::cin.good())
			exit(1);
		std::cout << "> ";
		if (!std::getline(std::cin, cmd))
			exit(1);
		if (cmd == "ADD")
		{
			while (f_name.empty())
			{
				if (!std::cin.good())
					exit(1);
				std::cout << "> Enter first name: ";
				if (!std::getline(std::cin, f_name))
					exit(1);
			}
			while (l_name.empty())
			{
				if (!std::cin.good())
					exit(1);
				std::cout << "> Enter last name: ";
				if (!std::getline(std::cin, l_name))
					exit(1);
			}
			while (nickname.empty())
			{
				if (!std::cin.good())
					exit(1);
				std::cout << "> Enter nickname: ";
				if (!std::getline(std::cin, nickname))
					exit(1);
			}
			while (number.empty())
			{
				if (!std::cin.good())
					exit(1);
				std::cout << "> Enter number: ";
				if (!std::getline(std::cin, number))
					exit(1);
			}
			while (secret.empty())
			{
				if (!std::cin.good())
					exit(1);
				std::cout << "> Enter secret: ";
				if (!std::getline(std::cin, secret))
					exit(1);
			}
			lst[i%8].set(f_name, l_name, nickname, number, secret, i % 8);
			f_name.clear();
			l_name.clear();
			nickname.clear();
			number.clear();
			secret.clear();
			i++;
		}
		if (cmd == "SEARCH")
		{
				
			for (j = 0; j < 8; j++)
			{
				if (!lst[j].get_f_name().empty())
				{
					std::cout << std::right << std::setw(10) << lst[j].get_index() << "|";
					
					f_name = lst[j].get_f_name();
					if (f_name.length() > 10)
					{
						f_name.resize(10, '\0');
						f_name[9] = '.';
					}
					std::cout << std::right << std::setw(10) << f_name << "|";
					
					l_name = lst[j].get_l_name();
					if (l_name.length() > 10)
					{
						l_name.resize(10, '\0');
						l_name[9] = '.';
					}
					std::cout << std::right << std::setw(10) << l_name << "|";
					
					nickname = lst[j].get_nickname();
					if (nickname.length() > 10)
					{
						nickname.resize(10, '\0');
						nickname[9] = '.';
					}
					std::cout << std::right << std::setw(10) << nickname << "|" << std::endl;
						
					f_name.clear();
					l_name.clear();
					nickname.clear();
				}
			}
			if (!lst[0].get_f_name().empty())
			{
				while (1)
				{
					if (!std::cin.good())
						exit(1);
					std::cout << "Enter index: ";
					if (!std::getline(std::cin, index))
						exit(1);
					if (index.length() == 1 && isdigit(index[0]) && stoi(index) < 8)
					{
						if (!lst[(stoi(index))].get_f_name().empty())
							break ;
					}
				}
				std::cout << "fisrt name: " << lst[(stoi(index))].get_f_name() << std::endl;
				std::cout << "last name: " << lst[(stoi(index))].get_l_name() << std::endl;
				std::cout << "nickname: " << lst[(stoi(index))].get_nickname() << std::endl;
				std::cout << "number phone: " << lst[(stoi(index))].get_number() << std::endl;
				std::cout << "darkest secret: " << lst[(stoi(index))].get_secret() << std::endl;
				index.clear();
			}
		}
	}
	return (0);
}
