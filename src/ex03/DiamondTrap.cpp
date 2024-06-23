/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 17:56:07 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/23 17:28:38 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/**
 * Dada nossa ordem de construção, essencialmente todas as variáveis ​​de membro se tornarão
 * aquelas de FragTrap.
 * 
 * ClapTrap -> ScavTrap (substituir) -> FragTrap (substituir)
 * 
 * então, atribuímos manualmente os pontos de energia de ScavTrap e na classe base,
 * o ataque estará "usando" ScavTrap
 * 
 * em TODOS OS CONSTRUTORES, o compilador verificará se a ordem pela qual chamamos os
 * construtores herdados é mantida em relação ao que definimos no arquivo de cabeçalho:
 * 
 * "class DiamondTrap : public ScavTrap, public FragTrap"
 * 
 * neste caso, "_name" também é uma variável de membro da classe DiamondTrap em si
 * então podemos adicioná-la à lista de inicializadores de membros antes do corpo da função
 * 
 * ClapTrap("_clap_name") <- por que não isso na lista de inicializadores de membros?
 * porque será substituído por Scav e Frag :)
 * adicione manualmente "_clap_name" a clap name e pronto
 * 
 * Curiosidade...
 * ScavTrap::name += "_clap_name"; obtém exatamente o mesmo efeito
 * 
 * porque.......... são todas a mesma variável com nomes diferentes
 * assembly é exatamente o mesmo.
 * FragTrap::name também funcionaria.
 * 
 * As variáveis ​​não são duplicadas, especialmente considerando que estamos usando herança 
 * virtual e apenas uma instância de classe base é criada. Os construtores restantes 
 * adicionam a ela, na melhor das hipóteses, se eles adicionarem mais variáveis.
 * então, ClapTrap::name == ScavTrap::name == FragTrap::Name,
 * A exceção é DiamondTrap::name que se refere à sua própria variável membro
 * A resolução do conflito é resolvida para o candidato mais próximo, que neste caso
 * é sua própria variável e não a herdada
 * Então, para se referir a herdado, diga explicitamente de onde ele vem (ClapTrap::name, por exemplo)
 * 
 */

/**
 * Na herança virtual, a classe mais derivada DEVE CHAMAR TODOS OS SEUS ANCESTRAIS DIRETAMENTE.
 * Se eu omitir o "ClapTrap(start_name + "_clap_name")" na lista de inicializadores de membros,
 * o compilador chamará o construtor padrão do ClapTrap -> é o compilador que nos salva
 * Eu esperava que o construtor de parâmetros do ClapTrap fosse chamado pelo construtor de parâmetros do ScavTrap
 * mas na compilação, o ClapTrap padrão foi chamado, o que significa que foi o compilador
 * que o colocou lá
 * 
 * Se você omitir o ClapTrap(copy) no construtor de cópia, o compilador não permite
 * que você compile e pronto. Para cumprir as regras de herança, os mais derivados
 * deve chamar tudo, ele mesmo. É assim que a herança virtual é traduzida para ter
 * 
 * apenas uma instância de cada ancestral no máximo: é o neto que chama um de cada,
 * os construtores da família do meio apenas adicionam coisas no topo, eles próprios não chamam
 * seus respectivos ancestrais.
 * 
 * O que significa... na herança virtual, o compilador basicamente remove todas as chamadas de construtor de seus
 * construtores do meio.....?
 * 
 * A ordem importa, se você chamar explicitamente o construtor ScavTrap antes do ClapTrap, não compilará e
 * avisará que a ordem está incorreta porque o ClapTrap é a base do ScavTrap
 */

/**
 * configuração redundante do nome para += "_clap_name" mas eu tinha scav e clap sobrescrevendo
 * a variável name em sua construção.
 * De qualquer forma, é inevitável que clap::name seja igual a frag::name, mesma variável
 */
DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(),
								FragTrap(), _name("None")
{
	// _hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::scavEnergyPoints; // ScavTrap::_energyPoints == FragTrap::_energyPoints
	// _attackDamage = FragTrap::_attackDamage;
	
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

/**
 * A lista de inicialização é mais eficiente porque inicializa os membros
 * diretamente, evitando a criação temporária de objetos e cópias desnecessárias.
 * 
 * Trazendo à eficiência, imutabilidade e clareza do codigo. 
 * Portanto, usar `ClapTrap::_name = name  + "_clap_name"` dentro do escopo da
 * funcao nao e uma boa pratica.
 */
DiamondTrap::DiamondTrap(const std::string &name) 
	: ClapTrap(name  + "_clap_name"), ScavTrap(), FragTrap(), _name(name)
{
	// _hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::scavEnergyPoints;
	// _attackDamage = FragTrap::_attackDamage;
	
	std::cout << "DiamondTrap " << name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copyObj) : ClapTrap(copyObj), 
									ScavTrap(copyObj), FragTrap(copyObj)
{
	// *this = copyObj;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

/**
 * Neste caso, uma sobrecarga de operator= para DiamondTrap é inevitável, 
 * pois adiciona uma variável membro sobre as variáveis ​​membro herdadas
 * 
 * Em qualquer caso, para permitir um crescimento maior de suas superclasses, 
 * chamamos os operadores de atribuição na ordem de herança que especificamos
 * em DiamondTrap.hpp
 */
DiamondTrap &DiamondTrap::operator=(const DiamondTrap &copyAssObj)
{
	if (this != &copyAssObj)
	{
		ScavTrap::operator=(copyAssObj);
		FragTrap::operator=(copyAssObj);
		_name = copyAssObj._name;
	}
	
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	return (*this);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called for ";
	std::cout << this->_name << std::endl;
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "I'm " << this->_name << " and my ClapTrap name is ";
	std::cout << ClapTrap::_name << std::endl;
}

// void DiamondTrap::attack(const std::string &target)
// {
// 	std::cout << "\nEntrou " << target << "\n";
// 	ScavTrap::attack(target); // Explicitly call ScavTrap's attack method
// }
