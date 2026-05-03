/*
 * Function: FUN_010117f0
 * Entry:    010117f0
 * Prototype: undefined __stdcall FUN_010117f0(undefined1 * param_1, uint param_2)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_010117f0(undefined1 *param_1,uint param_2)

{
  byte bVar1;
  ushort uVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  byte *pbVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  undefined4 extraout_r2;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined4 extraout_r2_00;
  undefined2 uVar11;
  undefined4 extraout_r3;
  undefined4 *puVar12;
  undefined4 *puVar13;
  undefined4 extraout_r3_00;
  int iVar14;
  undefined4 uVar15;
  uint uVar16;
  undefined4 uVar17;
  undefined8 local_30;
  undefined4 uStack_28;
  uint uStack_24;
  
  if (param_1[200] != '\0') {
    MasterStackPointer = 0x3d;
    return;
  }
  param_1[0xc9] = *param_1;
  pbVar6 = DAT_21000f20;
  if (param_2 == 0xff) {
    param_1[0xca] = (byte)(((uint)*DAT_21000f20 << 0x19) >> 0x1f);
    *(undefined4 *)(param_1 + 0xcb) = *(undefined4 *)(pbVar6 + 3);
    *(undefined2 *)(param_1 + 0xcf) = *(undefined2 *)(pbVar6 + 7);
  }
  else {
    iVar3 = FUN_0100d298(param_2,param_1 + 0xca,(undefined4 *)(param_1 + 0xcb));
    if (iVar3 == 0) {
      FUN_01009500(0x2d,0xfc2,extraout_r2,extraout_r3);
                    /* WARNING (jumptable): Read-only address (ram,0x00000000) is written */
                    /* WARNING: Read-only address (ram,0x00000000) is written */
      MasterStackPointer = 0x13;
      puVar9 = (undefined4 *)(((uint)param_1 >> 0x1c) + 9);
      puVar12 = (undefined4 *)&LAB_00000002_1;
      do {
        puVar10 = puVar9 + 4;
        uVar17 = puVar9[1];
        puVar13 = puVar12 + 4;
        uVar15 = puVar9[2];
        uVar7 = puVar9[3];
        *puVar12 = *puVar9;
        puVar12[1] = uVar17;
        puVar12[2] = uVar15;
        puVar12[3] = uVar7;
        puVar9 = puVar10;
        puVar12 = puVar13;
      } while (puVar10 != (undefined4 *)(((uint)param_1 >> 0x1c) + 0x29));
      *(undefined1 *)puVar13 = *(undefined1 *)puVar10;
      uVar2 = _Reset;
      LAB_00000006 = 1;
      uVar16 = (uint)_Reset;
      puVar4 = (ushort *)FUN_0100a518(_Reset,1);
      if (puVar4 != (ushort *)0x0) {
        FUN_0100b0dc((uint)*puVar4);
        iVar3 = FUN_0100a564(uVar2,1);
        if (iVar3 != 0) {
          local_30 = FUN_01009500(0x2d,0x249,extraout_r2_00,extraout_r3_00);
          puVar8 = (undefined1 *)((ulonglong)local_30 >> 0x20);
          iVar3 = (int)local_30;
          uStack_28 = 1;
          *puVar8 = 0x13;
          puVar8[3] = 0;
          uVar5 = *(uint *)(*(undefined2 **)(iVar3 + 0x18) + 10);
          *(undefined2 *)(puVar8 + 4) = **(undefined2 **)(iVar3 + 0x18);
          puVar8[6] = 1;
          uStack_24 = uVar16;
          uVar16 = FUN_0100ddd0(uVar5);
          iVar14 = *(int *)(iVar3 + 0x18);
          *(short *)(puVar8 + 0x1a) = (short)uVar16;
          *(undefined2 *)(puVar8 + 0x1c) = *(undefined2 *)(iVar14 + 0x1c);
          *(undefined2 *)(puVar8 + 0x1e) = *(undefined2 *)(iVar14 + 0x1e);
          puVar8[0x20] = *(undefined1 *)(iVar14 + 0x2d8);
          puVar8[0x21] = 0xff;
          *(undefined2 *)(puVar8 + 0x22) = *(undefined2 *)(*(int *)(iVar3 + 0x14) + 8);
          if ((*(char *)(iVar14 + 9) == '\x01') && ((*(byte *)(iVar14 + 0xf) & 0xc0) == 0x40)) {
            *(undefined4 *)(puVar8 + 0xe) = *(undefined4 *)(iVar14 + 10);
            uVar11 = *(undefined2 *)(iVar14 + 0xe);
          }
          else {
            uVar11 = 0;
            *(undefined4 *)(puVar8 + 0xe) = 0;
          }
          *(undefined2 *)(puVar8 + 0x12) = uVar11;
          iVar14 = DAT_210014c0;
          pbVar6 = (byte *)(DAT_210014c0 + 0x54);
          *(undefined4 *)(puVar8 + 0x14) = *(undefined4 *)(DAT_210014c0 + 0x54);
          *(undefined2 *)(puVar8 + 0x18) = *(undefined2 *)(iVar14 + 0x58);
          iVar14 = *(int *)(iVar3 + 0x18);
          local_30._0_4_ = 0;
          bVar1 = *(byte *)(iVar14 + 2);
          local_30._4_4_ = local_30._4_4_ & 0xffff0000;
          puVar8[7] = bVar1;
          iVar3 = FUN_010260cc(pbVar6,(byte *)&local_30,6);
          if (iVar3 != 0) {
            puVar8[7] = bVar1 | 2;
          }
          *(undefined4 *)(puVar8 + 8) = *(undefined4 *)(iVar14 + 3);
          *(undefined2 *)(puVar8 + 0xc) = *(undefined2 *)(iVar14 + 7);
                    /* WARNING: Could not recover jumptable at 0x01011978. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          (*(code *)0x10118df)();
          return;
        }
      }
                    /* WARNING: Could not recover jumptable at 0x010118b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      (*(code *)0x101185f)();
      return;
    }
    param_1[0xca] = param_1[0xca] | 2;
  }
  FUN_0100f788((undefined4 *)(param_1 + 0xc0),0x101113d,2);
  return;
}


