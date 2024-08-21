/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 19:07:55 by mott              #+#    #+#             */
/*   Updated: 2024/08/21 19:07:56 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

class DiamondTrap {
	public:
		DiamondTrap();
		DiamondTrap(const DiamondTrap &other);

		~DiamondTrap();

		DiamondTrap& operator=(const DiamondTrap &other);

	private:
};

#endif // DIAMONDTRAP_H
