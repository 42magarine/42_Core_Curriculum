#!/bin/sh

if [ ! -f /var/www/html/wp-config.php ]; then
    # This downloads the WordPress core files.
    wp core download --allow-root --path=/var/www/html

    # This will generate the WordPress configuration file (wp-config.php).
    wp config create --allow-root \
        --dbname="${DB_NAME}" \
        --dbuser="${DB_USER}" \
        --dbpass="${DB_USER_PASSWORD}" \
        --dbhost="${DB_HOST}" \
        # --force

    # This will then install WordPress.
    wp core install --allow-root \
        --url="${WP_URL}" \
        --title="${WP_TITLE}" \
        --admin_user="${WP_ADMIN_USER}" \
        --admin_password="${WP_ADMIN_PASSWORD}" \
        --admin_email="${WP_ADMIN_EMAIL}"

    # This create a new WordPress user.
    wp user create "${WP_USER_NAME}" "${WP_USER_EMAIL}" \
        --user_pass="${WP_USER_PASSWORD}" \
        --role="${WP_USER_ROLE}"
        # --allow-root

    wp theme activate twentytwentyfour --allow-root

    chown -R nobody:nobody /var/www/html
fi

# This is the command that will keep WordPress up and running.
# PHP FastCGI Process Manager (PHP-FPM)
exec php-fpm83 -F
