/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 16:41:26 by faaraujo          #+#    #+#             */
/*   Updated: 2024/06/21 21:43:54 by faaraujo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap diamond("Joao");
	
	diamond.whoAmI();
	diamond.guardGate();
	diamond.attack("Fulano");
	diamond.takeDamage(42);
	diamond.beRepaired(3);
	diamond.getStatusLife();
	diamond.highFivesGuys();
	
	return (0);
}
