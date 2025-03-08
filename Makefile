# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mott <mott@student.42heilbronn.de>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/28 13:43:24 by mott              #+#    #+#              #
#    Updated: 2025/01/31 16:26:50 by mott             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RESET	=	\033[0m
RED		=	\033[31m
GREEN	=	\033[32m
YELLOW	=	\033[33m
BLUE	=	\033[34m

up:
	mkdir -p ${HOME}/data3/wordpress \
		${HOME}/data3/mariadb \
		${HOME}/data3/jekyll \
		${HOME}/data3/portainer
# docker compose -f srcs/docker-compose.yml build --no-cache
	docker compose -f srcs/docker-compose.yml build
	docker compose -f srcs/docker-compose.yml up --detach

down start stop:
	docker compose -f srcs/docker-compose.yml $@

ls:
	@echo "$(YELLOW)"
	docker compose -f srcs/docker-compose.yml ps --all
	@echo ""
	docker compose -f srcs/docker-compose.yml images
	@echo ""
	docker volume ls
	@echo ""
	docker network ls

logs:
	docker compose -f srcs/docker-compose.yml logs

nginx wordpress mariadb redis ftp jekyll adminer portainer:
	docker compose -f srcs/docker-compose.yml exec $@ sh

clean: down
	@echo "$(RED)"
	docker system prune --all --force --volumes

fclean: clean
	docker volume rm --force $$(docker volume ls --quiet) 2>/dev/null || true
	docker network rm --force $$(docker network ls --quiet) 2>/dev/null || true
# sudo rm -rf ${HOME}/data
