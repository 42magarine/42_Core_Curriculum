#!/bin/sh

if [ ! -f "/hugo/hugo.toml" ]; then
    hugo new site /hugo
    git clone https://github.com/maolonglong/hugo-simple.git /hugo/themes/hugo-simple

    mv /tmp/hugo.toml /hugo/hugo.toml
    sed -i "s|baseURL = 'https://127.0.0.1'|baseURL = 'https://$DOMAIN_NAME/hugo'|" /hugo/hugo.toml

    mkdir -p /hugo/content/blog
    mv /tmp/_index.md /hugo/content/_index.md
    mv /tmp/*.md /hugo/content/blog/
fi

exec hugo server --bind 0.0.0.0 --port 1313 --baseURL "https://$DOMAIN_NAME/hugo" --buildDrafts
