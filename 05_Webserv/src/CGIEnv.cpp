/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGIEnv.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 00:55:12 by mleibeng          #+#    #+#             */
/*   Updated: 2024/12/04 02:03:16 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RequestHandler.hpp"

/// @brief Constructor sets Environment using RAII
/// @param request sent request of the client
/// @param cgi_path path to the executable script
/// @param handler type of handler responsible for executing the script
RequestHandler::CGIEnv::CGIEnv(const HttpRequest& request, const std::string& cgi_path, const CGIHandler& handler)
{
	setEnviron(request, cgi_path, handler);
}

/// @brief clean up class contents
RequestHandler::CGIEnv::~CGIEnv()
{
	env_array.clear();
	env_bufs.clear();
}

/// @brief returns environment array data
/// @return returns a char ** for easy execve use
char** RequestHandler::CGIEnv::getEnv()
{
	return env_array.data();
}

/// @brief sets the basic environment variables necessary for script execution in CGI's
/// @param request request necessary to be executed
/// @param cgi_path path to the executable script
/// @param handler handler chosen for execution of script
void RequestHandler::CGIEnv::setEnviron(const HttpRequest& request, const std::string& cgi_path, const CGIHandler& handler)
{
	std::string method = request.getMethod();
	addEnvStuff("PYTHONPATH", "html_pages"); // <--- could use improvement not hardcoding it
	// addEnvStuff("PYTHONUNBUFFERED", "1"); // logging for immediate print output

	addEnvStuff("SCRIPT_FILENAME", cgi_path); // Necessary to locate file for execution
	addEnvStuff("DOCUMENT_ROOT", "html_pages"); // <--- could use improvement -> should actually take both doc root and py path from route_conf
	addEnvStuff("REQUEST_URI", request.getUri()); // Necessary for request context
	addEnvStuff("SCRIPT_NAME", request.getUri()); // Necessary for script to find itself within
	addEnvStuff("REQUEST_METHOD", method); // Necessary for different handling of methods
	addEnvStuff("QUERY_STRING", request.getQuery()); // Necessary for processing the query
	addEnvStuff("REDIRECT_STATUS", "200"); // Necessary because PHP CGI binary was compiled with force-cgi-redirect enabled.

	if (method == "POST")
	{
		addEnvStuff("CONTENT_LENGTH", std::to_string(request.getBody().length()));

		auto content_type = request.getHeader("Content-Type");
		if (!content_type.empty())
			addEnvStuff("CONTENT_TYPE", content_type);
		else
			addEnvStuff("CONTENT_TYPE", "application/x-www-form-urlencoded");
	}
	else
	{
		addEnvStuff("CONTENT_LENGTH", "0");
		addEnvStuff("CONTENT_TYPE", handler.getDefaultContent());
	}

	const auto& headers = request.getAllHeaders();
	for (const auto& [header, value] : headers)
	{
		std::string env_name = "HTTP_ " + header;
		std::transform(env_name.begin(), env_name.end(), env_name.begin(), ::toupper);
		std::replace(env_name.begin(), env_name.end(), '-', '_');
		addEnvStuff(env_name, value);
	}

	env_array.push_back(nullptr);
}

/// @brief adds an env variable to the environment
/// @param name name of the variable
/// @param value value of the variable
void RequestHandler::CGIEnv::addEnvStuff(const std::string &name, const std::string& value)
{
	std::string env_var = name + "=" + value;
	auto buffer = std::make_unique<char[]>(env_var.length() + 1);
	std::strcpy(buffer.get(), env_var.c_str());
	env_array.push_back(buffer.get());
	env_bufs.push_back(std::move(buffer));
}

/// @brief print function for environment
void RequestHandler::CGIEnv::debugPrintEnv() const
{
	std::cout << "=== CGI Environment Variables ===" << std::endl;
	for (size_t i = 0; i < env_array.size() - 1; ++i)
	{
		if (env_array[i])
			std::cout << env_array[i] << std::endl;
	}
	std::cout << "===============================" << std::endl;
}
