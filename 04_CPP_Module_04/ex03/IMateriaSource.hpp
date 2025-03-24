/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 16:04:30 by mott              #+#    #+#             */
/*   Updated: 2024/09/14 16:05:36 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMATERIASOURCE_H
#define IMATERIASOURCE_H

#include "AMateria.hpp"
#include <string>

class IMateriaSource {
	public:
		virtual ~IMateriaSource() {}

		virtual void learnMateria(AMateria* m) = 0;
		virtual AMateria* createMateria(const std::string& type) = 0;
};

#endif // IMATERIASOURCE_H
