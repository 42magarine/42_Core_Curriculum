/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:08:55 by mott              #+#    #+#             */
/*   Updated: 2024/12/07 21:49:32 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
#define CLIENT_H

#include "HeaderIncludes.hpp"
#include "HttpRequest.hpp"
#include "Config.hpp"
#include "WebServer.hpp"

#define DEFAULT		"\033[0m"
#define RED			"\033[31m"
#define YELLOW		"\033[33m"

class Client
{
	public:
		Client(int client_fd, const Config& config);
		~Client();

		Client() = delete;
		Client(const Client& other) = delete;
		Client& operator=(const Client& other) = delete;

		const HttpRequest&	getRequest() const;
		HttpRequest& 		getRequest();
		void 				setCurrentRequest(const HttpRequest& request);
		const std::string&	getResponseString() const;
		void				setResponseString(const std::string& built_response);
		int					getFd() const;
		bool				hasResponse();

		ssize_t				read_request();
		ssize_t				send_response(const std::string& response_string);

		void				setRoute(const RouteConf* route);

		//incrementers
		void				setBuffer(size_t buffersize);

		//connection checkers
		bool				keepAlive() const;
		bool				checkKeepAliveHeaders();

		//route mngmt
		const std::string&	getName() const;
		int					setCourse();
		const RouteConf*	getRoute() const;
		const std::string&	getBestPath() const;
		const ServerConf	*findServerConf(const HttpRequest &request);
		const RouteConf		*findRouteConf(const ServerConf &server_conf, const HttpRequest& request);
		std::string			parsePath(const RouteConf& route_conf, const HttpRequest& request);
		int					isMethodAllowed(const RouteConf &route_conf, const std::string& method);
		// std::string 		generateUniqueName();

		const std::string&					getRaw_data() const;
		void 								clearRequestList();
		void 								clearRawData();
		bool 								check_content_length(const HttpRequest& request);

	private:
		static int		client_counter;
		std::string		_client_name;
		int				_client_fd;
		const Config&	_config;
		size_t			_buffersize;
		size_t			redirect_count;
		const RouteConf	*_route;
		bool			_keep_alive;
		std::string		_best_path;
		std::string		_response_to_send;

		std::string					_raw_data;
		std::vector<std::string>	_request_list;
		HttpRequest					_request;
};

#endif // CLIENT_H
