/*
 * Function: FUN_0103b346
 * Entry:    0103b346
 * Prototype: int __stdcall FUN_0103b346(int param_1, uint param_2)
 */


int FUN_0103b346(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  if (*(code **)(param_1 + 0x30) == (code *)0x0) {
    uVar2 = 0;
    if (*(uint *)(param_1 + 0xc) < 0x20) {
      uVar2 = param_2 >> (*(uint *)(param_1 + 0xc) & 0xff);
    }
    if ((*(int *)(param_1 + 4) == 0) || (*(uint *)(param_1 + 8) <= param_2)) {
      iVar1 = -1;
    }
    else {
      iVar1 = (*(uint *)(param_1 + 0x10) & param_2) + *(int *)(*(int *)(param_1 + 4) + uVar2 * 4);
    }
    return iVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x0103b376. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (**(code **)(param_1 + 0x30))();
  return iVar1;
}


