/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:00:00 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/09/26 01:05:57 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	pts_ = 100; nrg_pts_ = 50; atk_pts_ = 20;
	std::cout << "ScavTrap < " << getName() << " > default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	pts_ = 100; nrg_pts_ = 50; atk_pts_ = 20;
	std::cout << "ScavTrap < " << getName() << " > constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
	std::cout << "ScavTrap < " << getName() << " > copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	if (this != &obj)
		ClapTrap::operator=(obj);
	std::cout << "ScavTrap < " << getName() << " > copy assignment constructor called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap < " << getName() << " > destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (pts_ <= 0)
	{
		std::cout << "ScavTrap < " << getName() << " > cannot attack (no hit points left)" << std::endl;
		return;
	}
	if (nrg_pts_ <= 0)
	{
		std::cout << "ScavTrap < " << getName() << " > cannot attack (no energy points left)" << std::endl;
		return;
	}
	--nrg_pts_;
	std::cout << "ScavTrap < " << getName() << " > slashes < " << target
	<< " >, causing < " << atk_pts_ << " > points of damage" << std::endl;

}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap < " << getName() << " > is now in Gate keeper mode.\n";
}