#!/usr/bin/env bash

SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
ROOT="$(dirname "$SCRIPT_DIR")"
cd $ROOT

echo "Removing old build..."
rm -rf build
mkdir build

echo "Building..."
cd build
cmake ..
make LO21

echo "Running..."
./LO21
