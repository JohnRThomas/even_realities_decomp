/*
 * Function: L_shift
 * Entry:    0008ab1a
 * Prototype: undefined __stdcall L_shift(uint * param_1, uint * param_2, int param_3)
 */


/* exclude_from_export_ai */

void L_shift(uint *param_1,uint *param_2,int param_3)

{
  uint *puVar1;
  
  do {
    puVar1 = param_1 + 1;
    *param_1 = *param_1 | *puVar1 << ((8 - param_3) * -4 + 0x20U & 0xff);
    param_1 = param_1 + 1;
    *param_1 = *puVar1 >> ((8 - param_3) * 4 & 0xffU);
  } while (param_1 < param_2);
  return;
}


