#!/bin/sh

until mysql -h $DB_HOST -u $DB_USER -p$DB_PASS -e "USE ${DB_NAME}" 2>/dev/null; do
    echo "Waiting for MariaDB..."
    sleep 1
done

wp cli update --yes --allow-root
wp core download --allow-root --path=/var/www/html
wp config create --allow-root \
    --dbname=${DB_NAME} \
    --dbuser=${DB_USER} \
    --dbpass=${DB_PASS} \
    --dbhost=${DB_HOST} \
    --force

wp core install --allow-root \
    --title=${WP_TITEL} \
    --url=${SERVER_NAME} \
    --admin_user=${WP_ADMIN_USER} \
    --admin_password=${WP_ADMIN_PASS} \
    --admin_email=${WP_ADMIN_EMAIL}

wp user create ${WP_USER_NAME} ${WP_USER_EMAIL} \
    --user_pass=${WP_USER_PASS} \
    --role=${WP_USER_ROLE} \
    --allow-root

exec php-fpm83 -F
