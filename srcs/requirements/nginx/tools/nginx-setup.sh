#!/bin/sh

if [ ! -f /etc/ssl/private/nginx.key ] || [ ! -f /etc/ssl/certs/nginx.crt ]; then
    openssl req -newkey rsa:2048 -x509 -noenc \
        -keyout /etc/ssl/private/nginx.key \
        -out /etc/ssl/certs/nginx.crt \
        -subj "/C=DE/ST=Baden-Württemberg/L=Heilbronn/O=42 Heilbronn/OU=Inception/CN=${DOMAIN_NAME}"

    sed -i "s/\DOMAIN_NAME/${DOMAIN_NAME}/g" /etc/nginx/http.d/default.conf
fi

exec nginx -g 'daemon off;'
