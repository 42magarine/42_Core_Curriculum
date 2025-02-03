FROM alpine:3.20

RUN apk add --no-cache \
	curl \
	mariadb-client \
	php83 \
	php83-curl \
	php83-fpm \
	php83-json \
	php83-mbstring \
	php83-mysqli \
	php83-openssl \
	php83-pdo_mysql \
	php83-phar \
	php83-xml \
	php83-zip

# command line interface for WordPress
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

COPY ./conf/www.conf /etc/php83/php-fpm.d/www.conf
COPY ./tools/wordpress-setup.sh /wordpress-setup.sh

RUN chmod +x /wordpress-setup.sh

WORKDIR /var/www/html

EXPOSE 9000

ENTRYPOINT ["/wordpress-setup.sh"]
