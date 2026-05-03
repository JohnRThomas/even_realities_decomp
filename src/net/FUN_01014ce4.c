/*
 * Function: FUN_01014ce4
 * Entry:    01014ce4
 * Prototype: uint __stdcall FUN_01014ce4(uint param_1)
 */


uint FUN_01014ce4(uint param_1)

{
  byte bVar1;
  char cVar2;
  code *pcVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  bool bVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  char cVar11;
  char cVar12;
  char cVar13;
  undefined2 uVar14;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 uVar15;
  undefined4 extraout_r2_06;
  undefined4 extraout_r2_07;
  undefined4 extraout_r3;
  int extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 uVar16;
  undefined4 extraout_r3_04;
  byte abStack_18 [4];
  byte *local_14 [2];
  
  iVar7 = FUN_0100b104(local_14);
  if (iVar7 == 0) {
    FUN_01009500(0x31,0x832,extraout_r2,extraout_r3);
    uVar15 = extraout_r2_03;
    uVar16 = extraout_r3_02;
    goto LAB_01014f28;
  }
  FUN_01026284((undefined4 *)local_14[0],0,0x32);
  pbVar5 = local_14[0];
  FUN_0100eddc(local_14[0],3);
  bVar1 = *local_14[0];
  *local_14[0] = (byte)(bVar1 & 0xffffffef);
  FUN_0100ee34((uint)local_14[0],param_1,extraout_r2_00,bVar1 & 0xffffffef);
  iVar7 = extraout_r3_00;
  if (param_1 < 0x2b) {
    if (param_1 < 2) goto switchD_01014d28_caseD_3;
    iVar7 = param_1 - 2;
    switch(iVar7) {
    case 0:
    case 5:
      local_14[0][4] = *(byte *)(DAT_21000f6c + 0x54);
      break;
    default:
      goto switchD_01014d28_caseD_3;
    case 2:
      FUN_0100ef84((int)local_14[0],DAT_21000f6c + 0xc0);
      FUN_0100ef9c((int)local_14[0],DAT_21000f6c + 0x51);
      break;
    case 3:
    case 4:
    case 9:
    case 0x10:
    case 0x11:
      break;
    case 7:
      FUN_01010910(0x21000f68,(int)local_14[0]);
      break;
    case 10:
      local_14[0][8] = 0x21;
      *(undefined1 **)(local_14[0] + 4) = &DAT_0200590d;
      break;
    case 0xb:
      local_14[0][4] = *(byte *)((int)DAT_21000f6c + 0x14a);
      break;
    case 0xc:
      FUN_010108f4((int)local_14[0]);
      break;
    case 0xf:
      FUN_0100f0e8((int)local_14[0],*(undefined1 *)((int)DAT_21000f6c + 0x14b));
      FUN_0100f0f0((int)local_14[0],*(undefined1 *)((int)DAT_21000f6c + 0x14a));
      break;
    case 0x12:
    case 0x13:
      FUN_0100efb0((int)local_14[0],(uint)*(ushort *)(DAT_21000f6c + 0x14));
      FUN_0100efb8((int)local_14[0],(uint)*(ushort *)((int)DAT_21000f6c + 0x152));
      FUN_0100efc0((int)local_14[0],(uint)*(ushort *)(DAT_21000f6c + 0x13));
      FUN_0100efc8((int)local_14[0],(uint)*(ushort *)(DAT_21000f6c + 0x54));
      break;
    case 0x14:
      *(undefined2 *)(local_14[0] + 4) = *(undefined2 *)((int)DAT_21000f6c + 0x16e);
      break;
    case 0x15:
      if (*(char *)(DAT_21000f6c + 0x5b) == '\x01') {
        uVar14 = *(undefined2 *)((int)DAT_21000f6c + 0x16e);
      }
      else {
        uVar14 = *(undefined2 *)((int)DAT_21000f6c + 0x6a);
      }
      *(undefined2 *)(local_14[0] + 4) = uVar14;
      break;
    case 0x19:
      abStack_18[0] = 0;
      FUN_0100edf4(pbVar5,1);
      cVar12 = *(char *)(DAT_21000f6c + 4);
      if (cVar12 == '\x03') {
        cVar12 = '\0';
      }
      abStack_18[0] =
           *(byte *)((int)DAT_21000f6c + 0x11) & 0x1f | cVar12 << 6 | abStack_18[0] & 0x20;
      FUN_0100ee08((int)pbVar5,abStack_18);
      break;
    case 0x1a:
      FUN_0100f008((int)local_14[0],(undefined4 *)((int)DAT_21000f6c + 0x179));
      break;
    case 0x1b:
      FUN_0102a3da((int)local_14[0]);
      break;
    case 0x1c:
      FUN_0102a3ea((int)local_14[0]);
      break;
    case 0x1e:
      if (DAT_210001d4 != (code *)0x0) {
        (*DAT_210001d4)(local_14[0],&DAT_21000f68);
      }
      break;
    case 0x20:
      if (DAT_210001e4 != (code *)0x0) {
        (*DAT_210001e4)(local_14[0],DAT_21000f6c + 0x58);
      }
      break;
    case 0x21:
    case 0x22:
    case 0x23:
      goto code_r0x01014dba;
    case 0x28:
      FUN_0100f03c((int)local_14[0],(undefined4 *)((int)DAT_21000f6c + 0x179),
                   (undefined4 *)((int)DAT_21000f6c + 0x19b));
    }
  }
  else {
    if (param_1 == 0xff) {
      FUN_0100ee5c((int)local_14[0],(undefined4 *)DAT_21000f6c[0xee],
                   (uint)*(byte *)((int)DAT_21000f6c + 0x3b7),DAT_21000f6c);
      goto switchD_01014d28_caseD_5;
    }
switchD_01014d28_caseD_3:
    FUN_01009500(0x31,0x8e4,extraout_r2_01,iVar7);
code_r0x01014dba:
    (*DAT_210001ec)(param_1,local_14[0],&DAT_21000f68);
  }
switchD_01014d28_caseD_5:
  uVar8 = FUN_0100b134();
  uVar15 = extraout_r2_02;
  uVar16 = extraout_r3_01;
  if (uVar8 != 0) {
    return uVar8;
  }
LAB_01014f28:
  FUN_01009500(0x31,0x8e8,uVar15,uVar16);
  puVar4 = DAT_21000f6c;
  cVar12 = *(char *)((int)DAT_21000f6c + 0x3be);
  cVar2 = *(char *)((int)DAT_21000f6c + 0x3bf);
  cVar11 = cVar12;
  if (cVar12 == '\0') {
    cVar11 = *(char *)((int)DAT_21000f6c + 0x6e);
  }
  cVar13 = cVar2;
  if (cVar2 == '\0') {
    cVar13 = *(char *)((int)DAT_21000f6c + 0x6f);
  }
  *(char *)((int)DAT_21000f6c + 0x6f) = cVar13;
  *(char *)((int)puVar4 + 0x6e) = cVar11;
  pcVar3 = DAT_210001f4;
  *(undefined1 *)(puVar4 + 0x1c) = 0xff;
  uVar15 = 0;
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(DAT_21000f6c);
    uVar15 = extraout_r2_04;
  }
  if ((*(char *)(DAT_21000f6c + 0x5b) == '\x01') || (cVar12 != '\0' || cVar2 != '\0')) {
    FUN_01020134(0x21000f68,0,uVar15);
  }
  uVar8 = FUN_0100f8fc((int)(DAT_21000f6c + 0xc));
  bVar6 = FUN_0100f9f8((int)DAT_21000f6c);
  uVar15 = extraout_r2_05;
  uVar16 = extraout_r3_03;
  if (bVar6) {
    FUN_0100fb00(*(undefined2 *)DAT_21000f6c,(int)(DAT_21000f6c + 0xc),
                 (undefined4 *)((int)DAT_21000f6c + 0x1ce));
    uVar15 = extraout_r2_06;
    uVar16 = extraout_r3_04;
  }
  FUN_01014698(DAT_21000f6c,5,uVar15,uVar16);
  uVar9 = FUN_0100f8fc((int)(DAT_21000f6c + 0xc));
  if (uVar8 < uVar9) {
    uVar10 = FUN_01024688();
    uVar9 = uVar9 - uVar8;
    if (uVar9 < 0x76) {
      uVar9 = 0x76;
    }
    uVar8 = FUN_010246a8(uVar9,uVar10,extraout_r2_07);
    return (uint)(uVar8 == 0);
  }
  return 1;
}


