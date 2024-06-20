/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:50:12 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/20 20:39:52 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

/**
 * Classe derivada de `ClapTrap`
*/
class FragTrap : public ClapTrap
{
	public:
		FragTrap(); // Default constructor
		FragTrap(const std::string &name);
		FragTrap(const FragTrap &copyObj); // Copy constructor
		FragTrap &operator=(const FragTrap &copyAssObj); // Copy assignment operator
		~FragTrap(); // Destructor
		/*
		 Esta função membro exibe uma solicitação de cumprimento 
		 positivo (Toca aqui cara!) na saída padrão.
		*/
		void highFivesGuys(void);
};

#endif // FRAGTRAP_HPP