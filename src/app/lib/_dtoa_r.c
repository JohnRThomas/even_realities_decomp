/*
 * Function: _dtoa_r
 * Entry:    00014ab8
 * Prototype: char * __stdcall _dtoa_r(size_t param_1, uint param_2, char * param_3, int * param_4, undefined4 * param_5, undefined4 * param_6)
 */


/* WARNING: Type propagation algorithm not settling */
/* exclude_from_export */

char * _dtoa_r(size_t param_1,uint param_2,char *param_3,int *param_4,undefined4 *param_5,
              undefined4 *param_6)

{
  bool bVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  char *pcVar5;
  char *extraout_r0;
  undefined4 *puVar6;
  char *pcVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  uint uVar12;
  char *extraout_r2;
  uint uVar13;
  char *pcVar14;
  uint uVar15;
  char *pcVar16;
  char *pcVar17;
  char *pcVar18;
  uint *puVar19;
  char *pcVar20;
  uint uVar21;
  char *pcVar22;
  char cVar23;
  char *pcVar24;
  ulonglong in_d0;
  ulonglong uVar25;
  ulonglong uVar26;
  ulonglong uVar27;
  undefined8 local_80;
  undefined4 *local_78;
  char *local_74;
  undefined8 local_70;
  char *local_68;
  char *local_64;
  uint local_60;
  char *local_5c;
  char *local_50;
  undefined8 local_48;
  undefined4 *local_40;
  int local_30;
  int local_2c [2];
  
  pcVar18 = (char *)(in_d0 >> 0x20);
  pcVar7 = (char *)in_d0;
  pcVar14 = param_3;
  local_80 = in_d0;
  local_60 = param_2;
  local_50 = param_3;
  if (*(int *)(param_1 + 0x24) != 0) goto LAB_00014af4;
  pcVar5 = malloc(0x10);
  *(char **)(param_1 + 0x24) = pcVar5;
  puVar11 = (undefined4 *)0x0;
  pcVar14 = pcVar5;
  if (pcVar5 != (char *)0x0) goto LAB_00014aec;
  pcVar14 = "REENT malloc succeeded";
  iVar10 = 234;
  local_80 = in_d0;
LAB_00014ae6:
  __assert_func("/__w/_temp/workspace/build/.build/HOST-x86_64-w64-mingw32/arm-zephyr-eabi/src/newlib-nano/newlib/libc/stdlib/dtoa.c"
                ,iVar10,(char *)0x0,pcVar14);
  pcVar5 = extraout_r0;
  pcVar14 = extraout_r2;
LAB_00014aec:
  *(undefined4 **)(pcVar5 + 4) = puVar11;
  *(undefined4 **)(pcVar5 + 8) = puVar11;
  *(undefined4 **)pcVar5 = puVar11;
  *(undefined4 **)(pcVar5 + 0xc) = puVar11;
LAB_00014af4:
  puVar11 = (undefined4 *)**(undefined4 **)(param_1 + 0x24);
  if (puVar11 != (undefined4 *)0x0) {
    uVar13 = (*(undefined4 **)(param_1 + 0x24))[1];
    puVar11[1] = uVar13;
    puVar11[2] = 1 << (uVar13 & 0xff);
    Bfree(param_1,puVar11);
    pcVar14 = (char *)0x0;
    **(undefined4 **)(param_1 + 0x24) = 0;
  }
  if ((int)pcVar18 < 0) {
    pcVar14 = &DAT_00000001;
    local_80 = CONCAT44(pcVar18,(uint)local_80) & 0x7fffffffffffffff;
  }
  else {
    *param_5 = 0;
  }
  uVar27 = local_80;
  uVar13 = local_80._4_4_;
  if ((int)pcVar18 < 0) {
    *param_5 = pcVar14;
  }
  if ((~local_80._4_4_ & 0x7ff00000) == 0) {
    *param_4 = 9999;
    if ((local_80 & 0xfffff00000000) == 0 && pcVar7 == (char *)0x0) {
      if (param_6 == (undefined4 *)0x0) {
        return "Infinity";
      }
      local_74 = "Infinity";
      pcVar14 = "";
    }
    else {
      if (param_6 == (undefined4 *)0x0) {
        return "NaN";
      }
      local_74 = "NaN";
      pcVar14 = "";
    }
    *param_6 = pcVar14;
    return local_74;
  }
  uVar8 = (uint)local_80;
  bVar2 = __aeabi_dcmpeq(uVar8,local_80._4_4_,0,0);
  if (bVar2) {
    *param_4 = 1;
    if (param_6 != (undefined4 *)0x0) {
      *param_6 = "";
    }
    return "0";
  }
  uVar21 = (local_80._4_4_ & 0x7fffffff) >> 0x14;
  local_78 = d2b(uVar8,local_80._4_4_,param_1,local_2c,&local_30);
  if (uVar21 == 0) {
    iVar9 = local_30 + local_2c[0];
    iVar10 = iVar9 + 0x432;
    if (iVar10 < 0x21) {
      uVar21 = (int)pcVar7 << (0x20U - iVar10 & 0xff);
    }
    else {
      uVar21 = local_80._4_4_ << (0x40U - iVar10 & 0xff) | (uint)pcVar7 >> (iVar9 + 0x412U & 0xff);
    }
    param_5 = (undefined4 *)(iVar9 + -1);
    uVar25 = __floatunsidf(uVar21);
    uVar21 = (uint)uVar25;
    uVar15 = (int)(uVar25 >> 0x20) + 0xfe100000;
    bVar2 = true;
  }
  else {
    param_5 = (undefined4 *)(uVar21 - 0x3ff);
    uVar15 = local_80._4_4_ & 0xfffff | 0x3ff00000;
    bVar2 = false;
    uVar21 = uVar8;
  }
  uVar25 = __subdf(uVar21,uVar15,0,0x3ff80000);
  uVar25 = __muldf3((uint)uVar25,(uint)(uVar25 >> 0x20),0x636f4361,0x3fd287a7);
  uVar25 = __aeabi_dadd((uint)uVar25,(uint)(uVar25 >> 0x20),0x8b60c8b3,0x3fc68a28);
  uVar26 = __floatsidf((uint)param_5);
  uVar26 = __muldf3((uint)uVar26,(uint)(uVar26 >> 0x20),0x509f79fb,0x3fd34413);
  uVar25 = __aeabi_dadd((uint)uVar25,(uint)(uVar25 >> 0x20),(uint)uVar26,(uint)(uVar26 >> 0x20));
  uVar15 = (uint)(uVar25 >> 0x20);
  uVar21 = (uint)uVar25;
  puVar6 = (undefined4 *)_cast_double_to_int(uVar21,uVar15);
  bVar3 = __gedf2(uVar21,uVar15,0,0);
  if (bVar3) {
    uVar25 = __floatsidf((uint)puVar6);
    bVar3 = __aeabi_dcmpeq((uint)uVar25,(uint)(uVar25 >> 0x20),uVar21,uVar15);
    if (!bVar3) {
      puVar6 = (undefined4 *)((int)puVar6 + -1);
    }
  }
  if (&DAT_00000016 < puVar6) {
    bVar3 = true;
  }
  else {
    bVar3 = __gedf2(uVar8,local_80._4_4_,(&DAT_0008c0b8)[(int)puVar6 * 2],
                    (&DAT_0008c0bc)[(int)puVar6 * 2]);
    if (bVar3) {
      puVar6 = (undefined4 *)((int)puVar6 + -1);
      bVar3 = false;
    }
    else {
      bVar3 = false;
    }
  }
  local_64 = (char *)((local_30 - (int)param_5) + -1);
  if ((int)local_64 < 0) {
    local_68 = (char *)(1 - (local_30 - (int)param_5));
    local_64 = (char *)0x0;
  }
  else {
    local_68 = (char *)0x0;
  }
  if ((int)puVar6 < 0) {
    local_68 = local_68 + -(int)puVar6;
    local_5c = (char *)-(int)puVar6;
    local_40 = (undefined4 *)0x0;
  }
  else {
    local_64 = local_64 + (int)puVar6;
    local_5c = (char *)0x0;
    local_40 = puVar6;
  }
  if (9 < local_60) {
    pcVar7 = &DAT_00000001;
    local_60 = 0;
switchD_00014c92_default:
    bVar1 = true;
    pcVar5 = (char *)0xffffffff;
    local_50 = (char *)0x0;
    pcVar14 = (char *)0xffffffff;
    pcVar16 = &DAT_00000012;
    goto LAB_00014d20;
  }
  bVar1 = 5 < (int)local_60;
  if (bVar1) {
    local_60 = local_60 - 4;
  }
  pcVar7 = (char *)(uint)!bVar1;
  switch(local_60) {
  case 2:
    bVar1 = false;
    break;
  case 3:
    bVar1 = false;
    goto LAB_00014d0c;
  case 4:
    bVar1 = true;
    break;
  case 5:
    bVar1 = true;
LAB_00014d0c:
    pcVar14 = (char *)((int)puVar6 + (int)local_50);
    pcVar5 = pcVar14 + 1;
    pcVar16 = pcVar5;
    if ((int)pcVar5 < 1) {
      pcVar16 = &DAT_00000001;
    }
    goto LAB_00014d20;
  default:
    goto switchD_00014c92_default;
  }
  pcVar16 = local_50;
  pcVar5 = local_50;
  pcVar14 = local_50;
  if ((int)local_50 < 1) {
    pcVar16 = &DAT_00000001;
    pcVar5 = &DAT_00000001;
    local_50 = &DAT_00000001;
    pcVar14 = &DAT_00000001;
  }
LAB_00014d20:
  uVar21 = 0;
  for (iVar10 = 4; pcVar18 = (char *)(iVar10 + 0x14), pcVar18 <= pcVar16; iVar10 = iVar10 << 1) {
    uVar21 = uVar21 + 1;
  }
  *(uint *)(*(int *)(param_1 + 0x24) + 4) = uVar21;
  pcVar16 = (char *)Balloc(param_1,uVar21);
  if (pcVar16 == (char *)0x0) {
    pcVar14 = "Balloc succeeded";
    iVar10 = 0x1aa;
    puVar11 = puVar6;
    local_80 = uVar27;
    goto LAB_00014ae6;
  }
  **(undefined4 **)(param_1 + 0x24) = pcVar16;
  pcVar18 = local_5c;
  puVar11 = puVar6;
  pcVar22 = local_68;
  pcVar20 = pcVar16;
  if ((pcVar5 <= &DAT_0000000e) && (pcVar7 != (char *)0x0)) {
    if ((int)puVar6 < 1) {
      if (puVar6 == (undefined4 *)0x0) {
        uVar21 = 2;
      }
      else {
        puVar19 = &DAT_0008c090;
        uVar21 = 2;
        uVar15 = -(int)puVar6 & 0xf;
        iVar10 = -(int)puVar6 >> 4;
        local_80 = __muldf3(uVar8,local_80._4_4_,(&DAT_0008c0b8)[uVar15 * 2],
                            (&DAT_0008c0bc)[uVar15 * 2]);
        bVar4 = false;
        uVar25 = local_80;
        while( true ) {
          if (iVar10 == 0) break;
          if (iVar10 << 0x1f < 0) {
            uVar21 = uVar21 + 1;
            uVar25 = __muldf3((uint)uVar25,(uint)(uVar25 >> 0x20),*puVar19,puVar19[1]);
            bVar4 = true;
          }
          iVar10 = iVar10 >> 1;
          puVar19 = puVar19 + 2;
        }
        if (bVar4) goto LAB_00014e10;
      }
    }
    else {
      uVar15 = (int)puVar6 >> 4;
      local_48 = *(ulonglong *)(&DAT_0008c0b8 + ((uint)puVar6 & 0xf) * 2);
      if ((int)puVar6 << 0x17 < 0) {
        uVar15 = uVar15 & 0xf;
        uVar21 = 3;
        local_80 = __divdf3(uVar8,local_80._4_4_,0x7f73bf3c,0x75154fdd);
      }
      else {
        uVar21 = 2;
      }
      puVar19 = &DAT_0008c090;
      while( true ) {
        if (uVar15 == 0) break;
        if ((int)(uVar15 << 0x1f) < 0) {
          uVar21 = uVar21 + 1;
          local_48 = __muldf3((uint)local_48,local_48._4_4_,*puVar19,puVar19[1]);
        }
        uVar15 = (int)uVar15 >> 1;
        puVar19 = puVar19 + 2;
      }
      uVar25 = __divdf3((uint)local_80,local_80._4_4_,(uint)local_48,local_48._4_4_);
LAB_00014e10:
      local_80 = uVar25;
    }
    pcVar7 = pcVar5;
    if (((bVar3) && (bVar4 = __gedf2((uint)local_80,local_80._4_4_,0,0x3ff00000), bVar4)) &&
       (pcVar5 != (char *)0x0)) {
      if ((int)pcVar14 < 1) goto LAB_00014ea4;
      local_80 = __muldf3((uint)local_80,local_80._4_4_,0,0x40240000);
      uVar21 = uVar21 + 1;
      pcVar7 = pcVar14;
      puVar11 = (undefined4 *)((int)puVar6 + -1);
    }
    uVar25 = __floatsidf(uVar21);
    uVar25 = __muldf3((uint)uVar25,(uint)(uVar25 >> 0x20),(uint)local_80,local_80._4_4_);
    uVar25 = __aeabi_dadd((uint)uVar25,(uint)(uVar25 >> 0x20),0,0x401c0000);
    iVar10 = (int)(uVar25 >> 0x20);
    uVar21 = iVar10 + 0xfcc00000;
    local_48._0_4_ = (uint)uVar25;
    if (pcVar7 == (char *)0x0) {
      uVar25 = __subdf((uint)local_80,local_80._4_4_,0,0x40140000);
      uVar15 = (uint)(uVar25 >> 0x20);
      bVar4 = __ltdf2((uint)uVar25,uVar15,(uint)local_48,uVar21);
      if (!bVar4) {
        bVar4 = __gedf2((uint)uVar25,uVar15,(uint)local_48,iVar10 + 0x7cc00000);
        if (!bVar4) goto LAB_00014ea4;
        goto LAB_000150d8;
      }
    }
    else {
      pcVar17 = pcVar7 + (int)pcVar16;
      if (bVar1) {
        uVar25 = __divdf3(0,0x3fe00000,(&DAT_0008c0b0)[(int)pcVar7 * 2],
                          (&DAT_0008c0b4)[(int)pcVar7 * 2]);
        local_48 = __subdf((uint)uVar25,(uint)(uVar25 >> 0x20),(uint)local_48,uVar21);
        pcVar7 = pcVar16;
        while( true ) {
          uVar21 = _cast_double_to_int((uint)local_80,local_80._4_4_);
          uVar25 = __floatsidf(uVar21);
          uVar25 = __subdf((uint)local_80,local_80._4_4_,(uint)uVar25,(uint)(uVar25 >> 0x20));
          uVar12 = (uint)(uVar25 >> 0x20);
          uVar15 = (uint)uVar25;
          pcVar24 = pcVar7 + 1;
          *pcVar7 = (char)uVar21 + '0';
          bVar4 = __ltdf2((uint)local_48,local_48._4_4_,uVar15,uVar12);
          if (bVar4) goto LAB_000152f8;
          uVar25 = __subdf(0,0x3ff00000,uVar15,uVar12);
          bVar4 = __ltdf2((uint)local_48,local_48._4_4_,(uint)uVar25,(uint)(uVar25 >> 0x20));
          pcVar7 = pcVar24;
          if (bVar4) goto LAB_000153b6;
          if (pcVar24 == pcVar17) break;
          local_48 = __muldf3((uint)local_48,local_48._4_4_,0,0x40240000);
          local_80 = __muldf3(uVar15,uVar12,0,0x40240000);
        }
        if ((local_2c[0] < 0) || (0xe < (int)puVar6)) goto LAB_00015386;
        goto LAB_00015334;
      }
      uVar25 = __muldf3((&DAT_0008c0b0)[(int)pcVar7 * 2],(&DAT_0008c0b4)[(int)pcVar7 * 2],
                        (uint)local_48,uVar21);
      pcVar24 = pcVar16;
      while( true ) {
        uVar21 = _cast_double_to_int((uint)local_80,local_80._4_4_);
        uVar26 = __floatsidf(uVar21);
        uVar26 = __subdf((uint)local_80,local_80._4_4_,(uint)uVar26,(uint)(uVar26 >> 0x20));
        uVar12 = (uint)(uVar26 >> 0x20);
        uVar15 = (uint)uVar26;
        pcVar7 = pcVar24 + 1;
        *pcVar24 = (char)uVar21 + '0';
        if (pcVar7 == pcVar17) break;
        local_80 = __muldf3(uVar15,uVar12,0,0x40240000);
        pcVar24 = pcVar7;
      }
      local_48._0_4_ = (uint)uVar25;
      local_48._4_4_ = (uint)(uVar25 >> 0x20);
      uVar25 = __aeabi_dadd((uint)local_48,local_48._4_4_,0,0x3fe00000);
      bVar2 = __ltdf2(uVar15,uVar12,(uint)uVar25,(uint)(uVar25 >> 0x20));
      if (bVar2) goto LAB_000153b6;
      uVar25 = __subdf(0,0x3fe00000,(uint)local_48,local_48._4_4_);
      bVar2 = __gedf2(uVar15,uVar12,(uint)uVar25,(uint)(uVar25 >> 0x20));
      if (bVar2) goto LAB_0001523a;
      if ((local_2c[0] < 0) || (0xe < (int)puVar6)) goto LAB_00014eb8;
      local_70 = *(undefined8 *)(&DAT_0008c0b8 + (int)puVar6 * 2);
      if ((-1 < (int)local_50) || (pcVar5 != (char *)0x0)) goto LAB_00015290;
LAB_00015352:
      uVar27 = __muldf3((uint)local_70,local_70._4_4_,0,0x40140000);
      bVar2 = __aeabi_dcmpge((uint)uVar27,(uint)(uVar27 >> 0x20),uVar8,uVar13);
      puVar11 = puVar6;
      if (bVar2) goto LAB_000150d8;
    }
    puVar6 = puVar11;
    pcVar7 = (char *)0x0;
    pcVar20 = pcVar7;
LAB_000154de:
    puVar6 = (undefined4 *)((int)puVar6 + 1);
    *pcVar16 = '1';
    pcVar24 = pcVar16 + 1;
    goto LAB_000150e4;
  }
LAB_00014ea4:
  if ((local_2c[0] < 0) || (0xe < (int)puVar6)) {
    if (bVar1) {
LAB_00015386:
      if ((int)local_60 < 2) {
        if (bVar2) {
          pcVar7 = (char *)(local_2c[0] + 0x433);
        }
        else {
          pcVar7 = (char *)(0x36 - local_30);
        }
      }
      else {
        pcVar20 = pcVar5 + -1;
        pcVar7 = pcVar5;
        if ((int)local_5c < (int)pcVar20) {
          local_40 = (undefined4 *)((int)local_40 + ((int)pcVar20 - (int)local_5c));
          pcVar18 = (char *)0x0;
          local_5c = pcVar20;
        }
        else {
          pcVar18 = local_5c + -(int)pcVar20;
          if ((int)pcVar5 < 0) {
            pcVar7 = (char *)0x0;
            pcVar22 = local_68 + -(int)pcVar5;
          }
        }
      }
      local_68 = local_68 + (int)pcVar7;
      local_64 = local_64 + (int)pcVar7;
      pcVar20 = (char *)i2b(param_1,1);
    }
    else {
LAB_00014eb8:
      pcVar20 = (char *)0x0;
    }
    if ((pcVar22 != (char *)0x0) && (0 < (int)local_64)) {
      pcVar7 = local_64;
      if ((int)pcVar22 <= (int)local_64) {
        pcVar7 = pcVar22;
      }
      local_68 = local_68 + -(int)pcVar7;
      pcVar22 = pcVar22 + -(int)pcVar7;
      local_64 = local_64 + -(int)pcVar7;
    }
    if (local_5c != (char *)0x0) {
      if ((bVar1) && (pcVar18 != (char *)0x0)) {
        pcVar20 = (char *)pow5mult(param_1,(undefined4 *)pcVar20,(uint)pcVar18);
        puVar11 = (undefined4 *)mult(param_1,(int)pcVar20,(int)local_78);
        Bfree(param_1,local_78);
        local_5c = local_5c + -(int)pcVar18;
        local_78 = puVar11;
        if (local_5c == (char *)0x0) goto LAB_00014f2a;
      }
      local_78 = pow5mult(param_1,local_78,(uint)local_5c);
    }
LAB_00014f2a:
    pcVar7 = (char *)i2b(param_1,1);
    if (local_40 == (undefined4 *)0x0) {
      if (((int)local_60 < 2) && (uVar8 == 0)) goto LAB_0001544e;
LAB_0001547a:
      iVar10 = 1;
    }
    else {
      pcVar7 = (char *)pow5mult(param_1,(undefined4 *)pcVar7,(uint)local_40);
      if (((int)local_60 < 2) && (uVar8 == 0)) {
LAB_0001544e:
        if ((uVar27 & 0xfffff00000000) == 0) {
          puVar11 = (undefined4 *)(uVar13 & 0x7ff00000);
          if ((uVar27 & 0x7ff0000000000000) != 0) {
            puVar11 = (undefined4 *)&DAT_00000001;
            local_68 = local_68 + 1;
            local_64 = local_64 + 1;
          }
        }
        else {
          puVar11 = (undefined4 *)0x0;
        }
        bVar2 = local_40 == (undefined4 *)0x0;
        local_40 = puVar11;
        if (bVar2) goto LAB_0001547a;
      }
      else {
        puVar11 = (undefined4 *)0x0;
      }
      iVar10 = hi0bits(*(uint *)(pcVar7 + *(int *)(pcVar7 + 0x10) * 4 + 0x10));
      iVar10 = 0x20 - iVar10;
      local_40 = puVar11;
    }
    uVar13 = (uint)(local_64 + iVar10) & 0x1f;
    if (uVar13 == 0) {
      iVar10 = 0;
LAB_00015486:
      iVar10 = iVar10 + 0x1c;
      local_68 = local_68 + iVar10;
      pcVar22 = pcVar22 + iVar10;
      local_64 = local_64 + iVar10;
    }
    else {
      iVar10 = 0x20 - uVar13;
      if (iVar10 < 5) {
        if (iVar10 != 4) goto LAB_00015486;
      }
      else {
        iVar10 = 0x1c - uVar13;
        local_68 = local_68 + iVar10;
        pcVar22 = pcVar22 + iVar10;
        local_64 = local_64 + iVar10;
      }
    }
    if (0 < (int)local_68) {
      local_78 = lshift(param_1,local_78,(uint)local_68);
    }
    if (0 < (int)local_64) {
      pcVar7 = (char *)lshift(param_1,(undefined4 *)pcVar7,(uint)local_64);
    }
    pcVar18 = pcVar16;
    if ((bVar3) && (iVar10 = cmp(local_78,pcVar7), iVar10 < 0)) {
      local_78 = multadd(param_1,local_78,10,0);
      puVar6 = (undefined4 *)((int)puVar6 + -1);
      pcVar5 = pcVar14;
      if (bVar1) {
        pcVar20 = (char *)multadd(param_1,(undefined4 *)pcVar20,10,0);
        if ((0 < (int)pcVar14) || ((int)local_60 < 3)) goto LAB_00015000;
      }
      else if ((0 < (int)pcVar14) || ((int)local_60 < 3)) goto LAB_000154fc;
    }
    else if ((0 < (int)pcVar5) || ((int)local_60 < 3)) {
      pcVar14 = pcVar5;
      if (!bVar1) goto LAB_000154fc;
LAB_00015000:
      pcVar18 = pcVar20;
      if (0 < (int)pcVar22) {
        pcVar18 = (char *)lshift(param_1,(undefined4 *)pcVar20,(uint)pcVar22);
      }
      pcVar20 = pcVar18;
      if (local_40 == (undefined4 *)0x0) goto LAB_00015542;
      puVar11 = Balloc(param_1,*(uint *)(pcVar18 + 4));
      if (puVar11 == (undefined4 *)0x0) {
        pcVar14 = "Balloc succeeded";
        iVar10 = 0x2ea;
        puVar11 = (undefined4 *)0x0;
        param_5 = puVar6;
        local_80 = uVar27;
        goto LAB_00014ae6;
      }
      memcpy(puVar11 + 3,pcVar18 + 0xc,(*(int *)(pcVar18 + 0x10) + 2) * 4);
      pcVar20 = (char *)lshift(param_1,puVar11,1);
LAB_00015542:
      pcVar22 = pcVar16;
      while( true ) {
        pcVar14 = pcVar22 + 1;
        uVar8 = quorem(local_78,pcVar7);
        uVar13 = uVar8 + 0x30;
        iVar10 = cmp(local_78,pcVar18);
        puVar11 = diff(param_1,pcVar7,pcVar20);
        if (puVar11[3] != 0) break;
        iVar9 = cmp(local_78,puVar11);
        Bfree(param_1,puVar11);
        if (iVar9 == 0) {
          if ((local_60 == 0) && ((uVar27 & 1) == 0)) {
            if (uVar13 == 0x39) goto LAB_00015620;
            if (0 < iVar10) goto LAB_000155f4;
            goto LAB_00015600;
          }
          if (iVar10 < 0) goto LAB_00015600;
        }
        else {
          if ((iVar10 < 0) || ((local_60 == 0 && iVar10 == 0 && ((uVar27 & 1) == 0)))) {
            if (0 < iVar9) goto LAB_00015594;
            goto LAB_00015600;
          }
          if (0 < iVar9) goto LAB_0001561a;
        }
        *pcVar22 = (char)uVar13;
        if (pcVar5 + (int)pcVar16 == pcVar14) goto LAB_000156c0;
        local_78 = multadd(param_1,local_78,10,0);
        pcVar22 = pcVar14;
        if (pcVar18 == pcVar20) {
          pcVar20 = (char *)multadd(param_1,(undefined4 *)pcVar18,10,0);
          pcVar18 = pcVar20;
        }
        else {
          pcVar18 = (char *)multadd(param_1,(undefined4 *)pcVar18,10,0);
          pcVar20 = (char *)multadd(param_1,(undefined4 *)pcVar20,10,0);
        }
      }
      Bfree(param_1,puVar11);
      if ((iVar10 < 0) || ((local_60 == 0 && iVar10 == 0 && ((uVar27 & 1) == 0)))) {
LAB_00015594:
        local_78 = lshift(param_1,local_78,1);
        iVar10 = cmp(local_78,pcVar7);
        if ((0 < iVar10) || ((iVar10 == 0 && ((uVar13 & 1) != 0)))) {
          if (uVar13 == 0x39) goto LAB_00015620;
LAB_000155f4:
          uVar13 = uVar8 + 0x31;
        }
LAB_00015600:
        cVar23 = (char)uVar13;
      }
      else {
LAB_0001561a:
        if (uVar13 == 0x39) {
LAB_00015620:
          *pcVar22 = '9';
          pcVar14 = pcVar22 + 1;
          goto LAB_00015628;
        }
        cVar23 = (char)uVar13 + '\x01';
      }
      pcVar24 = pcVar22 + 1;
      *pcVar22 = cVar23;
      goto LAB_000150e8;
    }
    if (pcVar5 == (char *)0x0) {
      pcVar7 = (char *)multadd(param_1,(undefined4 *)pcVar7,5,0);
      iVar10 = cmp(local_78,pcVar7);
      if (0 < iVar10) goto LAB_000154de;
    }
  }
  else {
LAB_00015334:
    local_70 = *(undefined8 *)(&DAT_0008c0b8 + (int)puVar6 * 2);
    if ((-1 < (int)local_50) || (0 < (int)pcVar5)) goto LAB_00015290;
    if (pcVar5 == (char *)0x0) goto LAB_00015352;
LAB_000150d8:
    pcVar7 = (char *)0x0;
    pcVar20 = (char *)0x0;
  }
  puVar6 = (undefined4 *)~(uint)local_50;
  pcVar24 = pcVar16;
LAB_000150e4:
  pcVar18 = (char *)0x0;
  goto LAB_000150e8;
LAB_0001523a:
  do {
    pcVar24 = pcVar17;
    pcVar17 = pcVar24 + -1;
  } while (pcVar24[-1] == '0');
  goto LAB_000152f8;
LAB_000154fc:
  while( true ) {
    uVar13 = quorem(local_78,pcVar7);
    uVar13 = uVar13 + 0x30;
    *pcVar18 = (char)uVar13;
    if ((int)pcVar14 <= (int)(pcVar18 + 1) - (int)pcVar16) break;
    local_78 = multadd(param_1,local_78,10,0);
    pcVar18 = pcVar18 + 1;
  }
  pcVar18 = (char *)0x0;
  if ((int)pcVar14 < 1) {
    pcVar14 = &DAT_00000001;
  }
  pcVar14 = pcVar14 + (int)pcVar16;
LAB_000156c0:
  local_78 = lshift(param_1,local_78,1);
  iVar10 = cmp(local_78,pcVar7);
  if ((iVar10 < 1) && ((iVar10 != 0 || ((uVar13 & 1) == 0)))) {
    do {
      pcVar24 = pcVar14;
      pcVar14 = pcVar24 + -1;
    } while (pcVar24[-1] == '0');
  }
  else {
LAB_00015628:
    do {
      pcVar24 = pcVar14;
      pcVar14 = pcVar24 + -1;
      if (pcVar24[-1] != '9') {
        *pcVar14 = pcVar24[-1] + '\x01';
        goto LAB_000150e8;
      }
    } while (pcVar16 != pcVar14);
    puVar6 = (undefined4 *)((int)puVar6 + 1);
    *pcVar16 = '1';
  }
LAB_000150e8:
  Bfree(param_1,(undefined4 *)pcVar7);
  puVar11 = puVar6;
  if (pcVar20 != (char *)0x0) {
    if ((pcVar18 != (char *)0x0) && (pcVar18 != pcVar20)) {
      Bfree(param_1,(undefined4 *)pcVar18);
    }
    Bfree(param_1,(undefined4 *)pcVar20);
  }
  goto LAB_000152f8;
  while( true ) {
    uVar27 = __muldf3(uVar8,uVar21,0,0x40240000);
    bVar2 = __aeabi_dcmpeq((uint)uVar27,(uint)(uVar27 >> 0x20),0,0);
    puVar11 = puVar6;
    pcVar20 = pcVar24;
    if (bVar2) break;
LAB_00015290:
    uVar8 = (uint)(uVar27 >> 0x20);
    uVar25 = __divdf3((uint)uVar27,uVar8,(uint)local_70,local_70._4_4_);
    uVar13 = _cast_double_to_int((uint)uVar25,(uint)(uVar25 >> 0x20));
    uVar25 = __floatsidf(uVar13);
    uVar25 = __muldf3((uint)uVar25,(uint)(uVar25 >> 0x20),(uint)local_70,local_70._4_4_);
    uVar27 = __subdf((uint)uVar27,uVar8,(uint)uVar25,(uint)(uVar25 >> 0x20));
    uVar21 = (uint)(uVar27 >> 0x20);
    uVar8 = (uint)uVar27;
    pcVar24 = pcVar20 + 1;
    *pcVar20 = (char)uVar13 + '0';
    if (pcVar5 == pcVar24 + -(int)pcVar16) {
      uVar27 = __aeabi_dadd(uVar8,uVar21,uVar8,uVar21);
      uVar8 = (uint)(uVar27 >> 0x20);
      bVar2 = __ltdf2((uint)uVar27,uVar8,(uint)local_70,local_70._4_4_);
      pcVar7 = pcVar24;
      puVar11 = puVar6;
      if ((bVar2) ||
         ((bVar2 = __aeabi_dcmpeq((uint)uVar27,uVar8,(uint)local_70,local_70._4_4_), bVar2 &&
          ((int)(uVar13 << 0x1f) < 0)))) goto LAB_000153b6;
      break;
    }
  }
  goto LAB_000152f8;
  while (pcVar16 != pcVar7) {
LAB_000153b6:
    pcVar24 = pcVar7;
    pcVar7 = pcVar24 + -1;
    if (*pcVar7 != '9') goto LAB_000153ce;
  }
  puVar11 = (undefined4 *)((int)puVar11 + 1);
  *pcVar16 = '0';
LAB_000153ce:
  *pcVar7 = *pcVar7 + '\x01';
LAB_000152f8:
  Bfree(param_1,local_78);
  *pcVar24 = '\0';
  *param_4 = (int)puVar11 + 1;
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = pcVar24;
  }
  return pcVar16;
}


