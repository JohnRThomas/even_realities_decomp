/*
 * Function: FUN_0101dc04
 * Entry:    0101dc04
 * Prototype: uint __stdcall FUN_0101dc04(ushort * param_1)
 */


uint FUN_0101dc04(ushort *param_1)

{
  byte bVar1;
  ushort uVar2;
  ushort *puVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  int iVar7;
  int extraout_r1;
  char cVar8;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  undefined4 extraout_r2_03;
  undefined4 extraout_r2_04;
  undefined4 extraout_r2_05;
  undefined4 uVar9;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 extraout_r3_02;
  undefined4 extraout_r3_03;
  undefined4 extraout_r3_04;
  undefined4 uVar10;
  uint uVar11;
  byte local_18 [4];
  byte *local_14;
  
  DAT_21001124 = DAT_21001124 & 0xffffff00;
  DAT_2100112e = 0;
  DAT_2100112c = 0;
  DAT_21001138 = 0;
  DAT_21001128 = param_1;
  FUN_0100b0f8(*param_1);
  FUN_0100b154(*DAT_21001128);
  iVar7 = FUN_0100e41c((int)(DAT_21001128 + 0x54),(int)DAT_21001128,
                       (uint)(ushort)(param_1[0x181] + 1));
  if (iVar7 == 0) {
    param_1[0x181] = 0;
    if ((char)param_1[99] == '&') {
      if (-1 < (int)(((uint)param_1[0x5e] - (uint)param_1[0x18c]) * 0x10000)) {
        *(undefined1 *)(param_1 + 99) = 0;
        bVar6 = FUN_0101c730();
        goto joined_r0x0101ddc0;
      }
    }
    else if ((*(byte *)((int)param_1 + 0xc5) - 0x26 < 3) &&
            (-1 < (int)(((uint)param_1[0x5e] - (uint)param_1[0x18c]) * 0x10000))) {
      *(undefined1 *)((int)param_1 + 0xc5) = 0;
      bVar6 = FUN_0101c730();
joined_r0x0101ddc0:
      if (!bVar6) {
        FUN_0101ced0(0,0);
        return 0;
      }
    }
    if (((char)DAT_21001128[0x80] != '\0') && (DAT_21001128[0x7f] <= DAT_21001128[0x7e])) {
      return 1;
    }
    if (((char)DAT_21001128[0x82] != '\0') && (DAT_21001128[0x7f] <= DAT_21001128[0x81])) {
      return 1;
    }
    if (DAT_21001128[0x7c] <= DAT_21001128[0x7d]) {
      return 1;
    }
    if (*(char *)((int)DAT_21001128 + 0xc9) == '\0') {
      if (5 < DAT_21001128[0x7b]) {
        return 1;
      }
    }
    else if (DAT_21001128[0x7c] <= DAT_21001128[0x7b]) {
      return 1;
    }
    uVar11 = (uint)(byte)DAT_21001128[0xa7];
    if (uVar11 == 0xfe) {
LAB_0101dd7a:
      FUN_0100b980(DAT_21001124,DAT_21001128,0x101cb19,0x101ca35,0x101ced1);
      uVar11 = FUN_0100dbc0((int)(DAT_21001128 + 0x54),5,(uint)*(byte *)((int)DAT_21001128 + 0xc5),0
                           );
      if (uVar11 == 0) {
        return 1;
      }
      FUN_0100b970();
      return uVar11;
    }
    iVar7 = FUN_0100b104(&local_14);
    uVar9 = extraout_r2_00;
    uVar10 = extraout_r3_00;
    if (iVar7 == 0) goto LAB_0101e068;
    FUN_01026284((undefined4 *)local_14,0,0x32);
    pbVar4 = local_14;
    FUN_0100eddc(local_14,3);
    bVar1 = *local_14;
    *local_14 = (byte)(bVar1 & 0xffffffef);
    FUN_0100ee34((uint)local_14,uVar11,extraout_r2_01,bVar1 & 0xffffffef);
    pbVar5 = local_14;
    switch(uVar11) {
    case 0:
      uVar11 = FUN_0100de4c((uint)DAT_21001128[400],*(undefined **)(DAT_21001128 + 0x194));
      pbVar4 = local_14;
      pbVar5[4] = (byte)uVar11;
      uVar11 = FUN_0100de88(*(uint *)(DAT_21001128 + 0x192),*(undefined **)(DAT_21001128 + 0x194));
      pbVar5 = local_14;
      pbVar4[5] = (byte)uVar11;
      pbVar4[6] = (byte)(uVar11 >> 8);
      uVar11 = FUN_0100ddd0(*(uint *)(DAT_21001128 + 0x194));
      pbVar5[7] = (byte)uVar11;
      puVar3 = DAT_21001128;
      pbVar5[8] = (byte)(uVar11 >> 8);
      uVar2 = puVar3[0x196];
      local_14[9] = (byte)uVar2;
      local_14[10] = (byte)(uVar2 >> 8);
      FUN_0100ee8c((int)local_14,(uint)puVar3[0x197]);
      break;
    case 1:
      FUN_0100ef08((int)local_14,(undefined4 *)(*(int *)(DAT_21001128 + 0x188) + 1));
      break;
    case 2:
      local_14[4] = *(byte *)((int)DAT_21001128 + 0x161);
      break;
    case 3:
      FUN_0100ef2c((int)local_14,(undefined4 *)((int)DAT_21001128 + 0x331));
      FUN_0100ef44((int)local_14,(undefined2 *)((int)DAT_21001128 + 0x339));
      FUN_0100ef54((int)local_14,(undefined4 *)((int)DAT_21001128 + 0x34b));
      FUN_0100ef74((int)local_14,(undefined4 *)(DAT_21001128 + 0xa0));
      break;
    default:
      FUN_01009500(0x36,0x8ec,extraout_r2_02,extraout_r3_01);
    case 0x23:
    case 0x24:
    case 0x25:
      (*DAT_210004c8)(uVar11,local_14,&DAT_21001124);
      break;
    case 6:
    case 10:
    case 0xb:
    case 0x12:
    case 0x13:
      break;
    case 7:
      local_14[4] = (byte)DAT_21001128[0xa8];
      break;
    case 8:
      FUN_010108f4((int)local_14);
      break;
    case 9:
      FUN_01010910(0x21001124,(int)local_14);
      break;
    case 0xc:
      local_14[8] = 0x21;
      *(undefined1 **)(local_14 + 4) = &DAT_0200590d;
      break;
    case 0x11:
      if ((char)DAT_21001128[0xa8] == '\0') {
        FUN_0100f0e8((int)local_14,*(undefined1 *)((int)DAT_21001128 + 0x14b));
        FUN_0100f0f0((int)local_14,(char)DAT_21001128[0xa5]);
      }
      else {
        FUN_0100f0e8((int)local_14,*(undefined1 *)((int)DAT_21001128 + 0x14d));
        FUN_0100f0f0((int)local_14,(char)DAT_21001128[0xa6]);
      }
      break;
    case 0x14:
    case 0x15:
      FUN_0100efc0((int)local_14,(uint)DAT_21001128[0x26]);
      FUN_0100efc8((int)local_14,(uint)DAT_21001128[0xa8]);
      FUN_0100efb0((int)local_14,(uint)DAT_21001128[0x28]);
      FUN_0100efb8((int)local_14,(uint)DAT_21001128[0xa9]);
      break;
    case 0x16:
      *(ushort *)(local_14 + 4) = DAT_21001128[0xb7];
      break;
    case 0x18:
      uVar11 = FUN_0102a0a8((uint)*(byte *)((int)DAT_21001128 + 0x31b));
      FUN_0100f0b4((int)pbVar5,(char)uVar11);
      pbVar4 = local_14;
      bVar1 = (byte)DAT_21001128[0x18d];
      if ((((bVar1 & 0xc) == 0) || (((byte)DAT_21001128[0x37] & 0xc) == 0)) ||
         ((uint)bVar1 == (uint)(byte)DAT_21001128[0x37])) {
        uVar11 = FUN_0102a0a8((uint)bVar1);
        FUN_0100f0ac((int)pbVar4,(char)uVar11);
      }
      else {
        uVar11 = FUN_0102a0a8(0);
        FUN_0100f0ac((int)pbVar4,(char)uVar11);
      }
      break;
    case 0x1b:
      local_18[0] = 0;
      FUN_0100edf4(pbVar4,1);
      cVar8 = (char)DAT_21001128[8];
      if (cVar8 == '\x03') {
        cVar8 = '\0';
      }
      local_18[0] = *(byte *)((int)DAT_21001128 + 0x11) & 0x1f | cVar8 << 6 | local_18[0] & 0x20;
      FUN_0100ee08((int)pbVar4,local_18);
      break;
    case 0x1c:
      FUN_0100f008((int)local_14,(undefined4 *)((int)DAT_21001128 + 0x179));
      break;
    case 0x1d:
      FUN_0102a3da((int)local_14);
      break;
    case 0x1e:
      FUN_0102a3ea((int)local_14);
      break;
    case 0x1f:
      if (DAT_210004b4 != (code *)0x0) {
        (*DAT_210004b4)(pbVar4,DAT_21001128);
      }
      break;
    case 0x21:
      if (DAT_210004b0 != (code *)0x0) {
        (*DAT_210004b0)(local_14,DAT_21001128);
      }
      break;
    case 0x22:
      if (DAT_210001e8 != (code *)0x0) {
        (*DAT_210001e8)(local_14,DAT_21001128 + 0xb0);
      }
      break;
    case 0x2a:
      FUN_0100f03c((int)local_14,(undefined4 *)((int)DAT_21001128 + 0x179),
                   (undefined4 *)((int)DAT_21001128 + 0x19b));
    }
    iVar7 = FUN_0100b134();
    uVar9 = extraout_r2_03;
    uVar10 = extraout_r3_02;
    if (iVar7 != 0) {
      bVar1 = local_14[3];
      if (bVar1 == 1) {
        uVar2 = DAT_21001128[0x18b];
        local_14[9] = (byte)uVar2;
        local_14[10] = (byte)(uVar2 >> 8);
      }
      else if (bVar1 == 0) {
        uVar2 = DAT_21001128[399];
        local_14[0xd] = (byte)uVar2;
        local_14[0xe] = (byte)(uVar2 >> 8);
      }
      else if (bVar1 == 0x18) {
        FUN_0100f0bc((int)local_14,(uint)DAT_21001128[0x18c]);
      }
      goto LAB_0101dd7a;
    }
  }
  else {
    FUN_01009500(0x36,0x18e,extraout_r2,extraout_r3);
    uVar9 = extraout_r2_04;
    uVar10 = extraout_r3_03;
LAB_0101e068:
    FUN_01009500(0x36,0x810,uVar9,uVar10);
    uVar9 = extraout_r2_05;
    uVar10 = extraout_r3_04;
  }
  FUN_01009500(0x36,0x8f2,uVar9,uVar10);
  iVar7 = *(int *)((int)&DAT_21001124 + extraout_r1) << 7;
  if (((((char)DAT_21001128[0x80] != '\0') && (DAT_21001128[0x7f] <= DAT_21001128[0x7e])) ||
      (((char)DAT_21001128[0x82] != '\0' && (DAT_21001128[0x7f] <= DAT_21001128[0x81])))) ||
     (uVar11 = (uint)DAT_21001128[0x7c], uVar11 <= DAT_21001128[0x7d])) {
LAB_0101e0da:
    uVar11 = FUN_0101ced0(0,0);
    return uVar11;
  }
  if (*(char *)((int)DAT_21001128 + 0xc9) == '\0') {
    if (5 < DAT_21001128[0x7b]) goto LAB_0101e0da;
  }
  else if (uVar11 <= DAT_21001128[0x7b]) goto LAB_0101e0da;
  if (DAT_21000c8c != 0) {
    if ((char)DAT_21000c6c != '\0') {
      if (DAT_21000c8c != 2) {
        FUN_01009500(0x27,0x224,uVar11,(uint)DAT_21000c8c);
        uVar11 = FUN_0100b434();
        return uVar11;
      }
      iVar7 = FUN_01020fcc(*(uint *)(DAT_21000c70 + 0x2f0));
      goto LAB_0100bdb6;
    }
    if (DAT_21000c8c == 1) goto LAB_0100bdb6;
    FUN_01009500(0x27,0x220,uVar11,(uint)DAT_21000c8c);
  }
  iVar7 = FUN_0100b434();
LAB_0100bdb6:
  if ((*(char *)(DAT_21000c70 + 0x7b) == '\0') && (*(int *)(DAT_21000c70 + 0x74) != 0)) {
    uVar11 = FUN_01023250((uint)*(byte *)(DAT_21000c70 + 0x7a),(uint *)0x0,0,DAT_21000c70);
    return uVar11;
  }
                    /* WARNING: Could not recover jumptable at 0x0100bdc2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar11 = (*(code *)0x101e07d)(iVar7);
  return uVar11;
}


