/*
 * Function: FUN_0102a0f0
 * Entry:    0102a0f0
 * Prototype: undefined4 __stdcall FUN_0102a0f0(int param_1, int param_2)
 */


undefined4 FUN_0102a0f0(int param_1,int param_2)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  byte *pbVar6;
  undefined1 uVar7;
  byte bVar8;
  int iVar9;
  undefined4 uStack_18;
  int local_14;
  
  iVar9 = *(int *)(param_1 + 4);
  uStack_18 = param_1;
  local_14 = param_2;
  uVar3 = FUN_0100dbc0(iVar9 + 0xa8,0,(uint)*(byte *)(iVar9 + 0xc6),0);
  if (uVar3 == 0) {
    uVar5 = 1;
  }
  else if (*(byte *)(iVar9 + 0xc5) - 0x25 < 3) {
    uVar5 = 0x20;
  }
  else {
    cVar1 = FUN_0100b160(&local_14);
    pbVar6 = (byte *)0x0;
    if (cVar1 != '\0') {
      pbVar6 = (byte *)((int)&uStack_18 + 3);
      uStack_18 = CONCAT13(*(undefined1 *)(local_14 + 3),(undefined3)uStack_18);
    }
    iVar4 = FUN_01010000((uint)*(byte *)(iVar9 + 0xc5),pbVar6,0x16,
                         (undefined1 *)((int)&uStack_18 + 2));
    if (iVar4 == 0) {
      bVar2 = FUN_0100f07c(param_2);
      if (bVar2 == 0) {
        uVar5 = FUN_0101006c(param_1,param_2);
        return uVar5;
      }
      bVar2 = *(byte *)(param_2 + 4) & 7;
      *(byte *)(iVar9 + 0x66) = bVar2;
      bVar8 = *(byte *)(param_2 + 5) & 7;
      *(byte *)(iVar9 + 0x67) = bVar8;
      if ((*(char *)(iVar9 + 0x16d) == '\0') && (*(char *)(iVar9 + 0x16c) != '\x01')) {
        if ((*(byte *)(iVar9 + 0x6f) == bVar2) && (*(byte *)(iVar9 + 0x6e) == bVar8)) {
          *(undefined1 *)(*(int *)(param_1 + 4) + 0x16c) = 2;
        }
        else {
          FUN_01020174(param_1);
        }
      }
      uVar7 = 0x23;
    }
    else {
      FUN_0100ffd0(param_1,0x16,uStack_18._2_1_);
      uVar7 = 0x30;
    }
    uVar5 = 0;
    *(undefined1 *)(iVar9 + 0xc6) = uVar7;
    *(undefined2 *)(iVar9 + 0x102) = 0;
    *(undefined1 *)(iVar9 + 0x104) = 1;
  }
  return uVar5;
}


