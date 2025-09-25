/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:48:36 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/09/25 18:55:33 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main() {
	ClapTrap a("Alpha");
	ClapTrap b("Bravo");

	a.attack("Bravo");
	b.takeDamage(a.getAttackPoints());

	b.beRepaired(5);
	for (int i = 0; i < 5; ++i)
		a.attack("a dummy target");
	b.takeDamage(20);
	b.beRepaired(3);
	return 0;
}
