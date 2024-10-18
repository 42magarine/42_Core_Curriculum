/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RequestHandler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 02:32:48 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/17 22:51:40 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RequestHandler.hpp"

RequestHandler::RequestHandler()
{
	// std::cout << GREY << "Default constructor called" << RESET << std::endl;
}

RequestHandler::~RequestHandler()
{
	// std::cout << GREY << "Destructor called" << RESET << std::endl;
}

HttpResponse		RequestHandler::handleRequest(const HttpRequest& request, const Error& error)
{
	switch(request.getMethod())
	{
		case Method::GET:
			return (handleGetRequest(request, error));
		case Method::POST:
			return (handlePostRequest(request, error));
		case Method::DELETE:
			return (handleDeleteRequest(request, error));
		default:
		{
			HttpResponse response;
			response.setStatus(StatusCode::NOT_IMPLEMENTED);
			response.setBody(error.getErrorPage(501));
			response.setHeader("Content-Type", "html/txt");
		}
	}
}

HttpResponse		RequestHandler::handleGetRequest(const HttpRequest& request, const Error& error)
{
	HttpResponse response;
	if (!std::filesystem::exists(request.getFilePath()))
	{
		response.setStatus(StatusCode::NOT_FOUND);
		response.setBody(error.getErrorPage(404));
		response.
	}

	std::ifstream		file(request.getFilePath());
	std::stringstream	fileContent;

	fileContent << file.rdbuf();
	response.setStatus(StatusCode::OK);
	response.setBody(fileContent.str());
	response.setMimeType(getFileExtension(request.getFilePath()));

}
HttpResponse		RequestHandler::handlePostRequest(const HttpRequest& request, const Error& error)
{

}

HttpResponse		RequestHandler::handleDeleteRequest(const HttpRequest& request, const Error& error)
{

}

std::string		getFileExtension(const std::string& filepath)
{
	return (std::filesystem::path(filepath).extension().string());
}
