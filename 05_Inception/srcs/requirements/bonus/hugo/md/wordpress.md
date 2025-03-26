+++
title = "Wordpress"
date = 2025-01-01T00:00:00Z
draft = true
+++

### Wordpress Docker Container

> WordPress is a free and open-source content management system (CMS) that allows users to create and manage websites easily.

> WP-CLI (WordPress Command-Line Interface) is a tool that allows users to manage WordPress installations via the command line.

    https://wordpress.com/


#### Access:
    https://www.$DOMAIN_NAME/wp-login.php

* Username: `$WP_ADMIN_USER` or `$WP_USER_NAME`
* Password: `$WP_ADMIN_PASSWORD` or `$WP_USER_PASSWORD`


#### Configuration:
* PHP-FPM config: `/etc/php83/php-fpm.d/www.conf`


#### Useful Links:
* [WP-CLI commands](https://developer.wordpress.org/cli/commands/)
