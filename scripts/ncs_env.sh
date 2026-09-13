#!/bin/bash
# Source this to get the NCS v2.5.1 toolchain (west, ninja, cmake, arm-zephyr-eabi-*)
# on PATH, mirroring ~/ncs/toolchains/<id>/environment.json.
#   . scripts/ncs_env.sh
# NCS_TOOLCHAIN overrides the toolchain directory; ZEPHYR_BASE defaults to the stock
# NCS v2.5.1 tree unless it is set already.
TC=${NCS_TOOLCHAIN:-$HOME/ncs/toolchains/7795df4459}
export PATH="$TC/bin:$TC/usr/bin:$TC/usr/local/bin:$TC/opt/bin:$TC/opt/nanopb/generator-bin:$TC/opt/zephyr-sdk/arm-zephyr-eabi/bin:$PATH"
export LD_LIBRARY_PATH="$TC/lib:$TC/lib/x86_64-linux-gnu:$TC/usr/local/lib${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}"
export GIT_EXEC_PATH="$TC/usr/local/libexec/git-core"
export GIT_TEMPLATE_DIR="$TC/usr/local/share/git-core/templates"
export PYTHONHOME="$TC/usr/local"
export PYTHONPATH="$TC/usr/local/lib/python3.8:$TC/usr/local/lib/python3.8/site-packages"
export ZEPHYR_TOOLCHAIN_VARIANT=zephyr
export ZEPHYR_SDK_INSTALL_DIR="$TC/opt/zephyr-sdk"
export ZEPHYR_BASE=${ZEPHYR_BASE:-$HOME/ncs/v2.5.1/zephyr}
