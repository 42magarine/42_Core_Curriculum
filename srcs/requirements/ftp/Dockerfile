FROM alpine:latest

RUN apk update
RUN apk upgrade
RUN apk add --no-cache vsftpd

COPY vsftpd.conf /etc/vsftpd.conf

CMD ["/usr/sbin/vsftpd", "/etc/vsftpd.conf"]
