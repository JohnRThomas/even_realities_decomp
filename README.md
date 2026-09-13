# Open G1

This project is based on the Sample code [Simultaneous DFU for App and Net Core of nRF5340](https://github.com/hellesvik-nordic/samples_for_nrf_connect_sdk/tree/main/bootloader_samples/nrf5340/mcuboot_smp_ble_simultaneous) and is replacement for the official Even Realities Firmware on the G1 smart glasses.

## Prerequisites

Before you start, ensure you have:

- **nRF5340 DK** (Development Kit)
- **nRF Connect SDK v2.5.1** or later installed and configured
- **Toolchain** for nRF Connect SDK v2.5.1 (required compiler and build tools)
- **west tool** available in your PATH
- **nrfjprog** command-line tool installed

## Building the Application

The build process compiles the application for the nRF5340 DK with both cores enabled.

### Command Line

#### Step 1: Build the Project

```bash
west build -b nrf5340dk_nrf5340_cpuapp
```

**What this does:**
- Compiles the firmware for both the application core and network core
- Generates the necessary build artifacts including the DFU package
- Places outputs in the `build/` directory

#### Step 2: Verify Build Output

After a successful build, you should find:
- `build/zephyr/app_signed.hex` - Signed application firmware
- `build/zephyr/dfu_application.zip` - DFU package (used for OTA updates)

#### VSCode
TODO: Use the GUI

## Flashing
See [Over The Air Update](ota/README.md)
