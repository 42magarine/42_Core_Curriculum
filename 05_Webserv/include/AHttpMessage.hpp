/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AHttpMessage.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:56:27 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/08 00:59:23 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AHTTPMESSAGE_H
#define AHTTPMESSAGE_H

#define RED		"\033[31m"
#define YELLOW	"\033[33m"
#define	RESET	"\033[0m"

#include "HeaderIncludes.hpp"

class AHttpMessage
{
	public:
		AHttpMessage();
		AHttpMessage(const AHttpMessage &other);
		AHttpMessage& operator=(const AHttpMessage &other);
		virtual ~AHttpMessage();

		void			setHttpVersion(const std::string& vers);
		void			setHeader(const std::string& key, const std::string& val);
		void			setAllHeaders(const std::unordered_map<std::string, std::string>& headers);
		void			setBody(const std::string& body);

		std::string		getHttpVersion() const;
		std::string		getBody() const;
		std::string		getHeader(const std::string& key) const;
		std::string		getCookie(const std::string& key) const;

		const std::unordered_map<std::string, std::string>&	getAllHeaders() const;
		const std::unordered_map<std::string, std::string>&	getAllCookies() const;

		bool			parseHeader(std::istringstream& input);
		void			parseCookies();
		void			parseCookiePair(const std::string& pair);
		bool			hasCookie(const std::string &name) const;

		static std::string	trimStr(const std::string& str);

	protected:
		std::string										_httpVersion;
		std::string										_body;
		std::unordered_map<std::string, std::string>	_header;
		std::unordered_map<std::string, std::string>	_cookies;
};

#endif // AHTTPMESSAGE_H
