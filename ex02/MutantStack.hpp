/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 14:49:56 by mott              #+#    #+#             */
/*   Updated: 2024/10/19 18:44:59 by mott             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {
	public:
		MutantStack() : std::stack<T>() {};
		MutantStack(const MutantStack& other) : std::stack<T>(other) {};

		~MutantStack() {};

		MutantStack& operator=(const MutantStack& other) {
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this;
		}

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator begin() {
			return std::stack<T>::c.begin();
		};

		iterator end() {
			return std::stack<T>::c.end();
		};

		const_iterator begin() const {
			return std::stack<T>::c.begin();
		};

		const_iterator end() const {
			return std::stack<T>::c.end();
		};
};

// stack definition:
// template <class _Tp, class _Container /*= deque<_Tp>*/>
// class _LIBCPP_TEMPLATE_VIS stack
// {
// public:
//     typedef _Container                               container_type;
//     typedef typename container_type::value_type      value_type;
//     typedef typename container_type::reference       reference;
//     typedef typename container_type::const_reference const_reference;
//     typedef typename container_type::size_type       size_type;
//     static_assert((is_same<_Tp, value_type>::value), "" );

// protected:
//     container_type c;
// }
