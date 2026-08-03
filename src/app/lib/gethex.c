/*
 * Function: gethex
 * Entry:    0007b3b8
 * Prototype: byte * __stdcall gethex(size_t param_1, int * param_2, int * param_3, int * param_4, undefined4 * param_5, uint param_6)
 */


/* exclude_from_export_ai */

byte * gethex(size_t param_1,int *param_2,int *param_3,int *param_4,undefined4 *param_5,uint param_6
             )

{
  byte bVar1;
  bool bVar2;
  bool bVar3;
  char cVar4;
  size_t n;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  byte *extraout_r1;
  byte *extraout_r1_00;
  int iVar8;
  uint extraout_r1_01;
  uint uVar9;
  byte *extraout_r2;
  byte *extraout_r2_00;
  int extraout_r2_01;
  byte *extraout_r3;
  uint uVar10;
  int *piVar11;
  int *piVar12;
  byte *pbVar13;
  int iVar14;
  byte *pbVar15;
  byte *s1;
  byte *s1_00;
  uint *puVar16;
  byte *pbVar17;
  uint uVar18;
  uint *local_40;
  
  n = strlen(".");
  bVar1 = "Registrazione della Nota rapida..."[n + 0x20];
  pbVar17 = (byte *)(*param_2 + 2);
  do {
    s1_00 = pbVar17;
    pbVar17 = s1_00 + 1;
  } while (*s1_00 == 0x30);
  pbVar17 = s1_00 + (-2 - *param_2);
  cVar4 = __hexdig_fun((uint)*s1_00);
  if (cVar4 == '\0') {
    iVar5 = strncmp((char *)s1_00,".",n);
    s1 = s1_00;
    if (iVar5 == 0) {
      pbVar13 = s1_00 + n;
      cVar4 = __hexdig_fun((uint)s1_00[n]);
      pbVar15 = pbVar13;
      s1 = pbVar13;
      if (cVar4 != '\0') {
        do {
          s1_00 = pbVar15;
          pbVar15 = s1_00 + 1;
        } while (*s1_00 == 0x30);
        cVar4 = __hexdig_fun((uint)*s1_00);
        pbVar17 = (byte *)0x1;
        bVar2 = cVar4 == '\0';
        pbVar15 = s1_00;
        goto LAB_0007b43a;
      }
    }
    iVar5 = 0;
    bVar2 = true;
  }
  else {
    bVar2 = false;
    pbVar13 = (byte *)0x0;
    pbVar15 = s1_00;
LAB_0007b43a:
    do {
      s1 = pbVar15;
      cVar4 = __hexdig_fun((uint)*s1);
      pbVar15 = extraout_r2;
    } while (cVar4 != '\0');
    iVar5 = strncmp((char *)s1,".",n);
    if (iVar5 == 0) {
      if (pbVar13 == (byte *)0x0) {
        pbVar13 = s1 + n;
        pbVar15 = pbVar13;
        do {
          s1 = pbVar15;
          cVar4 = __hexdig_fun((uint)*s1);
          pbVar15 = extraout_r2_00;
        } while (cVar4 != '\0');
      }
    }
    else {
      iVar5 = 0;
      if (pbVar13 == (byte *)0x0) goto LAB_0007b47a;
    }
    iVar5 = ((int)pbVar13 - (int)s1) * 4;
  }
LAB_0007b47a:
  pbVar15 = s1;
  if ((*s1 & 0xdf) == 0x50) {
    if (s1[1] == 0x2b) {
      bVar3 = false;
LAB_0007b4e4:
      pbVar13 = s1 + 2;
    }
    else {
      if (s1[1] == 0x2d) {
        bVar3 = true;
        goto LAB_0007b4e4;
      }
      pbVar13 = s1 + 1;
      bVar3 = false;
    }
    cVar4 = __hexdig_fun((uint)*pbVar13);
    pbVar13 = extraout_r1;
    if ((byte)(cVar4 - 1U) < 0x19) {
      do {
        cVar4 = __hexdig_fun((uint)pbVar13[1]);
        pbVar13 = extraout_r1_00;
      } while ((byte)(cVar4 - 1U) < 0x19);
      iVar8 = extraout_r2_01;
      if (bVar3) {
        iVar8 = -extraout_r2_01;
      }
      iVar5 = iVar5 + iVar8;
      pbVar15 = extraout_r1_00;
    }
  }
  *param_2 = (int)pbVar15;
  if (bVar2) {
    if (pbVar17 != (byte *)0x0) {
      return (byte *)0x0;
    }
    return &DAT_00000006;
  }
  pbVar17 = s1 + (-1 - (int)s1_00);
  uVar9 = 0;
LAB_0007b500:
  if (7 < (int)pbVar17) {
LAB_0007b51a:
    uVar9 = uVar9 + 1;
    pbVar17 = (byte *)((int)pbVar17 >> 1);
    goto LAB_0007b500;
  }
  puVar6 = Balloc(param_1,uVar9);
  if (puVar6 == (undefined4 *)0x0) {
    iVar8 = 0xde;
LAB_0007b514:
    __assert_func("/__w/_temp/workspace/build/.build/HOST-x86_64-w64-mingw32/arm-zephyr-eabi/src/newlib-nano/newlib/libc/stdlib/gdtoa-gethex.c"
                  ,iVar8,(char *)0x0,"Balloc succeeded");
    uVar9 = extraout_r1_01;
    pbVar17 = extraout_r3;
    goto LAB_0007b51a;
  }
  uVar18 = 0;
  puVar16 = puVar6 + 5;
  uVar9 = 0;
  local_40 = puVar16;
  while (pbVar17 = s1, s1_00 < pbVar17) {
    if (((pbVar17[-1] != bVar1) || (s1 = pbVar17 + -1 + (1 - n), s1 < s1_00)) ||
       (iVar8 = strncmp((char *)s1,".",n), iVar8 != 0)) {
      if (uVar18 == 0x20) {
        *local_40 = uVar9;
        uVar9 = 0;
        uVar18 = 0;
        local_40 = local_40 + 1;
      }
      cVar4 = __hexdig_fun((uint)pbVar17[-1]);
      uVar10 = uVar18 & 0xff;
      uVar18 = uVar18 + 4;
      uVar9 = uVar9 | ((int)cVar4 & 0xfU) << uVar10;
      s1 = pbVar17 + -1;
    }
  }
  *local_40 = uVar9;
  iVar14 = (int)local_40 + (4 - (int)puVar16) >> 2;
  puVar6[4] = iVar14;
  iVar8 = hi0bits(uVar9);
  s1_00 = (byte *)*param_3;
  iVar8 = iVar14 * 0x20 - iVar8;
  if ((int)s1_00 < iVar8) {
    uVar18 = iVar8 - (int)s1_00;
    iVar8 = any_on((int)puVar6,uVar18);
    uVar9 = 0;
    if (iVar8 != 0) {
      uVar10 = uVar18 - 1;
      uVar9 = 1;
      if ((1 << (uVar10 & 0x1f) & puVar16[(int)uVar10 >> 5]) != 0) {
        if (((int)uVar10 < 2) || (iVar8 = any_on((int)puVar6,uVar18 - 2), iVar8 == 0)) {
          uVar9 = 2;
        }
        else {
          uVar9 = 3;
        }
      }
    }
    iVar5 = iVar5 + uVar18;
    rshift((int)puVar6,uVar18);
  }
  else {
    if (iVar8 < (int)s1_00) {
      iVar5 = iVar5 - ((int)s1_00 - iVar8);
      puVar6 = lshift(param_1,puVar6,(int)s1_00 - iVar8);
      puVar16 = puVar6 + 5;
    }
    uVar9 = 0;
  }
  puVar7 = puVar6;
  if (param_3[2] < iVar5) goto LAB_0007b59a;
  if (iVar5 < param_3[1]) {
    pbVar17 = (byte *)(param_3[1] - iVar5);
    if ((int)s1_00 <= (int)pbVar17) {
      iVar5 = param_3[3];
      if (iVar5 == 2) {
        if (param_6 != 0) goto LAB_0007b690;
      }
      else {
        if (iVar5 != 3) {
          if ((iVar5 != 1) || (s1_00 != pbVar17)) goto LAB_0007b690;
          if (s1_00 == &DAT_00000001) goto LAB_0007b65e;
          param_6 = any_on((int)puVar6,(uint)(s1_00 + -1));
        }
        if (param_6 == 0) {
LAB_0007b690:
          Bfree(param_1,puVar6);
          *param_5 = 0;
          return (byte *)0x50;
        }
      }
LAB_0007b65e:
      *param_4 = param_3[1];
      puVar6[4] = 1;
      *puVar16 = 1;
      *param_5 = puVar6;
      return (byte *)0x62;
    }
    pbVar15 = pbVar17 + -1;
    if (uVar9 == 0) {
      if (pbVar15 != (byte *)0x0) {
        uVar9 = any_on((int)puVar6,(uint)pbVar15);
      }
    }
    else {
      uVar9 = 1;
    }
    s1_00 = s1_00 + -(int)pbVar17;
    s1 = &DAT_00000002;
    if ((1 << ((uint)pbVar15 & 0x1f) & puVar16[(int)pbVar15 >> 5]) != 0) {
      uVar9 = uVar9 | 2;
    }
    rshift((int)puVar6,(uint)pbVar17);
    iVar5 = param_3[1];
  }
  else {
    s1 = &DAT_00000001;
  }
  if (uVar9 == 0) goto LAB_0007b782;
  iVar8 = param_3[3];
  if (iVar8 != 2) {
    uVar18 = param_6;
    if (iVar8 == 3) goto joined_r0x0007b714;
    if ((iVar8 == 1) && ((uVar9 & 2) != 0)) {
      uVar18 = (uVar9 | *puVar16) & 1;
      goto joined_r0x0007b714;
    }
LAB_0007b716:
    s1 = (byte *)((uint)s1 | 0x10);
    goto LAB_0007b782;
  }
  param_6 = 1 - param_6;
  uVar18 = param_6;
joined_r0x0007b714:
  if (uVar18 == 0) goto LAB_0007b716;
  iVar8 = puVar6[4];
  piVar11 = puVar6 + 5;
  do {
    piVar12 = piVar11 + 1;
    if (*piVar11 != -1) {
      *piVar11 = *piVar11 + 1;
      goto LAB_0007b758;
    }
    *piVar11 = 0;
    piVar11 = piVar12;
  } while (piVar12 < puVar6 + 5 + iVar8);
  if ((int)puVar6[2] <= iVar8) {
    puVar7 = Balloc(param_1,puVar6[1] + 1);
    if (puVar7 == (undefined4 *)0x0) {
      iVar8 = 0x84;
      goto LAB_0007b514;
    }
    memcpy(puVar7 + 3,puVar6 + 3,(puVar6[4] + 2) * 4);
    Bfree(param_1,puVar6);
  }
  iVar14 = puVar7[4];
  puVar7[4] = iVar14 + 1;
  puVar7[iVar14 + 5] = 1;
LAB_0007b758:
  if (s1 == &DAT_00000002) {
    uVar9 = 2;
    if (((byte *)(*param_3 + -1) != s1_00) ||
       ((1 << ((uint)s1_00 & 0x1f) & puVar7[((int)s1_00 >> 5) + 5]) == 0)) goto LAB_0007b77e;
  }
  else if ((iVar8 < (int)puVar7[4]) ||
          ((((uint)s1_00 & 0x1f) != 0 &&
           (iVar8 = hi0bits(puVar7[iVar8 + 4]), iVar8 < (int)(0x20 - ((uint)s1_00 & 0x1f)))))) {
    rshift((int)puVar7,1);
    iVar5 = iVar5 + 1;
    if (param_3[2] < iVar5) {
LAB_0007b59a:
      Bfree(param_1,puVar7);
      *param_5 = 0;
      return (byte *)0xa3;
    }
  }
  uVar9 = 1;
LAB_0007b77e:
  s1 = (byte *)(uVar9 | 0x20);
LAB_0007b782:
  *param_5 = puVar7;
  *param_4 = iVar5;
  return s1;
}


