/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 02:42:52 by mleibeng          #+#    #+#             */
/*   Updated: 2024/12/04 03:21:12 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
Purpose: Handle parsing of config file
Handles: configuration of hosts, ports and route structure on server-side.
*/

#ifndef CONFIG_HPP
#define CONFIG_HPP

#include "HeaderIncludes.hpp"

struct GlobalConf
{
	int		g_timeout = 60;  // set timeout for closing connections
	size_t	g_max_header_size = 1024; // limit client header size
	size_t	g_max_connects = 1000; // set maximum number of connections (to prevent DDoS)
	size_t	g_max_body_size = 1024 * 1024; //limit client body size

	enum class ConfigKey
	{
		MAX_HEADER_SIZE,
		TIMEOUT,
		MAX_CONNECTIONS,
		MAX_BODY_SIZE,
	};

	std::variant<int,size_t>	getConfig(ConfigKey key) const;
};

struct RouteConf
{
	std::string					path;
	std::vector<std::string>	methods; // Define a list of accepted HTTPS methods for the route
	std::optional<int>			port;
	std::optional<int>			redirect_code;
	std::optional<std::string>	redirect; // Define a HTTP redirection
	std::string					root; //Define a directory or a file from where the file should be searched
	std::string					default_file; // set default file to answer if the request is a directory
	std::vector<std::string>	cgi_extensions; //execute CGI based on certain file extension ex: .php
	std::string					upload_dir; // make the route able to accept uploaded file and configure where they should be saved.
	std::optional<int>			max_header_size; // limit client header size
	std::optional<size_t>		max_body_size; //limit client body size
	std::optional<int>			timeout; // set timeout for closing connections
	std::optional<int>			max_connects; // set maximum number of connections (to prevent DDoS)
	std::optional<int>			max_redirects; //could also implement body buffer size for bigger bodies to control where they split;
	bool						dir_listing_active = false; // turn on or off directory listing
};

struct ServerConf
{
	std::string					hostname; //host for each 'server'
	std::string					default_error_pages; //setup default error pages
	int							port = 80; // port for each 'server'
	std::vector<std::string>	server_names; //'setup the server_names or not'
	std::unordered_map<std::string, RouteConf>	routes; // setup routes with one or multiple of the following -> refer to RouteConf
};

class Config
{
	public:
		Config() = default;
		static Config					parse(const std::string& conf_file);
		const std::vector<ServerConf>&	getServerConfs() const;
		static void						parseServerBlock(ServerConf& conf, const std::string& key, const std::vector<std::string>& value);
		static void						parseRouteBlock(RouteConf& conf, const std::string& key, const std::vector<std::string>& value);
		static void						parseGlobalBlock(GlobalConf& conf, const std::string& key, const std::vector<std::string>& value);
		void							print() const;

		static std::string				trim(const std::string &s);
		std::variant<int, size_t>		getGlobalConf(GlobalConf::ConfigKey key) const;

	private:
		GlobalConf				globuli;
		std::vector<ServerConf>	servers;
};

#endif
