/*
 * Function: FUN_0102a1be
 * Entry:    0102a1be
 * Prototype: undefined4 __stdcall FUN_0102a1be(int param_1, int param_2)
 */


undefined4 FUN_0102a1be(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  byte bVar4;
  int iVar5;
  
  iVar5 = *(int *)(param_1 + 4);
  uVar2 = FUN_0100dbc0(iVar5 + 0xa8,0xb,(uint)*(byte *)(iVar5 + 0xc6),1);
  if (uVar2 == 0) {
    uVar2 = FUN_0100dbc0(iVar5 + 0xa8,0,(uint)*(byte *)(iVar5 + 0xc6),1);
    if (uVar2 == 0) {
      return 1;
    }
    if (*(char *)(iVar5 + 0xc5) != '&') {
      bVar1 = FUN_0100f07c(param_2);
      if (bVar1 != 0) {
        bVar4 = *(byte *)(param_2 + 5) & 7;
        *(byte *)(iVar5 + 0x67) = bVar4;
        bVar1 = *(byte *)(param_2 + 4) & 7;
        *(byte *)(iVar5 + 0x66) = bVar1;
        if ((*(char *)(iVar5 + 0x16d) == '\0') && (*(char *)(iVar5 + 0x16c) != '\x01')) {
          if ((*(byte *)(iVar5 + 0x6f) == bVar1) && (*(byte *)(iVar5 + 0x6e) == bVar4)) {
            *(undefined1 *)(iVar5 + 0x16c) = 2;
          }
          else {
            FUN_01020174(param_1);
          }
        }
        *(undefined1 *)(iVar5 + 0xc6) = 0x23;
        FUN_0100ff98(param_1);
        return 0;
      }
      uVar3 = FUN_01010034(param_1,param_2);
      return uVar3;
    }
  }
  return 0x20;
}


