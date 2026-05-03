/*
 * Function: FUN_01039faa
 * Entry:    01039faa
 * Prototype: undefined __stdcall FUN_01039faa(int param_1, uint param_2, uint param_3)
 */


void FUN_01039faa(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_01039efc(param_1,param_2,3);
  if (param_2 == uVar1) {
    *(uint *)(param_1 + 0xc) = *(uint *)(param_1 + 0xc) & ~(1 << (param_3 & 0xff));
    *(undefined4 *)(param_1 + (param_3 + 4) * 4) = 0;
    return;
  }
  uVar2 = FUN_01039efc(param_1,param_2,2);
  *(uint *)(param_1 + (param_3 + 4) * 4) = uVar1;
  FUN_01039f12(param_1,uVar2,3,uVar1);
  FUN_01039f12(param_1,uVar1,2,uVar2);
  return;
}


