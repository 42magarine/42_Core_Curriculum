/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Loop.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 03:00:30 by mleibeng          #+#    #+#             */
/*   Updated: 2024/10/16 00:32:11 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Loop.hpp"
#include <iostream>

Loop::Loop()
{
#ifdef __APPLE__
	_loop_fd = kqueue();
#else
	_loop_fd = epoll_create1(0);
#endif
	if (_loop_fd == -1)
		throw std::runtime_error("Couldn't Create loop fd");
}

Loop::~Loop()
{
	if (_loop_fd != -1)
		close(_loop_fd);
}

void Loop::addFd(int fd, uint32_t event)
{
#ifdef __APPLE__
	//dont know yet
#else
	epoll_event ev;
	ev.events = event;
	ev.data.fd = fd;
	if (epoll_ctl(_loop_fd, EPOLL_CTL_ADD, fd, &ev) == -1)
		throw std::runtime_error("Couldn't add fd to epoll");
	events[fd] = ev;
	std::cout << fd << std::endl;
#endif
}

void Loop::removeFd(int fd)
{
	// (void)fd;
#ifdef __APPLE__
	// don't know yet
#else
	epoll_ctl(_loop_fd, EPOLL_CTL_DEL, fd, nullptr);
	events.erase(fd);
#endif
}

std::vector<std::pair<int, uint32_t>> Loop::wait(int timeout)
{
	// (void)timeout;
	std::vector<std::pair<int, uint32_t>> result;
#ifdef __APPLE__
	// don't know yet
#else
	int nev = epoll_wait(_loop_fd, event_list, MAX_EVENTS, timeout);
	for (int i = 0; i < nev; ++i)
	{
		int fd = event_list[i].data.fd;
		uint32_t events = event_list[i].events;
		result.emplace_back(fd, events);
	}
#endif
	return result;
}