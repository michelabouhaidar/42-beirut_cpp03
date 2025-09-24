/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:20:42 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/09/24 13:46:55 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>


ClapTrap::ClapTrap() : name_("default"), pts_(10), nrg_pts_(10), atk_pts_(0)
{
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}