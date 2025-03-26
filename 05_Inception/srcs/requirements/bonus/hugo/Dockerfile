# Use the penultimate stable version of Alpine Linux
FROM alpine:3.20.6

# Install Git and Hugo
RUN apk add --no-cache \
    git \
    hugo

# Copy the Hugo configuration file and markdown files
COPY ./conf/hugo.toml /tmp/
COPY ./md/ /tmp/

# Copy the Hugo setup script and set execution permissions
COPY --chmod=755 ./tools/hugo-setup.sh /usr/local/bin/

# Set the working directory for Hugo
WORKDIR /hugo

# Expose the default Hugo server port
EXPOSE 1313

# Set the entrypoint to execute the Hugo setup script
ENTRYPOINT [ "hugo-setup.sh" ]
