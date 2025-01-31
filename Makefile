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
	docker compose -f srcs/docker-compose.yml up --build -d

down:
	docker compose -f srcs/docker-compose.yml down -v

start:
	docker compose -f srcs/docker-compose.yml start

stop:
	docker compose -f srcs/docker-compose.yml stop

ls:
	@echo "$(YELLOW)"
	docker compose -f srcs/docker-compose.yml  ps -a
	@echo ""
	docker compose -f srcs/docker-compose.yml images
	@echo ""

nginx:
	docker compose -f srcs/docker-compose.yml exec nginx sh

wordpress:
	docker compose -f srcs/docker-compose.yml exec wordpress sh

mariadb:
	docker compose -f srcs/docker-compose.yml exec mariadb sh

clean:
	@echo "$(RED)"
	docker system prune -af --volumes

fclean: clean
	rm -rf srcs/data
