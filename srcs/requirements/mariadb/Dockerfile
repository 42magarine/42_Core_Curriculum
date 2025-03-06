# Use the penultimate stable version of Alpine Linux
FROM alpine:3.20.6

# Install required packages
RUN apk add --no-cache \
    mariadb \
    mariadb-client

# Copy the configuration file
# COPY ./conf/mariadb-server.cnf /etc/my.cnf.d/

# Copy the setup script with execute permissions
COPY --chmod=755 ./tools/mariadb-setup.sh /usr/local/bin/

# Expose port
EXPOSE 3306

# Set the entrypoint script
# ENTRYPOINT [ "mariadb-setup.sh" ]

CMD ["tail", "-f"]
