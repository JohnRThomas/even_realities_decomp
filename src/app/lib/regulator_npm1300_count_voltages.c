/*
 * Function: regulator_npm1300_count_voltages
 * Entry:    00087922
 * Prototype: uint __stdcall regulator_npm1300_count_voltages(device * dev)
 */


/* exclude_from_export */

uint regulator_npm1300_count_voltages(device *dev)

{
  uint uVar1;
  
  if ((byte)dev->config[0x20] < 4) {
    uVar1 = 0x18;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


