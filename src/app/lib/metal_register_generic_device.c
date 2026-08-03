/*
 * Function: metal_register_generic_device
 * Entry:    0006b4ac
 * Prototype: int __stdcall metal_register_generic_device(metal_device * device)
 */


/* exclude_from_export_ai */

int metal_register_generic_device(metal_device *device)

{
  dword *pdVar1;
  int iVar2;
  
  if (((device->name == (char *)0x0) || (*device->name == '\0')) || (1 < device->num_regions)) {
    iVar2 = -0x16;
  }
  else {
    device->bus = (undefined *)&DAT_20002c5c;
    device[2].node = (dword)DAT_2000be28;
    device[2].regions_METAL_MAX_DEVICE_REGIONS_ = (dword)&DAT_2000be24;
    iVar2 = 0;
    pdVar1 = &device[2].regions_METAL_MAX_DEVICE_REGIONS_;
    *DAT_2000be28 = (dword)&device[2].regions_METAL_MAX_DEVICE_REGIONS_;
    DAT_2000be28 = pdVar1;
  }
  return iVar2;
}


