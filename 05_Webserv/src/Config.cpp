/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Config.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 00:05:15 by mleibeng          #+#    #+#             */
/*   Updated: 2024/12/04 01:51:05 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Config.hpp"
#include <algorithm>
#include <iostream>

/// @brief modifies value notations like 10M or 8G to size_t
/// @param sizeStr value notation to transform
/// @return size_t value
size_t parseSizeNotation(const std::string& sizeStr)
{
	std::unordered_map<char, size_t> multipliers =
	{
		{'K', 1024},
		{'M', 1024 * 1024},
		{'G', 1024 * 1024 * 1024}
	};
	size_t size = 0;
	size_t currentNumber = 0;

	for (char c : sizeStr)
	{
		if (std::isdigit(c))
			currentNumber = currentNumber * 10 + (c - '0');
		else if (std::isalpha(c))
		{
			char unit = std::toupper(c);
			if (multipliers.find(unit) == multipliers.end())
				throw (std::runtime_error("Invalid size unit: " + std::string(1, c)));
			size += currentNumber * multipliers[unit];
			currentNumber = 0;
		}
		else if (c != ' ' && c != '\t')
			throw (std::runtime_error("Invalid character in size notation: " + std::string(1, c)));
	}
	if (currentNumber > 0)
		size += currentNumber;
	return (size);
}

/// @brief trim string when finding whitespace
/// @param string to trim
/// @return trimmmed string
std::string Config::trim(const std::string &s)
{
	auto wsfront = std::find_if_not(s.begin(), s.end(), [](int c) { return std::isspace(c); });
	auto wsback = std::find_if_not(s.rbegin(), s.rend(), [](int c) { return std::isspace(c); }).base();
	return (wsback <= wsfront ? std::string() : std::string(wsfront, wsback));
}

/// @brief saves information for the server block
/// @param conf config to read out
/// @param key key part of key/value pair
/// @param values value part of key/value pair
void Config::parseServerBlock(ServerConf& conf, const std::string& key, const std::vector<std::string>& values)
{
	if (key == "hostname")
		conf.hostname = values[0];
	else if (key == "port")
		conf.port = std::stoi(values[0]);
	else if (key == "server_name")
		conf.server_names = values;
	else if (key == "default_error_pages")
		conf.default_error_pages = values[0];
	else
		throw (std::runtime_error("Unknown Server Configuration key"));
}

/// @brief saves information for the route block
/// @param conf config to read out
/// @param key key part of key/value pair
/// @param values value part of key/value pair
void Config::parseRouteBlock(RouteConf& conf, const std::string& key, const std::vector<std::string>& values)
{
	if (key == "methods")
		conf.methods = values;
	else if (key == "redirect")
	{
		if (values.size() == 1)
			conf.redirect = values[0];
		else if (values.size() == 2)
		{
			conf.redirect_code = std::stoi(values[0]);
			conf.redirect = values[1];
		}
	}
	else if (key == "max_redirects")
		conf.max_redirects = std::stoi(values[0]);
	else if (key == "port")
		conf.port = std::stoi(values[0]);
	else if (key == "root")
		conf.root = values[0];
	else if (key == "dir_listing")
		conf.dir_listing_active = (values[0] == "on" || values[0] == "true" || values[0] == "1");
	else if (key == "default_file")
		conf.default_file = values[0];
	else if (key == "cgi_extension")
		conf.cgi_extensions = values;
	else if (key == "upload_dir")
		conf.upload_dir = values[0];
	else if (key == "max_body_size")
		conf.max_body_size = parseSizeNotation(values[0]);
	else if (key == "max_header_size")
		conf.max_header_size = parseSizeNotation(values[0]);
	else if (key == "timeout")
		conf.timeout = std::stoi(values[0]);
	else if (key == "max_connects")
		conf.max_connects = std::stoi(values[0]);
	else
		throw (std::runtime_error("Unknown Route Configuration key"));
}

/// @brief saves global values
/// @param conf config to read out
/// @param key key part of key/value pair
/// @param values value part of key/value pair
void Config::parseGlobalBlock(GlobalConf& conf, const std::string& key, const std::vector<std::string>& values)
{
	if (key == "timeout")
		conf.g_timeout = std::stoi(values[0]);
	else if (key == "max_connects")
		conf.g_max_connects = std::stoi(values[0]);
	else if (key == "max_body_size")
		conf.g_max_body_size = parseSizeNotation(values[0]);
	else if (key == "max_header_size")
		conf.g_max_header_size = parseSizeNotation(values[0]);
	else
		throw (std::runtime_error("Unknown Global Configuration key"));
}

std::variant<int,size_t> GlobalConf::getConfig(ConfigKey key) const
{
	switch (key)
	{
		case ConfigKey::MAX_HEADER_SIZE:
			return (g_max_header_size);
		case ConfigKey::MAX_BODY_SIZE:
			return (g_max_body_size);
		case ConfigKey::MAX_CONNECTIONS:
			return (g_max_connects);
		case ConfigKey::TIMEOUT:
			return (g_timeout);
		default:
			throw (std::invalid_argument("invalid global config key"));
	}
}

std::variant<int, size_t> Config::getGlobalConf(GlobalConf::ConfigKey key) const
{
	 return (globuli.getConfig(key));
}

/// @brief parses the config file to save appropriate information
/// @param conf_file config file to parse
/// @return parsed Config file
Config Config::parse(const std::string& conf_file)
{
	Config config;
	std::ifstream file(conf_file);
	if (!file.is_open())
		throw (std::runtime_error("Unable to open config file!"));

	std::string line;
	ServerConf current_server;
	RouteConf current_route;
	std::string current_route_path;
	bool in_server_block = false;
	bool in_route_block = false;
	int line_number = 0;

	while (std::getline(file, line))
	{
		line_number++;
		line = trim(line);
		if (line.empty() || line[0] == '#')
			continue ;
		if (line == "server {")
		{
			in_server_block = true;
			current_server = ServerConf();
		}
		else if (line.substr(0,6) == "route " && line.back() == '{')
		{
			if (!in_server_block)
				throw (std::runtime_error("route block outside of server block at line: " + std::to_string(line_number)));
			in_route_block = true;
			current_route = RouteConf();
			current_route_path = trim(line.substr(6, line.find('{') - 7));
			current_route.path = current_route_path;
		}
		else if (line == "}")
		{
			if (in_route_block)
			{
				in_route_block = false;
				current_server.routes[current_route_path] = current_route;
				current_route_path.clear();
			}
			else if (in_server_block)
			{
				in_server_block = false;
				config.servers.push_back(current_server);
			}
			else
				throw (std::runtime_error("Unexpected closing brace at line: " + std::to_string(line_number)));
		}
		else
		{
			std::istringstream iss(line);
			std::string key;
			std::vector<std::string> values;
			if (iss >> key)
			{
				std::string value;
				while (iss >> value)
					values.push_back(value);
				if (in_route_block)
					parseRouteBlock(current_route, key, values);
				else if (in_server_block)
					parseServerBlock(current_server, key, values);
				else
					parseGlobalBlock(config.globuli, key, values);
			}
			else
				throw (std::runtime_error("invalid config line at: "  + std::to_string(line_number)));
		}
	}
	for (auto& server : config.servers)
	{
		for (auto& [path, route] : server.routes)
		{
			if (!route.max_redirects) route.max_redirects = 10;
			if (route.redirect.has_value() && !route.redirect_code.has_value()) route.redirect_code = 301;
			if (!route.max_header_size) route.max_header_size = config.globuli.g_max_header_size;
			if (!route.max_body_size) route.max_body_size = config.globuli.g_max_body_size;
			if (!route.timeout) route.timeout = config.globuli.g_timeout;
			if (!route.max_connects) route.max_connects = config.globuli.g_max_connects;
			if (!route.port) route.port = server.port;
		}
	}
	return (config);
}

/// @brief vector of server configurations
/// @return std::vector of server conf struct
const std::vector<ServerConf>& Config::getServerConfs() const
{
	return (servers);
}

/// @brief prints the parsed config file
void Config::print() const
{
	std::cout << "Global Configuration:\n";
	std::cout << "  Max Header Size: " << globuli.g_max_header_size << "\n";
	std::cout << "  Max Body Size: " << globuli.g_max_body_size << "\n";
	std::cout << "  Timeout: " << globuli.g_timeout << "\n";
	std::cout << "  Max Connects: " << globuli.g_max_connects << "\n\n";

	for (const auto& server : servers)
	{
		std::cout << "Server Configuration:\n";
		std::cout << "  Hostname: " << server.hostname << "\n";
		std::cout << "  Port: " << server.port << "\n";
		std::cout << "  Server Names: ";
		for (const auto& name : server.server_names)
			std::cout << name << " ";
		std::cout << "\n";
		std::cout << "  Default Error Pages: " << server.default_error_pages << "\n";

		for (const auto& [path, route] : server.routes)
		{
			std::cout << "  Route: " << path << "\n";
			std::cout << "    Methods: ";
			for (const auto& method : route.methods)
				std::cout << method << " ";
			std::cout << "\n";
			if (route.redirect)
			{
				std::cout << "    Redirect code: " << *route.redirect_code << "\n";
				std::cout << "    Redirect: " << *route.redirect << "\n";
			}
			std::cout << "    Route Port: " << *route.port << "\n";
			std::cout << "    Root: " << route.root << "\n";
			std::cout << "    Directory Listing: " << (route.dir_listing_active ? "On" : "Off") << "\n";
			std::cout << "    Default File: " << route.default_file << "\n";
			for (const auto& cgi_extension : route.cgi_extensions)
				std::cout << cgi_extension << " ";
			std::cout << "\n";
			std::cout << "    Upload Directory: " << route.upload_dir << "\n";
			std::cout << "    Max Header Size: " << *route.max_header_size << "\n";
			std::cout << "    Max Body Size: " << *route.max_body_size << "\n";
			std::cout << "    Timeout: " << *route.timeout << "\n";
			std::cout << "    Max Connects: " << *route.max_connects << "\n";
		}
		std::cout << "\n";
	}
}
