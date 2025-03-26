# Use the penultimate stable version of Alpine Linux
FROM alpine:3.20.6

# Install Redis
RUN apk add --no-cache \
    redis

# Copy the Redis configuration file
COPY ./conf/redis.conf /etc/

# Expose the Redis default port
EXPOSE 6379

# Start Redis with the specified configuration file
CMD [ "redis-server", "/etc/redis.conf" ]
