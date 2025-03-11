# Use the penultimate stable version of Alpine Linux
FROM alpine:3.20.6

# Install required packages
RUN apk add --no-cache \
    git \
    hugo

# copy hugo config file and markdown files
COPY ./conf/ /tmp/

COPY --chmod=755 ./tools/hugo-setup.sh /usr/local/bin/

WORKDIR /hugo

# Expose ports
EXPOSE 1313

ENTRYPOINT [ "hugo-setup.sh" ]

# CMD [ "tail", "-f" ]
