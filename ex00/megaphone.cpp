/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: larmenou <larmenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:39:52 by larmenou          #+#    #+#             */
/*   Updated: 2023/11/08 16:05:32 by larmenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			std::cout << (char)std::toupper(argv[i][j]);
			j++;	
		}
		i++;
	}
	std::cout << std::endl;
	return (0);
}
