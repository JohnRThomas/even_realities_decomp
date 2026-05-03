/*
 * Function: FUN_01035afc
 * Entry:    01035afc
 * Prototype: int __stdcall FUN_01035afc(int param_1, undefined4 param_2, uint param_3, int param_4, int param_5)
 */


int FUN_01035afc(int param_1,undefined4 param_2,uint param_3,int param_4,int param_5)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar2;
  
  if (param_1 == 0) {
    iVar1 = -0x16;
  }
  else {
    if ((*(undefined4 **)(param_1 + 0x20) != (undefined4 *)0x0) &&
       (UNRECOVERED_JUMPTABLE = (code *)**(undefined4 **)(param_1 + 0x20),
       UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x01035b1e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    if (*(uint *)(param_1 + 0x28) < param_3) {
      iVar1 = -0xbc0;
    }
    else {
      for (uVar2 = 0; uVar2 != param_3; uVar2 = uVar2 + 1) {
        iVar1 = FUN_0103b3cc(param_1,(short)uVar2,*(undefined4 *)(param_4 + uVar2 * 4),
                             (int *)(*(int *)(param_1 + 0x2c) + uVar2 * 0x18 + 4),
                             *(undefined4 *)(param_5 + uVar2 * 4),
                             *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x28),
                             *(undefined4 **)(*(int *)(param_1 + 0x2c) + uVar2 * 0x18));
        if (iVar1 != 0) {
          return iVar1;
        }
      }
      iVar1 = 0;
    }
  }
  return iVar1;
}


