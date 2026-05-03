/*
 * Function: FUN_00065318
 * Entry:    00065318
 * Prototype: undefined4 __stdcall FUN_00065318(int param_1, char * param_2, undefined2 * param_3)
 */


undefined4 FUN_00065318(int param_1,char *param_2,undefined2 *param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined2 uVar3;
  
  if (((int)param_2 < 1000000) || (3300000 < param_1)) {
LAB_0006535c:
    uVar1 = 0xffffffea;
  }
  else {
    if (param_1 < 1000000) {
      uVar3 = 0;
    }
    else {
      if ((int)param_2 < 0x325aa1) {
        uVar2 = (param_1 - 0xdbba1U) / 100000;
        *param_3 = (short)uVar2;
        if ("failed to set gyroscope full-scale\r\n" + uVar2 * 100000 + 0xd <= param_2) {
          return 0;
        }
        goto LAB_0006535c;
      }
      uVar3 = 0x17;
    }
    uVar1 = 0xffffffde;
    *param_3 = uVar3;
  }
  return uVar1;
}


