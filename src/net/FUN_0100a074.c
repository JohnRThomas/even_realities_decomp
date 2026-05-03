/*
 * Function: FUN_0100a074
 * Entry:    0100a074
 * Prototype: int __stdcall FUN_0100a074(undefined4 param_1, undefined4 param_2, undefined4 param_3)
 */


int FUN_0100a074(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((DAT_21000ba8 != 1) && (DAT_21000ba8 != 3)) {
    FUN_01009500(0x17,0x146,param_3,(uint)DAT_21000ba8);
  }
  if (DAT_21000ba8 == 3) {
    if (DAT_21000bb0 != DAT_21000bac) {
      FUN_01009500(0x17,0x149,DAT_21000bb0,DAT_21000bac);
    }
    FUN_01009dc0();
    DAT_21000ba8 = 4;
    iVar1 = 0;
  }
  else {
    DAT_21000ba8 = 2;
    iVar1 = DAT_21000bac;
  }
  return iVar1;
}


