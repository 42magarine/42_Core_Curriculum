#!/bin/sh

if [ ! -d /var/run/vsftpd/empty ]; then
    FTP_PASSWORD=$(cat /run/secrets/ftp_password | tr -d '\n')

    mkdir -p /var/run/vsftpd/empty
    chmod 555 /var/run/vsftpd/empty

    adduser --disabled-password -G nobody $FTP_USER
    echo "$FTP_USER:$FTP_PASSWORD" | chpasswd

    sed -i "s|local_root=.*|local_root=/home/$FTP_USER|" /etc/vsftpd/vsftpd.conf
fi

exec vsftpd /etc/vsftpd/vsftpd.conf
