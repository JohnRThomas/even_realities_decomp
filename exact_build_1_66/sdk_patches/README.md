# Vendor patches to NCS v2.5.1

The shipped v1.66 image was built from a private zephyr commit
(`833f89df…-dirty`) and a dirty nrf tree.  Their differences from the public
trees, as far as they show in the image, are recreated here:

* `zephyr/0001-G1-vendor-zephyr-tree.patch` – one patch on top of sdk-zephyr
  `v3.4.99-ncs1-1`.  Its commit message lists each change and the evidence for
  it: hci_core.c (the 1.66 `bt_hci_cmd_send_sync_timeout()`), conn.c, lsm6dso.c,
  dmic_nrfx_pdm.c and lib/crc.  nrf_qspi_nor.c is stock in 1.66 (only 1.63 had a
  modified driver).  The zephyr `git describe` string is not in the image.
* `nrf/` – on top of sdk-nrf `v2.5.1`.  They must stay uncommitted so that
  `git describe` stays `v2.5.1`: the boot banner embeds it
  ("*** Booting nRF Connect SDK v2.5.1 ***").

`../build_repro.sh` copies the NCS v2.5.1 workspace (`NCS_DIR`, default
`~/ncs/v2.5.1`) to `G1_NCS_DIR` (default `~/ncs/v2.5.1-g1`) if that does not exist
yet and applies both with `git apply`, skipping patches that are already applied.
The plain `west build` uses the stock tree without them; `../../README.md` lists what
that changes.

Both nrf patches (ANCS attribute data 256 bytes, ESB event IRQ on SWI3) are in
every firmware version from 1.45 to 1.66.  The ANCS code of 1.45 to 1.56 differs
only by the application's CONFIG_BT_ANCS_CLIENT_CP_BUFF_SIZE (2048, 4096 from
1.63 on).  Checked with ai_helpers/variant_scan.py, which matches a vendor and a
stock build of a file against each shipped image.
