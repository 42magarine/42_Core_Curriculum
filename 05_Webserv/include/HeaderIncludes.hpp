/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HeaderIncludes.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 01:10:59 by mleibeng          #+#    #+#             */
/*   Updated: 2024/12/07 22:07:03 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_INCLUDES
#define HEADER_INCLUDES

#include <sys/epoll.h>
#define EPOLLIN_FLAG EPOLLIN
#define EPOLLERR_FLAG EPOLLERR
#define EPOLLHUP_FLAG EPOLLHUP
#define EPOLLOUT_FLAG EPOLLOUT
#define EPOLLET_FLAG EPOLLET

#include <vector>
#include <unordered_map>
#include <chrono>
#include <functional>
#include <sys/types.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <memory>
#include <stdexcept>
#include <cstring>
#include <cerrno>
#include <fcntl.h>
#include <fstream>
#include <optional>
#include <variant>
#include <filesystem>
#include <exception>
#include <sys/wait.h>
#include <atomic>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <thread>
#include <algorithm>
#include <unordered_set>

std::string getTime();

#endif
