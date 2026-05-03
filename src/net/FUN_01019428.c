/*
 * Function: FUN_01019428
 * Entry:    01019428
 * Prototype: undefined4 __stdcall FUN_01019428(byte * param_1)
 */


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_01019428(byte *param_1)

{
  byte bVar1;
  bool bVar2;
  uint uVar3;
  undefined *puVar4;
  int iVar5;
  undefined1 *extraout_r1;
  undefined1 *extraout_r1_00;
  undefined1 *extraout_r1_01;
  undefined1 *puVar6;
  undefined1 *puVar7;
  undefined1 *extraout_r2;
  uint extraout_r2_00;
  uint uVar8;
  undefined1 *puVar9;
  int unaff_r4;
  undefined4 uVar10;
  uint unaff_r5;
  char cVar11;
  uint unaff_r6;
  uint unaff_r7;
  uint unaff_r8;
  uint unaff_r9;
  undefined4 unaff_lr;
  undefined4 *puVar12;
  undefined4 *puVar13;
  
  iVar5 = FUN_0100df60();
  DAT_2100001c = (char)iVar5;
  if ((*param_1 & 0xf) != 7) {
    FUN_01019ee0();
    return 1;
  }
  iVar5 = 1;
  puVar12 = (undefined4 *)&stack0xfffffffc;
  do {
    *puVar12 = unaff_lr;
    puVar12[-1] = unaff_r9;
    puVar12[-2] = unaff_r8;
    puVar12[-3] = unaff_r7;
    puVar12[-4] = unaff_r6;
    puVar12[-5] = unaff_r5;
    puVar12[-6] = unaff_r4;
    FUN_0101a870(param_1,(byte *)(puVar12 + -0x11));
    if ((byte)DAT_21001039 != 0) {
      puVar12[-0x10] = 0;
      *(byte *)((int)puVar12 + -0x43) = *(byte *)((int)puVar12 + -0x43) & 0xfe;
    }
    if (DAT_21001039._1_1_ != '\0') {
      puVar12[-0xf] = 0;
      *(byte *)((int)puVar12 + -0x43) = *(byte *)((int)puVar12 + -0x43) & 0xfd;
    }
    if ((*(char *)(puVar12 + -0x11) != DAT_21001018) ||
       (((uVar3 = FUN_0101a6b4((ushort *)(puVar12 + -0x11),iVar5), uVar3 == 0 &&
         ((-1 < (int)((uint)*(byte *)((int)puVar12 + -0x43) << 0x1c) ||
          (bVar1 = ((byte *)puVar12[-0xc])[1],
          bVar2 = FUN_0101a6f8((uint)(bVar1 >> 4),(uint)*(byte *)puVar12[-0xc] | (bVar1 & 0xf) << 8)
          , !bVar2)))) || (uVar3 = FUN_01017c6c((int)(puVar12 + -0x11),7,iVar5), _DAT_21001012 == 0)
        ))) {
LAB_01019028:
      uVar10 = 1;
      FUN_01019ee0();
      goto LAB_0101902e;
    }
    *(undefined1 *)((int)puVar12 + -0x47) = 0;
    *(undefined1 *)((int)puVar12 + -0x46) = 0;
    *(undefined1 *)((int)puVar12 + -0x45) = 0;
    if (puVar12[-0xf] == 0) {
      unaff_r7 = 0xff;
      cVar11 = '\0';
      unaff_r8 = 0;
      unaff_r9 = 0;
    }
    else {
      uVar3 = FUN_01017e58((int)(puVar12 + -0x11),(int)puVar12 + -0x46,
                           (char *)((int)puVar12 + -0x47),(byte *)((int)puVar12 + -0x45));
      unaff_r8 = (uint)*(byte *)((int)puVar12 + -0x47);
      unaff_r7 = (uint)DAT_21000fd5;
      if (unaff_r8 != 0) {
        unaff_r7 = unaff_r7 | 2;
      }
      unaff_r9 = (uint)*(byte *)((int)puVar12 + -0x46);
      cVar11 = *(char *)((int)puVar12 + -0x45);
    }
    unaff_r5 = (uint)*(byte *)(puVar12 + -0x11);
    if (unaff_r5 != 1) {
      if (unaff_r5 == 2) {
        if (DAT_21000fe4 != '\x03') {
          puVar7 = (undefined1 *)(uint)*(byte *)((int)puVar12 + -0x43);
          if (((uint)puVar7 & 9) == 9) {
            if (DAT_21000fe4 != '\x02') {
              puVar7 = (undefined1 *)((uint)puVar7 & 2);
              if ((*(byte *)((int)puVar12 + -0x43) & 2) == 0) {
                puVar6 = &DAT_2100001c;
                puVar9 = (undefined1 *)(int)DAT_2100001c;
                if (puVar9 == (undefined1 *)0x7f) goto LAB_010193e8;
                if (DAT_21001000 != '\x05') {
                  if (DAT_21001000 == '\b') {
                    puVar7 = (undefined1 *)0x3;
                  }
                  else {
                    puVar7 = (undefined1 *)0x1;
                  }
                }
                puVar12[-0x15] = puVar9;
                puVar12[-0x14] = puVar7;
                goto LAB_01019326;
              }
              puVar6 = (undefined1 *)0x9;
              if (unaff_r8 == 0) {
                bVar2 = FUN_0100b23c((uint)DAT_21000fd5,(byte *)&DAT_21000fd6,
                                     (uint)*(byte *)((int)puVar12 + -0x32),(byte *)puVar12[-0xf]);
                uVar3 = (uint)bVar2;
                puVar6 = extraout_r1_00;
                if (uVar3 == 0) goto LAB_01019180;
              }
              puVar7 = &DAT_2100001c;
              puVar9 = (undefined1 *)(int)DAT_2100001c;
              if (puVar9 == (undefined1 *)0x7f) goto LAB_010193e8;
              if (DAT_21001000 == '\x05') {
                uVar10 = 0;
              }
              else if (DAT_21001000 == '\b') {
                uVar10 = 3;
              }
              else {
                uVar10 = 1;
              }
              puVar12[-0x14] = uVar10;
              goto LAB_010191f0;
            }
            puVar6 = (undefined1 *)0x9;
            if ((-1 < (int)puVar7 << 0x1e) || (unaff_r8 != 0)) {
LAB_01019368:
              puVar9 = &DAT_2100001c;
              unaff_r5 = (uint)DAT_2100001c;
              if (unaff_r5 == 0x7f) goto LAB_010193e8;
              DAT_2100001c = '\x7f';
              FUN_01016ae0(3);
              puVar12[-0x14] = 1;
              puVar12[-0x17] = (uint)DAT_2100101f;
              puVar12[-0x16] = (uint)DAT_21001009;
              puVar12[-0x15] = unaff_r5;
              uVar3 = FUN_0101a2a0((ushort *)(puVar12 + -0x11),unaff_r7,&DAT_21000fd6,
                                   (uint)DAT_21001049,*(undefined1 *)(puVar12 + -0x17),
                                   *(byte *)(puVar12 + -0x16),*(undefined1 *)(puVar12 + -0x15),
                                   *(char *)(puVar12 + -0x14));
              if ((uVar3 != 0) && (bVar2 = FUN_01029e1a(0x21001014), bVar2)) {
                uVar10 = 0xd;
                goto LAB_0101902e;
              }
              goto LAB_01019132;
            }
            if (cVar11 != '\0') {
              bVar2 = FUN_0100b23c((uint)DAT_21000fd5,(byte *)&DAT_21000fd6,
                                   (uint)*(byte *)((int)puVar12 + -0x32),(byte *)puVar12[-0xf]);
              uVar3 = (uint)bVar2;
              puVar6 = extraout_r1_01;
              puVar7 = extraout_r2;
              if (uVar3 != 0) goto LAB_01019368;
            }
LAB_01019180:
            if ((DAT_21000fe5 - 2 < 2) && (unaff_r9 != 0)) {
              uVar10 = 1;
              FUN_010174c8((ushort *)(puVar12 + -0x11),0xfe);
              goto LAB_0101902e;
            }
          }
        }
      }
      else {
        if (unaff_r5 != 0) goto LAB_01019028;
        if (DAT_21000fe4 != '\x03') {
          if ((int)((uint)*(byte *)((int)puVar12 + -0x43) << 0x1e) < 0) {
            if ((unaff_r8 == 0) &&
               (bVar2 = FUN_0100b23c((uint)DAT_21000fd5,(byte *)&DAT_21000fd6,
                                     (uint)*(byte *)((int)puVar12 + -0x32),(byte *)puVar12[-0xf]),
               !bVar2)) {
              if ((1 < DAT_21000fe5 - 2) || (unaff_r9 == 0)) goto LAB_01019132;
              unaff_r7 = 0xfe;
            }
          }
          else {
            unaff_r7 = 0xff;
          }
          if (((DAT_21001013 != '\0') && (DAT_21000308 != (code *)0x0)) && (puVar12[-10] != 0)) {
            (*DAT_21000308)(puVar12[-10],puVar12[-8]);
          }
          puVar4 = FUN_0101789c((ushort *)(puVar12 + -0x11),unaff_r7);
          if (puVar4 != (undefined *)0x0) {
            uVar10 = 3;
            goto LAB_0101902e;
          }
        }
      }
LAB_01019132:
      uVar10 = 1;
LAB_0101902e:
      if (DAT_2100100c != '\0') {
        FUN_010210b0();
        FUN_010204a8();
        DAT_2100100c = 0;
        return uVar10;
      }
      return uVar10;
    }
    uVar8 = (uint)*(byte *)((int)puVar12 + -0x43);
    puVar6 = (undefined1 *)(uint)(byte)DAT_21001039;
    if ((uVar8 & 9) != 9) {
      if ((puVar6 != (undefined1 *)0x0) && (puVar6 = (undefined1 *)(uVar8 << 0x1c), (int)puVar6 < 0)
         ) {
        if (DAT_21000fe4 == '\x03') goto LAB_01019284;
        goto LAB_0101915a;
      }
      goto LAB_01019132;
    }
    if (DAT_21000fe4 == '\x03') {
      if (((puVar6 != (undefined1 *)0x0) ||
          (bVar2 = FUN_0100b23c((uint)DAT_21001020,(byte *)&DAT_21001019,(uint)DAT_21000feb,
                                (byte *)&DAT_21000fec), DAT_21000fe6 == '\x01')) ||
         ((DAT_21000fe6 == '\0' && ((bVar2 || (DAT_21001008 == DAT_2100100b)))))) {
LAB_01019284:
        if ((((byte *)puVar12[-0xf] == (byte *)0x0) ||
            ((unaff_r8 != 0 ||
             ((cVar11 != '\0' &&
              (bVar2 = FUN_0100b23c((uint)DAT_21000fd5,(byte *)&DAT_21000fd6,
                                    (uint)*(byte *)((int)puVar12 + -0x32),(byte *)puVar12[-0xf]),
              bVar2)))))) && (bVar2 = FUN_01029e1a(0x21001014), bVar2)) {
          uVar10 = 0xe;
          goto LAB_0101902e;
        }
      }
      goto LAB_01019132;
    }
LAB_0101915a:
    puVar9 = (undefined1 *)(uVar8 & 2);
    if ((*(byte *)((int)puVar12 + -0x43) & 2) == 0) {
      puVar6 = &DAT_2100001c;
      puVar7 = (undefined1 *)(int)DAT_2100001c;
      if (puVar7 != (undefined1 *)0x7f) {
        if (DAT_21001000 != '\x05') {
          if (DAT_21001000 == '\b') {
            puVar9 = (undefined1 *)0x3;
          }
          else {
            puVar9 = (undefined1 *)0x1;
          }
        }
        puVar12[-0x15] = puVar7;
        puVar12[-0x14] = puVar9;
LAB_01019326:
        DAT_2100001c = '\x7f';
        puVar12[-0x17] = (uint)DAT_2100101f;
        puVar12[-0x16] = (uint)DAT_21001009;
        uVar3 = FUN_0101a2a0((ushort *)(puVar12 + -0x11),0xff,&DAT_21000fd6,(uint)DAT_21001049,
                             *(undefined1 *)(puVar12 + -0x17),*(byte *)(puVar12 + -0x16),
                             *(undefined1 *)(puVar12 + -0x15),*(char *)(puVar12 + -0x14));
        goto joined_r0x0101933c;
      }
    }
    else {
      if (unaff_r8 == 0) {
        bVar2 = FUN_0100b23c((uint)DAT_21000fd5,(byte *)&DAT_21000fd6,
                             (uint)*(byte *)((int)puVar12 + -0x32),(byte *)puVar12[-0xf]);
        uVar3 = (uint)bVar2;
        puVar6 = extraout_r1;
        if (uVar3 == 0) goto LAB_01019180;
      }
      puVar7 = &DAT_2100001c;
      puVar9 = (undefined1 *)(int)DAT_2100001c;
      if (puVar9 != (undefined1 *)0x7f) {
        if (DAT_21001000 == '\x05') {
          uVar10 = 0;
        }
        else {
          uVar10 = 1;
          if (DAT_21001000 == '\b') {
            uVar10 = 3;
          }
        }
        puVar12[-0x14] = uVar10;
LAB_010191f0:
        DAT_2100001c = '\x7f';
        puVar12[-0x16] = (uint)DAT_21001009;
        puVar12[-0x15] = puVar9;
        puVar12[-0x17] = (uint)DAT_2100101f;
        uVar3 = FUN_0101a2a0((ushort *)(puVar12 + -0x11),unaff_r7,&DAT_21000fd6,(uint)DAT_21001049,
                             *(undefined1 *)(puVar12 + -0x17),*(byte *)(puVar12 + -0x16),
                             *(undefined1 *)(puVar12 + -0x15),*(char *)(puVar12 + -0x14));
joined_r0x0101933c:
        if (uVar3 != 0) {
          uVar10 = 1;
          FUN_01019e60();
          goto LAB_0101902e;
        }
        goto LAB_01019132;
      }
    }
LAB_010193e8:
    param_1 = (byte *)FUN_01017028(uVar3,puVar6,puVar7,puVar9);
    unaff_r6 = extraout_r2_00 >> 0x1f;
    puVar13 = puVar12 + -0x18;
    *puVar13 = 0x10193ed;
    puVar12[-0x19] = (int)extraout_r2_00 >> 0x20;
    iVar5 = FUN_0100df60();
    DAT_2100001c = (char)iVar5;
    if ((*param_1 & 0xf) != 7) {
      FUN_01019ee0();
                    /* WARNING: Could not recover jumptable at 0x01019420. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar10 = (*(code *)*puVar13)(1);
      return uVar10;
    }
    iVar5 = 3;
    unaff_r4 = puVar12[-0x19];
    unaff_lr = *puVar13;
    puVar12 = puVar13;
  } while( true );
}


