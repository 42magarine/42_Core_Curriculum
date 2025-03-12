+++
title = "Nginx"
date = 2025-01-01T00:00:00Z
draft = true
+++

### Nginx Docker Container

> Nginx ("engine x") is an HTTP web server, reverse proxy, content cache, load balancer, TCP/UDP proxy server, and mail proxy server.

    https://nginx.org/



#### Access:
    https://www.$DOMAIN_NAME



#### HTTPS:
* TLS (Transport Layer Security)
  is a cryptographic protocol designed to provide communications security over a computer network, such as the Internet.
* The `openssl` command can be used to generate a self-signed certificate for HTTPS:
```sh
  * openssl req         # generate a certificate request
  * newkey rsa:2048     # generates a new private key using RSA with a key size of 2048 bits
  * x509                # generate a self-signed certificate
  * noenc               # prevents the private key from being encrypted
  * subj val            # sets the subject of the certificate
```



#### Configuration:
* Nginx config: `/etc/nginx/http.d/default.conf`



#### Useful Links:
* [Nginx configuration file](http://nginx.org/en/docs/beginners_guide.html)
* [Transport Layer Security](https://en.wikipedia.org/wiki/Transport_Layer_Security)
