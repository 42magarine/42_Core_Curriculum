/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HttpRequest.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 15:56:33 by fwahl             #+#    #+#             */
/*   Updated: 2024/12/04 02:56:07 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include "HeaderIncludes.hpp"
#include "Config.hpp"
#include "AHttpMessage.hpp"

class HttpRequest : public AHttpMessage
{
	public:
		enum class State
		{
			R_HEADER,
			ROUTING,
			R_BODY,
			COMPLETE,
			ERROR
		};

		HttpRequest();
		HttpRequest(const HttpRequest &other);
		HttpRequest& operator=(const HttpRequest &other);
		~HttpRequest();

		bool				parse(const std::string& rawmsg);
		bool				Complete() const;

		void				setMethod(const std::string& method);
		void				setQuery(const std::string& uri);
		void				setState(State state);

		const std::string&	getMethod() const;
		const std::string&	getUri() const;
		const std::string&	getQuery() const;
		const std::string&	getUploadPath() const;
		State				getState() const;


	private:
		State							_state;
		std::string						_method;
		std::string						_uri;
		std::string						_query;
		std::string						_part_headers;
		std::string						_upload_path;
		std::unique_ptr<std::ofstream>	_upload_file;
		size_t							_expected_content_len;
		size_t							_byte_read;
		std::string						_boundary;
};

#endif // HTTPREQUEST_H
