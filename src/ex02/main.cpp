/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:49:21 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/21 16:39:23 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap foo("Fulano");
	ScavTrap bar("Beltrano");
	FragTrap man("Ciclano");
	
	foo.getStatusLife();
	bar.getStatusLife();
	man.getStatusLife();
	man.highFivesGuys();
	
	std::cout << "\n*************************************\n" << std::endl;

	foo.attack("Beltrano");
	bar.takeDamage(7);
	
	bar.attack("Fulano");
	foo.takeDamage(9);
	bar.beRepaired(1);
	
	bar.attack("Ciclano");
	man.takeDamage(4);
	man.attack("Beltrano");
	man.beRepaired(7);
	
	foo.getStatusLife();
	bar.getStatusLife();
	man.getStatusLife();

	man.highFivesGuys();
	
	return (0);
}
