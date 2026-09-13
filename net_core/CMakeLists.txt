# SPDX-License-Identifier: Apache-2.0
#
# Even Realities G1 network core firmware (reconstruction of v1.66).  Built as the
# network core child image of the application (../cmake/modules/mcuboot/CMakeLists.txt);
# NCS signs it for b0n and MCUboot into net_core_app_update.bin.

cmake_minimum_required(VERSION 3.20.0)

find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(net_core)

# Link order = target address order of the vendor code.
target_sources(app PRIVATE
  src/main.c
  src/ipc.c
  src/hci_rpmsg.c
  src/app_esb.c
  src/timeslot.c
)

# Build time reported to the application core: configure time.
string(TIMESTAMP G1_BUILD_TIME "%Y-%m-%d %H:%M:%S")
set_property(SOURCE src/main.c TARGET_DIRECTORY app APPEND PROPERTY
             COMPILE_DEFINITIONS G1_BUILD_TIME="${G1_BUILD_TIME}")
