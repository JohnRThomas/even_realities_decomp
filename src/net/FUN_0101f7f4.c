/*
 * Function: FUN_0101f7f4
 * Entry:    0101f7f4
 * Prototype: int __stdcall FUN_0101f7f4(void)
 */


int FUN_0101f7f4(void)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  ushort *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 extraout_r1;
  undefined4 *extraout_r1_00;
  uint uVar7;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  byte *unaff_r4;
  byte *unaff_r5;
  uint unaff_r6;
  byte *pbVar8;
  uint *unaff_r7;
  uint unaff_r8;
  uint unaff_r9;
  uint unaff_r10;
  uint unaff_r11;
  ushort in_stack_00000012;
  byte in_stack_00000014;
  undefined4 in_stack_00000018;
  undefined4 in_stack_0000001c;
  undefined4 in_stack_00000020;
  undefined4 in_stack_00000024;
  int in_stack_00000028;
  undefined4 in_stack_0000002c;
  
  do {
    if (unaff_r11 == unaff_r10) {
      if (unaff_r6 == 1) {
        uVar5 = unaff_r7[3];
        if (0x270f9a7 < uVar5 - 1000) {
          return 0x30;
        }
        if (0x270f9a7 < *unaff_r7 - 1000) {
          return 0x30;
        }
        if (*unaff_r7 < uVar5) {
          return 0x12;
        }
        unaff_r8 = unaff_r8 + uVar5;
      }
    }
    else {
      if (*unaff_r7 < unaff_r7[3]) {
        return 0x12;
      }
      unaff_r8 = unaff_r8 + unaff_r7[3];
      bVar2 = FUN_0101ed30(0,(uint)*(ushort *)(unaff_r5 + 2),(uint)*(ushort *)(unaff_r5 + 8),
                           (uint)*(ushort *)(unaff_r5 + 0xe),*(ushort *)(unaff_r5 + 0x14),
                           *(ushort *)(unaff_r5 + 0x1a),*(ushort *)(unaff_r5 + 0x20));
      if (!bVar2) {
        return 0x30;
      }
      if (unaff_r10 != 0) {
        if (*(short *)(unaff_r5 + 2) != *(short *)unaff_r5) {
          return 0x12;
        }
        if (*(short *)(unaff_r5 + 8) != *(short *)(unaff_r5 + 6)) {
          return 0x12;
        }
        if (*(short *)(unaff_r5 + 0xe) != *(short *)(unaff_r5 + 0xc)) {
          return 0x12;
        }
        if (*(short *)(unaff_r5 + 0x14) != *(short *)(unaff_r5 + 0x12)) {
          return 0x12;
        }
      }
    }
    unaff_r5 = unaff_r5 + 2;
    unaff_r7 = unaff_r7 + 1;
    unaff_r9 = unaff_r9 + 1;
    while (unaff_r10 = unaff_r9 & 0xff, unaff_r6 <= unaff_r10) {
      if (*(uint *)(unaff_r4 + 0xc) < unaff_r8) {
        return 0x12;
      }
      if (1 < *unaff_r4) {
        return 0x12;
      }
      if ((*unaff_r4 == 0) && (1 < unaff_r4[2])) {
        return 0x12;
      }
      if (3 < unaff_r4[1]) {
        return 0x12;
      }
      if (6 < unaff_r4[0x4c] - 1) {
        return 0x12;
      }
      bVar2 = FUN_01028ba4();
      if (bVar2) {
        return 0xc;
      }
      iVar3 = func_0x0101946c();
      if ((iVar3 != 0) || (bVar2 = FUN_01019458(), bVar2)) {
        return 0x3a;
      }
      if (*(uint *)(unaff_r4 + 0x18) < 0xf42401) {
        *(uint *)(unaff_r4 + 0x18) = *(uint *)(unaff_r4 + 0x18);
      }
      else {
        unaff_r4[0x18] = 0;
        unaff_r4[0x19] = 0x24;
        unaff_r4[0x1a] = 0xf4;
        unaff_r4[0x1b] = 0;
      }
      if (*(uint *)(unaff_r4 + 0x1c) < 0xf42401) {
        *(uint *)(unaff_r4 + 0x1c) = *(uint *)(unaff_r4 + 0x1c);
      }
      else {
        unaff_r4[0x1c] = 0;
        unaff_r4[0x1d] = 0x24;
        unaff_r4[0x1e] = 0xf4;
        unaff_r4[0x1f] = 0;
      }
      if (*(uint *)(unaff_r4 + 0x20) < 0xf42401) {
        *(uint *)(unaff_r4 + 0x20) = *(uint *)(unaff_r4 + 0x20);
      }
      else {
        unaff_r4[0x20] = 0;
        unaff_r4[0x21] = 0x24;
        unaff_r4[0x22] = 0xf4;
        unaff_r4[0x23] = 0;
      }
      puVar4 = (ushort *)FUN_0100a3c4(&stack0x00000012,0);
      if (puVar4 == (ushort *)0x0) {
        return 0xd;
      }
      uVar5 = FUN_0101eeac(puVar4,in_stack_00000012,(int)unaff_r4,1);
      if ((uVar5 == 0) &&
         (uVar5 = FUN_0101c3ec((uint)puVar4,extraout_r1,extraout_r2,extraout_r3), uVar5 == 0)) {
        pbVar8 = unaff_r4 + 3;
        FUN_0101971c(unaff_r4[1]);
        cVar1 = FUN_010196b4((uint)*unaff_r4,(uint)unaff_r4[2],pbVar8);
        if (cVar1 == '\0') {
          uVar5 = 0x12;
        }
        else {
          FUN_01019728();
          uVar5 = func_0x010197d4(*unaff_r4,unaff_r4[2],pbVar8);
          if (uVar5 == 0) {
            uVar5 = (uint)unaff_r4[9];
            if (uVar5 != 2) {
              uVar6 = FUN_010200d8();
              uVar5 = FUN_01028aac(uVar6 & uVar5 & 5);
            }
            uVar5 = FUN_01019640(uVar5);
            if (uVar5 == 0) {
              uVar5 = FUN_01019850(3,puVar4);
              bVar2 = FUN_01028a96((uint)unaff_r4[2]);
              FUN_01019814(bVar2,extraout_r1_00,extraout_r2_00,extraout_r3_00);
              if (uVar5 == 0) {
                if ((*unaff_r4 == 0) &&
                   (bVar2 = FUN_01028c12((int)puVar4,(uint)unaff_r4[2],pbVar8), bVar2)) {
                  uVar5 = 0xb;
                }
                else {
                  uVar5 = func_0x01019868(1);
                  if ((uVar5 == 0) && (uVar5 = func_0x01019878(1), uVar5 == 0)) {
                    uVar5 = (uint)unaff_r4[9];
                    uVar6 = uVar5 & 1;
                    in_stack_00000014 = (unaff_r4[9] & 1) != 0;
                    if ((bool)in_stack_00000014) {
                      in_stack_00000018 = *(undefined4 *)(unaff_r4 + 0xc);
                      in_stack_0000001c = *(undefined4 *)(unaff_r4 + 0x18);
                    }
                    uVar7 = uVar5 << 0x1e;
                    if ((int)uVar7 < 0) {
                      if (uVar5 == 2) {
                        in_stack_00000020 = *(undefined4 *)(unaff_r4 + 0xc);
                        in_stack_00000024 = *(undefined4 *)(unaff_r4 + 0x18);
                        uVar7 = in_stack_00000014 | 2;
                        in_stack_00000014 = (byte)uVar7;
                      }
                      uVar6 = uVar6 + 1;
                    }
                    iVar3 = uVar5 << 0x1d;
                    if (iVar3 < 0) {
                      iVar3 = *(int *)(unaff_r4 + uVar6 * 4 + 0xc);
                      in_stack_0000002c = *(undefined4 *)(unaff_r4 + uVar6 * 4 + 0x18);
                      uVar6 = in_stack_00000014 | 4;
                      in_stack_00000014 = (byte)uVar6;
                      in_stack_00000028 = iVar3;
                    }
                    uVar5 = FUN_0101b7a8(&stack0x00000014,uVar7,iVar3,uVar6);
                    FUN_010196a8(unaff_r4[0x48] != 0);
                    FUN_01019634(unaff_r4[0x4c]);
                    if (((uVar5 == 0) && (uVar5 = func_0x01019918(), uVar5 == 0)) &&
                       (uVar5 = FUN_0101b6e0((int)puVar4,(uint *)(uint)*(ushort *)(unaff_r4 + 0x4a))
                       , uVar5 == 0)) {
                      return 0;
                    }
                  }
                }
              }
            }
          }
        }
      }
      FUN_0100b0dc((uint)*puVar4);
      iVar3 = FUN_0100a564(*puVar4,0);
      if (iVar3 == 0) {
        return uVar5;
      }
      FUN_01009500(0x39,&DAT_00001255,extraout_r2_01,extraout_r3_01);
      unaff_r6 = 1;
      if ((int)(uVar5 << 0x1e) < 0) {
        unaff_r11 = 1;
        unaff_r6 = 2;
      }
      else {
        unaff_r11 = 0xff;
      }
      if ((int)(uVar5 << 0x1d) < 0) {
        if (0x270f3cb < *(int *)(unaff_r4 + (unaff_r6 + 6) * 4) - 0x9c4U) {
          return 0x30;
        }
        unaff_r6 = unaff_r6 + 1;
      }
      unaff_r5 = unaff_r4 + 0x22;
      unaff_r7 = (uint *)(unaff_r4 + 0xc);
      unaff_r8 = 0;
      unaff_r9 = 0;
    }
  } while( true );
}


