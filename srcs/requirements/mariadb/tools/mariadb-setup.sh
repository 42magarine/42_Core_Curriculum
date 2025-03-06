#!/bin/sh

mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld

if [ ! -d "/var/lib/mysql/mysql" ]; then
    DB_PASSWORD=$(cat /run/secrets/db_password | tr -d '\n')
    DB_ROOT_PASSWORD=$(cat /run/secrets/db_root_password | tr -d '\n')

    mariadb-install-db --user=mysql --datadir=/var/lib/mysql --skip-test-db

    mariadbd --user=mysql --bootstrap << EOF
USE mysql;
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';
CREATE DATABASE ${DB_NAME};
CREATE USER '${DB_USER}'@'%' IDENTIFIED BY '${DB_PASSWORD}';
GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';
FLUSH PRIVILEGES;
EOF
fi

exec mariadbd --user=mysql
