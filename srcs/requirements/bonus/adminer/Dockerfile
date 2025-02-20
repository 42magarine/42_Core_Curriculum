# Use the penultimate stable version of Alpine Linux
FROM alpine:3.20

# Install required packages
RUN apk add --no-cache \
    curl


RUN curl -o index.php https://www.adminer.org/latest.php


# Set the entrypoint script
ENTRYPOINT ["/usr/local/bin/-setup.sh"]
