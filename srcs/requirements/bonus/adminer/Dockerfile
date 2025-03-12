# Use the penultimate stable version of Alpine Linux
FROM alpine:3.20.6

# Install required packages
RUN apk add --no-cache \
    curl \
    php83 \
    php83-fpm \
    php83-json \
    php83-mbstring \
    php83-mysqli \
    php83-pdo \
    php83-pdo_mysql \
    php83-session \
    php83-xml

# Download Adminer
RUN mkdir -p /var/www/html && \
    curl -L -o /var/www/html/index.php https://www.adminer.org/static/download/5.0.1/adminer-5.0.1.php

# Copy the PHP-FPM configuration file
COPY ./conf/www.conf /etc/php83/php-fpm.d/

# Expose PHP-FPM port for Nginx
EXPOSE 9000

# Start PHP-FPM in the foreground mode
CMD [ "php-fpm83", "-F" ]
