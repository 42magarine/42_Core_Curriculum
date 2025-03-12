+++
title = "Adminer"
date = 2025-01-01T00:00:00Z
draft = true
+++

### Adminer Docker Container

> **Adminer** is a database management tool for **MySQL/MariaDB**, providing a simple web interface in a single PHP file.

    https://www.adminer.org/


#### Access:
    https://www.$DOMAIN_NAME/adminer

* System: MySQL
* Server: mariadb
* Username: `root` or `$DB_USER`
* Password: `$DB_ROOT_PASSWORD` or `$DB_PASSWORD`
* Database: `$DB_NAME`


#### Configuration:
* PHP-FPM config: `/etc/php83/php-fpm.d/www.conf`
