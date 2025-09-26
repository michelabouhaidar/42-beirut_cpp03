/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 13:00:44 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/09/26 23:00:32 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(), FragTrap(), name_("default")
{
	pts_ = 100;
	nrg_pts_ = 50;
	atk_pts_ = 30;
	std::cout << "DiamondTrap < " <<  name_ << " > construtor called" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name_(name)
{
	pts_ = 100;
	nrg_pts_ = 50;
	atk_pts_ = 30;
	std::cout << "DiamondTrap < " <<  name_ << " > construtor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj), ScavTrap(obj), FragTrap(obj), name_(obj.name_)
{
	ClapTrap::name_ = name_ + "_clap_name";
	std::cout << "DiamondTrap < " << name_ << " > copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	if (this != &obj)
	{
		ClapTrap::operator=(obj);
		ScavTrap::operator=(obj);
		FragTrap::operator=(obj);
		name_ = obj.name_;
		ClapTrap::name_ = name_ + "_clap_name";
		pts_ = obj.pts_;
		nrg_pts_ = obj.nrg_pts_;
		atk_pts_ = obj.atk_pts_;
	}
	std::cout << "DiamondTrap < " << name_ << " > copy assignment operator called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap < " << name_ << " > destructor called" << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "I am DiamondTrap < " << name_
			  << "> and my ClapTrap name is < " << ClapTrap::name_ << " >" << std::endl;
}