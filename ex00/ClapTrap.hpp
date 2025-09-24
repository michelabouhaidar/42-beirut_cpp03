/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabou-ha <mabou-ha>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 13:00:25 by mabou-ha          #+#    #+#             */
/*   Updated: 2025/09/24 23:23:08 by mabou-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_H

#include <string>

class ClapTrap
{
	private:
		std::string name_;
		int pts_;
		int nrg_pts_;
		int atk_pts_;
	public:
		ClapTrap();
		ClapTrap(const std::string name);
		ClapTrap(const ClapTrap& obj);
		ClapTrap operator=(const ClapTrap& obj);
		~ClapTrap();
		void setName(const std::string name);
		void setPoints(const int pts);
		void setEnergyPoints(const int pts);
		int getPoints() const;
		int getEnergyPoints() const;
		int getAttackPoints() const;
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif