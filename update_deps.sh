#!/bin/bash

DEPS_DIR="./third_party"
SOKOL_DIR="${DEPS_DIR}/sokol"

WGET_OPTS="-q --show-progress"

download_sokol_files() {
    local base_url="https://raw.githubusercontent.com/floooh/sokol/refs/heads/master"

    local core_files=("sokol_app.h" "sokol_gfx.h" "sokol_glue.h")
    for file in "${core_files[@]}"; do
        wget $WGET_OPTS "${base_url}/${file}" -O "${SOKOL_DIR}/${file}"
    done
}

echo "Downloading latest sokol files..."
mkdir -p "$SOKOL_DIR"
download_sokol_files
