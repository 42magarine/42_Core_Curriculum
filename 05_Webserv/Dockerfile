FROM debian:latest

RUN apt-get update && apt-get upgrade -y && \
    apt-get install -y \
    build-essential \
    libreadline-dev \
    g++ \
    git \
    make \
    valgrind \
    strace \
    cmake \
    php \
    php-cgi \
    curl \
    siege \
    python3 && \
    apt-get clean && \
    rm -fr /var/lib/apt/lists/*

WORKDIR /workspace

# ENV LOOPBACK_ADDRESSES="127.0.0.1 127.0.0.2"

EXPOSE 8080 8081

CMD ["tail", "-f", "/dev/null"]
# CMD ["./webserv"]
