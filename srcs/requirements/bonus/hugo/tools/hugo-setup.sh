#!/bin/sh

if [ ! -f "/hugo/hugo.toml" ]; then
    hugo new site /hugo
    cd /hugo
    git clone https://github.com/vaga/hugo-theme-m10c themes/m10c
    hugo new content/test.md
    sed -i 's/draft: true/draft: false/' /hugo/content/test.md
    hugo -b https://127.0.0.1/hugo
    # git init
    # git submodule add https://github.com/MeiK2333/github-style.git themes/github-style
    # echo "theme = 'github-style'" >> hugo.toml
fi

# hugo server --bind 0.0.0.0 --port 1313
hugo server --bind 0.0.0.0 --port 1313 --baseURL https://127.0.0.1/hugo/ --appendPort=false --buildDrafts
