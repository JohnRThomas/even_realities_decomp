/*
 * Function: FUN_01026922
 * Entry:    01026922
 * Prototype: uint __stdcall FUN_01026922(undefined4 * param_1, byte * param_2, undefined * param_3)
 */


uint FUN_01026922(undefined4 *param_1,byte *param_2,undefined *param_3)

{
  byte *extraout_r1;
  byte *pbVar1;
  undefined4 uVar2;
  ushort uVar3;
  undefined4 *puVar4;
  uint uVar5;
  byte bVar6;
  undefined1 uVar7;
  undefined *puVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int iVar12;
  uint uVar13;
  undefined4 *puVar11;
  
  puVar8 = (undefined *)(*param_2 - 1);
  pbVar1 = param_2;
  switch(puVar8) {
  case (undefined *)0x0:
    goto switchD_01026934_caseD_1;
  case (undefined *)0x1:
    *param_2 = 0x1a;
    bVar6 = 1;
    goto LAB_010269ae;
  case (undefined *)0x2:
    *param_2 = 0x3e;
    bVar6 = 2;
    break;
  case (undefined *)0x3:
    *(undefined1 *)param_1 = 0x3e;
    *(undefined1 *)((int)param_1 + 2) = 0xd;
    *(byte *)((int)param_1 + 3) = param_2[3];
    *(undefined2 *)(param_1 + 1) = *(undefined2 *)(param_2 + 0xd);
    *(byte *)((int)param_1 + 6) = param_2[4];
    *(undefined4 *)((int)param_1 + 7) = *(undefined4 *)(param_2 + 5);
    *(undefined2 *)((int)param_1 + 0xb) = *(undefined2 *)(param_2 + 9);
    *(byte *)((int)param_1 + 0xd) = param_2[0xf];
    *(byte *)((int)param_1 + 0xe) = param_2[0x10];
    *(byte *)((int)param_1 + 0xf) = param_2[0x11];
    *(byte *)(param_1 + 4) = param_2[0x1d];
    *(byte *)((int)param_1 + 0x11) = param_2[0xc];
    *(undefined2 *)((int)param_1 + 0x12) = *(undefined2 *)(param_2 + 0x14);
    *(byte *)(param_1 + 5) = param_2[0x16];
    *(undefined4 *)((int)param_1 + 0x15) = *(undefined4 *)(param_2 + 0x17);
    *(undefined2 *)((int)param_1 + 0x19) = *(undefined2 *)(param_2 + 0x1b);
    uVar5 = (uint)param_2[0xb];
    *(byte *)((int)param_1 + 0x1b) = param_2[0xb];
    if (0xe4 < uVar5) {
      uVar5 = 0xe5;
    }
    FUN_01026198(param_1 + 7,(undefined4 *)(param_2 + 0x1f),uVar5);
    uVar5 = uVar5 + 0x1a & 0xff;
    goto LAB_01026a74;
  default:
    uVar2 = 0x287;
LAB_010269c2:
    FUN_01009500(199,uVar2,param_3,puVar8);
    pbVar1 = extraout_r1;
    goto switchD_01026934_caseD_1;
  case (undefined *)0x5:
    *param_2 = 0x3e;
    param_2[1] = 4;
    bVar6 = 0x14;
    break;
  case (undefined *)0x6:
    *param_2 = 0x3e;
    param_2[1] = 0xc;
    bVar6 = 4;
    break;
  case (undefined *)0x7:
    *param_2 = 0x3e;
    param_2[1] = 10;
    bVar6 = 3;
    break;
  case (undefined *)0x8:
    *param_2 = 0x3e;
    param_2[1] = 0xd;
    bVar6 = 5;
    break;
  case (undefined *)0x9:
    bVar6 = 5;
    goto LAB_01026b00;
  case (undefined *)0xa:
    bVar6 = 8;
LAB_01026b00:
    *param_2 = bVar6;
    bVar6 = 4;
    goto LAB_010269ae;
  case (undefined *)0xb:
    *param_2 = 0x30;
    bVar6 = 3;
    goto LAB_010269ae;
  case (undefined *)0xc:
    bVar6 = param_2[2];
    *(byte *)((int)param_1 + 2) = bVar6;
    if (bVar6 == 1) {
      uVar3 = 5;
      *(undefined1 *)param_1 = 0x13;
      *(char *)((int)param_1 + 3) = (char)*(undefined2 *)(param_2 + 3);
      *(char *)(param_1 + 1) = (char)((ushort)*(undefined2 *)(param_2 + 3) >> 8);
      *(char *)((int)param_1 + 5) = (char)*(undefined2 *)(param_2 + 5);
      *(char *)((int)param_1 + 6) = (char)((ushort)*(undefined2 *)(param_2 + 5) >> 8);
    }
    else {
      uVar3 = 0;
    }
    goto LAB_01026b86;
  case (undefined *)0xd:
    *param_2 = 0x57;
    bVar6 = 2;
    goto LAB_010269ae;
  case (undefined *)0xe:
    param_3 = (undefined *)(uint)*(ushort *)(param_2 + 3);
    *param_2 = 0xe;
    puVar8 = &DAT_00002083;
    if (param_3 != &DAT_00002083) {
      uVar2 = 0x31;
      goto LAB_010269c2;
    }
    bVar6 = 6;
LAB_010269ae:
    param_2[1] = bVar6;
    goto LAB_010269b0;
  case (undefined *)0x10:
    *param_2 = 0x3e;
    param_2[1] = 0x12;
    bVar6 = 0xb;
    break;
  case (undefined *)0x12:
    uVar5 = FUN_01009b8c(0x29);
    if (uVar5 == 0) {
      uVar5 = FUN_01009b8c(10);
      *(undefined1 *)param_1 = 0x3e;
      if (uVar5 == 0) {
        *(undefined1 *)((int)param_1 + 2) = 1;
        *(byte *)((int)param_1 + 3) = param_2[3];
        *(char *)(param_1 + 1) = (char)*(undefined2 *)(param_2 + 4);
        *(char *)((int)param_1 + 5) = (char)((ushort)*(undefined2 *)(param_2 + 4) >> 8);
        *(byte *)((int)param_1 + 6) = param_2[6];
        *(byte *)((int)param_1 + 7) = param_2[7] & 1;
        param_1[2] = *(undefined4 *)(param_2 + 8);
        *(undefined2 *)(param_1 + 3) = *(undefined2 *)(param_2 + 0xc);
        uVar5 = 0x13;
        *(char *)((int)param_1 + 0xe) = (char)*(undefined2 *)(param_2 + 0x1a);
        *(char *)((int)param_1 + 0xf) = (char)((ushort)*(undefined2 *)(param_2 + 0x1a) >> 8);
        *(char *)(param_1 + 4) = (char)*(undefined2 *)(param_2 + 0x1c);
        *(char *)((int)param_1 + 0x11) = (char)((ushort)*(undefined2 *)(param_2 + 0x1c) >> 8);
        *(char *)((int)param_1 + 0x12) = (char)*(undefined2 *)(param_2 + 0x1e);
        *(char *)((int)param_1 + 0x13) = (char)((ushort)*(undefined2 *)(param_2 + 0x1e) >> 8);
        *(byte *)(param_1 + 5) = param_2[0x20];
      }
      else {
        *(undefined1 *)((int)param_1 + 2) = 10;
        *(byte *)((int)param_1 + 3) = param_2[3];
        *(char *)(param_1 + 1) = (char)*(undefined2 *)(param_2 + 4);
        *(char *)((int)param_1 + 5) = (char)((ushort)*(undefined2 *)(param_2 + 4) >> 8);
        *(byte *)((int)param_1 + 6) = param_2[6];
        *(byte *)((int)param_1 + 7) = param_2[7];
        param_1[2] = *(undefined4 *)(param_2 + 8);
        *(undefined2 *)(param_1 + 3) = *(undefined2 *)(param_2 + 0xc);
        uVar5 = 0x1f;
        *(undefined4 *)((int)param_1 + 0xe) = *(undefined4 *)(param_2 + 0xe);
        *(undefined2 *)((int)param_1 + 0x12) = *(undefined2 *)(param_2 + 0x12);
        param_1[5] = *(undefined4 *)(param_2 + 0x14);
        *(undefined2 *)(param_1 + 6) = *(undefined2 *)(param_2 + 0x18);
        *(char *)((int)param_1 + 0x1a) = (char)*(undefined2 *)(param_2 + 0x1a);
        *(char *)((int)param_1 + 0x1b) = (char)((ushort)*(undefined2 *)(param_2 + 0x1a) >> 8);
        *(char *)(param_1 + 7) = (char)*(undefined2 *)(param_2 + 0x1c);
        *(char *)((int)param_1 + 0x1d) = (char)((ushort)*(undefined2 *)(param_2 + 0x1c) >> 8);
        *(char *)((int)param_1 + 0x1e) = (char)*(undefined2 *)(param_2 + 0x1e);
        *(char *)((int)param_1 + 0x1f) = (char)((ushort)*(undefined2 *)(param_2 + 0x1e) >> 8);
        *(byte *)(param_1 + 8) = param_2[0x20];
      }
      goto LAB_01026a74;
    }
    *param_2 = 0x3e;
    param_2[1] = 0x22;
    bVar6 = 0x29;
    break;
  case (undefined *)0x13:
    uVar5 = 0xb;
    *(undefined1 *)param_1 = 0x3e;
    *(undefined1 *)((int)param_1 + 2) = 7;
    *(char *)((int)param_1 + 3) = (char)*(undefined2 *)(param_2 + 2);
    *(char *)(param_1 + 1) = (char)((ushort)*(undefined2 *)(param_2 + 2) >> 8);
    *(char *)((int)param_1 + 5) = (char)*(undefined2 *)(param_2 + 4);
    *(char *)((int)param_1 + 6) = (char)((ushort)*(undefined2 *)(param_2 + 4) >> 8);
    *(char *)((int)param_1 + 7) = (char)*(undefined2 *)(param_2 + 6);
    *(char *)(param_1 + 2) = (char)((ushort)*(undefined2 *)(param_2 + 6) >> 8);
    *(char *)((int)param_1 + 9) = (char)*(undefined2 *)(param_2 + 8);
    *(char *)((int)param_1 + 10) = (char)((ushort)*(undefined2 *)(param_2 + 8) >> 8);
    *(char *)((int)param_1 + 0xb) = (char)*(undefined2 *)(param_2 + 10);
    *(char *)(param_1 + 3) = (char)((ushort)*(undefined2 *)(param_2 + 10) >> 8);
    goto LAB_01026a74;
  case (undefined *)0x14:
    *param_2 = 0x3e;
    param_2[1] = 6;
    bVar6 = 0xc;
    break;
  case (undefined *)0x15:
    *param_2 = 0x3e;
    param_2[1] = 6;
    bVar6 = 0x12;
    break;
  case (undefined *)0x16:
    *param_2 = 0x3e;
    param_2[1] = 9;
    bVar6 = 0x13;
    break;
  case (undefined *)0x17:
    *param_2 = 0x3e;
    param_2[1] = 1;
    bVar6 = 0x11;
    break;
  case (undefined *)0x19:
    *(undefined1 *)param_1 = 0x3e;
    uVar5 = FUN_01009b8c(0x24);
    if (uVar5 == 0) {
      uVar7 = 0xe;
      uVar5 = 0xf;
    }
    else {
      uVar7 = 0x24;
      uVar5 = 0x13;
    }
    goto LAB_01026c72;
  case (undefined *)0x1b:
    *(undefined1 *)param_1 = 0x3e;
    uVar5 = FUN_01009b8c(0x25);
    if (uVar5 == 0) {
      iVar12 = 7;
      *(undefined1 *)((int)param_1 + 2) = 0xf;
      *(undefined2 *)((int)param_1 + 3) = *(undefined2 *)(param_2 + 2);
      *(byte *)((int)param_1 + 5) = param_2[4];
      *(byte *)((int)param_1 + 6) = param_2[5];
      *(byte *)((int)param_1 + 7) = param_2[6];
      *(byte *)(param_1 + 2) = param_2[10];
      *(byte *)((int)param_1 + 9) = param_2[0xb];
    }
    else {
      iVar12 = 10;
      *(undefined1 *)((int)param_1 + 2) = 0x25;
      *(undefined4 *)((int)param_1 + 3) = *(undefined4 *)(param_2 + 2);
      *(undefined4 *)((int)param_1 + 7) = *(undefined4 *)(param_2 + 6);
      *(undefined2 *)((int)param_1 + 0xb) = *(undefined2 *)(param_2 + 10);
    }
    FUN_01026198((undefined4 *)(iVar12 + 3 + (int)param_1),(undefined4 *)(param_2 + 0xc),
                 (uint)param_2[0xb]);
    uVar5 = param_2[0xb] + 1 + iVar12;
    goto LAB_01026a74;
  case (undefined *)0x1c:
    *param_2 = 0x3e;
    param_2[1] = 3;
    bVar6 = 0x10;
    break;
  case (undefined *)0x1d:
    *param_2 = 0x3e;
    param_2[1] = 5;
    bVar6 = 0x20;
    break;
  case (undefined *)0x1e:
    *param_2 = 0x3e;
    param_2[1] = 9;
    bVar6 = 0x21;
    break;
  case (undefined *)0x20:
    *(undefined1 *)param_1 = 0x3e;
    uVar5 = FUN_01009b8c(0x26);
    if (uVar5 == 0) {
      uVar7 = 0x18;
      uVar5 = 0x13;
    }
    else {
      uVar7 = 0x26;
      uVar5 = 0x17;
    }
LAB_01026c72:
    *(undefined1 *)((int)param_1 + 2) = uVar7;
    FUN_01026198((undefined4 *)((int)param_1 + 3),(undefined4 *)(param_2 + 2),uVar5);
    uVar5 = uVar5 + 1;
    goto LAB_01026a74;
  case (undefined *)0x21:
    *param_2 = 0x3e;
    param_2[1] = 4;
    bVar6 = 0x27;
    break;
  case (undefined *)0x22:
    *(undefined1 *)param_1 = 0x3e;
    uVar5 = 0;
    *(undefined1 *)((int)param_1 + 2) = 0x28;
    puVar4 = (undefined4 *)((int)param_1 + 3);
    *puVar4 = *(undefined4 *)(param_2 + 2);
    for (bVar6 = 0; bVar6 < *(byte *)((int)param_1 + 6); bVar6 = bVar6 + 1) {
      *(undefined4 *)((int)puVar4 + uVar5 + 4) = *(undefined4 *)(param_2 + uVar5 + 6);
      *(undefined2 *)((int)puVar4 + uVar5 + 8) = *(undefined2 *)(param_2 + uVar5 + 10);
      uVar13 = (uint)*(byte *)((int)puVar4 + uVar5 + 9);
      FUN_01026198((undefined4 *)((int)puVar4 + uVar5 + 10),(undefined4 *)(param_2 + uVar5 + 0xc),
                   uVar13);
      uVar5 = uVar5 + uVar13 + 6 & 0xffff;
    }
    uVar3 = (short)uVar5 + 5;
LAB_01026b86:
    uVar5 = (uint)uVar3;
    if (uVar5 != 0) goto LAB_01026a74;
    goto LAB_010269b0;
  case (undefined *)0x23:
    *param_2 = 0x3e;
    param_2[1] = 0x1d;
    bVar6 = 0x19;
    break;
  case (undefined *)0x24:
    *param_2 = 0x3e;
    param_2[1] = 7;
    bVar6 = 0x1a;
    break;
  case (undefined *)0x25:
    *param_2 = 0x3e;
    param_2[1] = 5;
    bVar6 = 0x1f;
    break;
  case (undefined *)0x26:
    *param_2 = 0x3e;
    param_2[1] = 0x14;
    bVar6 = 0x22;
    break;
  case (undefined *)0x27:
    *param_2 = 0x3e;
    param_2[1] = param_2[0x14] * '\x02' + 0x13;
    bVar6 = 0x1b;
    break;
  case (undefined *)0x28:
    *param_2 = 0x3e;
    param_2[1] = 3;
    bVar6 = 0x1c;
    break;
  case (undefined *)0x29:
    *param_2 = 0x3e;
    param_2[1] = param_2[0x10] * '\x02' + 0xf;
    bVar6 = 0x1d;
    break;
  case (undefined *)0x2a:
    *param_2 = 0x3e;
    param_2[1] = 3;
    bVar6 = 0x1e;
    break;
  case (undefined *)0x2b:
  case (undefined *)0x2c:
    *param_2 = 0x3e;
    goto LAB_010269b0;
  case (undefined *)0x2d:
    *param_2 = 0xff;
    param_2[1] = 5;
    bVar6 = 0xa4;
    break;
  case (undefined *)0x2e:
    *param_2 = 0xff;
    param_2[1] = 0xb;
    bVar6 = 0xa2;
    break;
  case (undefined *)0x2f:
    *param_2 = 0xff;
    param_2[1] = 5;
    bVar6 = 0xa3;
    break;
  case (undefined *)0x30:
    *(undefined1 *)param_1 = 0xff;
    *(undefined1 *)((int)param_1 + 2) = 0x81;
    puVar9 = *(undefined4 **)(param_2 + 3);
    puVar4 = (undefined4 *)((int)param_1 + 3);
    puVar10 = puVar9;
    do {
      puVar11 = puVar10 + 1;
      *puVar4 = *puVar10;
      puVar4 = puVar4 + 1;
      puVar10 = puVar11;
    } while (puVar11 != puVar9 + 10);
    uVar5 = 0x29;
LAB_01026a74:
    *(char *)((int)param_1 + 1) = (char)uVar5;
    return uVar5 + 2 & 0xffff;
  case (undefined *)0x31:
    *param_2 = 0xff;
    param_2[1] = 0xd;
    bVar6 = 0x80;
  }
  param_2[2] = bVar6;
LAB_010269b0:
  bVar6 = param_2[1];
  FUN_01026198(param_1,(undefined4 *)param_2,bVar6 + 2);
  return bVar6 + 2;
switchD_01026934_caseD_1:
  *pbVar1 = 0xc;
  bVar6 = 8;
  goto LAB_010269ae;
}


