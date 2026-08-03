/*
 * Function: __unorddf2
 * Entry:    0000de2c
 * Prototype: undefined4 __stdcall __unorddf2(int param_1, uint param_2, int param_3, uint param_4)
 */


/* exclude_from_export_ai */

undefined4 __unorddf2(int param_1,uint param_2,int param_3,uint param_4)

{
  if ((((int)(param_2 << 1) >> 0x15 != -1) || (param_1 == 0 && (param_2 & 0xfffff) == 0)) &&
     (((int)(param_4 << 1) >> 0x15 != -1 || (param_3 == 0 && (param_4 & 0xfffff) == 0)))) {
    return 0;
  }
  return 1;
}


