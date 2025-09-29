/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:00:00 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/09/26 21:33:38 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap()
{
	pts_ = 100; nrg_pts_ = 50; atk_pts_ = 20;
	std::cout << "ScavTrap < " << name_ << " > default constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name) : ClapTrap(name)
{
	pts_ = 100; nrg_pts_ = 50; atk_pts_ = 20;
	std::cout << "ScavTrap < " << name_ << " > constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj)
{
	std::cout << "ScavTrap < " << name_ << " > copy constructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& obj)
{
	if (this != &obj)
		ClapTrap::operator=(obj);
	std::cout << "ScavTrap < " << name_ << " > copy assignment constructor called" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap < " << name_ << " > destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (pts_ <= 0)
	{
		std::cout << "ScavTrap < " << name_ << " > cannot attack (no hit points left)" << std::endl;
		return;
	}
	if (nrg_pts_ <= 0)
	{
		std::cout << "ScavTrap < " << name_ << " > cannot attack (no energy points left)" << std::endl;
		return;
	}
	--nrg_pts_;
	std::cout << "ScavTrap < " << name_ << " > slashes < " << target
	<< " >, causing < " << atk_pts_ << " > points of damage" << std::endl;

}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap < " << name_ << " > is now in Gate keeper mode.\n";
}