/*
 * Function: write_block
 * Entry:    0007f9d8
 * Prototype: undefined4 __stdcall write_block(int param_1, undefined4 * param_2, int param_3)
 */


/* exclude_from_export_ai */

undefined4 write_block(int param_1,undefined4 *param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (param_1 != 0) {
    if (param_2 == (undefined4 *)0x0) {
      uVar1 = 0;
    }
    else {
      *param_2 = 0;
      param_2[1] = 0;
      iVar2 = *(int *)(param_1 + 0x14);
      if ((iVar2 == 0) || (*(code **)(iVar2 + 8) == (code *)0x0)) {
        if (param_3 != 0) {
          FUN_0007f9c4(param_1,param_2);
        }
      }
      else {
        (**(code **)(iVar2 + 8))(iVar2);
      }
      uVar1 = *param_2;
    }
  }
  return uVar1;
}


