#!/usr/bin/env bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
ROOT="$(dirname "$SCRIPT_DIR")"
cd $ROOT

echo "Updating gh-pages..."
if [ -d /tmp/lo21-doc ]; then
    rm -rf /tmp/lo21-doc
fi

mkdir /tmp/lo21-doc
cp -R doc/* /tmp/lo21-doc/

git checkout gh-pages
rm -rf *
cp -R /tmp/lo21-doc/* .
git add -A .
