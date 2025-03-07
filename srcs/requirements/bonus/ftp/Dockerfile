# Use the penultimate stable version of Alpine Linux
FROM alpine:3.20.6

# Install required packages
RUN apk add --no-cache \
    vsftpd

# Copy the configuration file
COPY ./conf/vsftpd.conf /etc/vsftpd/

# Copy the setup script with execute permissions
COPY --chmod=755 ./tools/ftp-setup.sh /usr/local/bin/

# Expose ports
EXPOSE 20 21 42000-42042

# Set the entrypoint script
ENTRYPOINT [ "ftp-setup.sh" ]

# CMD ["tail", "-f"]
