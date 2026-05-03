/*
 * Function: FUN_0102e280
 * Entry:    0102e280
 * Prototype: int __stdcall FUN_0102e280(int param_1, int param_2, undefined4 param_3, int param_4, int param_5, int param_6, int param_7, int param_8)
 */


int FUN_0102e280(int param_1,int param_2,undefined4 param_3,int param_4,int param_5,int param_6,
                int param_7,int param_8)

{
  int iVar1;
  
  if ((param_1 == 0) || (param_6 == 0)) {
    iVar1 = -0x16;
  }
  else {
    if (param_8 == 0) {
      param_8 = 0x102e1d9;
    }
    if (param_2 != 0) {
      iVar1 = FUN_01035ff0((undefined1 *)(param_1 + 0xe0),param_5,param_8,param_4);
      return iVar1;
    }
    FUN_0103b86c((int *)(param_1 + 0x19c),param_6,param_7);
    iVar1 = FUN_01035ff0((undefined1 *)(param_1 + 0xe0),param_5,param_8,param_4);
  }
  return iVar1;
}


