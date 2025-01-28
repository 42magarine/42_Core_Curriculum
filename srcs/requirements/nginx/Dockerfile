FROM alpine:3.20

RUN apk add --no-cache \
	nginx \
	openssl

COPY ./conf/default.conf /etc/nginx/http.d/default.conf

EXPOSE 80 443

CMD ["nginx", "-g", "daemon off;"]
