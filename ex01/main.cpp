/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:05:49 by larmenou          #+#    #+#             */
/*   Updated: 2023/12/01 15:02:59 by larmenou         ###   ########.fr       */
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
	while (cmd != "EXIT")
	{
		std::cout << "> ";
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
		{
			while (f_name.empty())
			{
				std::cout << "> Enter first name: ";
				std::getline(std::cin, f_name);
			}
			while (l_name.empty())
			{
				std::cout << "> Enter last name: ";
				std::getline(std::cin, l_name);
			}
			while (nickname.empty())
			{
				std::cout << "> Enter nickname: ";
				std::getline(std::cin, nickname);
			}
			while (number.empty())
			{
				std::cout << "> Enter number: ";
				std::getline(std::cin, number);
			}
			while (secret.empty())
			{
				std::cout << "> Enter secret: ";
				std::getline(std::cin, secret);
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
					std::cout << lst[j].get_index();
					std::cout << "         |";
					
					f_name = lst[j].get_f_name();
					f_name.resize(10, ' ');
					if (f_name[9] != ' ')
						f_name[9] = '.';
					std::cout << f_name << "|";
					
					l_name = lst[j].get_l_name();
					l_name.resize(10, ' ');
					if (l_name[9] != ' ')
						l_name[9] = '.';
					std::cout << l_name << "|";
					
					nickname = lst[j].get_nickname();
					nickname.resize(10, ' ');
					if (nickname[9] != ' ')
						nickname[9] = '.';
					std::cout << nickname << "|" << std::endl;
					
					f_name.clear();
					l_name.clear();
					nickname.clear();
				}
			}
			if (!lst[0].get_f_name().empty())
			{
				while (1)
				{
					std::cout << "Enter index: ";
					std::getline(std::cin, index);
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
