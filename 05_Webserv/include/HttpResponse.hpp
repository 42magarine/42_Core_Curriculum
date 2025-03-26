/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpResponse.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:56:37 by fwahl             #+#    #+#             */
/*   Updated: 2024/12/07 19:59:59 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include "HeaderIncludes.hpp"
#include "AHttpMessage.hpp"

enum class StatusCode
{
	OK = 200,
	CREATED = 201,
	NOCONTENT = 204,
	MOVED_PERM = 301,
	BAD_REQUEST = 400,
	FORBIDDEN = 403,
	NOT_FOUND = 404,
	METH_NOT_ALLOWED = 405,
	CONFLICT = 409,
	PAYLOAD_TOO_LARGE = 413,
	INTERNAL_SERV_ERR = 500,
	NOT_IMPLEMENTED = 501,
	ENDLESS_LOOP = 508
};

class HttpResponse : public AHttpMessage
{
	public:
		HttpResponse();
		HttpResponse(const HttpResponse &other);
		HttpResponse& operator=(const HttpResponse &other);
		~HttpResponse();

		void		setCookie(const std::string& key, const std::string& value,
									int maxAge = -1, const std::string &path = "/",
									bool secure = false, bool HttpOnly = false);
		void		removeCookie(const std::string& key, const std::string& path = "/");
		std::string	buildResponse() const;

		std::string	getMimeType(const std::string extension);
		int			getStatus() const;

		void		setStatus(int status);
		void		setStatus(StatusCode status);
		void		setMimeType(std::string extension);

	private:
		std::string	stostr() const;
		int			stoi() const;
		StatusCode	itos(int code) const;

		StatusCode					_status;
		std::string					_mimeType;
		std::vector<std::string>	_response_cookies;
};

#endif // HTTPRESPONSE_H
