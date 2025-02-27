#!/bin/sh

if [ ! -f /var/www/html/wp-config.php ]; then
    # This downloads the WordPress core files.
    wp core download --allow-root --path=/var/www/html --version=6.7.1

    # This will generate the WordPress configuration file (wp-config.php).
    wp config create --allow-root \
        --dbname="${DB_NAME}" \
        --dbuser="${DB_USER}" \
        --dbpass="${DB_USER_PASSWORD}" \
        --dbhost="${DB_HOST}"

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

    wp theme activate twentytwentyfour --allow-root

    # Install and configure Redis plugin
    wp config set WP_REDIS_HOST redis --allow-root
    wp config set WP_REDIS_PORT 6379 --allow-root
    wp config set WP_CACHE true --allow-root --raw
    wp config set WP_REDIS_CLIENT phpredis --allow-root

    wp plugin install redis-cache --allow-root --activate
    wp redis enable --allow-root

    # Set appropriate file ownership
    chown -R nobody:nobody /var/www/html
fi

# This is the command that will keep WordPress up and running.
# PHP FastCGI Process Manager (PHP-FPM)
exec php-fpm83 -F
