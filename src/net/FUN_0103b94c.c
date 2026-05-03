/*
 * Function: FUN_0103b94c
 * Entry:    0103b94c
 * Prototype: undefined4 __stdcall FUN_0103b94c(int param_1, uint param_2, uint param_3, undefined4 param_4)
 */


undefined4 FUN_0103b94c(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  if ((int)((ulonglong)param_2 * (ulonglong)param_3 >> 0x20) == 0) {
    puVar1 = FUN_010391b8(0,(uint)((ulonglong)param_2 * (ulonglong)param_3),param_3,param_4);
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = 0xfffffff4;
    }
    else {
      FUN_0103b924(param_1,(int)puVar1,param_2,param_3);
      *(undefined1 *)(param_1 + 0x30) = 1;
      uVar2 = 0;
    }
  }
  else {
    uVar2 = 0xffffffea;
  }
  return uVar2;
}


