/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:39:31 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/17 20:34:14 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string name;
		int	hitPoints = 10;
		int energyPoints = 10;
		int	attackDamage = 0;
	public:
		ClapTrap(); // Default constructor
		ClapTrap(const ClapTrap &copyObj); // Copy constructor
		ClapTrap &operator=(const ClapTrap &copyAssObj); // Copy assignment operator
		~ClapTrap(); // Destructor
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
}

#endif // CLAPTRAP_HPP