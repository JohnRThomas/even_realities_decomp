#!/bin/bash
# Byte-identical rebuild of the shipped Even G1 v1.66 firmware: app_update.bin and
# net_core_app_update.bin of its dfu_application.zip.
#
# Usage: exact_build_1_66/build_repro.sh [BUILD_DIR]
#   BUILD_DIR  directory name inside the project (default build_repro).  It must be a
#              direct subdirectory: the image holds the application's __FILE__ strings,
#              which are relative to it ("../src/...").
#
# Environment:
#   NCS_DIR        stock NCS v2.5.1 workspace (default ~/ncs/v2.5.1)
#   G1_NCS_DIR     vendor-patched copy of it (default ~/ncs/v2.5.1-g1); copied from
#                  NCS_DIR if it does not exist
#   NCS_TOOLCHAIN  NCS v2.5.1 toolchain directory (scripts/ncs_env.sh)
#
# Steps:
#   1. apply sdk_patches/zephyr and sdk_patches/nrf to G1_NCS_DIR (skipped when already
#      applied).  They stay uncommitted: the boot banner embeds `git describe` of nrf,
#      which must remain "v2.5.1".
#   2. fetch the Windows newlib into sdk_patches/toolchain_libs/ (fetch_win_newlib.sh)
#   3. west build with the v1.66 values below.  The project's CMake files know nothing
#      about this build: everything is passed on the command line, including the
#      CMake file that is included after project() of both images (repro.cmake)
#   4. compare both update images with the shipped ones (SHA-256)
set -euo pipefail

# ---- the shipped v1.66 build ----
APP_BUILD_TIME="2025-10-22 14:20:59"
NET_BUILD_TIME="2025-10-22 14:21:16"
GIT_COMMIT=baf56701
# salts of its MCUboot RSA-PSS signatures (pss_salt.py recover)
APP_PSS_SALT=b3f6f1cb980eaa7b8253e25781a9481cdc52f7803fa8e0e29227370d0990e927
NET_PSS_SALT=83941557a9dceb369d257ef1d27cbb60891e759848d308e502a50f618dc89a7a
APP_SHA256=ae032838e27037156da98e19de90df78f5406715751f3b38adf50498db3010c1
NET_SHA256=c277749be97a2763742db399afeb10ca6916059abd60d41bbc05c8892c002c77

HERE=$(cd "$(dirname "$0")" && pwd)
FW=$(dirname "$HERE")
BUILD=${1:-build_repro}
NCS_DIR=${NCS_DIR:-$HOME/ncs/v2.5.1}
G1_NCS_DIR=${G1_NCS_DIR:-$HOME/ncs/v2.5.1-g1}
die() { echo "build_repro.sh: $*" >&2; exit 1; }
case $BUILD in */* | . | .. | '') die "BUILD_DIR must be a directory name inside $FW" ;; esac

. "$FW/scripts/ncs_env.sh"
export ZEPHYR_BASE=$G1_NCS_DIR/zephyr

# 1. vendor-patched NCS tree
if [ ! -e "$G1_NCS_DIR" ]; then
	[ -d "$NCS_DIR/zephyr" ] && [ -d "$NCS_DIR/nrf" ] || die "no NCS workspace at $NCS_DIR"
	echo "-- copying $NCS_DIR to $G1_NCS_DIR"
	cp -a --reflink=auto "$NCS_DIR" "$G1_NCS_DIR"
fi
for repo in zephyr nrf; do
	for p in "$HERE/sdk_patches/$repo"/*.patch; do
		git -C "$G1_NCS_DIR/$repo" apply --reverse --check "$p" 2>/dev/null && continue
		echo "-- applying $(basename "$p") to $G1_NCS_DIR/$repo"
		git -C "$G1_NCS_DIR/$repo" apply "$p" || die "$p does not apply to $G1_NCS_DIR/$repo"
	done
done

# 2. Windows newlib
WIN_NEWLIB=$HERE/sdk_patches/toolchain_libs/zephyr-sdk-0.16.1-windows/thumb/v8-m.main+fp/hard
[ -f "$WIN_NEWLIB/libc_nano.a" ] || "$HERE/fetch_win_newlib.sh"

# 3. build; start over if BUILD_DIR was configured against another NCS tree
cd "$FW"
pristine=auto
if [ -f "$BUILD/CMakeCache.txt" ] && ! grep -qxF "ZEPHYR_BASE:PATH=$ZEPHYR_BASE" "$BUILD/CMakeCache.txt"; then
	pristine=always
fi
# - repro.cmake is included at the end of project() of the application and of the
#   network core image (variables named net_core_* go to that image without the prefix)
# - newlib: the shipped image was linked on Windows, three newlib assert __FILE__ strings
#   contain HOST-x86_64-w64-mingw32/.  Zephyr appends the toolchain's own library
#   directory to LIB_INCLUDE_DIR, so the Windows libc_nano.a comes first on the link line.
# - b0n signature of the network core image: the vendor's ECDSA P-256 key is private;
#   b0_vendor/ holds its public key and the signature taken from the shipped image
#   (ai_helpers/extract_b0_validation.py).  NCS runs the custom signing command as
#   "COMMAND HASH_FILE > SIGNATURE_FILE": the signature is fed on stdin and "sh -c cat"
#   takes HASH_FILE as an unused $0 (a plain "cat SIGNATURE" would print the hash file
#   after the signature).  validation_data.py checks the signature against the hash of
#   the image, so the build fails unless the network core image is identical to v1.66.
west build -p $pristine -b nrf5340dk_nrf5340_cpuapp -d "$BUILD" -- \
	"-DCMAKE_PROJECT_ar_glasses_INCLUDE=$HERE/repro.cmake" \
	"-Dnet_core_CMAKE_PROJECT_net_core_INCLUDE=$HERE/repro.cmake" \
	"-DG1_EXACT_BUILD_TIME=$APP_BUILD_TIME" "-DG1_EXACT_GIT_COMMIT=$GIT_COMMIT" \
	"-Dnet_core_G1_EXACT_BUILD_TIME=$NET_BUILD_TIME" \
	"-DG1_APP_PSS_SALT=$APP_PSS_SALT" "-DG1_NET_PSS_SALT=$NET_PSS_SALT" \
	"-DLIB_INCLUDE_DIR=-L$WIN_NEWLIB" \
	-Dnet_core_CONFIG_SB_SIGNING_CUSTOM=y \
	"-Dnet_core_CONFIG_SB_SIGNING_COMMAND=\"sh -c cat <$HERE/b0_vendor/app_firmware.signature\"" \
	"-Dnet_core_CONFIG_SB_SIGNING_PUBLIC_KEY=\"$HERE/b0_vendor/public.pem\"" ||
	die "build failed (a 'signature verification' error from validation_data.py means the network core image differs from v1.66)"

# 4. compare with v1.66
status=0
for f in app_update.bin:$APP_SHA256 net_core_app_update.bin:$NET_SHA256; do
	bin=$BUILD/zephyr/${f%%:*}
	if [ "$(sha256sum <"$bin" | cut -d' ' -f1)" = "${f#*:}" ]; then
		echo "${f%%:*}: identical to v1.66"
	else
		echo "${f%%:*}: DIFFERS from v1.66"
		status=1
	fi
done
echo "DFU package: $FW/$BUILD/zephyr/dfu_application.zip"
exit $status
