/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGICreator.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 23:07:04 by mleibeng          #+#    #+#             */
/*   Updated: 2024/12/04 02:05:25 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CGICreator.hpp"

/// @brief returns the php executable path
/// @return returns an std::string value
std::string PHPHandler::getCGIPath() const
{
	return ("/usr/bin/php-cgi");
}

/// @brief return php cgi executable name
/// @return returns an std::string value
std::string PHPHandler::getCGIName() const
{
	return ("php-cgi");
}

/// @brief return php cgi default content
/// @return returns an std::string value
std::string PHPHandler::getDefaultContent() const
{
	return ("application/x-httpd-php");
}

/// @brief return python cgi executable path
/// @return returns an std::string value
std::string PythonHandler::getCGIPath() const
{
	return ("/usr/bin/python3");
}

/// @brief return python cgi name
/// @return returns an std::string value
std::string PythonHandler::getCGIName() const
{
	return ("python3");
}

/// @brief return an extra argument list for python script execution
/// @return returns a string vector
std::vector<std::string> PythonHandler::getArgList() const
{
	return {"-u"};
}

/// @brief return python cgi default content
/// @return returns an std::string value
std::string PythonHandler::getDefaultContent() const
{
	return ("text/x-python");
}

/// @brief returns a CGI Handler object, throws an error in case of unsupported file extension
/// @param file_extension return object is based upon file extension of the script
/// @return returns a unique pointer to the created CGI Handler object
std::unique_ptr<CGIHandler> CGIHandleCreator::createHandler(const std::string& file_extension)
{
	if (file_extension == ".php")
		return (std::make_unique<PHPHandler>());
	if (file_extension == ".py")
		return (std::make_unique<PythonHandler>());
	throw (std::runtime_error("Unsupported File extension for CGI Handling detected"));
}
