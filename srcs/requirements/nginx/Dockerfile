# penultimate stable version of Alpine
FROM alpine:3.20

RUN apk add --no-cache \
	nginx \
	openssl

RUN openssl req -x509 -nodes -newkey rsa:2048 \
	-keyout /etc/ssl/nginx.key \
	-out /etc/ssl/nginx.crt \
	-subj "/C=DE/O=42 Heilbronn/OU=Inception/CN=${SERVER_NAME}"

COPY ./conf/default.conf /etc/nginx/http.d/default.conf

EXPOSE 443

CMD ["nginx", "-g", "daemon off;"]
