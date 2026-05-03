/*
 * Function: FUN_01017c6c
 * Entry:    01017c6c
 * Prototype: undefined __stdcall FUN_01017c6c(int param_1, uint param_2, int param_3)
 */


/* WARNING: Removing unreachable block (ram,0x01017f16) */
/* WARNING: Removing unreachable block (ram,0x01017eaa) */
/* WARNING: Removing unreachable block (ram,0x01017f26) */
/* WARNING: Removing unreachable block (ram,0x01017eb2) */
/* WARNING: Removing unreachable block (ram,0x01017ede) */
/* WARNING: Removing unreachable block (ram,0x01017ee4) */
/* WARNING: Removing unreachable block (ram,0x01017ef6) */
/* WARNING: Removing unreachable block (ram,0x01017f36) */
/* WARNING: Removing unreachable block (ram,0x01017f00) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_01017c6c(int param_1,uint param_2,int param_3)

{
  char cVar1;
  char cVar2;
  undefined1 uVar3;
  byte bVar4;
  bool bVar5;
  byte bVar6;
  int iVar7;
  uint uVar8;
  undefined4 extraout_r2;
  undefined1 *extraout_r2_00;
  undefined4 extraout_r3;
  undefined4 *puVar9;
  byte *extraout_r3_00;
  byte local_21;
  uint auStack_20 [2];
  
  if (param_2 == 7) {
    iVar7 = *(int *)(param_1 + 4);
    if (iVar7 == 0 && param_3 == 0) {
      _DAT_21001012 = CONCAT11(DAT_21001013,1);
      if (DAT_2100103b == '\0') {
        MasterStackPointer = 0x3d;
        return;
      }
      bVar5 = FUN_0102a324(DAT_2100103c + 0x50);
      if (bVar5) {
        return;
      }
      _DAT_21001012 = CONCAT11(1,DAT_21001012);
      return;
    }
    cVar2 = '\0';
    if (iVar7 != 0) {
      if ((((*(char *)(param_1 + 0x11) == '\x01') && ((*(byte *)(iVar7 + 5) & 0xc0) == 0x40)) &&
          (DAT_2100100c != '\0')) &&
         (((param_3 != 0 || (DAT_21001049 != '\x01')) ||
          (DAT_2100100c = FUN_0100d2d4(iVar7,1), DAT_2100100c != '\0')))) goto LAB_01017d42;
LAB_01017ca0:
      uVar8 = (uint)DAT_21001008;
joined_r0x01017ca6:
      if (uVar8 == 0xff) {
                    /* WARNING: Read-only address (ram,0x00000000) is written */
        cVar2 = FUN_01011090((uint)*(byte *)(param_1 + 0x11),*(uint **)(param_1 + 4));
        bVar4 = FUN_0100c45c((uint)*(byte *)(param_1 + 0x11),*(byte **)(param_1 + 4),&DAT_21001008);
        if (bVar4 == 0) {
          _DAT_21001012 = 0;
          return;
        }
      }
      else {
                    /* WARNING: Read-only address (ram,0x00000000) is written */
        iVar7 = FUN_0100d298(uVar8,&local_21,auStack_20);
        if (iVar7 == 0) {
          FUN_01009500(0x32,0xd21,extraout_r2,extraout_r3);
          bVar4 = DAT_2100100d ^ 1;
          if (DAT_2100100c != '\0') {
            if ((DAT_21000fe4 != '\x03') || (bVar6 = DAT_2100100b, DAT_21000fdd == '\0')) {
              if ((_Reset == 0) && (bVar5 = FUN_0101a1cc(), !bVar5)) goto LAB_01017ebe;
              bVar6 = DAT_21001008;
            }
            uVar8 = (uint)bVar6;
            if (((uVar8 != 0xff) && (uVar8 != 8)) && (bVar6 = FUN_0100c404(uVar8), bVar6 != 0)) {
              bVar4 = bVar6;
            }
          }
LAB_01017ebe:
          *extraout_r2_00 = 0;
          MasterStackPointer = 0;
                    /* WARNING: Read-only address (ram,0x00000000) is written */
          *extraout_r3_00 = bVar4;
          return;
        }
        cVar2 = FUN_01011090((uint)local_21,auStack_20);
      }
      goto LAB_01017cc4;
    }
    if (param_3 == 0) {
LAB_01017d8e:
      if ((int)((uint)*(byte *)(param_1 + 1) << 0x1b) < 0) goto LAB_01017d94;
    }
    else {
LAB_01017e0c:
      if (DAT_21001012 == '\0') goto LAB_01017d9c;
      if (*(int *)(param_1 + 4) != 0) goto LAB_01017ccc;
    }
    cVar1 = DAT_21000fdd;
    bVar5 = FUN_0101a1cc();
    if (((!bVar5) || (cVar2 = DAT_21001012, DAT_21001012 == '\0')) && (cVar2 = cVar1, cVar1 == '\0')
       ) {
      cVar2 = FUN_0100c450();
    }
  }
  else {
    if (*(int *)(param_1 + 4) != 0) {
      if (((*(char *)(param_1 + 0x11) != '\x01') ||
          ((*(byte *)(*(int *)(param_1 + 4) + 5) & 0xc0) != 0x40)) || (DAT_2100100c == '\0'))
      goto LAB_01017ca0;
LAB_01017d42:
      uVar8 = FUN_0100d310();
      _DAT_21001008 = (ushort)uVar8 & 0xff | (ushort)((uVar8 & 0xff) << 8);
      DAT_21001010 = 1;
      goto joined_r0x01017ca6;
    }
    cVar2 = '\0';
LAB_01017cc4:
    if (6 < param_2) {
      if (8 < param_2) {
LAB_01017d9c:
        cVar2 = '\0';
        goto LAB_01017cd0;
      }
      if (param_3 != 0) goto LAB_01017e0c;
      if (*(int *)(param_1 + 4) == 0) goto LAB_01017d8e;
    }
LAB_01017ccc:
    if (DAT_21000fdd == '\0') goto LAB_01017cd0;
LAB_01017d94:
    cVar2 = '\x01';
  }
LAB_01017cd0:
  _DAT_21001012 = CONCAT11(DAT_21001013,cVar2);
  if (DAT_21000214 != (code *)0x0) {
    uVar3 = (*DAT_21000214)(param_1,param_3);
    _DAT_21001012 = CONCAT11(uVar3,DAT_21001012);
  }
  puVar9 = *(undefined4 **)(param_1 + 4);
  if (puVar9 != (undefined4 *)0x0) {
    DAT_21001020 = *(undefined1 *)(param_1 + 0x11);
    DAT_21001019 = *puVar9;
    DAT_2100101d = *(undefined2 *)(puVar9 + 1);
  }
  if ((*(int *)(param_1 + 8) != 0) && (param_2 == 7)) {
    if ((DAT_21001008 != 0xff) && (_DAT_21001012 != 0)) {
      FUN_0100d328(*(int *)(param_1 + 8),(uint)DAT_21001008);
      DAT_21001011 = 1;
    }
  }
                    /* WARNING: Read-only address (ram,0x00000000) is written */
  return;
}


