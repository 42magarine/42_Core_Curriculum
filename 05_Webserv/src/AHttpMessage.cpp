/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AHttpMessage.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:56:42 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/07 18:37:31 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AHttpMessage.hpp"

AHttpMessage::AHttpMessage()
{
}

AHttpMessage::AHttpMessage(const AHttpMessage &other)
{
	*this = other;
}

AHttpMessage& AHttpMessage::operator=(const AHttpMessage &other)
{
	if (this != &other)
	{
		setHttpVersion(other.getHttpVersion());
		setAllHeaders(other._header);
		setBody(other.getBody());
	}
	return (*this);
}

AHttpMessage::~AHttpMessage()
{
}

//SETTERS

/// @brief set http version
/// @param vers
void	AHttpMessage::setHttpVersion(const std::string& vers)
{
	_httpVersion = vers;
}

/// @brief set message body
/// @param body
void	AHttpMessage::setBody(const std::string& body)
{
	_body = body;
}

/// @brief set message headers as key[value] pair
/// @param key
/// @param val
void	AHttpMessage::setHeader(const std::string& key, const std::string& val)
{
	_header[key] = val;
}

/// @brief set all message headers as key[value] pairs
/// @param headers
void AHttpMessage::setAllHeaders(const std::unordered_map<std::string, std::string>& headers)
{
	_header.clear();
	for (std::unordered_map<std::string, std::string>::const_iterator it = headers.begin(); it != headers.end(); ++it)
	{
		_header[it->first] = it->second;
	}
}

//GETTERS

/// @brief get version
/// @return
std::string		AHttpMessage::getHttpVersion() const
{
	return (_httpVersion);
}

/// @brief get message body
/// @return
std::string		AHttpMessage::getBody() const
{
	return (_body);
}

/// @brief get header value or nothing depending on key
/// @param key
/// @return corresponding value to the requested key
std::string		AHttpMessage::getHeader(const std::string& key) const
{
	auto iter = (_header.find(key));
	return (iter != _header.end() ? iter->second : "");
}

/// @brief get the complete key[value] map not the individual values
/// @return return an ordered map
const std::unordered_map<std::string, std::string>&	AHttpMessage::getAllHeaders() const
{
	return (_header);
}

//PARSE

/// @brief seperate key value pairs from the inputstream to save them in the ordered header map
/// @param input
bool	AHttpMessage::parseHeader(std::istringstream& input)
{
	std::string line;
	while (std::getline(input, line) && !line.empty() && line != "\r")
	{
		size_t separator = line.find(':');
		if (separator != std::string::npos) {
			std::string key = trimStr(line.substr(0, separator));
			std::string value = trimStr(line.substr(separator + 1));
			setHeader(key,value);
		}
	}
	return (true);
}

std::string AHttpMessage::getCookie(const std::string& key) const
{
	auto it = _cookies.find(key);
	return ((it != _cookies.end()) ? it->second : "");
}

const std::unordered_map<std::string, std::string>& AHttpMessage::getAllCookies() const
{
	return (_cookies);
}

bool AHttpMessage::hasCookie(const std::string& key) const
{
	return (_cookies.find(key) != _cookies.end());
}

void AHttpMessage::parseCookiePair(const std::string &pair)
{
	size_t separator = pair.find('=');
	if (separator != std::string::npos)
	{
		std::string key = trimStr(pair.substr(0, separator));
		std::string value = trimStr(pair.substr(separator + 1));
		_cookies[key] = value;
	}
}

void AHttpMessage::parseCookies()
{
	auto it = _header.find("Cookie");
	if (it == _header.end())
		return ;

	const std::string& cookieHeader = it->second;
	size_t start = 0;
	size_t end = 0;
	while ((end = cookieHeader.find(';', start)) != std::string::npos)
	{
		parseCookiePair(cookieHeader.substr(start, end - start));
		start = end + 1;
	}
	if (start < cookieHeader.length())
		parseCookiePair(cookieHeader.substr(start));
}

//UTILS

/// @brief find first and last occurence of a whitespace
/// @param str
/// @return return a substring without these whitespaces
std::string	AHttpMessage::trimStr(const std::string& str)
{
	size_t first = str.find_first_not_of(" \t\n\r");
	if (first == std::string::npos)
		return ("");

	size_t last = str.find_last_not_of(" \t\n\r");
	return (str.substr(first, (last - first + 1)));
}
