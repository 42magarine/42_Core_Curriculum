# Use the penultimate stable version of Alpine Linux
FROM alpine:3.20.6

# Install VSFTPD
RUN apk add --no-cache \
    vsftpd

# Copy the VSFTPD configuration file
COPY ./conf/vsftpd.conf /etc/vsftpd/

# Copy the FTP setup script and set execution permissions
COPY --chmod=755 ./tools/ftp-setup.sh /usr/local/bin/

# Expose FTP control and passive mode ports
EXPOSE 20 21 42000-42042

# Set the entrypoint to execute the FTP setup script
ENTRYPOINT [ "ftp-setup.sh" ]
