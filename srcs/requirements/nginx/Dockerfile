# Use the penultimate stable version of Alpine Linux
FROM alpine:3.20.6

# Install required packages
RUN apk add --no-cache \
    nginx \
    openssl

# Copy the configuration file
COPY ./conf/default.conf /etc/nginx/http.d/

# Copy the setup script with execute permissions
COPY --chmod=755 ./tools/nginx-setup.sh /usr/local/bin/

# Expose port
EXPOSE 443

# Set the entrypoint script
ENTRYPOINT [ "nginx-setup.sh" ]

# CMD ["tail", "-f"]
