FROM alpine:3.20

RUN apk add --no-cache \
	php83-fpm

COPY ./conf/www.conf /etc/php83/php-fpm.d/www.conf

CMD ["php-fpm83", "-F"]
