/*
 * Function: FUN_0102c3ac
 * Entry:    0102c3ac
 * Prototype: byte * __stdcall FUN_0102c3ac(undefined4 * param_1, byte * param_2, uint param_3, char * param_4, undefined4 * param_5)
 */


byte * FUN_0102c3ac(undefined4 *param_1,byte *param_2,uint param_3,char *param_4,undefined4 *param_5
                   )

{
  bool bVar1;
  byte bVar2;
  char cVar3;
  undefined4 uVar4;
  byte *pbVar5;
  byte *extraout_r1;
  byte bVar6;
  char *pcVar7;
  uint uVar8;
  uint uVar9;
  uint extraout_r3;
  undefined4 *puVar10;
  byte *pbVar11;
  byte *pbVar12;
  uint uVar13;
  int iVar14;
  undefined4 *puVar15;
  undefined4 *puVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  char *local_68;
  int local_54;
  byte local_48 [16];
  byte abStack_38 [20];
  
  uVar8 = param_3 & 4;
  local_54 = ((param_3 << 0x1a) >> 0x1d) + 1;
  if (((uint)param_1 & 3) != 0) {
    return (byte *)0xfffffff2;
  }
  if (param_1 == (undefined4 *)0x0) {
    puVar16 = (undefined4 *)((uint)param_2 & 7);
    param_2 = (byte *)(8 - (int)puVar16);
  }
  else {
    puVar16 = param_1;
    if (param_2 < &NMI) {
      return (byte *)0xffffffe4;
    }
  }
  pbVar11 = (byte *)(puVar16 + 1);
  iVar14 = 0;
  uVar17 = 4;
  pbVar5 = (byte *)(param_4 + -1);
  uVar13 = 0;
  bVar6 = 0xff;
  uVar18 = 0;
  uVar9 = 4;
  cVar3 = '\0';
  local_68 = param_4;
LAB_0102c40a:
  if (param_1 != (undefined4 *)0x0) {
    *(char **)pbVar11 = local_68;
  }
  puVar16 = param_5;
  uVar19 = uVar18;
  if ((local_54 < 1) && ((local_68 <= "" || (&UNK_0103eca8 <= local_68)))) {
    uVar20 = (int)pbVar11 - (int)param_1;
    bVar2 = (byte)(uVar20 >> 2);
    if (-1 < (int)(param_3 << 0x1e)) goto LAB_0102c5f4;
    bVar1 = false;
  }
  else {
    if (-1 < (int)(param_3 << 0x1e)) goto LAB_0102c656;
    bVar1 = true;
    uVar20 = (int)pbVar11 - (int)param_1;
    bVar2 = (byte)(uVar20 >> 2);
  }
  if (uVar20 < 0x200) {
    if (0xf < uVar13) goto LAB_0102c61a;
    if (param_1 != (undefined4 *)0x0) {
      local_48[uVar13] = bVar2;
      abStack_38[uVar13] = bVar6;
      if (!bVar1) goto LAB_0102c60e;
      local_48[uVar13] = bVar2 | 0x80;
      iVar14 = iVar14 + 1;
      goto LAB_0102c654;
    }
    if (!bVar1) goto LAB_0102c680;
    param_2 = param_2 + 1;
    goto LAB_0102c654;
  }
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/cbprintf_packaged.c",
               0x27b,uVar9);
LAB_0102c5ee:
  do {
    while( true ) {
      uVar4 = FUN_0103a370();
      bVar2 = (byte)uVar4;
      pbVar5 = extraout_r1;
      uVar9 = extraout_r3;
LAB_0102c5f4:
      if (uVar13 < 0x10) break;
LAB_0102c61a:
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                   "WEST_TOPDIR/zephyr/lib/os/cbprintf_packaged.c",0x280,uVar9);
    }
    param_5 = puVar16;
    uVar18 = uVar19;
    if (param_1 == (undefined4 *)0x0) {
LAB_0102c680:
      param_2 = param_2 + 2;
      if (uVar8 == 0) {
        pcVar7 = FUN_0102aa68(local_68);
        param_2 = param_2 + (int)pcVar7;
      }
    }
    else {
      local_48[uVar13] = bVar2;
      abStack_38[uVar13] = bVar6;
LAB_0102c60e:
      cVar3 = cVar3 + '\x01';
    }
LAB_0102c654:
    uVar13 = uVar13 + 1;
    puVar16 = param_5;
LAB_0102c656:
    pbVar11 = pbVar11 + 4;
    uVar19 = uVar18;
switchD_0102c46a_caseD_4c:
    pbVar12 = pbVar5;
    pbVar5 = pbVar12 + 1;
    bVar2 = *pbVar5;
    if (bVar2 != 0) {
      if (uVar19 == 0) break;
      if (bVar2 < 0x7b) {
        if (0x4b < bVar2) {
          switch(bVar2) {
          case 0x4c:
          case 0x68:
          case 0x6c:
            break;
          default:
            goto switchD_0102c46a_caseD_4d;
          case 0x58:
          case 99:
          case 100:
          case 0x69:
          case 0x6f:
          case 0x75:
          case 0x78:
            if (*pbVar12 == 0x6c) {
              uVar19 = 0;
              if (pbVar12[-1] != 0x6c) goto LAB_0102c4a4;
              uVar9 = 8;
              goto LAB_0102c51c;
            }
            uVar19 = 0;
            uVar18 = uVar19;
            goto LAB_0102c4c8;
          case 0x61:
          case 0x65:
          case 0x66:
          case 0x67:
switchD_0102c46a_caseD_61:
            puVar15 = (undefined4 *)((int)puVar16 + 7U & 0xfffffff8);
            puVar10 = (undefined4 *)((uint)(pbVar11 + 7) & 0xfffffff8);
            puVar16 = puVar15 + 2;
            uVar4 = puVar15[1];
            if (param_1 != (undefined4 *)0x0) {
              if (param_2 < (byte *)((8 - (int)param_1) + (int)puVar10)) {
                return (byte *)0xffffffe4;
              }
              *puVar10 = *puVar15;
              puVar10[1] = uVar4;
            }
            uVar19 = 0;
            pbVar11 = (byte *)(puVar10 + 2);
          case 0x6a:
            uVar9 = 8;
            uVar17 = uVar9;
            break;
          case 0x6e:
          case 0x70:
            uVar19 = 0;
            goto LAB_0102c4a4;
          case 0x73:
LAB_0102c4a4:
            uVar9 = 4;
LAB_0102c51c:
            uVar17 = uVar9;
            uVar18 = 0;
LAB_0102c4c8:
            pbVar11 = (byte *)(uVar17 * ((uint)(pbVar11 + (uVar17 - 1)) / uVar17));
            if (param_1 == (undefined4 *)0x0) {
              if (uVar19 != 0) goto LAB_0102c5b8;
              if (uVar9 != 4) {
                if (uVar9 != 8) goto LAB_0102c69a;
                puVar16 = (undefined4 *)((int)puVar16 + 7U & 0xfffffff8);
                goto LAB_0102c594;
              }
            }
            else {
              if (param_2 < pbVar11 + (uVar9 - (int)param_1)) {
                return (byte *)0xffffffe4;
              }
              if (uVar19 != 0) {
LAB_0102c5b8:
                local_54 = local_54 + -1;
                param_5 = puVar16 + 1;
                local_68 = (char *)*puVar16;
                goto LAB_0102c40a;
              }
              if (uVar9 != 4) {
                if (uVar9 != 8) {
LAB_0102c69a:
                  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                               "WEST_TOPDIR/zephyr/lib/os/cbprintf_packaged.c",0x2c5,uVar9);
                  uVar19 = uVar18;
                  goto LAB_0102c5ee;
                }
                puVar16 = (undefined4 *)((int)puVar16 + 7U & 0xfffffff8);
                uVar4 = puVar16[1];
                *(undefined4 *)pbVar11 = *puVar16;
                *(undefined4 *)(pbVar11 + 4) = uVar4;
LAB_0102c594:
                puVar16 = puVar16 + 2;
                uVar9 = 8;
                pbVar11 = pbVar11 + 8;
                uVar19 = uVar18;
                break;
              }
              *(undefined4 *)pbVar11 = *puVar16;
            }
            puVar16 = puVar16 + 1;
            uVar9 = 4;
            pbVar11 = pbVar11 + 4;
            uVar19 = uVar18;
            break;
          case 0x74:
          case 0x7a:
            goto switchD_0102c46a_caseD_74;
          }
          goto switchD_0102c46a_caseD_4c;
        }
        if (0x47 < bVar2) goto switchD_0102c46a_caseD_4d;
        if (0x29 < bVar2) {
          uVar18 = 1 << (uint)(byte)(bVar2 - 0x2a);
          if ((uVar18 & 0xffda) == 0) {
            if ((uVar18 & 0x38800000) != 0) goto switchD_0102c46a_caseD_61;
            uVar18 = uVar18 & 1;
            uVar19 = uVar18;
            if (uVar18 != 0) {
              uVar19 = 0;
              goto LAB_0102c4c8;
            }
          }
          goto switchD_0102c46a_caseD_4c;
        }
        if (bVar2 == 0x25) {
          bVar6 = bVar6 - 1;
        }
        else if (bVar2 < 0x26) {
          if (bVar2 != 0x20) {
            uVar19 = (uint)(bVar2 == 0x23);
          }
          goto switchD_0102c46a_caseD_4c;
        }
      }
switchD_0102c46a_caseD_4d:
      uVar19 = 0;
      goto switchD_0102c46a_caseD_4c;
    }
    uVar9 = (int)pbVar11 - (int)param_1;
    if (uVar9 < 0x400) {
      if (param_1 == (undefined4 *)0x0) {
        return param_2 + (uVar9 - 8);
      }
      *param_1 = 0;
      *(char *)param_1 = (char)(uVar9 >> 2);
      if (uVar8 == 0) {
        *(char *)((int)param_1 + 1) = cVar3;
      }
      else {
        *(char *)((int)param_1 + 3) = cVar3;
      }
      *(char *)((int)param_1 + 2) = (char)iVar14;
      if (iVar14 != 0) {
        pbVar5 = local_48;
        for (uVar9 = 0; uVar13 != uVar9; uVar9 = uVar9 + 1) {
          pbVar12 = pbVar11;
          if ((int)((uint)*pbVar5 << 0x18) < 0) {
            if (param_2 < pbVar11 + (1 - (int)param_1)) {
              return (byte *)0xffffffe4;
            }
            pbVar12 = pbVar11 + 1;
            *pbVar11 = *pbVar5 & 0x7f;
          }
          pbVar5 = pbVar5 + 1;
          pbVar11 = pbVar12;
        }
      }
      uVar9 = 0;
      pbVar5 = local_48;
      do {
        if (uVar13 == uVar9) {
          return pbVar11 + -(int)param_1;
        }
        if ((iVar14 == 0) || (-1 < (char)*pbVar5)) {
          if (uVar8 == 0) {
            local_68 = (char *)param_1[*pbVar5];
            param_1[*pbVar5] = 0;
            pcVar7 = FUN_0102aa68(local_68);
            pcVar7 = pcVar7 + 1;
          }
          else {
            *pbVar11 = abStack_38[uVar9];
            pcVar7 = (char *)0x0;
            pbVar11 = pbVar11 + 1;
          }
          if (param_2 < pcVar7 + (1 - (int)param_1) + (int)pbVar11) {
            return (byte *)0xffffffe4;
          }
          *pbVar11 = *pbVar5;
          FUN_0103bdd4((int)(pbVar11 + 1),local_68,(int)pcVar7);
          pbVar11 = pbVar11 + 1 + (int)pcVar7;
        }
        uVar9 = uVar9 + 1;
        pbVar5 = pbVar5 + 1;
      } while( true );
    }
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/cbprintf_packaged.c",
                 0x2d1,uVar9);
  } while( true );
  if (bVar2 == 0x25) {
    uVar19 = 1;
    bVar6 = bVar6 + 1;
switchD_0102c46a_caseD_74:
    uVar9 = 4;
    uVar17 = uVar9;
  }
  goto switchD_0102c46a_caseD_4c;
}


