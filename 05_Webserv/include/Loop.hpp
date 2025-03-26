/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Loop.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 02:58:49 by mleibeng          #+#    #+#             */
/*   Updated: 2024/12/04 03:22:40 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Purpose: Implement event handling
Handles: I/O operations using kqueue, file descriptors, timers and async actions
*/

#ifndef LOOP_HPP
#define LOOP_HPP

#include "HeaderIncludes.hpp"

class Loop
{
	public:
		Loop();
		~Loop();

		void	addFd(int fd, uint32_t events);
		void	removeFd(int fd);
		void	modifyFd(int fd, uint32_t event);

		std::vector<std::pair<int, uint32_t>> wait(int timeout = -1);

	private:
		int										loop_fd;
		static const int						MAX_EVENTS = 1024;
		std::unordered_map<int, epoll_event>	events;
		epoll_event								event_list[MAX_EVENTS];
};

#endif
