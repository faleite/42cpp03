/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:41:21 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/24 18:32:18 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

// #include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/**
 * Neste exercício, você criará um monstro: um ClapTrap que é metade FragTrap, 
 * metade ScavTrap. Ele será chamado de DiamondTrap e herdará tanto do FragTrap 
 * quanto do ScavTrap. Isso é muito arriscado!
 *
 * A classe DiamondTrap terá um atributo privado name. Dê a esse atributo 
 * exatamente o mesmo nome de variável (não estou falando do nome do robô aqui) 
 * que o da classe base ClapTrap.
 * 
 * Para ser mais claro, aqui estão dois exemplos.
 * Se a variável do ClapTrap for name, dê o nome name para o do DiamondTrap.
 * Se a variável do ClapTrap for _name, dê o nome _name para o do DiamondTrap.
 * 
 * Seus atributos e funções de membro serão escolhidos de qualquer uma de 
 * suas classes pai:
 * 
 * - Nome, que é passado como um parâmetro para um construtor
 * - ClapTrap::name (parâmetro do construtor + sufixo "_clap_name")
 * - Hit points  (FragTrap)
 * - Energy points (ScavTrap)
 * - Attack damage (FragTrap)
 * - Attack() (Scavtrap)
 * 
 * Além das funções especiais de ambas as classes pai, DiamondTrap terá sua 
 * própria capacidade especial:
 * 
 * void whoAmI();
 *
 * Esta função membro exibirá seu nome e seu nome ClapTrap.
 * Claro, o sub-objeto ClapTrap do DiamondTrap será criado uma vez, e apenas
 * uma vez. Sim, há um truque.
*/

/**
 * `Classe Derivada Final`: classe que herda das duas classes intermediárias.
 * 
 * Isso e um chamado de "Diamond Problem". O problema ocorre quando uma classe
 * deriva de duas classes que têm uma classe base comum, formando uma estrutura 
 * em forma de diamante.
 * 
 *     		 ClapTrap
 *     		   / \
 *     FragTrap   ScavTrap
 *     		   \ /
 *     		DiamondTrap
 * 
 * DiamondTrap herda de FragTrap e ScavTrap, que ambos herdam de ClapTrap 
 * (Classe Base). Isso cria uma ambiguidade porque DiamondTrap agora tem duas 
 * cópias da classe Base, uma através de FragTrap e outra através de ScavTrap.
 * 
 * Ao tentar acessar membros da classe Base a partir de um objeto da classe 
 * DiamondTrap, o compilador não saberá qual versão da Classe Base utilizar.
 *
 * Herança Virtual: 
 * Para resolver o Diamond Problem, o C++ permite o uso de herança virtual.
 * Herança virtual garante que apenas uma instância da classe base seja 
 * compartilhada entre todas as classes derivadas. Isso é feito usando 
 * a palavra-chave virtual na herança das classes intermediárias.
 * 
 * 		ClapTrap  ClapTrap
 * 		     |  	 |
 * 		FragTrap   ScavTrap
 * 		      \     /
 * 		    DiamondTrap
 * 
 * A flag `-Wshadow` Ativa avisos sobre variáveis que sombreiam outras variáveis 
 * em escopos externos.
 * A flag `-Wno-shadow` Desativa esses avisos.
 * 
 * Sombreamento ocorre quando uma variável local em um bloco de código 
 * (por exemplo, uma função ou um método) tem o mesmo nome que uma variável 
 * em um escopo mais externo (como uma variável membro de classe ou uma variável 
 * global). Isso pode causar confusão, porque a variável local pode ocultar 
 * (ou sombrear) a variável externa.
 * 
 * Exemplo de compilacao: `c++ -Wshadow -o main main.cpp`
 * 
*/
class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(); // Default constructor
		DiamondTrap(const std::string &name);
		DiamondTrap(const DiamondTrap &copyObj); // Copy constructor
		DiamondTrap &operator=(const DiamondTrap &copyAssObj); // Copy assignment operator
		~DiamondTrap(); // Destructor
		
		void whoAmI(void);
	private:
		std::string _name;
};

#endif // DIAMONDTRAP_HPP