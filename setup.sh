#!/bin/bash

SECRETS_DIR="$HOME/inception/secrets"
ENV_FILE="$HOME/inception/srcs/.env"

PASSWORD=""

for file in db_password.txt db_root_password.txt ftp_password.txt portainer_admin_password.txt wp_admin_password.txt wp_user_password.txt; do
    echo "$PASSWORD" > "$SECRETS_DIR/$file"
done

cat << EOF > "$ENV_FILE"
DOMAIN_NAME=login.42.fr

DB_NAME=
DB_USER=

WP_TITLE=
WP_ADMIN_USER=
WP_ADMIN_EMAIL=
WP_USER_NAME=
WP_USER_EMAIL=
WP_USER_ROLE=

FTP_USER=
EOF

echo "done."
