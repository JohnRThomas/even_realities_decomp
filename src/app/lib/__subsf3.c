/*
 * Function: __subsf3
 * Entry:    0000df88
 * Prototype: uint __stdcall __subsf3(uint param_1, uint param_2, undefined4 param_3, uint param_4)
 */


/* exclude_from_export_ai */

uint __subsf3(uint param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  
  uVar1 = __addsf3(param_1 ^ 0x80000000,param_2,param_3,param_4);
  return uVar1;
}


