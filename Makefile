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

RESET	=	\x1b[0m
RED		=	\x1b[31m
GREEN	=	\x1b[32m
YELLOW	=	\x1b[33m
BLUE	=	\x1b[34m

up:
	mkdir -p ${HOME}/data/mariadb ${HOME}/data/wordpress ${HOME}/data/jekyll
	docker compose -f srcs/docker-compose.yml up --build --detach

down:
	docker compose -f srcs/docker-compose.yml down

start:
	docker compose -f srcs/docker-compose.yml start

stop:
	docker compose -f srcs/docker-compose.yml stop

ls:
	@echo "$(YELLOW)"
	docker compose -f srcs/docker-compose.yml  ps --all
	@echo ""
	docker compose -f srcs/docker-compose.yml images
	@echo ""
	docker volume ls
	@echo ""

logs:
	docker compose -f srcs/docker-compose.yml logs

nginx:
	docker compose -f srcs/docker-compose.yml exec nginx sh

wordpress:
	docker compose -f srcs/docker-compose.yml exec wordpress sh

mariadb:
	docker compose -f srcs/docker-compose.yml exec mariadb sh

redis:
	docker compose -f srcs/docker-compose.yml exec redis sh

ftp:
	docker compose -f srcs/docker-compose.yml exec ftp sh

jekyll:
	docker compose -f srcs/docker-compose.yml exec jekyll sh

adminer:
	docker compose -f srcs/docker-compose.yml exec adminer sh

clean: down
	@echo "$(RED)"
	docker system prune --all --force --volumes
# docker network prune --force

fclean: clean
	rm -rf ${HOME}/data
# docker volume prune --force
