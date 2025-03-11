+++
title = "MariaDB"
date = 2025-01-01T00:00:00Z
draft = true
+++


Homepage:
https://mariadb.org/


Standard configuration files:
/etc/my.cnf.d/mariadb-server.cnf


https://mariadb.com/kb/en/mariadb-install-db/

https://wiki.alpinelinux.org/wiki/MariaDB



 how to login into the database. Verify that the
database is not empty:

mysql -u <user> -p<password>
SHOW DATABASES;
USE <database>;
SHOW TABLES;
# SELECT Host, Use
desc <database>.<table>
select <> from <database>.<table>
