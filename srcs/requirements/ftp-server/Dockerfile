# penultimate stable version of Alpine
FROM alpine:3.20

RUN apk add --no-cache \
    vsftpd

# RUN mkdir -p var/www/html
# RUN adduser -D -h /var/www/html -s /sbin/nologin ftpuser \
#     && echo "ftpuser:P@ssw0rd42" | /usr/sbin/chpasswd \
#     && chown -R ftpuser:ftpuser /var/www/html

# COPY conf/vsftpd.conf /etc/vsftpd.conf
COPY ./conf/vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY ./tools/ftp-setup.sh /ftp-setup.sh

RUN chmod +x /ftp-setup.sh

# EXPOSE 21 22

ENTRYPOINT [ "/ftp-setup.sh" ]

# CMD ["tail", "-f"]
# CMD ["/usr/sbin/vsftpd", "/etc/vsftpd.conf"]
CMD ["/usr/sbin/vsftpd", "/etc/vsftpd/vsftpd.conf"]
# CMD ["/usr/sbin/vsftpd", "-foreground", "/etc/vsftpd/vsftpd.conf"]


