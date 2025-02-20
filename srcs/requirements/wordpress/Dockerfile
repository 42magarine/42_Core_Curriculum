# Use the penultimate stable version of Alpine Linux
FROM alpine:3.20

# Install required packages
RUN apk add --no-cache \
    curl \
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

# Download and install WP-CLI (WordPress command-line interface)
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar && \
    chmod +x wp-cli.phar && \
    mv wp-cli.phar /usr/local/bin/wp

# Copy the configuration file
COPY ./conf/www.conf /etc/php83/php-fpm.d/

# Copy the setup script with execute permissions
COPY --chmod=755 ./tools/wordpress-setup.sh /usr/local/bin/

# Set the working directory to the default WordPress root
WORKDIR /var/www/html

# Expose port
EXPOSE 9000

# Set the entrypoint script
ENTRYPOINT ["/usr/local/bin/wordpress-setup.sh"]
