/*
 * Function: FUN_01011d40
 * Entry:    01011d40
 * Prototype: uint __stdcall FUN_01011d40(uint param_1, int param_2, char * param_3)
 */


uint FUN_01011d40(uint param_1,int param_2,char *param_3)

{
  undefined2 uVar1;
  bool bVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  undefined *puVar6;
  uint uVar7;
  undefined1 *puVar8;
  uint uVar9;
  undefined4 extraout_r2;
  uint extraout_r2_00;
  undefined1 uVar10;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  uint uVar11;
  char cVar12;
  byte local_29;
  uint auStack_28 [3];
  
  if (param_2 == 3) {
    if (-1 < (int)((uint)*(ushort *)(param_1 + 2) << 0x1e)) {
      return 0;
    }
    cVar12 = '\x02';
  }
  else {
    if (*(char *)(param_1 + 0x78) != '\0') {
      return 0;
    }
    if ((param_2 == 5) && (-1 < (int)((uint)*(ushort *)(param_1 + 2) << 0x1f))) {
      return 0;
    }
    cVar12 = '\x01';
  }
  uVar7 = 0;
  if (DAT_21000f32 == '\0') {
LAB_01011d72:
    if (*param_3 != -1) goto LAB_01011d78;
  }
  else {
    uVar7 = FUN_0100d310();
    *param_3 = (char)uVar7;
    if (uVar7 != 0xff) {
      iVar5 = FUN_0100d298(uVar7,&local_29,auStack_28);
      if (iVar5 == 0) {
        FUN_01009500(0x2d,0xf45,extraout_r2,extraout_r3);
        cVar12 = DAT_21000f32;
        puVar8 = (undefined1 *)(param_1 >> 0x1c);
        *(short *)(puVar8 + 0x40) = *(short *)(puVar8 + 0x40) + 1;
        uVar7 = 0;
        if (cVar12 != '\0') {
          FUN_010210b0();
          FUN_010204a8();
          DAT_21000f32 = '\0';
          uVar7 = extraout_r2_00;
        }
        DAT_21000f24 = 0;
        if (puVar8[0x79] != '\0') {
          puVar6 = FUN_010148ec(puVar8,1,uVar7,extraout_r3_00);
          return (uint)puVar6;
        }
        uVar11 = (uint)(byte)puVar8[0xd];
        if ((uVar11 != 0) && (uVar7 = (uint)*(ushort *)(puVar8 + 0x40), uVar11 <= uVar7)) {
          FUN_010148ec(puVar8,1,uVar7,uVar11);
          if ((int)((uint)*(ushort *)(puVar8 + 2) << 0x1f) < 0) {
            uVar1 = **(undefined2 **)(puVar8 + 0x1c);
            bVar3 = FUN_01020088();
            if (bVar3 != 0) {
              return (uint)bVar3;
            }
            cVar12 = puVar8[0xd];
            *(undefined2 *)(puVar8 + 0xb1) = uVar1;
            puVar8[0xb0] = *puVar8;
            puVar8[0xaf] = 0x43;
          }
          else {
            bVar3 = FUN_01020088();
            if (bVar3 != 0) {
              return (uint)bVar3;
            }
            cVar12 = puVar8[0xd];
            puVar8[0xb0] = *puVar8;
            puVar8[0xb1] = 0xff;
            puVar8[0xb2] = 0xff;
            puVar8[0xaf] = 0x43;
          }
          uVar10 = 0;
          if (cVar12 != '\0') {
            uVar10 = puVar8[0x40];
          }
          puVar8[0xb3] = uVar10;
          uVar7 = FUN_0100f788((undefined4 *)(puVar8 + 0xa6),0x1011add,2);
          return uVar7;
        }
        puVar6 = FUN_010148ec(puVar8,0,uVar7,extraout_r3_00);
        return (uint)puVar6;
      }
      uVar7 = FUN_01011090((uint)local_29,auStack_28);
      goto LAB_01011d72;
    }
  }
  uVar7 = FUN_01011090(((uint)*DAT_21000f20 << 0x19) >> 0x1f,(uint *)(DAT_21000f20 + 3));
LAB_01011d78:
  bVar2 = FUN_0100b23c(((uint)*DAT_21000f20 << 0x19) >> 0x1f,DAT_21000f20 + 3,
                       (uint)*(byte *)(param_1 + 0x67),(byte *)(param_1 + 0x68));
  uVar11 = (uint)bVar2;
  uVar4 = FUN_0100cf44(((uint)*DAT_21000f20 << 0x19) >> 0x1f,DAT_21000f20 + 3);
  bVar2 = FUN_0100d400(uVar4);
  if ((bVar2) && (puVar6 = FUN_0100d280(uVar4), puVar6 != (undefined *)0x0)) {
    bVar3 = FUN_0100c3ec(uVar4);
    uVar4 = (uint)bVar3;
    uVar9 = uVar4 ^ 1;
  }
  else {
    uVar4 = 1;
    uVar9 = 0;
  }
  if (*param_3 == -1) {
    uVar11 = uVar11 & uVar4;
  }
  else if (uVar11 == 0) {
    uVar11 = (uint)(*(char *)(param_1 + 0x1b) == *param_3);
  }
  if ((int)((uint)*(ushort *)(param_1 + 2) << 0x1d) < 0) {
    return uVar11;
  }
  if (uVar9 != 0) {
    return 0;
  }
  if (uVar7 == 0) {
    return (uint)(*(char *)(param_1 + 0x11) == cVar12 || *(char *)(param_1 + 0x11) == '\0');
  }
  return uVar7;
}


