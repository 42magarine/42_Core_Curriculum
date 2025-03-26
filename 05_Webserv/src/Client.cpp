/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:09:03 by mott              #+#    #+#             */
/*   Updated: 2024/12/07 22:01:31 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

int Client::client_counter = 0;

Client::Client(int client_fd, const Config& config) : _client_fd(client_fd), _config(config), _buffersize(std::get<size_t>(config.getGlobalConf(GlobalConf::ConfigKey::MAX_HEADER_SIZE))), redirect_count(0), _route(nullptr), _keep_alive(true), _best_path()
{
	// ++client_counter;
}


// _client_name(generateUniqueName())
// std::string Client::generateUniqueName()
// {
// 	auto now = std::chrono::system_clock::now();
// 	auto now_time_t = std::chrono::system_clock::to_time_t(now);
// 	auto now_tm = *std::localtime(&now_time_t);

// 	std::ostringstream oss;
// 	oss << std::put_time(&now_tm, "%Y%m%d%H%M%S") << "_" << client_counter;
// 	return oss.str();
// }

Client::~Client()
{
	close(_client_fd);
}

const	std::string& Client::getResponseString() const
{
	return (_response_to_send);
}

void	Client::setResponseString(const std::string& built_response)
{
	_response_to_send = built_response;
}

void Client::setBuffer(size_t buffersize)
{
	_buffersize = buffersize;
}

bool Client::hasResponse()
{
	return (!_response_to_send.empty());
}

void 	Client::setCurrentRequest(const HttpRequest& request)
{
	_request = request;
}

bool Client::check_content_length(const HttpRequest& request)
{
	std::string content_len = request.getHeader("Content-Length");

	if (!content_len.empty())
	{
		size_t content_length = std::stoi(content_len);
		if (content_length >= std::get<size_t>(_config.getGlobalConf(GlobalConf::ConfigKey::MAX_BODY_SIZE)))
		{
			_keep_alive = false;
			throw std::invalid_argument("request body too large");
		}
	}
	return true;
}

/// @brief reads in the clientside data sent from the webbrowser
/// @return returns length of request or -1 in case of error
ssize_t Client::read_request()
{
	std::array<char, 4096> buffer = {};

	ssize_t bytes = read(_client_fd, buffer.data(), buffer.size());

	if (bytes < 0)
	{
		_keep_alive = false;
		throw std::runtime_error("Read error");
	}
	if (bytes == 0)
	{
		_keep_alive = false;
		throw std::runtime_error("Connection closed");
	}

	_raw_data.append(buffer.data(), bytes);
	return (bytes);
}

const std::string& Client::getName() const
{
	return (_client_name);
}

// int Client::getNumRedirects() const
// {
// 	return (redirect_count);
// }

// void Client::increaseRedirectCount()
// {
// 	redirect_count++;
// }

void Client::setRoute(const RouteConf* route)
{
	_route = route;
}

bool Client::keepAlive() const
{
	return (_keep_alive);
}

bool Client::checkKeepAliveHeaders()
{
	auto connection = _request.getHeader("Connection");
	if (!connection.empty())
		return (std::strcmp(connection.c_str(), "close") != 0);
	return (_request.getHttpVersion() == "HTTP/1.1");
}

const RouteConf* Client::getRoute() const
{
	return (_route);
}

const std::string& Client::getBestPath() const
{
	return (_best_path);
}

int Client::setCourse()
{
	const ServerConf* server_conf = findServerConf(_request);
	if (!server_conf)
		return (404);

	const RouteConf* route_conf = findRouteConf(*server_conf, _request);
	if (!route_conf)
		return (404);

	_route = route_conf;
	_best_path = parsePath(*route_conf, _request);
	return (0);
}

/// @brief sends a response back to the client side
/// @param response_string std::string response to send
/// @return returns length of string sent or -1 in case of write error
ssize_t Client::send_response(const std::string& response_string)
{
	ssize_t total_sent = 0;
	size_t remaining = response_string.size();

	ssize_t sent = write(_client_fd,
						response_string.c_str() + total_sent,
						remaining);
	if (sent <= 0)
		return (-1);
	total_sent += sent;
	remaining -= sent;

	if (remaining > 0)
		return -202;
	return (total_sent);
}

/// @brief get fd of client
/// @return returns an integer
int Client::getFd() const
{
	return (_client_fd);
}

/// @brief get parsed request as object
/// @return returns an HttpRequest object
const HttpRequest& Client::getRequest() const
{
	return (_request);
}

HttpRequest& Client::getRequest()
{
	return (_request);
}

/// @brief find host:port combination and split
/// @param host host:port combination to split
/// @return string including only the host portion
std::string extractHostname(const std::string& host)
{
	if (size_t pos = host.find(':'); pos != std::string::npos)
		return (host.substr(0, pos));
	return (host);
}

/// @brief find and extract correct server configuration out of vector of server configs for sent request
/// @param request request to parse and respond to
/// @return ServerConf struct with correct hostname/servername or nullptr in case of failure
const ServerConf *Client::findServerConf(const HttpRequest &request)
{
	std::string hostname = extractHostname(request.getHeader("Host"));

	for (const auto& conf : _config.getServerConfs())
	{
		if (conf.hostname == hostname ||
			std::find(conf.server_names.begin(), conf.server_names.end(), hostname) != conf.server_names.end())
			return (&conf);
	}
	return (nullptr);
}

/// @brief find longest matching string from uri to route.path
/// @param server_conf serverconfig to parse for routes
/// @param request request to process and compare to route
/// @return best matching route/default route if not found/nullptr if no default
const RouteConf *Client::findRouteConf(const ServerConf &server_conf, const HttpRequest& request)
{
	const std::string& uri = request.getUri();
	const RouteConf *best_match = nullptr;
	size_t longest_match = 0;

	for (const auto& [path, route] : server_conf.routes)
	{
		if (path.length() <= uri.length() &&
		uri.compare(0, path.length(), path) == 0 &&
		path.length() > longest_match)
		{
			longest_match = path.length();
			best_match = &route;
		}
	}
	if (best_match)
		return (best_match);
	else
	{
		if(server_conf.routes.count("/"))
			return (&server_conf.routes.at("/"));
		else
			return (nullptr);
	}
}

/// @brief check whether or not a string starts with a certain prefix (basic c++20 string function)
/// @param str string to check
/// @param prefix prefix to check at start of string
/// @return true/false
bool startsWith(const std::string& str, const std::string& prefix)
{
	if (prefix.size() > str.size())
		return (false);
	return (str.compare(0, prefix.size(), prefix) == 0);
}

/// @brief check whether or not configured route allows request method to be processed
/// @param route_conf route to check
/// @param method to check
/// @return  true/false
int Client::isMethodAllowed(const RouteConf &route_conf, const std::string &method)
{
	std::vector<std::string> implemented;
	implemented.push_back("DELETE");
	implemented.push_back("POST");
	implemented.push_back("GET");
	if (std::find(implemented.begin(), implemented.end(), method) == implemented.end())
		return (501);
	if (std::find(route_conf.methods.begin(), route_conf.methods.end(), method) == route_conf.methods.end())
		return (405);
	return (0);
}

/// @brief finds best complete path to file
/// @param route_conf route config to build start of route
/// @param request request to add resource requested
/// @return built path to resource
std::string Client::parsePath(const RouteConf& route_conf, const HttpRequest& request)
{
	std::string phys_path;
	std::string uri = request.getUri();

	phys_path = route_conf.root;
	if (!phys_path.empty() && phys_path.back() != '/')
		phys_path += '/';

	if (route_conf.path == "/")
	{
		if (uri != "/")
			phys_path += (uri[0] == '/') ? uri.substr(1) : uri;
	}
	else if (uri.compare(0, route_conf.path.length(), route_conf.path) == 0)
	{
		if (uri.length() == route_conf.path.length() || uri[route_conf.path.length()] == '/')
		{
			std::string remain = uri.substr(route_conf.path.length());
			if (!remain.empty())
				phys_path += (remain[0] == '/') ? remain.substr(1) : remain;
		}
		else
			phys_path += (uri[0] == '/' ? uri.substr(1) : uri);
	}
	return (phys_path);
}

// void Client::split_request(const std::string& raw_data) {
// 	size_t start = 0;
// 	size_t separator_pos;

// 	while ((separator_pos = raw_data.find("\r\n\r\n", start)) != std::string::npos)
// 	{
// 		size_t request_length = separator_pos + 4 - start; // +4 for "\r\n\r\n"
// 		std::string single_request = raw_data.substr(start, request_length);
// 		_request_list.push_back(single_request);

// 		start = separator_pos + 4;
// 	}
// }

// const std::vector<std::string>& Client::getRequest_list() const
// {
// 	return (_request_list);
// }

const std::string& Client::getRaw_data() const
{
	return _raw_data;
}

void Client::clearRequestList()
{
	_request_list.clear();
}

void Client::clearRawData()
{
	_raw_data.clear();
}
