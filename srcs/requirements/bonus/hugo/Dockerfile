# Use the penultimate stable version of Alpine Linux
FROM alpine:3.20.6

WORKDIR /hugo

# Install required packages
RUN apk add --no-cache \
    git \
    hugo

COPY --chmod=755 ./tools/hugo-setup.sh /usr/local/bin/
# COPY ./tools /hugo/content
# COPY ./conf/config.toml /hugo/

# Expose ports
EXPOSE 1313

# CMD ["hugo", "server", "--bind", "0.0.0.0", "--port", "1313"]

ENTRYPOINT [ "hugo-setup.sh" ]

# CMD [ "tail", "-f" ]
