# Byte-identical build of v1.66

`build_repro.sh` rebuilds the project so that `app_update.bin` and
`net_core_app_update.bin` are byte-identical to the ones in the shipped v1.66
`dfu_application.zip`.  Everything that only this build needs is in this directory.
The rest of the project does not refer to it: the directory can be deleted without
changing the plain `west build` (`../README.md`).

| | plain `west build` | `build_repro.sh` |
|---|---|---|
| SDK | stock NCS v2.5.1 | NCS v2.5.1 + `sdk_patches/` |
| build time, commit | configure time, `git rev-parse HEAD` | values of v1.66 |
| MCUboot signature | default key, random salt | default key, salt of v1.66 |
| b0n signature (net core) | key generated in the build directory | signature of v1.66 |
| newlib | Linux Zephyr SDK | Windows Zephyr SDK 0.16.1 |
| result | own images; runtime differences in `../README.md` | byte-identical to v1.66 |

## Usage

Requirements of the plain build, plus `curl` and `7z` (the Windows newlib is fetched
once).

```sh
exact_build_1_66/build_repro.sh [BUILD_DIR]        # default build_repro
```

1. Copies `~/ncs/v2.5.1` to `~/ncs/v2.5.1-g1` if that does not exist (a reflink copy
   on btrfs/XFS) and applies `sdk_patches/` to it with `git apply`; already applied
   patches are skipped.  `NCS_DIR` and `G1_NCS_DIR` override both paths.
2. Fetches the Windows newlib into `sdk_patches/toolchain_libs/`
   (`fetch_win_newlib.sh`).
3. Runs `west build` against the patched tree with the v1.66 build strings and
   signature salts, which are set at the top of the script.  The project's CMake
   files have no switch for this build: the script passes everything on the command
   line, including `repro.cmake`, which CMake includes after `project()` of both
   images (`CMAKE_PROJECT_<name>_INCLUDE`).
4. Compares `app_update.bin` and `net_core_app_update.bin` with the SHA-256 of the
   shipped images and exits non-zero if either differs.

The build directory is created in the project directory, of which it must be a
direct subdirectory: the image contains the application's `__FILE__` strings, which
are relative to it (`../src/...`).  `dfu_application.zip` itself is not
byte-identical to the shipped zip (its `manifest.json` holds build timestamps and
the project directory name), but the two images in it are.

## Files

* `build_repro.sh`: the build, with the v1.66 build strings, salts and image hashes.
* `repro.cmake`: the CMake part.  It replaces the build strings, compiles
  `crc8_sw.c` as an application source and re-signs the update images.
* `pss_salt.py`: recovers and pins MCUboot RSA-PSS salts.
* `b0_vendor/`: the b0n public key and the signature of the shipped network core
  image.
* `sdk_patches/`: the vendor's changes to zephyr and nrf (see its README), and the
  fetched Windows newlib in `toolchain_libs/` (not in git).
* `fetch_win_newlib.sh`: fetches that newlib.
