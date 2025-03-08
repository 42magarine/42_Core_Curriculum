FROM alpine:3.20.6

RUN apk add --no-cache \
    curl \
    python3 \
    py3-bcrypt

# Copy the setup script with execute permissions
COPY --chmod=755 ./tools/portainer-setup.sh /usr/local/bin/

EXPOSE 9443

ENTRYPOINT [ "portainer-setup.sh" ]

# CMD ["tail", "-f"]
