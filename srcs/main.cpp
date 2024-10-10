/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvinleibenguth <marvinleibenguth@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 00:05:06 by mleibeng          #+#    #+#             */
/*   Updated: 2024/10/10 15:14:57 by marvinleibe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WebServer.hpp"
#include <iostream>

//should probably also implement signal handling!
int main(int argc, char **argv)
{
	std::string config_file;

	if (argc != 2)
		config_file = "Configs/NGINX1.conf";
	else
		config_file = argv[1];
	try
	{
		std::cout << config_file << std::endl;
		WebServer MainServ(config_file);
		// MainServ.initialize();
		// MainServ.start();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
	catch (...)
	{
		std::cerr << "unknown error" << std::endl;
		return 1;
	}
	return (0);
}