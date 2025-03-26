#!/bin/sh

if [ ! -f "/portainer/portainer" ]; then
    curl -L -o portainer.tar.gz https://github.com/portainer/portainer/releases/download/2.27.1/portainer-2.27.1-linux-amd64.tar.gz
    tar -xzf portainer.tar.gz
    rm portainer.tar.gz

    RAW_PASSWORD=$(cat "/run/secrets/portainer_admin_password")
    HASHED_PASSWORD=$(python3 -c "import bcrypt; print(bcrypt.hashpw(b'$RAW_PASSWORD', bcrypt.gensalt()).decode())")

    exec /portainer/portainer --admin-password "$HASHED_PASSWORD"
else
    exec /portainer/portainer
fi
