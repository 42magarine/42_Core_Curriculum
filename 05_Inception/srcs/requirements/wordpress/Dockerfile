# Use the penultimate stable version of Alpine Linux
FROM alpine:3.20.6

# Install required packages for WordPress and PHP extensions
RUN apk add --no-cache \
    curl \
    php83 \
    php83-ctype \
    php83-curl \
    php83-fpm \
    php83-json \
    php83-mbstring \
    php83-mysqli \
    php83-openssl \
    php83-pdo_mysql \
    php83-phar \
    php83-redis \
    php83-tokenizer \
    php83-xml \
    php83-zip

# Download and install WP-CLI
RUN curl -o /usr/local/bin/wp \
        -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x /usr/local/bin/wp

# Copy PHP-FPM configuration file
COPY ./conf/www.conf /etc/php83/php-fpm.d/

# Copy the WordPress setup script and set execution permissions
COPY --chmod=755 ./tools/wordpress-setup.sh /usr/local/bin/

# Set the working directory to the default WordPress root directory
WORKDIR /var/www/html

# Expose PHP-FPM port for Nginx
EXPOSE 9000

# Set the entrypoint to execute the WordPress setup script
ENTRYPOINT [ "wordpress-setup.sh" ]
