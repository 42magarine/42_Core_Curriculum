+++
title = "Redis"
date = 2025-01-01T00:00:00Z
draft = true
+++


Homepage:
https://redis.io/


Standard configuration files:
/etc/redis.conf

Der Name Redis entstand als Abkürzung für englisch remote dictionary server

sh % redis-cli -h localhost -p 6379

docker exec -it redis redis-cli
MONITOR -
INFO
KEYS *
