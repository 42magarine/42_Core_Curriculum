/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 00:05:06 by mleibeng          #+#    #+#             */
/*   Updated: 2024/12/04 01:22:08 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Config.hpp"
#include <iostream>
#include <string>
#include <csignal>
#include "WebServer.hpp"
#include <thread>

#define DEFAULT	"\033[0m"
#define RED		"\033[31m"

static WebServer* g_server_ptr = nullptr;

/// @brief signal handler to stop running webserver
/// @param signum SIGINT causes webserver to stop running
void sighandler(int signum)
{
	if (signum == SIGINT && g_server_ptr)
		g_server_ptr->stop();
}

/// @brief entrypoint for webserver logic
/// @param argc less/more than 2 arguments cause default configuration file to be utilized
/// @param argv specific configuration file to use instead
/// @return ok/not ok in case of error
int main(int argc, char** argv)
{
	std::string config_file;

	if (argc != 2)
		config_file = "Configs/NGINX1.conf";
	else
		config_file = argv[1];
	try
	{
		WebServer MainServ(config_file);
		g_server_ptr = &MainServ;
		std::signal(SIGINT, sighandler);
		MainServ.initialize(std::thread::hardware_concurrency());
		MainServ.start();
		g_server_ptr = nullptr;
	}
	catch (const std::runtime_error& e)
	{
		g_server_ptr = nullptr;
		std::cerr << e.what() << std::endl;
		return (1);
	}
	return (0);
}
