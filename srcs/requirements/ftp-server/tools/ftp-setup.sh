#!/bin/sh

mkdir -p var/www/html

adduser -D -h /var/www/html -s /sbin/nologin ftpuser \

chown -R ftpuser:ftpuser /var/www/html

echo "ftpuser:P@ssw0rd42" | /usr/sbin/chpasswd \

exec "$@"
