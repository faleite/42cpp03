/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:39:31 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/22 21:24:42 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		// Member attributes:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
	    // Memebers function:
		ClapTrap(); // Default constructor
		ClapTrap(const std::string &name); // Parameterized constructor
		ClapTrap(const ClapTrap &copyObj); // Copy constructor
		ClapTrap &operator=(const ClapTrap &copyAssObj); // Copy assignment operator
		~ClapTrap(); // Destructor
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void getStatusLife();
};

#endif // CLAPTRAP_HPP