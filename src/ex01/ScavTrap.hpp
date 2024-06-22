/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:50:12 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/22 21:06:33 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

/**
 * Como você nunca pode ter ClapTraps o suficiente, agora você criará um robô 
 * derivado. Ele será chamado de ScavTrap e herdará os construtores e destrutor 
 * do ClapTrap. No entanto, seus construtores, destrutor e attack() imprimirão 
 * mensagens diferentes. Afinal, os ClapTraps estão cientes de sua individualidade.
 *
 * Observe que o encadeamento de construção/destruição adequado deve ser mostrado 
 * em seus testes. Quando um ScavTrap é criado, o programa começa construindo um 
 * ClapTrap. A destruição é na ordem inversa. Por quê?
 * 
 * ScavTrap usará os atributos de ClapTrap (atualizar ClapTrap em consequência) 
 * e deve inicializá-los para:
 * Nome, que é passado como parâmetro para um construtor
 * Pontos de vida (100), representam a saúde do ClapTrap
 * Pontos de energia (50)
 * Dano de ataque (20)
 * 
 * ScavTrap também terá sua própria capacidade especial:
 * void guardGate();
 * 
 * Esta função membro exibirá uma mensagem informando que o ScavTrap está agora 
 * no modo Gate keeper
 */

/**
 * Classe derivada de `ClapTrap`
 * 
 * A ordem de construcao: Classes Base primeiro, Classes derivadas depois
 * A classe derivada pode depender de membros e 
 * funcionalidades fornecidas pelas classes base. Para garantir que a classe 
 * derivada tenha um estado válido, todos os membros herdados devem ser 
 * inicializados antes de qualquer inicialização específica da classe derivada.
 * 
 * A ordem de desconstrucao: Classes derivadas primeiro, Classes base depois
 * Isso garante que quaisquer recursos alocados pelas classes derivadas sejam 
 * liberados antes que os recursos das classes base sejam liberados, evitando 
 * possíveis acessos inválidos a recursos que já foram destruídos.
*/
class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(); // Default constructor
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap &copyObj); // Copy constructor
		ScavTrap &operator=(const ScavTrap &copyAssObj); // Copy assignment operator
		~ScavTrap(); // Destructor
		
		void attack(const std::string& target); // Overriding the base class virtual function
		void guardGate();
};

#endif // SCAVTRAP_HPP