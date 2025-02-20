# Use the penultimate stable version of Alpine Linux
FROM alpine:3.20

# Install required packages
RUN apk add --no-cache \
    nginx \
    openssl

RUN openssl req -newkey rsa -x509 -nodes \
    -keyout /etc/ssl/nginx.key \
    -out /etc/ssl/nginx.crt \
    -subj "/C=DE/O=42 Heilbronn/OU=Inception/CN=${SERVER_NAME}"

# Copy the configuration file
COPY ./conf/default.conf /etc/nginx/http.d/

# Expose port
EXPOSE 443

# ???
CMD ["nginx", "-g", "daemon off;"]
