# penultimate stable version of Alpine
FROM alpine:3.20

RUN apk add --no-cache \
	mariadb \
	mariadb-client

COPY ./conf/mariadb-server.cnf /etc/my.cnf.d/mariadb-server.cnf
COPY ./tools/mariadb-setup.sh /mariadb-setup.sh

RUN chmod +x /mariadb-setup.sh

EXPOSE 3306

ENTRYPOINT ["/mariadb-setup.sh"]
