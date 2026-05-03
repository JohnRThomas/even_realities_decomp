/*
 * Function: FUN_01028e56
 * Entry:    01028e56
 * Prototype: int __stdcall FUN_01028e56(ushort * param_1)
 */


int FUN_01028e56(ushort *param_1)

{
  int iVar1;
  undefined2 *puVar2;
  bool bVar3;
  ushort uVar4;
  bool bVar5;
  char local_2c [4];
  int local_28;
  undefined2 uStack_24;
  ushort local_22;
  ushort local_20;
  ushort local_1e;
  ushort local_1c;
  
  iVar1 = FUN_0100d7c0(*param_1,local_2c);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = FUN_01028aa6((int)local_2c);
  bVar5 = *(char *)(local_28 + 0x1ea) != '\0';
  if (local_2c[0] == '\0') {
    if (*(char *)(iVar1 + 0x1e) == '\x1f') {
LAB_01028e8e:
      bVar3 = !bVar5;
      goto LAB_01028e96;
    }
  }
  else if (*(int *)(iVar1 + 0xc) << 0x1a < 0) goto LAB_01028e8e;
  bVar3 = false;
LAB_01028e96:
  if (((int)((uint)*(byte *)(iVar1 + 0x6e) << 0x1a) < 0) || (bVar3)) {
    if (((ushort)(param_1[3] - 0x1b) < 0xe1) &&
       ((((ushort)(param_1[4] - 0x148) < 0x4149 && ((ushort)(param_1[1] - 0x1b) < 0xe1)) &&
        ((ushort)(param_1[2] - 0x148) < 0x4149)))) {
      if ((param_1[4] < 0xa91) && (param_1[2] < 0xa91)) {
        puVar2 = (undefined2 *)FUN_01028aa2((int)local_2c);
        *(undefined1 *)(local_28 + 0x163) = 0xff;
        if (bVar5) {
          iVar1 = 0x3a;
        }
        else {
          FUN_01028afc(puVar2,(uint)(local_2c[0] == '\0'),&uStack_24);
          if (param_1[1] <= local_1e) {
            local_1e = param_1[1];
          }
          uVar4 = param_1[2];
          *(ushort *)(local_28 + 0x168) = local_1e;
          if (0x847 < local_1c) {
            local_1c = 0x848;
          }
          if (param_1[3] <= local_22) {
            local_22 = param_1[3];
          }
          *(ushort *)(local_28 + 0x164) = local_22;
          if (0x847 < local_20) {
            local_20 = 0x848;
          }
          if (param_1[4] <= local_20) {
            local_20 = param_1[4];
          }
          *(ushort *)(local_28 + 0x166) = local_20;
          if (local_1c <= uVar4) {
            uVar4 = local_1c;
          }
          *(ushort *)(local_28 + 0x16a) = uVar4;
          *(undefined1 *)(local_28 + 0x162) = 0xff;
          iVar1 = 0;
        }
        *(undefined1 *)(local_28 + 0x163) = 0;
      }
      else {
        iVar1 = 0x11;
      }
    }
    else {
      iVar1 = 0x12;
    }
  }
  else {
    iVar1 = 0x1a;
  }
  return iVar1;
}


