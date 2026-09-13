# Over The Air Updates
There are two options to run the custom firmware:
1. Build or Download a firmware image, then permanently flash a firmware to the glasses.
2. Flash a patched version of the official firmware that allows for uploading and temporarily running a custom firmware image.

### Permanent Flashing
> ⛔ **FLASHING CUSTOM FIRMWARE IS INHERIENTLY DANGEROUS, IT WILL VOID YOUR WARRENTY AN MAY BRICK YOUR DEVICE PERMANENTLY. PROCEED WITH CAUTION!**

## Performing DFU Over BLE
This process updates the firmware on both cores wirelessly using Bluetooth Low Energy.

If you have a `dfu_application.zip` file: follow the steps from the [Official Nordic Documentation](https://nrfconnectdocs.nordicsemi.com/ncs/latest/nrf/app_dev/device_guides/nrf53/fota_update_nrf5340.html#testing-steps) using the [nRF Connect for Mobile](https://www.nordicsemi.com/Products/Development-tools/nrf-connect-for-mobile) app.

## Direct Flashing Over BLE from PC/Mac
TODO: Fill this in with the companion app steps.

### Ephemeral Flashing
Using a patched version of the Official firmware, new BLE commands can be added to the official FW that allow for a temporary image to be loaded and run from system RAM. On reboot, this image will be lost and the firmware in ROM will be loaded. This mode is useful for testing unsafe FW images, there is still risk of corrupting ROM while running these images, so this is meant for development only.

If this is the first time flashing the Glasses with ephemeral firmware, you will need to flash a patched version of the official firmware to the glasses. Follow the steps in [Flashing Ephemeral Handler Image](#flashing-ephemeral-handler-image)

#### Flashing New Ephemeral Image 
TODO: Fill in how to use the companion app to upload a temporary image to the glasses.

#### Flashing Ephemeral Handler Image
The patching scripts are based around the v1.4.5 firmware image. The script will verify that the hash of the input file matches the known hash of the v1.4.5 image. Patching other images is possible, but not supported without modifying the script. Make sure you know exactly what you are doing before attempting to use other versions.

##### Fetch an Official Image
- Download Directly from Even Realities: [v1.4.5](https://cdn.evenreal.co/firmware/61e29fec9417f65fe7b2fe103825db8f.zip)
- Extract `app_update.bin` from the zip file to `./fw_patching/base_app_update.bin`.
- Extract `manifest.json` from the zip file to `./fw_patching/base_manifest.json`
- Extract `net_core_app_update.bin` from the zip file to `./fw_patching/net_core_app_update.bin`

##### Run the Patching Script
Move into the fw directory and run the patching script:
`cd ./fw_patching/ && python3 patch.py`

This should produce a new `app_update.bin` and a new `manifest.json`.
Zip `app_update.bin`, `manifest.json`, and `net_core_app_update.bin` into a new zip file called `dfu_application.zip`

##### Flash the Patched Image
Follow the steps in [Permanent Flashing](#Permanent-Flashing) to both arms of the glasses using the new `./fw_patching/dfu_application.zip` file.