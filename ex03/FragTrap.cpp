/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 00:17:45 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/09/26 22:38:56 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap()
{
	pts_ = 100; nrg_pts_ = 100; atk_pts_ = 30;
	std::cout << "FragTrap < " << name_ << " > default constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	pts_ = 100; nrg_pts_ = 100; atk_pts_ = 30;
	std::cout << "FragTrap < " << name_ << " > constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj)
{
	std::cout << "FragTrap < " << name_ << " > copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& obj)
{
	if (this != &obj)
		ClapTrap::operator=(obj);
	std::cout << "FragTrap < " << name_ << " > copy assignment constructor called" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap < " << name_ << " > destructor called" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
	if (pts_ <= 0)
	{
		std::cout << "FragTrap < " << name_ << " > cannot attack (no hit points left)" << std::endl;
		return;
	}
	if (nrg_pts_ <= 0)
	{
		std::cout << "FragTrap < " << name_ << " > cannot attack (no energy points left)" << std::endl;
		return;
	}
	--nrg_pts_;
	std::cout << "FragTrap < " << name_ << " > blasts < " << target
	<< " >, causing < " << atk_pts_ << " > points of damage" << std::endl;
}

void FragTrap::highFivesGuys()
{
    std::cout << "FragTrap <" << name_ << "> requests a high five!" << std::endl;
}