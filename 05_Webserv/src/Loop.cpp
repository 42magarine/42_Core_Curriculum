/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Loop.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvinleibenguth <marvinleibenguth@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 03:00:30 by mleibeng          #+#    #+#             */
/*   Updated: 2024/12/06 05:10:32 by marvinleibe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Loop.hpp"
#include <iostream>

/// @brief create epoll file descriptor / throw error in case of failure
Loop::Loop()
{
	loop_fd = epoll_create(1024);
	if (loop_fd == -1)
		throw (std::runtime_error("Couldn't create loop fd"));
}

/// @brief close epoll file descriptor
Loop::~Loop()
{
	if (loop_fd != -1)
		close(loop_fd);
}

/// @brief add file descriptor to epoll event
/// @param fd file descriptor to add to eventlist
/// @param event event list for processing
void Loop::addFd(int fd, uint32_t event)
{
	epoll_event ev;
	ev.events = event | EPOLLIN_FLAG;
	ev.data.fd = fd;
	if (epoll_ctl(loop_fd, EPOLL_CTL_ADD, fd, &ev) == -1)
		throw (std::runtime_error("Couldn't add fd to epoll"));
	events[fd] = ev;
}

/// @brief removes a file descriptor from event list
/// @param fd file descriptor to remove
void Loop::removeFd(int fd)
{
	epoll_ctl(loop_fd, EPOLL_CTL_DEL, fd, nullptr);
	events.erase(fd);
}

/// @brief wait for event to happen on registered file descriptors
/// @param timeout time to wait before closing file descriptor in ms (not yet utilized)
/// @return returns a vector of a pair of file descriptor/events being waited on.
std::vector<std::pair<int, uint32_t>> Loop::wait(int timeout)
{
	std::vector<std::pair<int, uint32_t>> result;
	int nev = epoll_wait(loop_fd, event_list, MAX_EVENTS, timeout);
	for (int i = 0; i < nev; ++i)
	{
		int fd = event_list[i].data.fd;
		uint32_t events = event_list[i].events;
		result.emplace_back(fd, events);
	}
	return (result);
}

void Loop::modifyFd(int fd, uint32_t event)
{
	epoll_event ev;
	ev.events = event;
	ev.data.fd = fd;
	if (epoll_ctl(loop_fd, EPOLL_CTL_MOD, fd, &ev) == -1)
		throw (std::runtime_error("cant mod fd"));
	events[fd] = ev;
}
