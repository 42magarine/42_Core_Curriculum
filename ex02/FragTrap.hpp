/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 18:07:36 by mott              #+#    #+#             */
/*   Updated: 2024/08/21 18:07:37 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H
#define FRAGTRAP_H

class FragTrap {
	public:
		FragTrap();
		FragTrap(const FragTrap &other);

		~FragTrap();

		FragTrap& operator=(const FragTrap &other);

	private:
};

#endif // FRAGTRAP_H
