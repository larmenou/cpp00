/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 10:53:33 by larmenou          #+#    #+#             */
/*   Updated: 2023/11/30 15:53:29 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# include <string>

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		void	set(std::string _f_name, std::string _l_name, std::string _nickname,
					std::string _number, std::string _secret, int _index);
		int		get_index();
		std::string	get_f_name() const;
		std::string	get_l_name() const;
		std::string	get_nickname() const;
		std::string	get_number() const;
		std::string	get_secret() const;

	private:
		int			_index;
		std::string	_f_name;
		std::string	_l_name;
		std::string	_nickname;
		std::string _number;
		std::string	_secret;
};

#endif
