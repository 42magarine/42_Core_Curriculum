#!/bin/sh

if [ ! -f "/hugo/hugo.toml" ]; then
    hugo new site /hugo
    cd /hugo
    git init
    git clone https://github.com/MeiK2333/github-style.git themes/github-style
    echo "theme = 'github-style'" >> hugo.toml
    # sed -i 's/draft: true/draft: false/' /hugo/content/test.md
    # hugo -b https://127.0.0.1/hugo
fi

# hugo server --bind 0.0.0.0 --port 1313
# hugo server --bind 0.0.0.0 --port 1313 --appendPort=false --buildDrafts
hugo server --bind 0.0.0.0 --port 1313 --baseURL https://127.0.0.1/hugo/ --appendPort=false --buildDrafts
