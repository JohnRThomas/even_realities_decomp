/*
 * Function: FUN_000854dc
 * Entry:    000854dc
 * Prototype: undefined4 __stdcall FUN_000854dc(int * param_1, undefined2 param_2, int * param_3)
 */


undefined4 FUN_000854dc(int *param_1,undefined2 param_2,int *param_3)

{
  undefined1 *puVar1;
  undefined2 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *puVar6;
  undefined1 uVar7;
  int iVar8;
  int iVar9;
  bool bVar10;
  bool bVar11;
  undefined4 *puVar5;
  
  iVar9 = *param_3;
  if (param_3[2] == 0) {
    puVar1 = net_buf_add((net_buf *)(param_3[1] + 0xc),1);
    param_3[2] = (int)puVar1;
    if (*(char *)*param_1 == '\0') {
      uVar7 = 1;
    }
    else {
      uVar7 = 2;
    }
    *puVar1 = uVar7;
  }
  if (*(char *)param_3[2] == '\x01') {
    if (*(char *)*param_1 == '\0') {
      puVar2 = net_buf_add((net_buf *)(param_3[1] + 0xc),4);
      param_3[3] = (int)puVar2;
      *puVar2 = param_2;
      *(undefined2 *)(param_3[3] + 2) = *(undefined2 *)(*param_1 + 2);
      if ((uint)*(ushort *)(iVar9 + 0x1e) < (uint)*(ushort *)(iVar9 + 0x2e)) {
        uVar3 = (uint)*(ushort *)(iVar9 + 0x1e) - (uint)*(ushort *)(param_3[1] + 0x10);
      }
      else {
        uVar3 = (uint)*(ushort *)(iVar9 + 0x2e) - (uint)*(ushort *)(param_3[1] + 0x10);
      }
      bVar11 = 3 < uVar3;
      bVar10 = uVar3 == 4;
      goto LAB_00085548;
    }
  }
  else if ((*(char *)param_3[2] == '\x02') && (*(char *)*param_1 == '\x02')) {
    puVar2 = net_buf_add((net_buf *)(param_3[1] + 0xc),0x12);
    param_3[3] = (int)puVar2;
    *puVar2 = param_2;
    iVar8 = *param_1;
    puVar4 = (undefined4 *)(iVar8 + 1);
    puVar6 = (undefined4 *)(param_3[3] + 2);
    do {
      puVar5 = puVar4 + 1;
      *puVar6 = *puVar4;
      puVar4 = puVar5;
      puVar6 = puVar6 + 1;
    } while (puVar5 != (undefined4 *)(iVar8 + 0x11));
    if ((uint)*(ushort *)(iVar9 + 0x1e) < (uint)*(ushort *)(iVar9 + 0x2e)) {
      uVar3 = (uint)*(ushort *)(iVar9 + 0x1e) - (uint)*(ushort *)(param_3[1] + 0x10);
    }
    else {
      uVar3 = (uint)*(ushort *)(iVar9 + 0x2e) - (uint)*(ushort *)(param_3[1] + 0x10);
    }
    bVar11 = 0x11 < uVar3;
    bVar10 = uVar3 == 0x12;
LAB_00085548:
    if (bVar11 && !bVar10) {
      return 1;
    }
    return 0;
  }
  return 0;
}


