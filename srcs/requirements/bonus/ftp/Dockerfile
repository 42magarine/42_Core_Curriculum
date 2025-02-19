# penultimate stable version of Alpine
FROM alpine:3.20

RUN apk add --no-cache \
    vsftpd

COPY ./conf/vsftpd.conf /etc/vsftpd/vsftpd.conf
COPY ./tools/ftp-setup.sh /ftp-setup.sh

RUN chmod +x /ftp-setup.sh

EXPOSE 20 21

ENTRYPOINT [ "/ftp-setup.sh" ]

# CMD ["tail", "-f"]
CMD ["/usr/sbin/vsftpd", "/etc/vsftpd/vsftpd.conf"]
