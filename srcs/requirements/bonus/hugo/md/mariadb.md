+++
title = "MariaDB"
date = 2025-01-01T00:00:00Z
draft = true
+++

### MariaDB Docker Container

> MariaDB is an open-source relational database management system that is a drop-in replacement for MySQL.
> It's known for its performance, scalability, and security features.

    https://mariadb.org/



#### Access / Common MariaDB Commands:
Inside the Docker container, you can access MariaDB with the following command:

```sh
mysql -u <user> -p<password>
SHOW DATABASES;
USE <database>;
SHOW TABLES;
DESCRIBE <database>.<table>;
SELECT * FROM <database>.<table>;
```



#### Configuration:
* MariaDB config: `/etc/my.cnf.d/mariadb-server.cnf`




#### Useful Links:
* [mariadb-install-db command](https://mariadb.com/kb/en/mariadb-install-db/)
* [MariaDB Commands on Alpine Wiki](https://wiki.alpinelinux.org/wiki/MariaDB)
