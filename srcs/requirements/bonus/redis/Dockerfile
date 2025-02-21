# Use the penultimate stable version of Alpine Linux
FROM alpine:3.20

# Install required packages
RUN apk add --no-cache \
    redis

# Copy the configuration file
COPY ./conf/redis.conf /etc/

# Expose port
EXPOSE 6379

# CMD ["tail", "-f"]
CMD ["redis-server", "/etc/redis.conf"]
