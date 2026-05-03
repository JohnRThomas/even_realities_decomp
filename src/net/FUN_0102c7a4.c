/*
 * Function: FUN_0102c7a4
 * Entry:    0102c7a4
 * Prototype: byte * __stdcall FUN_0102c7a4(byte * param_1, byte * param_2, undefined * param_3, undefined4 param_4, uint param_5, int param_6, uint param_7)
 */


byte * FUN_0102c7a4(byte *param_1,byte *param_2,undefined *param_3,undefined4 param_4,uint param_5,
                   int param_6,uint param_7)

{
  int iVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  uint uVar5;
  char *pcVar6;
  byte bVar7;
  byte extraout_r1;
  byte *extraout_r1_00;
  uint uVar8;
  char *pcVar9;
  uint uVar10;
  byte *pbVar11;
  byte *pbVar12;
  byte *pbVar13;
  uint uVar14;
  int iVar15;
  undefined1 *local_90;
  char *local_8c;
  byte *local_88;
  undefined2 local_80;
  uint local_78;
  uint local_74;
  int local_70;
  byte *local_6c;
  int local_68;
  uint local_64;
  uint local_60;
  undefined4 local_5c;
  byte *local_58;
  code *local_54;
  byte local_49;
  byte abStack_48 [16];
  byte abStack_38 [20];
  
  pbVar4 = param_1;
  pbVar11 = param_2;
  local_5c = param_4;
  local_54 = (code *)param_3;
  if (param_1 != (byte *)0x0) goto LAB_0102c7cc;
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/cbprintf_packaged.c",
               0x394,param_4);
LAB_0102c7c6:
  pbVar4 = (byte *)FUN_0103a370();
  param_2 = extraout_r1_00;
LAB_0102c7cc:
  bVar2 = pbVar4[2];
  uVar14 = (uint)bVar2;
  local_64 = (param_5 << 0x1c) >> 0x1f;
  if (param_2 == (byte *)0x0) {
    bVar7 = pbVar4[1];
    pbVar4 = param_1 + uVar14 + (uint)*pbVar4 * 4;
    for (; pbVar11 < (byte *)(uint)bVar7; pbVar11 = pbVar11 + 1) {
      pcVar9 = FUN_0102aa68((char *)(pbVar4 + 1));
      pbVar4 = (byte *)(pcVar9 + 1 + (int)(pbVar4 + 1));
    }
    pbVar11 = pbVar4 + -(int)param_1;
  }
  local_60 = (uint)param_1[3];
  uVar8 = uVar14;
  if ((uVar14 == 0) || (-1 < (int)(param_5 << 0x1f))) {
    if ((local_60 == 0) || (-1 < (int)(param_5 << 0x1e))) {
      if (local_54 == (code *)0x0) {
        return pbVar11;
      }
      (*local_54)(param_1,pbVar11,local_5c);
      return pbVar11;
    }
    pbVar4 = (byte *)(uint)*param_1;
    local_68 = (int)pbVar4 << 2;
    local_58 = *(byte **)(param_1 + 4);
    pbVar12 = param_1 + (int)pbVar4 * 4;
    if (local_54 == (code *)0x0) {
      if (uVar14 == 0) {
        uVar8 = 0;
      }
      else {
        if ((param_5 & 4) != 0) {
          pbVar12 = pbVar12 + uVar14;
        }
        uVar8 = 0;
      }
      goto LAB_0102c876;
    }
    uVar10 = uVar14;
    if (uVar14 == 0) goto LAB_0102c984;
    if ((param_5 & 4) == 0) {
      uVar8 = 0;
      uVar10 = 0;
      goto LAB_0102c984;
    }
    pbVar13 = abStack_38;
    uVar8 = 0;
  }
  else {
    local_58 = *(byte **)(param_1 + 4);
    pbVar4 = (byte *)(uint)*param_1;
    local_68 = (int)pbVar4 << 2;
    pbVar12 = param_1 + (int)pbVar4 * 4;
    if (local_54 == (code *)0x0) {
      uVar8 = 0;
      pbVar4 = pbVar12;
      while (pbVar12 + uVar14 != pbVar4) {
        pcVar9 = FUN_0102aa68(*(char **)(param_1 + (uint)*pbVar4 * 4));
        if ((param_6 != 0) && (uVar8 < param_7)) {
          *(short *)(param_6 + uVar8 * 2) = (short)(pcVar9 + 1);
          uVar8 = uVar8 + 1;
        }
        pbVar11 = pbVar11 + (int)(pcVar9 + 1);
        pbVar4 = pbVar4 + 1;
      }
      pbVar12 = pbVar12 + uVar14;
LAB_0102c876:
      if ((param_5 & 5) == 0) {
        iVar15 = 2;
      }
      else {
        iVar15 = 1;
      }
      iVar1 = local_60 * 2;
      local_54 = (code *)(param_5 & 2);
      pbVar4 = pbVar12;
      do {
        while( true ) {
          if (pbVar4 == pbVar12 + iVar1) {
            return pbVar11;
          }
          pbVar13 = pbVar4 + 2;
          pcVar9 = *(char **)(param_1 + (uint)pbVar4[1] * 4);
          if ((pcVar9 < &DAT_0103be24) || (&UNK_0103eca7 < pcVar9)) break;
          if ((local_64 == 0) || (uVar14 = FUN_01039e90(local_58,(uint)*pbVar4), uVar14 == 0)) {
            if ((int)(param_5 << 0x1f) < 0) {
LAB_0102c942:
              pcVar9 = FUN_0102aa68(pcVar9);
              if ((param_6 != 0) && (uVar8 < param_7)) {
                *(short *)(param_6 + uVar8 * 2) = (short)pcVar9 + 1;
                uVar8 = uVar8 + 1;
              }
              pbVar11 = pbVar11 + (int)pcVar9;
              pbVar4 = pbVar13;
            }
            else {
              pbVar11 = pbVar11 + -iVar15;
              pbVar4 = pbVar13;
            }
          }
          else {
LAB_0102c8c0:
            local_8c = 
            "(unsigned) char * used for %%p argument. It\'s recommended to cast it to void * because it may cause misbehavior in certain configurations. String:\"%s\" argument:%d"
            ;
            local_88 = local_58;
            local_80 = 0x200;
            local_90 = &DAT_01000004;
            FUN_0102ea44(0x103c00c,0x2480,(byte *)&local_90,(undefined1 *)0x0);
            pbVar11 = pbVar11 + -2;
            pbVar4 = pbVar13;
          }
        }
        if ((local_64 != 0) && (uVar14 = FUN_01039e90(local_58,(uint)*pbVar4), uVar14 != 0))
        goto LAB_0102c8c0;
        pbVar4 = pbVar13;
        if (local_54 != (code *)0x0) goto LAB_0102c942;
      } while( true );
    }
    uVar10 = 0;
    pbVar13 = abStack_48;
  }
  local_6c = pbVar4;
  FUN_0103bdd4((int)pbVar13,pbVar12,uVar14);
  pbVar4 = local_6c;
LAB_0102c984:
  local_70 = local_60 << 1;
  local_6c = pbVar12 + uVar14 + local_60 * 2;
  local_74 = param_5 & 2;
  pbVar12 = pbVar12 + uVar14;
LAB_0102c99c:
  while( true ) {
    do {
      if (pbVar12 == local_6c) {
        local_58 = (byte *)(uint)param_1[1];
        bVar7 = 0;
        if (-1 < (int)(param_5 << 0x1e)) {
          bVar7 = (byte)(uVar10 >> 1);
        }
        if ((int)(param_5 << 0x1f) < 0) {
          bVar3 = 0;
        }
        else if ((param_5 & 4) == 0) {
          bVar3 = 0;
        }
        else {
          bVar3 = (byte)uVar10;
        }
        param_1[1] = (char)uVar8 + param_1[1];
        param_1[2] = bVar3;
        param_1[3] = bVar7;
        local_64 = (uint)pbVar4;
        pbVar4 = (byte *)(*local_54)(param_1,local_68,local_5c);
        if ((int)pbVar4 < 0) {
          return pbVar4;
        }
        *param_1 = (byte)local_64;
        param_1[1] = (byte)local_58;
        param_1[2] = bVar2;
        param_1[3] = (byte)local_60;
        pbVar13 = (byte *)(*local_54)(abStack_38,uVar10,local_5c);
        if ((int)pbVar13 < 0) {
          return pbVar13;
        }
        pbVar11 = (byte *)(*local_54)(pbVar12,pbVar11 + ((-local_68 - uVar14) - local_70),local_5c);
        if (-1 < (int)pbVar11) {
          uVar14 = 0;
          pbVar11 = pbVar13 + (int)pbVar4 + (int)pbVar11;
          while( true ) {
            if (uVar8 <= uVar14) {
              (*local_54)(0,0,local_5c);
              return pbVar11;
            }
            local_49 = abStack_48[uVar14];
            pcVar9 = *(char **)(param_1 + (uint)local_49 * 4);
            if (param_6 == 0) {
              uVar10 = 0;
            }
            else {
              uVar10 = (uint)*(ushort *)(param_6 + uVar14 * 2);
            }
            pbVar4 = (byte *)(*local_54)(&local_49,1,local_5c);
            if ((int)pbVar4 < 0) break;
            if (uVar10 == 0) {
              pcVar6 = FUN_0102aa68(pcVar9);
              uVar10 = (uint)(pcVar6 + 1) & 0xffff;
            }
            pbVar12 = (byte *)(*local_54)(pcVar9,uVar10,local_5c);
            if ((int)pbVar12 < 0) {
              return pbVar12;
            }
            pbVar11 = pbVar11 + (int)pbVar4 + (int)pbVar12;
            uVar14 = uVar14 + 1;
          }
          return pbVar4;
        }
        return pbVar11;
      }
      pbVar13 = pbVar12 + 2;
      bVar7 = *pbVar12;
      bVar3 = pbVar12[1];
      pbVar12 = pbVar13;
      if ((&UNK_0103be23 < *(undefined **)(param_1 + (uint)bVar3 * 4)) &&
         (*(undefined **)(param_1 + (uint)bVar3 * 4) < &UNK_0103eca8)) goto LAB_0102cabc;
    } while ((local_64 != 0) &&
            (local_78 = (uint)pbVar4, uVar5 = FUN_01039e90(local_58,(uint)bVar7),
            pbVar4 = (byte *)local_78, bVar7 = extraout_r1, uVar5 != 0));
    if (local_74 != 0) {
      if (uVar8 < 0x10) goto LAB_0102cb26;
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                   "WEST_TOPDIR/zephyr/lib/os/cbprintf_packaged.c",0x448,pbVar4);
      goto LAB_0102c7c6;
    }
    if (0xf < uVar10) break;
    uVar5 = uVar10 + 1;
    abStack_38[uVar10] = bVar7;
    uVar10 = uVar10 + 2 & 0xff;
    abStack_38[uVar5 & 0xff] = bVar3;
  }
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/cbprintf_packaged.c",
               1099,pbVar4);
  goto LAB_0102c7c6;
LAB_0102cabc:
  if ((local_64 != 0) &&
     (local_78 = (uint)pbVar4, uVar5 = FUN_01039e90(local_58,(uint)bVar7), pbVar4 = (byte *)local_78
     , uVar5 != 0)) goto LAB_0102c99c;
  if ((int)(param_5 << 0x1f) < 0) {
    if (0xf < uVar8) {
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                   "WEST_TOPDIR/zephyr/lib/os/cbprintf_packaged.c",0x43e,pbVar4);
      goto LAB_0102c7c6;
    }
LAB_0102cb26:
    abStack_48[uVar8] = bVar3;
    uVar8 = uVar8 + 1 & 0xff;
    goto LAB_0102c99c;
  }
  if (-1 < (int)(param_5 << 0x1d)) goto LAB_0102c99c;
  if (uVar10 < 0x10) {
    abStack_38[uVar10] = bVar3;
    uVar10 = uVar10 + 1 & 0xff;
    goto LAB_0102c99c;
  }
  FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/cbprintf_packaged.c",
               0x441,pbVar4);
  goto LAB_0102c7c6;
}


