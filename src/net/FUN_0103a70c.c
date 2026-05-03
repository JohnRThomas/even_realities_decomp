/*
 * Function: FUN_0103a70c
 * Entry:    0103a70c
 * Prototype: int __stdcall FUN_0103a70c(int param_1, byte * param_2)
 */


int FUN_0103a70c(int param_1,byte *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_0102aa44(param_2,(byte *)(param_1 + 0x40));
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = FUN_0102aa44(param_2,(byte *)(param_1 + 0xb0));
    if (iVar2 != 0) {
      return 0;
    }
    iVar2 = 1;
  }
  return iVar2 * 0x70 + param_1;
}


