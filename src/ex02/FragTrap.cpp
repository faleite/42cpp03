/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 17:37:58 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/20 20:55:18 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/**
 * Chamar explicitamente `: ClapTrap()` garante que todos os membros da classe 
 * base sejam inicializados corretamente antes que o construtor da classe 
 * derivada FragTrap seja executado.
 * Depois o controle passa para o corpo do construtor de FragTrap, onde você 
 * pode sobrescrever ou modificar os membros conforme necessário.
*/
FragTrap::FragTrap() : ClapTrap()
{
	// _name = "None"; // _name sera inicializado pelo construtor `ClapTrap`
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	
	std::cout << "FragTrap default constructor called" << std::endl;
}

/**
 * Quando você usa a lista de inicialização : ClapTrap(name) no construtor 
 * FragTrap(const std::string &name), o membro _name da classe base ClapTrap 
 * será inicializado com o valor do argumento name passado ao 
 * construtor de FragTrap.
*/
FragTrap::FragTrap(const std::string &name) : ClapTrap(name)
{
	// _name = name; // _name sera inicializado pelo construtor `ClapTrap`
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	
	std::cout << "FragTrap " << name << " constructor called" << std::endl;
}
/**
 * Em geral, é recomendado usar a lista de inicialização para inicializar 
 * membros da classe base e permitir que o construtor de cópia da classe 
 * base faça seu trabalho de forma eficiente, sem precisar inicializar
 * os membros da classe derivada `FragTrap`.
 * 
 * Caso Especial: Se houver membros específicos na classe derivada que 
 * necessitam de inicialização adicional além do que é feito pela classe 
 * base, então é apropriado copiá-los explicitamente no corpo do 
 * construtor de cópia da classe derivada.
*/
FragTrap::FragTrap(const FragTrap &copyObj) : ClapTrap(copyObj)
{
	// _hitPoints = copyObj._hitPoints;
    // _energyPoints = copyObj._energyPoints;
    // _attackDamage = copyObj._attackDamage;
	
	std::cout << "FragTrap copy constructor called" << std::endl;
}

/**
 * Ao utilizar ClapTrap::operator=(copyAssObj) na classe derivada 
 * FragTrap, evita-se a duplicação de código necessário para copiar 
 * os membros da classe base.
 * 
 * Isso segue o princípio de reutilização de código e evita erros de 
 * consistência ao garantir que a atribuição de membros da classe base 
 * seja tratada pela implementação já existente na classe base.
*/
FragTrap &FragTrap::operator=(const FragTrap &copyAssObj)
{
	if (this != &copyAssObj)
		ClapTrap::operator=(copyAssObj);
	
	std::cout << "FragTrap assignment operator called" << std::endl;
	return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called for ";
	std::cout << this->_name << std::endl;
}

/**
 * Esta função membro exibe uma solicitação de cumprimento 
 * positivo (Toca aqui cara!) na saída padrão.
 */
void FragTrap::highFivesGuys(void)
{
	std::cout << "Hi! I'm FragTrap " << _name;
	std::cout << " high fives bro." << std::endl;
}
