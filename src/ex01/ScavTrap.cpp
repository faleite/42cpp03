/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:37:58 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/21 22:08:35 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/**
 * Chamar explicitamente `: ClapTrap()` garante que todos os membros da classe 
 * base sejam inicializados corretamente antes que o construtor da classe 
 * derivada ScavTrap seja executado.
 * Depois o controle passa para o corpo do construtor de ScavTrap, onde você 
 * pode sobrescrever ou modificar os membros conforme necessário.
*/
ScavTrap::ScavTrap() : ClapTrap()
{
	// _name = "None"; // _name sera inicializado pelo construtor `ClapTrap`
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	
	std::cout << "ScavTrap default constructor called" << std::endl;
}

/**
 * Quando você usa a lista de inicialização : ClapTrap(name) no construtor 
 * ScavTrap(const std::string &name), o membro _name da classe base ClapTrap 
 * será inicializado com o valor do argumento name passado ao 
 * construtor de ScavTrap.
*/
ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name)
{
	// _name = name; // _name sera inicializado pelo construtor `ClapTrap`
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	
	std::cout << "ScavTrap " << name << " constructor called" << std::endl;
}
/**
 * Em geral, é recomendado usar a lista de inicialização para inicializar 
 * membros da classe base e permitir que o construtor de cópia da classe 
 * base faça seu trabalho de forma eficiente, sem precisar inicializar
 * os membros da classe derivada `ScavTrap`.
 * 
 * Caso Especial: Se houver membros específicos na classe derivada que 
 * necessitam de inicialização adicional além do que é feito pela classe 
 * base, então é apropriado copiá-los explicitamente no corpo do 
 * construtor de cópia da classe derivada.
*/
ScavTrap::ScavTrap(const ScavTrap &copyObj) : ClapTrap(copyObj)
{
	// _hitPoints = copyObj._hitPoints;
    // _energyPoints = copyObj._energyPoints;
    // _attackDamage = copyObj._attackDamage;
	
	std::cout << "ScavTrap copy constructor called" << std::endl;
}

/**
 * Ao utilizar ClapTrap::operator=(copyAssObj) na classe derivada 
 * ScavTrap, evita-se a duplicação de código necessário para copiar 
 * os membros da classe base.
 * 
 * Isso segue o princípio de reutilização de código e evita erros de 
 * consistência ao garantir que a atribuição de membros da classe base 
 * seja tratada pela implementação já existente na classe base.
*/
ScavTrap &ScavTrap::operator=(const ScavTrap &copyAssObj)
{
	if (this != &copyAssObj)
		ClapTrap::operator=(copyAssObj);
	
	std::cout << "ScavTrap assignment operator called" << std::endl;
	return (*this);
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called for ";
	std::cout << this->_name << std::endl;
}

/**
 * substitui funcao membro da superclass (override)
*/
void ScavTrap::attack(const std::string& target)
{
	if (_energyPoints < 1)
	{
		std::cout << "ScavTrap " << _name;
		std::cout << " has not energy points to attack!" << std::endl;
	}
	if (_hitPoints < 1)
	{
		std::cout << "ScavTrap " << _name;
		std::cout << " has not hit points to attack!" << std::endl;
	}
	else
	{
		_energyPoints--;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing ";
		std::cout << _attackDamage << " points of damage!" << std::endl;
	}
}
void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode!" << std::endl;
}
