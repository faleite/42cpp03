/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 16:25:44 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/21 21:55:48 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/**
 * Quando ClapTrack ataca, ele faz com que seu alvo perca <dano de ataque> 
 * pontos de vida. Quando ClapTrap se repara, ele recebe <quantidade> 
 * pontos de vida de volta. Atacar e reparar custam 1 ponto de energia cada. 
 * Claro, ClapTrap não pode fazer nada se não tiver pontos de vida ou pontos
 * de energia restantes.
 * 
 * Em todas essas funções de membro, você tem que imprimir uma mensagem para 
 * descrever o que acontece. Por exemplo, a função attack() pode exibir algo 
 * como (claro, sem os colchetes angulares):
 *
 * ClapTrap <nome> ataca <alvo>, causando <dano> pontos de dano!
 *
 * Os construtores e destrutores também devem exibir uma mensagem, para que 
 * seus avaliadores de pares possam ver facilmente que foram chamados.
 *
 * Implemente e entregue seus próprios testes para garantir que seu código 
 * funcione conforme o esperado.
*/
int	main(void)
{
	ClapTrap foo("Fulano");
	ClapTrap bar("Beltrano");
	
	// Ex. Use A copy assignment operator overload.
	ClapTrap man("Ciclano");
	man = foo;
	// Ex. Use copy constructor 
	ClapTrap a = bar;

	foo.attack("Beltrano");
	bar.takeDamage(7);
	bar.getStatusLife();
	
	bar.attack("Fulano");
	foo.takeDamage(9);
	bar.beRepaired(1);
	foo.getStatusLife();
	bar.getStatusLife();
	
	foo.attack("Beltrano");
	bar.takeDamage(4);
	foo.takeDamage(1);
	foo.beRepaired(1);
	foo.getStatusLife();
	bar.getStatusLife();

	return (0);
}
