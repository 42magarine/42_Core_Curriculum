/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HandlePost.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:54:25 by mott              #+#    #+#             */
/*   Updated: 2024/12/07 21:32:36 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RequestHandler.hpp"



/// @brief
/// @param client
/// @param route_conf
/// @param parsed
void	RequestHandler::handlePostRequest(Client& client)
{
	const RouteConf* route_conf = client.getRoute();
	const std::string& parsed = client.getBestPath();
	const std::string& content_type = client.getRequest().getHeader("Content-Type");
	const std::string& body = client.getRequest().getBody();

	std::string file_extension = getFileExtension(parsed);
	if (!route_conf->cgi_extensions.empty() && std::find(route_conf->cgi_extensions.begin(), route_conf->cgi_extensions.end(), file_extension) != route_conf->cgi_extensions.end())
		handleCGI(client, parsed);
	else if (content_type.find("multipart/form-data") != std::string::npos)
		handleFileUpload(client, content_type, body);
	else if (content_type.find("application/x-www-form-urlencoded") != std::string::npos)
		handleFormSubmission(client, body);
	else
		serveErrorPage(client, 405);
}

void	RequestHandler::handleFileUpload(Client& client, const std::string& content_type, const std::string& body)
{
	std::string boundary = extractBoundary(content_type);
	if (boundary.empty())
		return (serveErrorPage(client, 400));
	std::string file = extractFile(body, boundary);
	if (file.empty())
		return (serveErrorPage(client, 400));
	std::string filename = extractFilename(file);
	if (filename.empty())
		return (serveErrorPage(client, 400));
	std::string file_data = extractFileData(file);
	if (file_data.empty())
		return (serveErrorPage(client, 400));

	std::filesystem::path upload_dir = std::filesystem::current_path() / "html_pages/uploads";
	std::filesystem::path file_path = upload_dir / filename;
	if (std::filesystem::exists(file_path))
		return (serveErrorPage(client, 409));

	std::ofstream new_file(file_path, std::ios::binary);
	if (new_file) {
		new_file.write(file_data.data(), file_data.size());
		new_file.close();

		HttpResponse response;
		response.setStatus(201);
		response.setCookie("lastPostRequest", getTime());
		response.setBody("upload successful");
		response.setMimeType(".html");
		client.setResponseString(response.buildResponse());
	}
	else
	{
		// std::cout << "This is the problem" << std::endl;
		return (serveErrorPage(client, 500));
	}
}

std::string RequestHandler::extractBoundary(const std::string& content_type)
{
	size_t boundary_start = content_type.find("boundary=");
	if (boundary_start == std::string::npos)
		return ("");

	return (content_type.substr(boundary_start + 9));
}

std::string RequestHandler::extractFile(const std::string& body, const std::string& boundary)
{
	size_t file_start = body.find(boundary);
	if (file_start == std::string::npos)
		return ("");
	file_start += boundary.size() + 2;   // +2 == \r\n

	size_t file_end = body.find(boundary, file_start);
	if (file_end == std::string::npos)
		return ("");
	file_end -=  4;   // -4 == \r\n--

	return (body.substr(file_start, file_end - file_start));
}

std::string RequestHandler::extractFilename(const std::string& file)
{
	size_t filename_start = file.find("filename=\"");
	if (filename_start == std::string::npos)
		return ("");
	filename_start += 10;   // +10 == filename="

	size_t filename_end = file.find("\"", filename_start);
	if (filename_start == std::string::npos)
		return ("");

	return (file.substr(filename_start, filename_end - filename_start));
}

std::string RequestHandler::extractFileData(const std::string& file)
{
	size_t content_start = file.find("\r\n\r\n");
	if (content_start == std::string::npos)
		return ("");
	content_start += 4;	// +4 == \r\n\r\n

	return (file.substr(content_start));
}



void	RequestHandler::handleFormSubmission(Client& client, const std::string& body)
{
	size_t pos_name = body.find("name=");
	size_t pos_message = body.find("message=");

	std::string name = body.substr(pos_name + 5, pos_message - (pos_name + 5) - 1);
	std::string message = body.substr(pos_message + 8);

	HttpResponse response;

	response.setStatus(201);
	response.setCookie("lastPostRequest", getTime());
	response.setBody("name: " + name + "<br>" + "message: " + message);
	response.setMimeType(".html");
	client.setResponseString(response.buildResponse());
}
