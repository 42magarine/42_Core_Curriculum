/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HandleDelete.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvinleibenguth <marvinleibenguth@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 17:57:22 by fwahl             #+#    #+#             */
/*   Updated: 2024/12/04 04:51:48 by marvinleibe      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RequestHandler.hpp"

void	RequestHandler::handleDeleteRequest(Client& client)
{
	std::filesystem::path	file_path = client.getBestPath();

	if (!std::filesystem::exists(file_path))
		return (serveErrorPage(client, 404));
	if (std::filesystem::is_directory(file_path))
		return (serveErrorPage(client, 403));

	std::error_code err;
	bool removed = std::filesystem::remove(file_path, err);
	if (!removed || err)
		return (serveErrorPage(client, 500));
	HttpResponse response;
	response.setStatus(204);
	response.setBody("Successfully deleted");
	response.setMimeType(".html");
	client.setResponseString(response.buildResponse());
}
