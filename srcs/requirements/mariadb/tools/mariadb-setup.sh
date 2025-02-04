#!/bin/sh

mkdir -p /run/mysqld && chown -R mysql:mysql /run/mysqld

if [ ! -d "/var/lib/mysql/mysql" ]; then
    mariadb-install-db --user=mysql --datadir=/var/lib/mysql

    mysqld --user=mysql --bootstrap << EOF
USE mysql;
DELETE FROM mysql.user WHERE User='';
DELETE FROM mysql.user WHERE User='root' AND Host NOT IN ('localhost', '127.0.0.1', '::1');
ALTER USER 'root'@'localhost' IDENTIFIED BY '${DB_ROOT_PASSWORD}';
CREATE DATABASE ${DB_NAME};
CREATE USER '${DB_USER}'@'%' IDENTIFIED BY '${DB_USER_PASSWORD}';
GRANT ALL PRIVILEGES ON ${DB_NAME}.* TO '${DB_USER}'@'%';
FLUSH PRIVILEGES;
EOF
fi

exec mysqld --user=mysql

# mysql -u root -p"${DB_ROOT_PASSWORD}"
# mysql -u "${DB_USER}" -p"${DB_USER_PASSWORD}"
# SHOW DATABASES;
# USE Inception;

# FLUSH PRIVILEGES;
# DROP DATABASE IF EXISTS test;
# DELETE FROM mysql.db WHERE Db='test' OR Db='test\\_%';
# SELECT Host, User, Password FROM
