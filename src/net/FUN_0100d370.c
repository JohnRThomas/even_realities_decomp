/*
 * Function: FUN_0100d370
 * Entry:    0100d370
 * Prototype: undefined __stdcall FUN_0100d370(int param_1)
 */


void FUN_0100d370(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (uint)DAT_21000d19;
  if (uVar3 != 0) {
    uVar2 = 0;
    uVar1 = 0;
    do {
      while ((&DAT_21000e5a)[uVar1] == '\0') {
        uVar2 = uVar2 + 1;
        FUN_0100b314((undefined4 *)(&DAT_21000d9a + uVar1 * 0x10),&DAT_21000e22 + uVar1 * 6,param_1)
        ;
        uVar3 = (uint)DAT_21000d19;
        uVar1 = uVar2 & 0xff;
        if (uVar3 <= uVar1) {
          return;
        }
      }
      uVar2 = uVar2 + 1;
      uVar1 = uVar2 & 0xff;
    } while (uVar1 < uVar3);
  }
  return;
}


