FROM alpine:3.20.6

WORKDIR /portainer

RUN apk add --no-cache \
    curl

RUN curl -fsSL https://github.com/portainer/portainer/releases/latest/download/portainer-ce-linux-amd64 -o /portainer/portainer \
    && chmod +x /portainer/portainer

EXPOSE 8000 9000

CMD ["tail", "-f"]
# CMD []
