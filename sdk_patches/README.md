# Vendor patches to NCS v2.5.1

The shipped v1.63 image was built from a private zephyr commit
(`7ae72792…-dirty`) and a dirty nrf tree.  Differences recovered from the
binary are recreated as patches here:

* `zephyr/` – on top of sdk-zephyr `v3.4.99-ncs1-1`
* `nrf/` – on top of sdk-nrf `v2.5.1`

r2_kcfg (2026-10-19): zephyr 0005 (conn.c send_frag LOG_DBG removed -> register order),
0006 (lsm6dso: lsm6dso_init exported/called by main, device init NULL, failure returns 0,
no "Initialize device" print, log level DBG; TRANSITIONAL --defsym lsm6dso_init_chip=lsm6dso_init
until src/main.c calls lsm6dso_init), 0007 (dmic_nrfx_pdm default gain 0x40 both channels,
skip_gpio_cfg not set).  These three are working-tree changes in (not
committed).  nrf: patches are now applied uncommitted on v2.5.1 so `git describe` = v2.5.1
(boot banner); see setup_ncs_vendor.sh.
