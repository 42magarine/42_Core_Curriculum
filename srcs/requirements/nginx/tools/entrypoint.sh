#!/bin/sh

if [ ! -f /etc/ssl/nginx.crt ]; then
  openssl req -x509 -nodes -newkey rsa:2048 \
    -keyout /etc/ssl/nginx.key \
    -out /etc/ssl/nginx.crt \
    -subj "/C=DE/O=42 Heilbronn/OU=Inception/CN=${SERVER_NAME}"
fi

exec "$@"
