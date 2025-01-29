#!bin/sh

set -e

mkdir -p /run/mysqld /var/lib/mysql
chown -R mysql:mysql /run/mysqld /var/lib/mysql

# if [ ! -d "/var/lib/mysql/${DB_NAME}" ]; then
# 	mysql_install_db --user=mysql --datadir=/var/lib/mysql

# 	mysqld --user=mysql --bootstrap <<EOF
# 	CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
# 	CREATE USER IF NOT EXISTS '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
# 	GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
# 	ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
# 	FLUSH PRIVILEGES;
# EOF
# fi


# Prüfe, ob die MariaDB-Systemdatenbank existiert
if [ ! -d "/var/lib/mysql/mysql" ]; then
    echo "Initialisiere MariaDB-Systemtabellen..."
    mysql_install_db --user=mysql --datadir=/var/lib/mysql
fi

# Falls die Datenbank noch nicht existiert, erstelle sie
if [ ! -d "/var/lib/mysql/${MYSQL_DATABASE}" ]; then
    echo "Erstelle Datenbank ${MYSQL_DATABASE}..."
    mysqld --user=mysql --bootstrap <<EOF
    CREATE DATABASE IF NOT EXISTS ${MYSQL_DATABASE};
    CREATE USER '${MYSQL_USER}'@'%' IDENTIFIED BY '${MYSQL_PASSWORD}';
    GRANT ALL PRIVILEGES ON ${MYSQL_DATABASE}.* TO '${MYSQL_USER}'@'%';
    ALTER USER 'root'@'localhost' IDENTIFIED BY '${MYSQL_ROOT_PASSWORD}';
    FLUSH PRIVILEGES;
EOF
fi


exec "$@"
