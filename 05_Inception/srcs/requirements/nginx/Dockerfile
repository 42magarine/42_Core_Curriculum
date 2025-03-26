# Use the penultimate stable version of Alpine Linux
FROM alpine:3.20.6

# Install Nginx and OpenSSL
RUN apk add --no-cache \
    nginx \
    openssl

# Copy Nginx configuration file
COPY ./conf/default.conf /etc/nginx/http.d/

# Copy the Nginx setup script and set execution permissions
COPY --chmod=755 ./tools/nginx-setup.sh /usr/local/bin/

# Expose HTTPS port
EXPOSE 443

# Set the entrypoint to execute the Nginx setup script
ENTRYPOINT [ "nginx-setup.sh" ]
