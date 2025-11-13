#!/bin/bash

DEPS_DIR="./third_party"
SOKOL_DIR="${DEPS_DIR}/sokol"
NUKLEAR_DIR="${DEPS_DIR}/nuklear"

WGET_OPTS="-q --show-progress"

download_sokol_files() {
    local base_url="https://raw.githubusercontent.com/floooh/sokol/refs/heads/master"

    local core_files=("sokol_app.h" "sokol_gfx.h" "sokol_glue.h")
    for file in "${core_files[@]}"; do
        wget $WGET_OPTS "${base_url}/${file}" -O "${SOKOL_DIR}/${file}"
    done

    local util_url="${base_url}/util"
    local nuklear_file="sokol_nuklear.h"
    wget $WGET_OPTS "${util_url}/${nuklear_file}" -O "${SOKOL_DIR}/${nuklear_file}"
}

download_nuklear_files() {
    local base_url="https://raw.githubusercontent.com/Immediate-Mode-UI/Nuklear/refs/heads/master"

    local core_file="nuklear.h"
    wget $WGET_OPTS "${base_url}/${core_file}" -O "${NUKLEAR_DIR}/${core_file}"
}

echo "Downloading latest sokol files..."
mkdir -p "$SOKOL_DIR"
download_sokol_files

echo "Downloading latest nuklear files..."
mkdir -p "$NUKLEAR_DIR"
download_nuklear_files
