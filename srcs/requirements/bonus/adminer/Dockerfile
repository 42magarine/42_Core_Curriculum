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
    curl -o /var/www/html/index.php https://www.adminer.org/latest.php

# Configure PHP-FPM to listen on port 9000
RUN sed -i 's|listen = .*|listen = 9000|' /etc/php83/php-fpm.d/www.conf

# Expose port for communication with Nginx
EXPOSE 9000

# Start PHP-FPM in foreground mode
CMD [ "php-fpm83", "-F" ]
