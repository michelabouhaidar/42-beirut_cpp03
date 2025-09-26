/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 22:34:43 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/09/26 22:35:43 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

static void banner(const std::string& t) {
    std::cout << "\n========== " << t << " ==========\n";
}

int main() {
    banner("construction chain + whoAmI");
    {
        DiamondTrap d("Dia");
        d.whoAmI();               // prints DiamondTrap name and ClapTrap name (Dia_clap_name)
        d.attack("intruder");     // must go through ScavTrap::attack
        d.beRepaired(10);
        d.takeDamage(5);
    } // observe reverse destruction (DiamondTrap -> FragTrap -> ScavTrap -> ClapTrap)

    banner("EP depletion blocks actions");
    {
        DiamondTrap e("Endurance");
        while (e.getEnergyPoints() > 0) {
            e.attack("dummy");
        }
        e.attack("one too many"); // should be blocked (no energy)
        e.beRepaired(3);          // should be blocked (no energy)
    }

    banner("HP to 0 blocks actions");
    {
        DiamondTrap f("Fragile");
        f.takeDamage(f.getHitPoints() + 42); // force HP to 0
        f.attack("blocked");          // blocked (dead)
        f.beRepaired(10);             // blocked (dead)
        f.whoAmI();                   // should say cannot run (dead)
    }

    banner("copy-construct and copy-assign");
    {
        DiamondTrap a("Alpha");
        a.attack("pre-copy");
        DiamondTrap b = a;      // copy-ctor
        b.whoAmI();
        DiamondTrap c("Temp");
        c = a;                  // copy-assign
        c.attack("post-assign");
        c.whoAmI();
    }

    banner("polymorphic delete (virtual base + virtual dtor)");
    {
        ClapTrap* p = new DiamondTrap("Poly");
        p->attack("via ClapTrap*");   // virtual -> DiamondTrap::attack -> ScavTrap::attack
        delete p;                     // ~DiamondTrap … ~ClapTrap
    }

    banner("inherited ScavTrap/FragTrap specials (optional)");
    {
        DiamondTrap z("Zed");
        // DiamondTrap inherits members; you *may* call these:
        z.guardGate();        // from ScavTrap
        z.highFivesGuys();    // from FragTrap
    }

    banner("done");
    return 0;
}
