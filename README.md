# Even Realities G1 firmware (v1.66 reconstruction)

Source of the Even G1 v1.66 firmware for the nRF5340: the application core image
(`src/`) and the network core image (`net_core/`).  It builds with nRF Connect SDK
v2.5.1 for the board `nrf5340dk_nrf5340_cpuapp`, like the shipped firmware.

The build produces MCUboot, both application images and b0n, and packages the two
update images in `build/zephyr/dfu_application.zip` (`app_update.bin`,
`net_core_app_update.bin`); `merged_domains.hex` is the full flash image for both cores.

## Table of Contents

- [Progress](#progress)
- [Requirements](#requirements)
- [Build](#build)
- [Build files](#build-files)
- [Deploying to Device](#deploying-to-device)
- [Performing DFU Over BLE](#performing-dfu-over-ble)
- [Troubleshooting](#troubleshooting)

## Progress

Both cores are complete: built against the vendor's SDK changes, `app_update.bin` and
`net_core_app_update.bin` are byte-identical to the shipped v1.66 images.

### App Core
|         Date | Function Progress | App Progress | Total Functions | Labeled Functions | Excluded Zephyr Functions | App Functions | Labeled App Functions |
| ------------ | ----------------- | ------------ | --------------- | ----------------- | ------------------------- | ------------- | --------------------- |
| *2026-11-05* |           100.00% |      100.00% |            3036 |              3036 |                      2140 |           896 |                   896 |
| *2026-11-04* |           100.00% |      100.00% |            3030 |              3030 |                      2138 |           892 |                   892 |
| *2026-10-22* |            99.93% |       99.78% |            3030 |              3028 |                      2138 |           892 |                   890 |
| *2026-06-30* |            87.01% |       59.82% |            2948 |              2565 |                      2057 |           871 |                   521 |
| *2026-06-28* |            86.93% |       59.49% |            2946 |              2561 |                      2057 |           869 |                   517 |
| *2026-06-27* |            86.03% |       58.08% |            2949 |              2537 |                      2057 |           873 |                   507 |
| *2026-06-07* |            87.10% |       57.24% |            2946 |              2566 |                      2062 |           884 |                   506 |
| *2026-05-31* |            86.86% |       56.71% |            2945 |              2558 |                      2058 |           887 |                   503 |
| *2026-05-26* |            86.40% |       56.03% |            2942 |              2542 |                      2046 |           896 |                   502 |
| *2026-05-25* |            85.34% |       54.11% |            2939 |              2508 |                      2015 |           924 |                   500 |
| *2026-05-24* |            84.41% |       52.49% |            2938 |              2480 |                      1995 |           943 |                   495 |
| *2026-05-20* |               84% |          52% |            2885 |              2426 |                      1915 |           970 |                   511 |
| *2026-05-19* |               84% |          52% |            2885 |              2426 |                      1912 |           973 |                   514 |
| *2026-05-13* |               84% |          52% |            2848 |              2395 |                      1889 |           959 |                   506 |
| *2026-05-12* |               83% |          53% |            2847 |              2391 |                      1869 |           978 |                   522 |
| *2026-05-04* |               83% |          52% |            2836 |              2366 |                      1845 |           991 |                   521 |
| *2026-05-03* |               83% |          52% |            2817 |              2352 |                      1843 |           974 |                   509 |
| *2026-05-02* |               83% |              |            2816 |              2351 |                      1889 |               |                       |
| *2026-04-19* |               82% |              |            2805 |              2305 |                      1063 |               |                       |
| *2026-04-05* |               81% |              |            2805 |              2290 |                      1033 |               |                       |

### Net Core
The network core image is Nordic's `hci_rpmsg` Bluetooth controller with the vendor's
ESB code added (`net_core/src`).  Its source is the same for v1.63 and v1.66; only the
compiled-in build time differs.
|         Date | Function Progress | App Progress | Total Functions | Labeled Functions | Excluded Zephyr Functions | App Functions | Labeled App Functions |
| ------------ | ----------------- | ------------ | --------------- | ----------------- | ------------------------- | ------------- | --------------------- |
| *2026-11-05* |           100.00% |      100.00% |            2006 |              2006 |                      1952 |            54 |                    54 |
| *2026-10-22* |           100.00% |      100.00% |            2006 |              2006 |                      1952 |            54 |                    54 |
| *2026-05-03* |                0% |           0% |            1625 |                 0 |                         0 |             0 |                     0 |

## Requirements

* An NCS v2.5.1 workspace, by default `~/ncs/v2.5.1`.
* Its toolchain.  `. scripts/ncs_env.sh` puts it on `PATH` (default
  `~/ncs/toolchains/7795df4459`, override with `NCS_TOOLCHAIN`) and sets
  `ZEPHYR_BASE` to `~/ncs/v2.5.1/zephyr` unless it is set already.  A shell from
  nRF Connect for VS Code or `nrfutil toolchain-manager` works as well.
* For flashing: an nRF5340 DK and the `nrfjprog` command-line tool.

> **Important:** The project has been built with nRF Connect SDK v2.5.1 only. Older or newer versions may cause compatibility issues.

## Build

```sh
. scripts/ncs_env.sh
west build -b nrf5340dk_nrf5340_cpuapp
```

Output in `build/`.  The build time and the git commit of this tree are compiled in,
MCUboot signs with its default key and b0n with a key generated in the build
directory.

This is the source as it is, built against the stock SDK.  The vendor built v1.66
against a modified zephyr and nrf tree; without those changes the firmware behaves
differently:

* Network core: ESB raises its event interrupt on SWI0, which MPSL also uses on the
  nRF5340 (the vendor moved ESB to SWI3, as Nordic's ESB/MPSL timeslot sample asks).
  Once ESB is initialised, it takes over MPSL's low-priority interrupt.
* Bluetooth connections start at security level L1 instead of L2, and
  `bt_conn_set_security()` returns early when the level is already reached.
* iOS (ANCS) notification attributes are cut at 32 bytes instead of 256.
* The DMIC default gain is the nrfx default instead of 0x40; the LSM6DSO driver logs
  through the log subsystem.
* The Bluetooth host has no `bt_hci_cmd_send_sync_timeout()` (the vendor's
  `bt_hci_cmd_send_sync()` with a timeout that returns an error instead of
  asserting); `src/ble/bt_hci_stock.c` stands in with the stock call, so an HCI
  command timeout at start-up asserts instead of resetting through the watchdog.
* The LSM6DSO initialises at boot, before `power_for_imu_and_mic()`.
  `src/imu/lsm6dso_stock.c` runs the driver's init function again when `main.c`
  calls `lsm6dso_init()` (the vendor's tree exports the driver's own function).

## Build files

* `CMakeLists.txt`, `prj.conf`, `Kconfig`, `boards/`, `pm_static.yml`, `linker/`:
  application image.
* `child_image/mcuboot.conf`: MCUboot.
* `net_core/`: network core image.
* `cmake/modules/`: adds `net_core/` as the network core child image.  NCS v2.5
  packages a network core image for DFU only if the child image is added before its
  MCUboot glue runs, so this glue wraps it (`cmake/modules/mcuboot/CMakeLists.txt`).
  `Kconfig` and `prj.conf` keep NCS from adding its own network core sample.
* `scripts/ncs_env.sh`: toolchain environment.

---

## Deploying to Device

This step programs the initial firmware onto the nRF5340 DK and enables the bootloader.

### Flash Initial Firmware

```bash
west flash --recover
```

**What this does:**
- Erases the entire flash memory on the device (`--recover` flag)
- Programs the MCUboot bootloader
- Programs the compiled application firmware for both cores
- Prepares the device for DFU updates

> **Note:** This step is only needed once during initial setup. For subsequent firmware updates, use DFU over BLE.

---

## Performing DFU Over BLE

This process updates the firmware on both cores wirelessly using Bluetooth Low Energy.

### Step 1: Install nRF Connect for Mobile

Download and install the [nRF Connect for Mobile app](https://www.nordicsemi.com/Products/Development-tools/nrf-connect-for-mobile) on your smartphone (iOS or Android).

### Step 2: Prepare the DFU Package

The DFU package was created during the build process at:

```
build/zephyr/dfu_application.zip
```

Transfer this file to your mobile phone using:
- USB cable
- Cloud storage (Google Drive, Dropbox, OneDrive)
- Email or messaging apps

For more details about the DFU package format, see the [nRF Connect SDK documentation](https://developer.nordicsemi.com/nRF_Connect_SDK/doc/2.1.0/nrf/app_build_system.html#output-build-files).

### Step 3: Connect to the Device

1. Open the **nRF Connect for Mobile** app
2. Tap **SCAN** to discover nearby Bluetooth devices
3. Find your nRF5340 DK in the list (usually named something like "nrf5340dk" or similar)
4. Tap **CONNECT** to establish a connection

![App Connect](https://github.com/hellesvik-nordic/samples_for_nrf_connect_sdk/raw/main/.images/nrf_connect_app_connect.png)

### Step 4: Initiate DFU

1. With the device connected, look for the **DFU** button in the app
2. Tap the **DFU** button to start the firmware update process

![App DFU](https://github.com/hellesvik-nordic/samples_for_nrf_connect_sdk/raw/main/.images/nrf_connect_app_dfu.png)

### Step 5: Select and Upload Firmware

1. When prompted, select the `dfu_application.zip` file from your phone
2. Choose **"Confirm Only"** upload mode
3. Tap **Start** to begin the update

**What happens:**
- The app transfers the firmware package to the device over BLE
- The bootloader verifies the firmware integrity
- Both the application core and network core are updated simultaneously

### Step 6: Reset the Device

After the upload completes successfully, reset the device to apply the update:

```bash
nrfjprog --reset
```

Or simply press the **RESET** button on the nRF5340 DK.

**What this does:**
- Restarts the device
- The bootloader processes the new firmware
- Both cores boot with the updated firmware

---

## Summary

| Step | Command/Action | Purpose |
|------|----------------|---------|
| 1 | `west build ...` | Compile firmware for both cores |
| 2 | `west flash --recover` | Program initial firmware to device |
| 3 | Transfer `dfu_application.zip` | Prepare update package for mobile |
| 4 | Connect via nRF Connect app | Establish BLE connection to device |
| 5 | Select file and upload | Transfer new firmware over BLE |
| 6 | `nrfjprog --reset` | Restart device and apply update |

---

## Troubleshooting

- **Build fails:** Ensure your nRF Connect SDK is up-to-date with `west update`
- **Flash fails:** Try unplugging and replugging the nRF5340 DK
- **DFU fails:** Verify the `dfu_application.zip` file is not corrupted
- **Connection drops:** Move closer to the device or reduce interference
