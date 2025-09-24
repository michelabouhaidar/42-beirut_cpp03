/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:20:42 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/09/24 23:26:35 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>


ClapTrap::ClapTrap() : name_("default"), pts_(10), nrg_pts_(10), atk_pts_(0)
{
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(const std::string name) : name_(name), pts_(10), nrg_pts_(10), atk_pts_(0)
{
	std::cout << "ClapTrap " << name_ << "constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	*this = obj;
}

