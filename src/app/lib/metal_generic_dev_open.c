/*
 * Function: metal_generic_dev_open
 * Entry:    0005339c
 * Prototype: int __stdcall metal_generic_dev_open(metal_bus * bus, char * dev_name, metal_device * * device)
 */


/* exclude_from_export_ai */

int metal_generic_dev_open(metal_bus *bus,char *dev_name,metal_device **device)

{
  return 1 << ((uint)bus & 0x1f) & *(uint *)(&DAT_e000e100 + ((uint)bus >> 5) * 4);
}


