/*
 * Function: kmu_validate_slot_and_size
 * Entry:    0007ee74
 * Prototype: undefined4 __stdcall kmu_validate_slot_and_size(uint param_1, int param_2)
 */


/* exclude_from_export */

undefined4 kmu_validate_slot_and_size(uint param_1,int param_2)

{
  undefined4 uVar1;
  
  if (0x7f < param_1) {
    return 0xf70001;
  }
  if (param_2 == 0) {
    return 0;
  }
  if (2 < param_2 - 1U) {
    return 0xf70003;
  }
  if (param_1 == 0x7f) {
    uVar1 = 0xf70001;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


