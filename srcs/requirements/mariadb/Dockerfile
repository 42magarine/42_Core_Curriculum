# Use the penultimate stable version of Alpine Linux
FROM alpine:3.20.6

# Install MariaDB server and client
RUN apk add --no-cache \
    mariadb \
    mariadb-client

# Copy MariaDB configuration file
COPY ./conf/mariadb-server.cnf /etc/my.cnf.d/

# Copy setup and health check scripts with execution permissions
COPY --chmod=755 ./tools/mariadb-setup.sh /usr/local/bin/
COPY --chmod=755 ./tools/healthcheck.sh /usr/local/bin/

# Expose MySQL/MariaDB default port
EXPOSE 3306

# Set the entrypoint to execute the MariaDB setup script
ENTRYPOINT [ "mariadb-setup.sh" ]
