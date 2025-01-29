FROM alpine:3.20

RUN apk add --no-cache \
	mariadb \
	mariadb-client

COPY ./tools/mariadb-setup.sh /mariadb-setup.sh

RUN chmod +x /mariadb-setup.sh

EXPOSE 3306

ENTRYPOINT ["/mariadb-setup.sh"]

CMD ["mysqld", "--user=mysql", "--bind-address=0.0.0.0"]
