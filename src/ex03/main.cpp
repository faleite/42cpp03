/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:41:26 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/23 17:24:36 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap diamond;
	DiamondTrap a("tests");
	diamond = a;
	
	a.whoAmI();
	a.getStatusLife();
	diamond.takeDamage(42);
	std::cout << "-------------------------" << std::endl;
	diamond.whoAmI();
	diamond.getStatusLife();
	
	// diamond.whoAmI();
	// diamond.guardGate();
	// diamond.attack("Fulano");
	// diamond.takeDamage(42);
	// diamond.beRepaired(3);
	// diamond.getStatusLife();
	// diamond.highFivesGuys();
	
	return (0);
}
