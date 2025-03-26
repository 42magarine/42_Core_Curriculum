#!/bin/sh

DB_PASSWORD=$(cat /run/secrets/db_password)

mariadb-admin ping -u "$DB_USER" -p"$DB_PASSWORD"
