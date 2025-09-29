/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:20:42 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/09/26 21:32:38 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap() : name_("default"), pts_(10), nrg_pts_(10), atk_pts_(0)
{
	std::cout << "ClapTrap < " << name_ << " > constructor called." << std::endl;
}

ClapTrap::ClapTrap(const std::string& name) : name_(name), pts_(10), nrg_pts_(10), atk_pts_(0)
{
	std::cout << "ClapTrap < " << name_ << " > constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj) : name_(obj.name_), pts_(obj.pts_), nrg_pts_(obj.nrg_pts_), atk_pts_(obj.atk_pts_)
{
	std::cout << "ClapTrap < " << name_ << " > copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{
	this->name_ = obj.name_;
	this->pts_ = obj.pts_;
	this->nrg_pts_ = obj.nrg_pts_;
	this->atk_pts_ = obj.atk_pts_;
	std::cout << "ClapTrap < " << name_ << " > copy assignment constructor called" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap < " << name_ << " > destructor called" << std::endl;
}

int ClapTrap::getHitPoints() const
{
	return pts_;
}

int ClapTrap::getEnergyPoints() const
{
	return nrg_pts_;
}

int ClapTrap::getAttackPoints() const
{
	return atk_pts_;
}

const std::string& ClapTrap::getName() const
{
	return name_;
}

void ClapTrap::attack(const std::string& target)
{
	if (pts_ <= 0)
	{
		std::cout << "ClapTrap < " << name_ << " > cannot attack (no hit points left)" << std::endl;
		return;
	}
	if (nrg_pts_ <= 0)
	{
		std::cout << "ClapTrap < " << name_ << " > cannot attack (no energy points left)" << std::endl;
		return;
	}
	--nrg_pts_;
	std::cout << "ClapTrap < " << name_ << " > attacks < " << target
	<< " >, causing < " << atk_pts_ << " > points of damage" << std::endl;

}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (pts_ <= 0) {
		std::cout << "ClapTrap < " << name_ << " > is already at 0 HP" << std::endl;
		return;
	}
	int before = pts_;
	pts_ -= static_cast<int>(amount);
	if (pts_ < 0) pts_ = 0;
	std::cout << "ClapTrap < " << name_ << " > takes < " << amount << " > damage "
			  << "(HP: " << before << " -> " << pts_ << ")" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (pts_ <= 0) {
		std::cout << "ClapTrap < " << name_ << " > can’t repair (no hit points left)" << std::endl;
		return;
	}
	if (nrg_pts_ <= 0) {
		std::cout << "ClapTrap < " << name_ << " > can’t repair (no energy points left)" << std::endl;
		return;
	}
	--nrg_pts_;
	int before = pts_;
	pts_ += static_cast<int>(amount);
	std::cout << "ClapTrap < " << name_ << " > repairs < " << amount << " > HP "
			  << "(HP: " << before << " -> " << pts_ << ")" << std::endl;
}