/*
 * Function: FUN_01034220
 * Entry:    01034220
 * Prototype: undefined4 __stdcall FUN_01034220(undefined1 * param_1, uint param_2)
 */


undefined4 FUN_01034220(undefined1 *param_1,uint param_2)

{
  undefined4 uVar1;
  
  if (DAT_21006458 == '\0') {
    if ((param_1 == (undefined1 *)0x0) || (8 < param_2)) {
      uVar1 = 0xffffffea;
    }
    else {
      FUN_0103bdd4(0x2100068c,param_1,param_2);
      DAT_21000694 = (undefined1)param_2;
      DAT_21000696 = (undefined1)(0xff >> (8 - param_2 & 0xff));
      FUN_010330f0();
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xfffffff0;
  }
  return uVar1;
}


