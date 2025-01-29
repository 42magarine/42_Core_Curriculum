FROM alpine:3.20

RUN apk add --no-cache \
	nginx \
	openssl

COPY ./conf/default.conf /etc/nginx/http.d/default.conf
COPY ./tools/entrypoint.sh /entrypoint.sh

RUN chmod +x /entrypoint.sh

EXPOSE 443

ENTRYPOINT ["/entrypoint.sh"]

CMD ["nginx", "-g", "daemon off;"]
