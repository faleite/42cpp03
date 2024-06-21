/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:49:11 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/21 22:02:57 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

/**
 * `virtual void attack(const std::string& target);` função declarada na 
 * classe base que pode ser sobrescrita (redefinida) nas classes derivadas. 
 * Ela permite que métodos com o mesmo nome e assinatura 
 * nas classes derivadas substituam o comportamento da função na classe base. 
 * 
 * Classes derivadas podem sobrescrever a função virtual da classe base 
 * usando a mesma assinatura (tipo de retorno e parâmetros).
*/
class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;
	public:
		ClapTrap(); // Default constructor
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &copyObj); // Copy constructor
		ClapTrap &operator=(const ClapTrap &copyAssObj); // Copy assignment operator
		~ClapTrap(); // Destructor
		
		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void getStatusLife();
};

#endif // CLAPTRAP_HPP