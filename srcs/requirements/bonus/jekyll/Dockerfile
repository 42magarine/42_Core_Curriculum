# Use the penultimate stable version of Alpine Linux
FROM alpine:3.20.6

# Install required packages
RUN apk add --no-cache \
    ruby \
    ruby-bundler \
    ruby-dev \
    build-base \
    git

RUN gem install jekyll bundler

# Copy the setup script with execute permissions
COPY --chmod=755 ./tools/setup-jekyll.sh /usr/local/bin/

# Set the working directory to the default WordPress root
WORKDIR /jekyll

# Expose ports
EXPOSE 4000

# Set the entrypoint script
# ENTRYPOINT ["/setup-jekyll.sh"]

CMD [ "tail", "-f" ]
