/*
 * Function: FUN_0101f2f8
 * Entry:    0101f2f8
 * Prototype: undefined1 __stdcall FUN_0101f2f8(ushort * param_1, int param_2)
 */


undefined1 FUN_0101f2f8(ushort *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int extraout_r3;
  ushort *local_10;
  int local_c;
  
  local_10 = param_1;
  local_c = param_2;
  iVar2 = FUN_0100d7c0(*param_1,(undefined1 *)&local_10);
  if (iVar2 == 0) {
    if ((char)local_10 == '\0') {
      bVar1 = FUN_01028ac4(local_c);
    }
    else {
      bVar1 = FUN_01028ae0(local_c);
    }
    if (bVar1 != false) {
      if ((*(char *)(local_c + 0x172) == '\0') &&
         (iVar2 = FUN_01028aa6((int)&local_10), *(char *)(iVar2 + 0x68) == '\0')) {
        if ((*(byte *)(iVar2 + 0x5f) & 3) == 0) {
          *(undefined1 *)(extraout_r3 + 0x172) = 1;
          FUN_0100f10c((char *)&local_10);
          return 0;
        }
        FUN_0100f7c8((undefined4 *)(iVar2 + 0x60),0x1010aa1,2);
        return 0;
      }
      return 0x3a;
    }
  }
  return 2;
}


