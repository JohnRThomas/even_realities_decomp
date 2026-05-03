/*
 * Function: FUN_01010910
 * Entry:    01010910
 * Prototype: undefined __stdcall FUN_01010910(int param_1, int param_2)
 */


void FUN_01010910(int param_1,int param_2)

{
  int iVar1;
  ulonglong uVar2;
  undefined8 local_18;
  
  iVar1 = *(int *)(param_1 + 4);
  uVar2 = FUN_010200cc();
  uVar2 = uVar2 & 0x1807f704492f;
  local_18 = CONCAT71((int7)(uVar2 >> 8),*(byte *)(iVar1 + 0x116) & (byte)uVar2);
  local_18._4_4_ = (undefined4)(uVar2 >> 0x20);
  *(undefined4 *)(param_2 + 4) = (undefined4)local_18;
  *(undefined4 *)(param_2 + 8) = local_18._4_4_;
  return;
}


