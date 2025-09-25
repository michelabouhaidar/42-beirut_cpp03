/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:48:36 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/09/26 01:09:07 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

static void banner(const std::string& t) {
    std::cout << "\n========== " << t << " ==========\n";
}

int main() {
	banner("construction chaining");
	{
		ClapTrap c("CL4P");
		FragTrap f("FR4G-TP");
	}

	banner("basic actions + override + special");
	{
		FragTrap f("Blaster");
		f.attack("dummy (override should print FragTrap-style message)");
		f.highFivesGuys();
		f.takeDamage(40);
		f.beRepaired(20);
	}

	banner("EP depletion (can’t act at 0 EP)");
	{
		FragTrap f("Runner100");
		while (f.getEnergyPoints() > 0) f.attack("target");
		f.attack("one too many");
		f.beRepaired(1);
	}

	banner("HP to 0 (can’t act at 0 HP)");
	{
		FragTrap f("Fragile");
		f.takeDamage(f.getHitPoints() + 5);
		f.attack("blocked");
		f.beRepaired(5);
	}

	banner("copy / assignment");
	{
		FragTrap a("Alpha");
		a.attack("pre-copy");
		FragTrap b = a;
		b.highFivesGuys();
		FragTrap c("Temp");
		c = a;
		c.attack("post-assign");
	}

	banner("polymorphism + virtual destructor");
	{
		ClapTrap* p1 = new ClapTrap("Basey");
		ClapTrap* p2 = new FragTrap("PolyFrag");
		p1->attack("T1");
		p2->attack("T2");
		delete p1;
		delete p2;
	}

	banner("done");
	return 0;
}



