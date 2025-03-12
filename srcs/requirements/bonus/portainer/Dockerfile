# Use the penultimate stable version of Alpine Linux
FROM alpine:3.20.6

# Install required packages
RUN apk add --no-cache \
    curl \
    python3 \
    py3-bcrypt

# Copy the Portainer setup script and set execution permissions
COPY --chmod=755 ./tools/portainer-setup.sh /usr/local/bin/

# Expose Portainer web UI port
EXPOSE 9443

# Set the entrypoint to execute the Portainer setup script
ENTRYPOINT [ "portainer-setup.sh" ]
