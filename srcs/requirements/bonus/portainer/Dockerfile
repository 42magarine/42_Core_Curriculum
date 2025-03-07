FROM alpine:3.20.6

RUN apk add --no-cache \
    curl

WORKDIR /usr/local/bin

RUN curl -L -o portainer.tar.gz https://github.com/portainer/portainer/releases/download/2.27.1/portainer-2.27.1-linux-amd64.tar.gz && \
    tar -xzf portainer.tar.gz && \
    rm portainer.tar.gz

EXPOSE 9443

ENTRYPOINT [ "./portainer/portainer" ]

# CMD ["tail", "-f"]
