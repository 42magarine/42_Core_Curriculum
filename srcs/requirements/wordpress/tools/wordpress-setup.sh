#!/bin/sh

# until mysql -h $DB_HOST -u $DB_USER -p$DB_PASS -e "USE ${DB_NAME}" 2>/dev/null; do
#     echo "Waiting for MariaDB..."
#     sleep 1
# done

# chown -R nobody:nobody /var/www/html

until mysql -h ${DB_HOST} -u ${DB_USER} -p${DB_PASSWORD} -e "SHOW DATABASES;" 2>/dev/null; do
    echo "Waiting for MariaDB..."
    sleep 3
done

wp cli update --yes --allow-root

if [ ! -f /var/www/html/wp-config.php ]; then
    # This downloads the WordPress core files.
    wp core download --allow-root --path=/var/www/html
	# wp core download --allow-root
fi

# This will generate the WordPress configuration file.
wp config create --allow-root \
    --dbname="${DB_NAME}" \
    --dbuser="${DB_USER}" \
    --dbpass="${DB_PASSWORD}" \
    --dbhost="${DB_HOST}" \
    # --force

# This will then install WordPress.
wp core install --allow-root \
    --url="${WP_URL}" \
    --title="${WP_TITEL}" \
    --admin_user="${WP_ADMIN_USER}" \
    --admin_password="${WP_ADMIN_PASSWORD}" \
    --admin_email="${WP_ADMIN_EMAIL}"

# This create a new WordPress user.
wp user create "${WP_USER_NAME}" "${WP_USER_EMAIL}" \
    --user_pass="${WP_USER_PASSWORD}" \
    --role="${WP_USER_ROLE}"
    # --allow-root

wp theme install bravada --path=/var/www/html --activate --allow-root
wp theme status bravada --allow-root

# This is the command that will keep WordPress up and running.
# PHP FastCGI Process Manager (PHP-FPM)
exec php-fpm83 -F
