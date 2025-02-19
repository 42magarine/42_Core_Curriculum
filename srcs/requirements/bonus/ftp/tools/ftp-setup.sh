#!/bin/sh

mkdir -p /var/run/vsftpd/empty
chmod 555 /var/run/vsftpd/empty

# adduser -D -h /var/www/html -s /sbin/nologin ftpuser \
adduser ftpuser --disabled-password

# echo "ftpuser:P@ssw0rd" | /usr/sbin/chpasswd \
echo "ftpuser:P@ssw0rd" | chpasswd

# mkdir -p var/www/html
mkdir -p /home/ftpuser/data/wordpress

# chown -R ftpuser:ftpuser /var/www/html
chown -R ftpuser:ftpuser /home/ftpuser/data/wordpress

exec "$@"
