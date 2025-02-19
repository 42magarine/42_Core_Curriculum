FROM alpine:3.20

RUN apk add --no-cache \
    curl



RUN curl -o index.php https://www.adminer.org/latest.php

CMD ["tail", "-f"]
