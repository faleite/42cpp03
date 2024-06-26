/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 16:49:21 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/20 19:41:01 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void)
{
	ClapTrap foo("Fulano");
	ScavTrap bar("Beltrano");
	foo.getStatusLife();
	bar.getStatusLife();
	
	std::cout << "\n*************************************\n" << std::endl;

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
