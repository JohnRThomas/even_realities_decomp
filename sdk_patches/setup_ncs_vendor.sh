#!/bin/bash
# Usage: setup_ncs_vendor.sh /path/to/ncs/v2.5.1 /path/to/dest
#
# zephyr: patches are committed on branch g1-vendor (the vendor zephyr was a private commit).
# nrf: the vendor tree was v2.5.1 "-dirty" (manifest: 87355af5914e...-dirty), so the patches
#      are applied as uncommitted changes: `git describe` must stay "v2.5.1" because the boot
#      banner embeds it ("*** Booting nRF Connect SDK v2.5.1 ***" in the shipped .rodata).
#      The same changes are also kept as commits on branch g1-vendor-commits.
set -e
SRC=$1; DST=$2; HERE=$(cd "$(dirname "$0")" && pwd)
cp -a --reflink=auto "$SRC" "$DST"
(cd "$DST/zephyr" && git checkout -q -b g1-vendor && \
 git -c user.name="G1 repro" -c user.email=repro@localhost am -q "$HERE/zephyr"/*.patch)
(cd "$DST/nrf" && git checkout -q -b g1-vendor-commits && \
 git -c user.name="G1 repro" -c user.email=repro@localhost am -q "$HERE/nrf"/*.patch && \
 git checkout -q -b g1-vendor && git reset -q --soft v2.5.1)
