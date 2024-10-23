/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RequestHandler.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleibeng <mleibeng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 02:32:48 by fwahl             #+#    #+#             */
/*   Updated: 2024/10/23 19:40:55 by mleibeng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RequestHandler.hpp"

RequestHandler::RequestHandler(const Config& config) : _config(config)
{
	loadErrorPages();
}

void RequestHandler::loadErrorPages() // this probably only works if we have 1 singular error pages...
{
	for (const auto &server : _config.getServerConfs())
	{
		if (!server.default_error_pages.empty())
		{
			std::ifstream file(server.default_error_pages);
			std::string line;
			while (std::getline(file, line))
			{
				std::istringstream iss(line);
				int error_code;
				std::string page_path;
				if (iss >> error_code >> page_path)
					_error_pages[error_code] = page_path;
			}
		}
	}
}

RequestHandler::~RequestHandler()
{
	// std::cout << GREY << "Destructor called" << RESET << std::endl;
}
const ServerConf *RequestHandler::findServerConf(const HttpRequest &request)
{
	const ServerConf *server_conf = nullptr;
	for (const auto& conf : _config.getServerConfs())
	{
		if (conf.hostname == request.getHeader("Host") || // Hier nicht sicher wie der Header fuer host heisst!!!
			std::find(conf.server_names.begin(), conf.server_names.end(), request.getHeader("Host")) != conf.server_names.end())
		{
			server_conf = &conf;
			break;
		}
	}
	return server_conf;
}

const RouteConf *RequestHandler::findRouteConf(const ServerConf &server_conf, const HttpRequest& request)
{
	const RouteConf *route_conf = nullptr;
	for (const auto& [path, conf] : server_conf.routes)
	{
		if (request.getUri().compare(0, path.length(), path) == 0) // also not sure here with the getUri() have to compare values
		{
			route_conf = &conf;
			break;
		}
	}
	return route_conf;
}

bool RequestHandler::isMethodAllowed(const RouteConf &route_conf, const std::string &method)
{
	if (std::find(route_conf.methods.begin(), route_conf.methods.end(), method) == route_conf.methods.end())
		return false;
	return true;
}

std::string		RequestHandler::handleRequest(const HttpRequest& request)
{

	const ServerConf* server_conf = findServerConf(request);
	if (!server_conf)
	{
		// Koennt ihr das machen?? keine Ahnung wie ihr das bauen wollt.
		// HttpResponse RueckgabeObjekt;
		// RueckgabeObjekt.setStatus(StatusCode::NOT_IMPLEMENTED);
		// RueckgabeObjekt.setBody(serveErrorPage(501)); gibs nich
		// RueckgabeObjekt.setHeader("Content-Type", "html/txt");
		// return RueckgabeObjekt;
	}

	const RouteConf* route_conf = findRouteConf(*server_conf, request);
	if (!route_conf)
	{
		// Koennt ihr das machen?? keine Ahnung wie ihr das bauen wollt.
		// HttpResponse RueckgabeObjekt;
		// RueckgabeObjekt.setStatus(StatusCode::NOT_IMPLEMENTED);
		// RueckgabeObjekt.setHeader("Content-Type", "html/txt");
		// serveErrorPage(404); //nich gefunden
		return;
	}

	// hier als string reingeben die method!!
	if (!isMethodAllowed(*route_conf, request.methodToStr()))
	{
		// Koennt ihr das machen?? keine Ahnung wie ihr das bauen wollt.
		// HttpResponse RueckgabeObjekt;
		// RueckgabeObjekt.setStatus(StatusCode::NOT_IMPLEMENTED);
		// RueckgabeObjekt.setHeader("Content-Type", "html/txt");
		// serveErrorPage(405); //verboten
		// return;
	}

	/* GANZ WICHTIG!! : Die Handles brauchen als zweites Argument die &route conf und die muss per pointer uebergeben werden!! */
	switch(request.getMethod())
	{
		// Bsp: handleGetRequest(request, *route_conf)
		case Method::GET:
			return (handleGetRequest(request, *route_conf).buildResponse());
		case Method::POST:
			return (handlePostRequest(request,*route_conf).buildResponse());
		case Method::DELETE:
			return (handleDeleteRequest(request, *route_conf).buildResponse());
		default:
		{
			HttpResponse response;
			response.setStatus(StatusCode::NOT_IMPLEMENTED);
			// response.setBody(error.getErrorPage(501));
			response.setHeader("Content-Type", "html/txt");
			return (response.buildResponse());
		}
	}
}

// und hier das argument nr2 so: ->  handleGetRequest(request, const RouteConf &route_conf)!
HttpResponse		RequestHandler::handleGetRequest(const HttpRequest& request, const RouteConf& route_conf)
{
	// HIER ist der FilePath
	//  |
	//  v
	std::string file_path = route_conf.root + request.getUri(); // weiss wie gesagt nich ob das 100% stimmt mit der URI

	HttpResponse response;

	// DIESE LOGIK FEHLT
	//      |
	//      V
	// if (std::filesystem::is_directory(file_path))
	// {
	// 	if (route_conf.dir_listing_active)
	// 		sendDirectoryListing(request, file_path);
	// 	else if (!route_conf._default_file.empty())
	// 	{
	// 		file_path += "/" + route_conf._default_file;
	// 		sendFile(request, file_path); 					//jetzt wahrscheinlich prepareFile oder so...
	// 	}
	// 	else
	// 		serveErrorPage(client.get_fd(), 403); // Forbidden
	// }
	// else
	// 	sendFile(request, file_path);

// ------------------------------------------------------------------------------------
	// if (!std::filesystem::exists(file_path))
	// {
	// 	response.setStatus(StatusCode::NOT_FOUND);
	// 	// response.setBody(error.getErrorPage(404));
	// 	response.setHeader("Content-Type", "html/txt");
	// }

	// std::ifstream		file(request.getFilePath());
	// std::ifstream		file("html_pages/index.html");
	// std::cout << RED << request.getUri() << RESET << std::endl;
	std::ifstream		file("html_pages/" + request.getUri());
	if (!file.is_open())
	{
		std::cerr << "Could not open " << std::endl;
	}
	std::stringstream	fileBuffer;
	std::string			fileContent;

	fileBuffer << file.rdbuf();
	fileContent = fileBuffer.str();
	file.close();
	response.setStatus(StatusCode::OK);
	response.setBody(fileContent);
	// response.setMimeType(getFileExtension(request.getFilePath()));
	// response.setMimeType(getFileExtension("html_pages/index.html"));
	response.setMimeType(getFileExtension("html_pages/" + request.getUri()));
	return(response);
}

HttpResponse		RequestHandler::handlePostRequest(const HttpRequest& request, const RouteConf& route_conf)
{
	// std::string file_path = route_conf.root + request.getUri();
	(void)request;
	HttpResponse response;

	// DIESE LOGIK MUSS REIN <- filedescriptor koennte ein issue sein. weil CGI schickt selber zurueck und baut keine Nachricht!!
	// if (!route_conf.cgi_extension.empty() && request.getUri().ends_with(route_conf.cgi_extension))
	//		handleCGI(int fd, file_path, request.getBody());
	// else
	//		normale handler logik!
	return(response);
}

HttpResponse		RequestHandler::handleDeleteRequest(const HttpRequest& request, const RouteConf& route_conf)
{
	// std::string file_path = route_conf.root + request.getUri();

	// LOGIK:
	//  |
	//  V
	// if (std::filesystem::exists(file_path) && !std::filesystem::is_directory(file_path))
	// {
	// 	if (std::filesystem::remove(file_path))
	// 		client.send_response(HttpResponse(200, "text/plain", "File deleted successfully"));
	// 	else
	// 		serveErrorPage(client.get_fd(), 500); // Internal Server Error
	// }
	// else
	// 	serveErrorPage(client.get_fd(), 404); // Not

	(void)request;
	HttpResponse response;
	return(response);
}

std::string		getFileExtension(const std::string& filepath)
{
	return (std::filesystem::path(filepath).extension().string());
}
