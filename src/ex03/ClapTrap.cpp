/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:40:50 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/21 19:02:33 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

// Default constructor
ClapTrap::ClapTrap() : _name("None"), _hitPoints(10), _energyPoints(10),
_attackDamage(0)
{
	std::cout << "ClapTrap Default constructor called" << std::endl;	
}
// Parameterized constructor
ClapTrap::ClapTrap(const std::string &name) : _name(name), _hitPoints(10),
 _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap constructor called for ";
	std::cout << this->_name << std::endl;
}

/**
 * @brief A copy constructor. 
 * Cria um novo objeto como uma cópia de um objeto existente
 * @param RefConstObjSrc Como e passado este parametro com `&` o objeto
 * referenciado por &RefConstObjSrc não pode ser modificado dentro do método.
 * 
 * Usar a lista de inicialização no construtor de cópia é a maneira correta 
 * e eficiente de inicializar um objeto com os valores de outro objeto. Isso 
 * garante que todos os membros sejam inicializados corretamente na criação 
 * do objeto, em vez de primeiro serem inicializados com valores padrão e 
 * depois reatribuídos. Além disso, alguns membros, como referências 
 * constantes e membros const, só podem ser inicializados, não atribuídos, 
 * tornando a lista de inicialização a única opção nesses casos.
 * 
 * No construtor de cópia, estamos criando um novo objeto e inicializando seus 
 * membros diretamente. Por isso, usamos a lista de inicialização para eficiência 
 * e para garantir a correta inicialização dos membros, especialmente aqueles que 
 * são const ou referências.
*/
ClapTrap::ClapTrap(const ClapTrap &copyObj) : _name(copyObj._name),
_hitPoints(copyObj._hitPoints), _energyPoints(copyObj._energyPoints), 
_attackDamage(copyObj._attackDamage)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

/**
 * @brief A copy assignment operator overload.
 * (Sobrecarga do operador de atribuição para cópia).
 * 
 * O operador de atribuição de cópia é utilizado para name
 * objeto que já foi inicializado.
 * 
 * No operador de atribuição de cópia, o objeto de destino já existe. 
 * Portanto, a lista de inicialização não pode ser usada aqui porque a 
 * inicialização dos membros já foi feita quando o objeto foi criado. 
 * Em vez disso, usamos atribuição para copiar os valores dos membros 
 * do objeto de origem para o objeto de destino.
*/
ClapTrap &ClapTrap::operator=(const ClapTrap &copyAssObj)
{
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
	
	if (this != &copyAssObj)
	{
		this->_name = copyAssObj._name;
		this->_hitPoints = copyAssObj._hitPoints;
		this->_energyPoints = copyAssObj._energyPoints;
		this->_attackDamage = copyAssObj._attackDamage;
	}
	return (*this); 
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor called for ";
	std::cout << this->_name << std::endl;
}

/**
 * Quando ClapTrack ataca. Atacar e reparar custam 1 ponto de energia cada. 
 * Claro, ClapTrap não pode fazer nada se não tiver pontos de vida ou pontos
 * de energia restantes.
*/
void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints < 1)
	{
		std::cout << "ClapTrap " << _name;
		std::cout << " has not energy points to attack!" << std::endl;
	}
	if (_hitPoints < 1)
	{
		std::cout << "ClapTrap " << _name;
		std::cout << " has not hit points to attack!" << std::endl;
	}
	else
	{
		_energyPoints--;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing ";
		std::cout << _attackDamage << " points of damage!" << std::endl;
	}
}

/**
 * Quando ClapTrack ataca, ele faz com que seu alvo perca <attack damage>
 * (dano de ataque) pontos de vida. 
 * Claro, ClapTrap não pode fazer nada se não tiver pontos de vida ou pontos
 * de energia restantes.
*/
void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints > amount)
	{
		_hitPoints -= amount;
		std::cout << "ClapTrap " << this->_name << " take " << amount;
		std::cout << " points of damage!" << std::endl;
	}
	else
	{
		_hitPoints = 0;
		std::cout << "ClapTrap " << this->_name << " has been destroyed!";
		std::cout << std::endl;
	}
}

/**
 * Quando ClapTrap se repara, ele recebe <amount> (quantidade) 
 * pontos de vida de volta. Atacar e reparar custam 1 ponto de energia cada.
 * Claro, ClapTrap não pode fazer nada se não tiver pontos de vida ou pontos
 * de energia restantes.
*/
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energyPoints > 0 && this->_hitPoints > 0)
	{
		this->_hitPoints += amount;
		this->_energyPoints--;
		std::cout << "ClapTrap " << this->_name << " was repaired with ";
		std::cout  << amount << " more health points!" << std::endl;
	}
	else
	{
		std::cout << "ClapTrap " << this->_name << " has not hit points or ";
		std::cout << "energy points, so it cannot be repaired!" << std::endl;
	}
}

void ClapTrap::getStatusLife()
{
	std::cout << "-------------------------" << std::endl;
	std::cout << "Status Life of " << _name << std::endl;
	std::cout << "Hit Points: " << _hitPoints << std::endl;
	std::cout << "Energy Points: " << _energyPoints << std::endl;
}