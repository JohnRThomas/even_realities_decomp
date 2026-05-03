/*
 * Function: FUN_01020194
 * Entry:    01020194
 * Prototype: undefined4 __stdcall FUN_01020194(int param_1, int param_2, undefined4 param_3)
 */


undefined4 FUN_01020194(int param_1,int param_2,undefined4 param_3)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  undefined2 uVar5;
  uint uVar6;
  uint extraout_r1;
  undefined4 uVar7;
  uint uVar8;
  undefined4 extraout_r2;
  undefined1 uVar9;
  uint uVar10;
  undefined1 *puVar11;
  int iVar12;
  undefined4 local_24;
  undefined4 uStack_20;
  
  puVar11 = *(undefined1 **)(param_1 + 4);
  cVar1 = puVar11[0xc5];
  local_24 = param_2;
  uStack_20 = param_3;
  if (puVar11[0xc6] != '$') goto LAB_01020204;
  puVar11 = puVar11 + 0xc6;
  do {
    bVar2 = FUN_0100f0c8(param_2);
    if (bVar2) {
      bVar3 = FUN_0100f0b0(param_2);
      bVar4 = FUN_0100f0b8(param_2);
      uVar6 = FUN_01029f1e((uint)bVar4);
      iVar12 = *(int *)(param_1 + 4);
      if ((uVar6 == 0) || (uVar10 = (uint)*(byte *)(iVar12 + 0x6e), uVar6 == uVar10))
      goto LAB_01020222;
      if (*(char *)(iVar12 + 0x16c) == '\x01') {
        bVar4 = *(byte *)(iVar12 + 0x16e);
      }
      else {
        bVar4 = *(byte *)(iVar12 + 0x6a);
      }
      if ((extraout_r1 & bVar4) == 0) goto LAB_01020252;
      if ((cVar1 == '\"') || (uVar8 = (uint)*(byte *)(iVar12 + 0x67), (extraout_r1 & uVar8) != 0)) {
LAB_01020222:
        uVar6 = FUN_01029f1e((uint)bVar3);
        if ((uVar6 != 0) && (*(byte *)(iVar12 + 0x6f) != uVar6)) {
          if (*(char *)(iVar12 + 0x16c) == '\x01') {
            bVar4 = *(byte *)(iVar12 + 0x16f);
          }
          else {
            bVar4 = *(byte *)(iVar12 + 0x6b);
          }
          if ((bVar3 & bVar4) == 0) goto LAB_01020252;
        }
        bVar2 = FUN_01029fb4(iVar12,param_2,(undefined1 *)&local_24);
        iVar12 = *(int *)(param_1 + 4);
        if (bVar2) {
          uVar5 = FUN_0100f0c4(param_2);
          *(undefined2 *)(iVar12 + 0x3bc) = uVar5;
          iVar12 = *(int *)(param_1 + 4);
          if ((ushort)((*(short *)(iVar12 + 0x3bc) + -1) - *(short *)(iVar12 + 0xbc)) < 0x7ffe) {
            if ((*(byte *)(iVar12 + 0xc6) != 0xe) && (1 < *(byte *)(iVar12 + 0xc6) - 0xb)) {
              *(undefined1 *)(iVar12 + 0x3be) = (undefined1)local_24;
              *(undefined1 *)(iVar12 + 0x3bf) = local_24._1_1_;
              *puVar11 = 0x26;
              goto LAB_0102030c;
            }
            uVar9 = 0x2a;
          }
          else {
            uVar9 = 0x28;
          }
          *(undefined1 *)(iVar12 + 0xe5) = uVar9;
          FUN_0100f788((undefined4 *)(iVar12 + 0xdc),&BYTE_010100a1,2);
        }
        else {
          if (*(char *)(iVar12 + 0x16c) == '\x01') {
            iVar12 = FUN_0102a082((uint)*(ushort *)(iVar12 + 0x170),(uint)*(byte *)(iVar12 + 0x6e),
                                  (undefined2 *)(iVar12 + 0x3bc),*(undefined2 *)(iVar12 + 0xbc));
            if (iVar12 == 0) {
              FUN_01020134(param_1,0,extraout_r2);
              *puVar11 = 0;
            }
            else {
              *(undefined1 *)(*(int *)(param_1 + 4) + 0xc5) = 0x28;
            }
          }
          else {
            *(undefined1 *)(iVar12 + 0x16c) = 0;
          }
          if (puVar11 == (undefined1 *)(*(int *)(param_1 + 4) + 0xc6)) {
            *(undefined1 *)(*(int *)(param_1 + 4) + 0xc6) = 0;
          }
        }
LAB_0102030c:
        if (puVar11 == (undefined1 *)(*(int *)(param_1 + 4) + 0xc6)) {
          FUN_0100ffb0(param_1);
        }
        else {
          *(undefined1 *)(*(int *)(param_1 + 4) + 0x100) = 0;
        }
        return 0;
      }
      if (uVar10 != 0) {
        if ((((uVar10 == 4) || (uVar6 == 4)) || (uVar10 == 8)) || (uVar6 == 8)) {
          if (uVar10 < uVar6) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
        }
        else {
          bVar2 = uVar6 < uVar10;
        }
        if (bVar2) goto LAB_01020252;
        goto LAB_01020222;
      }
      uVar7 = 0x178;
      uVar6 = 6;
      iVar12 = 0;
    }
    else {
LAB_01020252:
      if (*(char *)(*(int *)(param_1 + 4) + 0x16c) == '\x01') {
        FUN_01020134(param_1,0x1e,1);
      }
      else {
        *(undefined1 *)(*(int *)(param_1 + 4) + 0x16c) = 0;
      }
      if (cVar1 != '\"') {
        *puVar11 = 0;
        FUN_0100ffb0(param_1);
        uVar7 = FUN_01010034(param_1,param_2);
        return uVar7;
      }
      uVar8 = (uint)*(byte *)(param_2 + 3);
      iVar12 = *(int *)(param_1 + 4);
      *(byte *)(iVar12 + 0x149) = *(byte *)(param_2 + 3);
      if (uVar8 == 0x18) {
        uVar8 = 10;
        *(undefined1 *)(iVar12 + 0xc5) = 10;
        if (*(char *)(iVar12 + 0x100) != '\0') {
          return 0;
        }
        uVar7 = 0x275;
        iVar12 = 0;
      }
      else {
        uVar7 = 0x26d;
      }
      uVar6 = 0x7e;
    }
    FUN_01009500(uVar6,uVar7,uVar8,iVar12);
LAB_01020204:
    if (cVar1 != '\"') {
      return 2;
    }
    puVar11 = puVar11 + 0xc5;
  } while( true );
}


