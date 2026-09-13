#!/bin/bash
# Fetch the newlib libc_nano.a of the *Windows* Zephyr SDK 0.16.1 ARM toolchain.
#
# The shipped v1.66 image was linked on Windows: three newlib assert __FILE__
# strings contain HOST-x86_64-w64-mingw32/.  The Linux SDK's libc_nano.a has
# different paths, so build_repro.sh puts this copy first on the library
# search path.  build_repro.sh runs this script when the library is missing.
#
# Usage: fetch_win_newlib.sh [DEST_DIR]
#   DEST_DIR defaults to sdk_patches/toolchain_libs/zephyr-sdk-0.16.1-windows next to
#   this script
#   (the library lands in DEST_DIR/thumb/v8-m.main+fp/hard/libc_nano.a).
# Needs curl and 7z.
set -euo pipefail
HERE=$(cd "$(dirname "$0")" && pwd)
DEST=${1:-$HERE/sdk_patches/toolchain_libs/zephyr-sdk-0.16.1-windows}
URL=https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.16.1/toolchain_windows-x86_64_arm-zephyr-eabi.7z
MEMBER='arm-zephyr-eabi/arm-zephyr-eabi/lib/thumb/v8-m.main+fp/hard/libc_nano.a'
SHA256=3322dbfcd0df7172e9abe0f88fb363359ec683fef0fee605c70d28043b92b96f

TMP=$(mktemp -d)
trap 'rm -rf "$TMP"' EXIT
curl -fsSL --retry 3 -o "$TMP/toolchain.7z" "$URL"
7z x -y -o"$TMP/x" "$TMP/toolchain.7z" "$MEMBER" >/dev/null
echo "$SHA256  $TMP/x/$MEMBER" | sha256sum -c -
mkdir -p "$DEST/thumb/v8-m.main+fp/hard"
cp "$TMP/x/$MEMBER" "$DEST/thumb/v8-m.main+fp/hard/libc_nano.a"
echo "installed $DEST/thumb/v8-m.main+fp/hard/libc_nano.a"
