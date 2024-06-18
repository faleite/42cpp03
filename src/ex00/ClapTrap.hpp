/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:39:31 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/18 20:56:52 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	private:
		std::string _name;
		int	_hitPoints = 10;
		int _energyPoints = 10;
		int	_attackDamage = 0;
	public:
		ClapTrap(); // Default constructor
		ClapTrap(const std::string &name);
		ClapTrap(const ClapTrap &copyObj); // Copy constructor
		ClapTrap &operator=(const ClapTrap &copyAssObj); // Copy assignment operator
		~ClapTrap(); // Destructor
		
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

ClapTrap::ClapTrap() 
{
	std::cout << "Default constructor called" << std::endl;	
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10),
 _energyPoints(10), _attackDamage(0)
{
	std::cout << "String constructor called" << std::endl;
}

/**
 * @brief A copy constructor. 
 * Cria um novo objeto como uma cópia de um objeto existente
 * @param RefConstObjSrc Como e passado este parametro com `&` o objeto
 * referenciado por &RefConstObjSrc não pode ser modificado dentro do método.
*/
ClapTrap::ClapTrap(const ClapTrap &copyObj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = copyObj;
}

/**
 * @brief A copy assignment operator overload.
 * (Sobrecarga do operador de atribuição de cópia).
 * 
 * O operador de atribuição de cópia é utilizado para 
 * copiar o valor de um objeto existente para outro 
 * objeto que já foi inicializado. 
*/
ClapTrap &ClapTrap::operator=(const ClapTrap &copyAssObj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	
	if (this != &copyAssObj)
		// this.
	return (*this); 
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	std::cout << "ClapTrap" name << "attacks" target ", causing" damage "points of damage!" std::endl;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	
}
void ClapTrap::beRepaired(unsigned int amount)
{
	
}

#endif // CLAPTRAP_HPP