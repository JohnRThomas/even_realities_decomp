/*
 * Function: metal_device_open
 * Entry:    00088bb6
 * Prototype: int __stdcall metal_device_open(char * bus_name, char * dev_name, metal_device * * device)
 */


/* exclude_from_export */

int metal_device_open(char *bus_name,char *dev_name,metal_device **device)

{
  int iVar1;
  metal_bus *local_14;
  metal_device **ppmStack_10;
  
  if ((((bus_name == (char *)0x0) || (*bus_name == '\0')) || (dev_name == (char *)0x0)) ||
     ((*dev_name == '\0' || (device == (metal_device **)0x0)))) {
    iVar1 = -0x16;
  }
  else {
    local_14 = (metal_bus *)dev_name;
    ppmStack_10 = device;
    iVar1 = metal_bus_find(bus_name,&local_14);
    if (iVar1 == 0) {
      if ((code *)local_14->devices != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00088be2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
        iVar1 = (*(code *)local_14->devices)(local_14,dev_name,device);
        return iVar1;
      }
      iVar1 = -0x13;
    }
  }
  return iVar1;
}


