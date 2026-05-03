/*
 * Function: FUN_01010948
 * Entry:    01010948
 * Prototype: undefined __stdcall FUN_01010948(byte * param_1)
 */


void FUN_01010948(byte *param_1)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined1 *puVar4;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  int extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 uVar5;
  undefined4 extraout_r3;
  int iVar6;
  undefined4 extraout_r3_00;
  int extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 uVar7;
  int iVar8;
  undefined8 uVar9;
  
  iVar8 = *(int *)(param_1 + 4);
  uVar2 = FUN_0100dbc0(iVar8 + 0xa8,0,(uint)*(byte *)(iVar8 + 0xc5),(uint)*param_1);
  if (uVar2 != 0) {
    *(undefined1 *)(iVar8 + 0xc5) = 4;
    return;
  }
  pcVar3 = (char *)FUN_01009500(0x1c,0xaa,extraout_r2,extraout_r3);
  if (*pcVar3 == '\0') {
    uVar2 = FUN_0100dbc0(*(int *)(pcVar3 + 4) + 0xa8,0,(uint)*(byte *)(*(int *)(pcVar3 + 4) + 0xc6),
                         0);
    uVar5 = extraout_r2_00;
    uVar7 = extraout_r3_00;
    if (uVar2 != 0) {
      *(undefined1 *)(*(int *)(pcVar3 + 4) + 0x104) = 0;
      return;
    }
  }
  else {
    iVar8 = *(int *)(pcVar3 + 4);
    iVar6 = *(uint *)(iVar8 + 0xb4) << 0x1f;
    if (iVar6 < 0) {
      cVar1 = *(char *)(iVar8 + 0x104) + -1;
      *(char *)(iVar8 + 0x104) = cVar1;
      if (-1 < cVar1) {
        *(uint *)(iVar8 + 0xb4) = *(uint *)(iVar8 + 0xb4) & 0xfffffffe;
        return;
      }
      FUN_01009500(0x1c,0xb9,iVar8,(int)cVar1);
      iVar8 = extraout_r2_01;
      iVar6 = extraout_r3_01;
    }
    FUN_01009500(0x1c,0xb7,iVar8,iVar6);
    uVar5 = extraout_r2_02;
    uVar7 = extraout_r3_02;
  }
  uVar9 = FUN_01009500(0x1c,0xb2,uVar5,uVar7);
  puVar4 = (undefined1 *)((ulonglong)uVar9 >> 0x20);
  *puVar4 = 0xe;
  *(undefined2 *)(puVar4 + 2) = *(undefined2 *)((int)uVar9 + -0x1c5);
  return;
}


