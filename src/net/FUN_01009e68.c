/*
 * Function: FUN_01009e68
 * Entry:    01009e68
 * Prototype: undefined __stdcall FUN_01009e68(uint * param_1, undefined4 param_2, undefined4 param_3)
 */


void FUN_01009e68(uint *param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 == (uint *)0x0) {
    DAT_21000ba8 = 1;
    DAT_21000bb0 = 0;
    DAT_21000bac = 0;
  }
  else {
    if (DAT_21000ba8 != 2) {
      FUN_01009500(0x17,0x106,param_3,(uint)DAT_21000ba8);
    }
    DAT_21000ba8 = 3;
    if ((*param_1 & 7) != 0) {
      FUN_01009500(0x17,0x10b,3,*param_1 & 7);
    }
    DAT_21000bb0 = DAT_21000bac + *param_1;
    DAT_21000bac = *param_1;
    *param_1 = DAT_21000bb0;
    FUN_01026284((undefined4 *)&DAT_21000b7c,0,0x2c);
  }
  return;
}


