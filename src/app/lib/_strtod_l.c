/*
 * Function: _strtod_l
 * Entry:    00013eb0
 * Prototype: double __stdcall _strtod_l(char * __nptr, char * * __endptr, __locale_t __loc)
 */


/* exclude_from_export_ai */

double _strtod_l(char *__nptr,char **__endptr,__locale_t __loc)

{
  __locale_data _Var1;
  bool bVar2;
  bool bVar3;
  size_t n;
  byte *pbVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint extraout_r1;
  __locale_data *p_Var8;
  __locale_data *p_Var9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  undefined4 *puVar18;
  uint uVar19;
  uint uVar20;
  undefined4 *puVar21;
  __locale_data *p_Var22;
  uint uVar23;
  uint *puVar24;
  uint uVar25;
  uint uVar26;
  bool bVar27;
  undefined4 uVar28;
  undefined4 extraout_s1;
  longlong lVar29;
  uint extraout_s1_00;
  uint extraout_s1_01;
  uint extraout_s1_02;
  double dVar30;
  double dVar31;
  ulonglong uVar32;
  ulonglong uVar33;
  int local_88;
  undefined4 *local_84;
  undefined4 *local_80;
  undefined4 *local_7c;
  undefined8 local_78;
  uint local_64;
  undefined8 local_48;
  __locale_data *local_3c;
  undefined4 *local_38;
  int local_34;
  uint local_30;
  uint local_2c;
  
  local_38 = (undefined4 *)0x0;
  n = strlen(".");
  for (p_Var8 = (__locale_data *)__endptr; _Var1 = *p_Var8, _Var1 != (__locale_data)0x2b;
      p_Var8 = p_Var8 + 1) {
    if (0x2b < (byte)_Var1) {
      if (_Var1 == (__locale_data)0x2d) {
        local_64 = 1;
        goto LAB_00013f42;
      }
LAB_00013eee:
      local_64 = 0;
      local_3c = p_Var8;
      goto LAB_00013ef2;
    }
    if ((byte)_Var1 < 0xe) {
      if ((byte)_Var1 < 9) {
        if (_Var1 != (__locale_data)0x0) goto LAB_00013eee;
        goto LAB_00013f4e;
      }
    }
    else if (_Var1 != (__locale_data)0x20) goto LAB_00013eee;
  }
  local_64 = 0;
LAB_00013f42:
  local_3c = p_Var8 + 1;
  if (p_Var8[1] == (__locale_data)0x0) goto LAB_00013f4e;
LAB_00013ef2:
  p_Var8 = local_3c;
  if (*local_3c == (__locale_data)0x30) {
    if (((byte)local_3c[1] & 0xdf) == 0x58) {
      pbVar4 = gethex((size_t)__nptr,(int *)&local_3c,(int *)&DAT_0009c2e4,&local_34,&local_38,
                      local_64);
      uVar17 = (uint)pbVar4 & 7;
      dVar31 = 0.0;
      if (uVar17 != 0) {
        if (uVar17 == 6) {
          if (__loc == (__locale_t)0x0) {
            return 0.0;
          }
          __loc->__locales[0] = p_Var8 + 1;
          return 0.0;
        }
        if (local_38 != (undefined4 *)0x0) {
          copybits((int)&local_30,0x35,(int)local_38);
          Bfree((int)__nptr,local_38);
        }
        uVar20 = 0;
        uVar11 = 0;
        switch(uVar17) {
        case 1:
        case 5:
          uVar20 = local_30;
          uVar11 = local_2c & 0xffefffff | (local_34 + 0x433) * 0x100000;
          break;
        case 2:
          uVar20 = local_30;
          uVar11 = local_2c;
          break;
        case 3:
          uVar11 = 0x7ff00000;
          break;
        case 4:
          uVar20 = 0xffffffff;
          uVar11 = 0x7fffffff;
        }
        dVar31 = (double)CONCAT44(uVar11,uVar20);
        if ((int)pbVar4 << 0x1c < 0) {
          dVar31 = (double)(CONCAT44(uVar11,uVar20) | 0x8000000000000000);
        }
      }
      goto LAB_00013f8e;
    }
    do {
      p_Var9 = local_3c + 1;
      p_Var8 = local_3c + 1;
      local_3c = p_Var9;
    } while (*p_Var8 == (__locale_data)0x30);
    dVar31 = 0.0;
    if (*p_Var8 == (__locale_data)0x0) goto LAB_00013f8e;
    bVar27 = true;
  }
  else {
    bVar27 = false;
  }
  p_Var8 = local_3c;
  uVar17 = 0;
  local_84 = (undefined4 *)0x0;
  local_80 = (undefined4 *)0x0;
  while( true ) {
    uVar20 = (uint)(byte)*local_3c;
    uVar11 = uVar20 - 0x30;
    if (9 < (uVar11 & 0xff)) break;
    local_3c = local_3c + 1;
    if ((int)local_84 < 9) {
      local_80 = (undefined4 *)((int)local_80 * 10 + uVar11);
    }
    else {
      uVar17 = uVar17 * 10 + uVar11;
    }
    local_84 = (undefined4 *)((int)local_84 + 1);
  }
  iVar5 = strncmp((char *)local_3c,".",n);
  puVar18 = local_84;
  if (iVar5 == 0) {
    uVar20 = (uint)(byte)local_3c[n];
    if (local_84 != (undefined4 *)0x0) {
      iVar6 = 0;
      iVar5 = 0;
      local_3c = local_3c + n;
      goto LAB_0001407e;
    }
    iVar16 = 0;
    local_3c = local_3c + n;
    while (uVar20 == 0x30) {
      iVar16 = iVar16 + 1;
      uVar20 = (uint)(byte)local_3c[1];
      local_3c = local_3c + 1;
    }
    if (uVar20 - 0x31 < 9) {
      iVar6 = 0;
      puVar18 = (undefined4 *)0x0;
      p_Var8 = local_3c;
      do {
        iVar10 = uVar20 - 0x30;
        iVar5 = iVar6 + 1;
        if (iVar10 != 0) {
          iVar16 = iVar16 + iVar6 + 1;
          iVar5 = (int)puVar18;
          while (iVar5 != iVar6 + (int)puVar18) {
            iVar12 = iVar5 + 1;
            if (iVar5 < 9) {
              local_80 = (undefined4 *)((int)local_80 * 10);
              iVar5 = iVar12;
            }
            else {
              iVar5 = iVar12;
              if (iVar12 < 0x11) {
                uVar17 = uVar17 * 10;
              }
            }
          }
          iVar5 = (int)puVar18 + iVar6;
          puVar18 = (undefined4 *)((int)puVar18 + 1 + iVar6);
          if (iVar5 < 9) {
            local_80 = (undefined4 *)((int)local_80 * 10 + iVar10);
          }
          else if (iVar5 < 0x10) {
            uVar17 = uVar17 * 10 + iVar10;
          }
          iVar5 = 0;
        }
        iVar6 = iVar5;
        uVar20 = (uint)(byte)local_3c[1];
        iVar5 = iVar16;
        local_3c = local_3c + 1;
LAB_0001407e:
        iVar16 = iVar5;
      } while (uVar20 - 0x30 < 10);
      bVar3 = true;
      iVar16 = iVar6;
      goto LAB_00014018;
    }
    if ((uVar20 == 0x65) || (uVar20 == 0x45)) {
      iVar5 = 0;
      bVar3 = true;
LAB_00014022:
      if (!bVar27 && iVar16 == 0) goto LAB_00013f4e;
      puVar18 = (undefined4 *)0x0;
      goto LAB_0001402a;
    }
    bVar3 = true;
LAB_00014184:
    dVar31 = 0.0;
    if (iVar16 != 0 || bVar27) goto LAB_00013f8e;
    if (bVar3) goto LAB_00013f4e;
    if (uVar20 != 0x69) {
      if (uVar20 < 0x6a) {
        if (uVar20 == 0x49) goto LAB_000141ea;
        bVar27 = uVar20 == 0x4e;
      }
      else {
        bVar27 = uVar20 == 0x6e;
      }
      if ((!bVar27) || (iVar5 = match(&local_3c,(byte *)0xbecee), iVar5 == 0)) {
LAB_00013f4e:
        if (__loc == (__locale_t)0x0) {
          return 0.0;
        }
        __loc->__locales[0] = (__locale_data *)__endptr;
        return 0.0;
      }
      if ((*local_3c == (__locale_data)0x28) &&
         (iVar5 = hexnan((int *)&local_3c,(uint *)&DAT_0009c2d0,&local_30), iVar5 == 5)) {
        dVar31 = (double)(CONCAT44(local_2c,local_30) | 0x7ff0000000000000);
      }
      else {
        uVar28 = log_outline_float_math();
        dVar31 = (double)CONCAT44(extraout_s1,uVar28);
      }
      goto LAB_00013f8e;
    }
LAB_000141ea:
    iVar5 = match(&local_3c,(byte *)0xeef80);
    if (iVar5 == 0) goto LAB_00013f4e;
    local_3c = local_3c + -1;
    iVar5 = match(&local_3c,(byte *)0xf6be4);
    if (iVar5 == 0) {
      local_3c = local_3c + 1;
    }
  }
  else {
    iVar5 = 0;
    bVar3 = false;
    iVar16 = 0;
LAB_00014018:
    if ((uVar20 == 0x65) || (p_Var9 = local_3c, uVar20 == 0x45)) {
      if (puVar18 == (undefined4 *)0x0) goto LAB_00014022;
LAB_0001402a:
      __endptr = (char **)local_3c;
      uVar20 = (uint)(byte)local_3c[1];
      if (uVar20 == 0x2b) {
        bVar2 = false;
LAB_00014118:
        uVar20 = (uint)(byte)local_3c[2];
        local_3c = local_3c + 2;
      }
      else {
        if (uVar20 == 0x2d) {
          bVar2 = true;
          goto LAB_00014118;
        }
        bVar2 = false;
        local_3c = local_3c + 1;
      }
      p_Var9 = (__locale_data *)__endptr;
      if (9 < uVar20 - 0x30) goto LAB_00014048;
      while (p_Var9 = local_3c, uVar20 == 0x30) {
        uVar20 = (uint)(byte)local_3c[1];
        local_3c = local_3c + 1;
      }
      if (8 < uVar20 - 0x31) goto LAB_00014048;
      while( true ) {
        local_7c = (undefined4 *)(uVar20 - 0x30);
        p_Var22 = local_3c + 1;
        uVar20 = (uint)(byte)local_3c[1];
        local_3c = p_Var22;
        if (9 < uVar20 - 0x30) break;
        uVar20 = (int)local_7c * 10 + uVar20;
      }
      puVar21 = (undefined4 *)19999;
      if (((int)p_Var22 - (int)p_Var9 < 9) && ((int)local_7c < 20000)) {
        puVar21 = local_7c;
      }
      if (bVar2) {
        puVar21 = (undefined4 *)-(int)puVar21;
      }
    }
    else {
LAB_00014048:
      local_3c = p_Var9;
      puVar21 = (undefined4 *)0x0;
    }
    if (puVar18 == (undefined4 *)0x0) goto LAB_00014184;
    uVar20 = (int)puVar21 - iVar5;
    if (local_84 == (undefined4 *)0x0) {
      local_84 = puVar18;
    }
    iVar16 = (int)puVar18;
    if (0xf < (int)puVar18) {
      iVar16 = 0x10;
    }
    dVar31 = (double)__floatunsidf((uint)local_80);
    if ((int)puVar18 < 10) {
LAB_0001424a:
      uVar17 = (uint)((ulonglong)dVar31 >> 0x20);
      if (uVar20 == 0) goto LAB_00013f8e;
      if ((int)uVar20 < 1) {
        if (-0x17 < (int)uVar20) {
          dVar31 = (double)__divdf3(SUB84(dVar31,0),uVar17,
                                    (&DAT_0008c0b8)[(iVar5 - (int)puVar21) * 2],
                                    (&DAT_0008c0bc)[(iVar5 - (int)puVar21) * 2]);
          goto LAB_00013f8e;
        }
        goto LAB_0001429e;
      }
      if ((int)uVar20 < 0x17) {
        uVar32 = *(ulonglong *)(&DAT_0008c0b8 + uVar20 * 2);
      }
      else {
        if (0x25 - (int)puVar18 < (int)uVar20) {
          uVar17 = ((int)puVar18 - iVar16) + uVar20;
          goto LAB_000142f4;
        }
        iVar5 = 0xf - (int)puVar18;
        uVar32 = __muldf3((&DAT_0008c0b8)[iVar5 * 2],(&DAT_0008c0bc)[iVar5 * 2],SUB84(dVar31,0),
                          uVar17);
        dVar31 = *(double *)(&DAT_0008c0b8 + (uVar20 - iVar5) * 2);
      }
      dVar31 = (double)__muldf3((uint)uVar32,(uint)(uVar32 >> 0x20),SUB84(dVar31,0),
                                (uint)((ulonglong)dVar31 >> 0x20));
      goto LAB_00013f8e;
    }
    uVar32 = __muldf3(SUB84(dVar31,0),(uint)((ulonglong)dVar31 >> 0x20),(&DAT_0008c070)[iVar16 * 2],
                      (&DAT_0008c074)[iVar16 * 2]);
    uVar33 = __floatunsidf(uVar17);
    dVar31 = (double)__aeabi_dadd((uint)uVar32,(uint)(uVar32 >> 0x20),(uint)uVar33,
                                  (uint)(uVar33 >> 0x20));
    if ((int)puVar18 < 0x10) goto LAB_0001424a;
LAB_0001429e:
    uVar17 = ((int)puVar18 - iVar16) + uVar20;
    if ((int)uVar17 < 1) {
      if (uVar17 == 0) {
LAB_000143f0:
        local_88 = 0;
      }
      else {
        uVar11 = -uVar17 & 0xf;
        if (uVar11 != 0) {
          dVar31 = (double)__divdf3(SUB84(dVar31,0),(uint)((ulonglong)dVar31 >> 0x20),
                                    (&DAT_0008c0b8)[uVar11 * 2],(&DAT_0008c0bc)[uVar11 * 2]);
        }
        uVar17 = (int)-uVar17 >> 4;
        if (uVar17 == 0) goto LAB_000143f0;
        if (0x1f < (int)uVar17) {
LAB_000142d6:
          dVar31 = 0.0;
          __nptr[0] = '\"';
          __nptr[1] = '\0';
          __nptr[2] = '\0';
          __nptr[3] = '\0';
          goto LAB_00013f8e;
        }
        puVar24 = &DAT_0008c068;
        local_88 = 0;
        if ((uVar17 & 0x10) != 0) {
          local_88 = 0x6a;
        }
        bVar27 = false;
        dVar30 = dVar31;
        do {
          if ((int)(uVar17 << 0x1f) < 0) {
            dVar30 = (double)__muldf3(SUB84(dVar30,0),(uint)((ulonglong)dVar30 >> 0x20),*puVar24,
                                      puVar24[1]);
            bVar27 = true;
          }
          uVar17 = (int)uVar17 >> 1;
          puVar24 = puVar24 + 2;
        } while (uVar17 != 0);
        if (bVar27) {
          dVar31 = dVar30;
        }
        uVar17 = (uint)((ulonglong)dVar31 >> 0x20);
        if (local_88 != 0) {
          uVar11 = (uVar17 & 0x7fffffff) >> 0x14;
          uVar13 = 0x6b - uVar11;
          if (0 < (int)uVar13) {
            if ((int)uVar13 < 0x20) {
              dVar31 = (double)CONCAT44(uVar17,-1 << (uVar13 & 0xff) & SUB84(dVar31,0));
            }
            else {
              if ((int)uVar13 < 0x35) {
                uVar17 = -1 << (0x4b - uVar11 & 0xff) & uVar17;
              }
              else {
                uVar17 = 0x3700000;
              }
              dVar31 = (double)((ulonglong)uVar17 << 0x20);
            }
          }
          local_88 = 0x6a;
        }
        bVar27 = __aeabi_dcmpeq(SUB84(dVar31,0),(uint)((ulonglong)dVar31 >> 0x20),0,0);
        if (bVar27) goto LAB_000142d6;
      }
      puVar18 = (undefined4 *)s2b((size_t)__nptr,(int)p_Var8,(int)local_84,(int)puVar18,local_80);
      if (puVar18 != (undefined4 *)0x0) {
        uVar17 = iVar5 - (int)puVar21;
        if (-1 < (int)uVar20) {
          uVar17 = 0;
        }
        uVar11 = uVar20 & ~((int)uVar20 >> 0x1f);
        local_7c = (undefined4 *)0x0;
        local_84 = (undefined4 *)0x0;
        while( true ) {
          uVar13 = (uint)((ulonglong)dVar31 >> 0x20);
          uVar7 = SUB84(dVar31,0);
          local_80 = Balloc((size_t)__nptr,puVar18[1]);
          if (local_80 == (undefined4 *)0x0) break;
          memcpy(local_80 + 3,puVar18 + 3,(puVar18[4] + 2) * 4);
          lVar29 = ((ulonglong)uVar13 << 0x20) + ((ulonglong)dVar31 & 0xffffffff);
          local_38 = d2b((uint)lVar29,(uint)((ulonglong)lVar29 >> 0x20),(size_t)__nptr,&local_34,
                         (int *)&local_30);
          if (local_38 == (undefined4 *)0x0) break;
          local_84 = (undefined4 *)i2b((size_t)__nptr,1);
          if (local_84 == (undefined4 *)0x0) {
LAB_00014510:
            local_84 = (undefined4 *)0x0;
            break;
          }
          if (local_34 < 0) {
            uVar23 = uVar11 - local_34;
            uVar25 = uVar17;
          }
          else {
            uVar25 = local_34 + uVar17;
            uVar23 = uVar11;
          }
          iVar5 = 0x36 - local_30;
          iVar16 = (local_34 - local_88) + local_30 + -1;
          if (iVar16 < -0x3fe) {
            uVar14 = -iVar16 - 0x3fe;
            uVar19 = 1;
            iVar5 = iVar5 - uVar14;
            if ((int)uVar14 < 0x20) {
              uVar19 = 1 << (uVar14 & 0xff);
              uVar14 = 0;
            }
            else {
              uVar14 = 1 << (0xfffffbe2U - iVar16 & 0xff);
            }
          }
          else {
            uVar14 = 0;
            uVar19 = 1;
          }
          uVar26 = uVar25 + iVar5;
          uVar23 = uVar23 + iVar5 + local_88;
          uVar15 = uVar25;
          if ((int)uVar26 <= (int)uVar25) {
            uVar15 = uVar26;
          }
          if ((int)uVar23 <= (int)uVar15) {
            uVar15 = uVar23;
          }
          if (0 < (int)uVar15) {
            uVar26 = uVar26 - uVar15;
            uVar23 = uVar23 - uVar15;
            uVar25 = uVar25 - uVar15;
          }
          if (0 < (int)uVar17) {
            local_84 = pow5mult((size_t)__nptr,local_84,uVar17);
            if (local_84 == (undefined4 *)0x0) goto LAB_00014510;
            puVar21 = (undefined4 *)mult((size_t)__nptr,(int)local_84,(int)local_38);
            if (puVar21 == (undefined4 *)0x0) break;
            Bfree((int)__nptr,local_38);
            local_38 = puVar21;
          }
          if ((0 < (int)uVar26) &&
             (local_38 = lshift((size_t)__nptr,local_38,uVar26), local_38 == (undefined4 *)0x0))
          break;
          if (((0 < (int)uVar20) &&
              (local_80 = pow5mult((size_t)__nptr,local_80,uVar11), local_80 == (undefined4 *)0x0))
             || ((0 < (int)uVar23 &&
                 (local_80 = lshift((size_t)__nptr,local_80,uVar23), local_80 == (undefined4 *)0x0))
                )) {
            local_80 = (undefined4 *)0x0;
            break;
          }
          if (((0 < (int)uVar25) &&
              (local_84 = lshift((size_t)__nptr,local_84,uVar25), local_84 == (undefined4 *)0x0)) ||
             (local_7c = diff((size_t)__nptr,local_38,local_80), local_7c == (undefined4 *)0x0))
          break;
          iVar16 = local_7c[3];
          local_7c[3] = 0;
          iVar5 = cmp(local_7c,local_84);
          if (iVar5 < 0) {
            if (((iVar16 == 0 && uVar7 == 0) && (((ulonglong)dVar31 & 0xfffff00000000) == 0)) &&
               ((0x6b00000 < (uVar13 & 0x7ff00000) && ((local_7c[5] != 0 || (1 < (int)local_7c[4])))
                ))) {
              local_7c = lshift((size_t)__nptr,local_7c,1);
              iVar5 = cmp(local_7c,local_84);
              if (iVar5 < 1) goto LAB_000147de;
LAB_000146a8:
              uVar13 = uVar13 & 0x7ff00000;
              if (local_88 == 0) {
                dVar31 = (double)CONCAT44(~(~(uVar13 - 0x100000 >> 0x14) << 0x14),0xffffffff);
                goto LAB_00014376;
              }
              if (uVar13 < 0x6b00001) {
                if (uVar13 < 0x3700001) goto LAB_000146c2;
              }
              else {
                dVar31 = (double)CONCAT44(~(~(uVar13 - 0x100000 >> 0x14) << 0x14),0xffffffff);
              }
            }
            else {
LAB_000147de:
              if (local_88 == 0) goto LAB_00014376;
            }
LAB_00014750:
            dVar31 = (double)__muldf3(SUB84(dVar31,0),(uint)((ulonglong)dVar31 >> 0x20),0,0x39500000
                                     );
            if (dVar31 == 0.0) {
LAB_000146ca:
              __nptr[0] = '\"';
              __nptr[1] = '\0';
              __nptr[2] = '\0';
              __nptr[3] = '\0';
            }
            goto LAB_00014376;
          }
          if (iVar5 == 0) {
            if (iVar16 == 0) {
              if (((ulonglong)dVar31 & 0xfffff00000000) == 0) {
                if (uVar7 == 0) goto LAB_000146a8;
                if (uVar14 != 0) goto LAB_00014792;
                bVar27 = (uVar7 & uVar19) == 0;
              }
              else if (uVar14 == 0) {
                bVar27 = (uVar19 & uVar7) == 0;
              }
              else {
LAB_00014792:
                bVar27 = (uVar14 & uVar13) == 0;
              }
              if (bVar27) goto LAB_000147de;
              uVar17 = sulp(uVar7,uVar13,local_88);
              dVar31 = (double)__subdf(uVar7,uVar13,uVar17,extraout_s1_01);
              bVar27 = __aeabi_dcmpeq(SUB84(dVar31,0),(uint)((ulonglong)dVar31 >> 0x20),0,0);
              if (!bVar27) goto LAB_000147de;
LAB_000146c2:
              dVar31 = 0.0;
              goto LAB_000146ca;
            }
            if ((uVar13 & 0xfffff) == 0xfffff) {
              if (local_88 != 0) {
                uVar17 = uVar13 & 0x7ff00000;
                if (uVar17 < 0x6a00001) {
                  if (uVar7 != -1 << (0x6b - (uVar17 >> 0x14) & 0xff)) goto LAB_0001477a;
                }
                else {
                  if (uVar7 != 0xffffffff) {
LAB_0001477a:
                    if (uVar14 == 0) {
                      uVar14 = uVar7 & uVar19;
                    }
                    else {
                      uVar14 = uVar14 & uVar13;
                    }
                    if (uVar14 == 0) goto LAB_00014750;
                    goto LAB_000147c4;
                  }
                  if (uVar13 == 0x7fefffff) break;
                }
                dVar31 = (double)((ulonglong)(uVar17 + 0x100000) << 0x20);
                goto LAB_00014750;
              }
              if (uVar7 == 0xffffffff) {
                if (uVar13 != 0x7fefffff) {
                  dVar31 = (double)((ulonglong)((uVar13 & 0x7ff00000) + 0x100000) << 0x20);
                  goto LAB_00014376;
                }
                break;
              }
              if (uVar14 == 0) {
                uVar14 = uVar7 & uVar19;
              }
              else {
                uVar14 = uVar14 & uVar13;
              }
              if (uVar14 == 0) goto LAB_00014376;
            }
            else {
              if (uVar14 == 0) {
                uVar14 = uVar19 & uVar7;
              }
              else {
                uVar14 = uVar14 & uVar13;
              }
              if (uVar14 == 0) goto LAB_000147de;
            }
LAB_000147c4:
            uVar17 = sulp(uVar7,uVar13,local_88);
            dVar31 = (double)__aeabi_dadd(uVar7,uVar13,uVar17,extraout_s1_00);
            goto LAB_000147de;
          }
          uVar23 = ratio((int)local_7c,(int)local_84);
          bVar27 = __ledf2(uVar23,extraout_s1_02,0,0x40000000);
          if (bVar27) {
            if (iVar16 == 0) {
              if (uVar7 == 0) {
                if (((ulonglong)dVar31 & 0xfffff00000000) == 0) {
                  bVar27 = __gedf2(uVar23,extraout_s1_02,0,0x3ff00000);
                  if (bVar27) {
                    uVar32 = 0x3fe0000000000000;
                  }
                  else {
                    uVar32 = __muldf3(uVar23,extraout_s1_02,0,0x3fe00000);
                  }
                  goto LAB_00014892;
                }
              }
              else if (dVar31 == 4.94065645841247e-324) goto LAB_000146c2;
              uVar32 = 0x3ff0000000000000;
              local_78 = 0xbff0000000000000;
            }
            else {
              uVar32 = 0x3ff0000000000000;
              local_78 = 0x3ff0000000000000;
            }
          }
          else {
            uVar32 = __muldf3(uVar23,extraout_s1_02,0,0x3fe00000);
            local_78 = uVar32;
            if (iVar16 == 0) {
LAB_00014892:
              local_78 = CONCAT44((int)(uVar32 >> 0x20) + -0x80000000,(int)uVar32);
            }
          }
          uVar25 = (uint)(uVar32 >> 0x20);
          uVar23 = uVar13 & 0x7ff00000;
          if (uVar23 == 0x7fe00000) {
            dVar30 = ulp((double)(((ulonglong)(uVar13 + 0xfcb00000) << 0x20) +
                                 ((ulonglong)dVar31 & 0xffffffff)));
            uVar33 = __muldf3(SUB84(dVar30,0),(uint)((ulonglong)dVar30 >> 0x20),(uint)local_78,
                              local_78._4_4_);
            uVar33 = __aeabi_dadd((uint)uVar33,(uint)(uVar33 >> 0x20),uVar7,uVar13 + 0xfcb00000);
            uVar13 = (uint)(uVar33 >> 0x20);
            if ((uVar13 & 0x7ff00000) < 0x7ca00000) {
              dVar31 = (double)CONCAT44(uVar13 + 0x3500000,(int)uVar33);
              goto LAB_0001499c;
            }
            if (dVar31 == 1.79769313486232e+308) break;
            dVar31 = 1.79769313486232e+308;
          }
          else {
            if ((local_88 != 0) && (uVar23 < 0x6a00001)) {
              bVar27 = __ledf2((uint)uVar32,uVar25,0xffc00000,0x41dfffff);
              if (bVar27) {
                uVar25 = __fixunsdfsi((uint)uVar32,uVar25);
                if (uVar25 == 0) {
                  uVar25 = 1;
                }
                uVar32 = __floatunsidf(uVar25);
                local_48 = uVar32;
                if (iVar16 == 0) {
                  local_48 = CONCAT44((int)(uVar32 >> 0x20) + -0x80000000,(int)uVar32);
                }
                local_78._0_4_ = (uint)local_48;
                local_78._4_4_ = local_48._4_4_;
              }
              local_78._4_4_ = (local_78._4_4_ + 0x6b00000) - uVar23;
            }
            dVar31 = ulp(dVar31);
            uVar33 = __muldf3((uint)local_78,local_78._4_4_,SUB84(dVar31,0),
                              (uint)((ulonglong)dVar31 >> 0x20));
            dVar31 = (double)__aeabi_dadd((uint)uVar33,(uint)(uVar33 >> 0x20),uVar7,uVar13);
LAB_0001499c:
            uVar13 = (uint)(uVar32 >> 0x20);
            if ((local_88 == 0) && (uVar23 == ((uint)((ulonglong)dVar31 >> 0x20) & 0x7ff00000))) {
              uVar7 = __fixdfsi((uint)uVar32,uVar13);
              uVar33 = __aeabi_l2d(uVar7,extraout_r1);
              uVar32 = __subdf((uint)uVar32,uVar13,(uint)uVar33,(uint)(uVar33 >> 0x20));
              uVar7 = (uint)(uVar32 >> 0x20);
              uVar13 = (uint)uVar32;
              if ((((ulonglong)dVar31 & 0xfffff00000000) == 0 && SUB84(dVar31,0) == 0) &&
                  iVar16 == 0) {
                bVar27 = __gedf2(uVar13,uVar7,0x94a03595,0x3fcfffff);
              }
              else {
                bVar27 = __gedf2(uVar13,uVar7,0x94a03595,0x3fdfffff);
                if (bVar27) goto LAB_00014376;
                bVar27 = __ltdf2(uVar13,uVar7,0x35afe535,0x3fe00000);
              }
              if (bVar27 != false) goto LAB_00014376;
            }
          }
          Bfree((int)__nptr,local_38);
          Bfree((int)__nptr,local_80);
          Bfree((int)__nptr,local_84);
          Bfree((int)__nptr,local_7c);
        }
        dVar31 = INFINITY;
        __nptr[0] = '\"';
        __nptr[1] = '\0';
        __nptr[2] = '\0';
        __nptr[3] = '\0';
LAB_00014376:
        Bfree((int)__nptr,local_38);
        Bfree((int)__nptr,local_80);
        Bfree((int)__nptr,local_84);
        Bfree((int)__nptr,puVar18);
        Bfree((int)__nptr,local_7c);
        goto LAB_00013f8e;
      }
    }
    else {
LAB_000142f4:
      uVar11 = uVar17 & 0xf;
      if (uVar11 != 0) {
        dVar31 = (double)__muldf3((&DAT_0008c0b8)[uVar11 * 2],(&DAT_0008c0bc)[uVar11 * 2],
                                  SUB84(dVar31,0),(uint)((ulonglong)dVar31 >> 0x20));
      }
      if ((uVar17 & 0xfffffff0) == 0) goto LAB_000143f0;
      if ((int)(uVar17 & 0xfffffff0) < 0x135) {
        bVar27 = false;
        iVar16 = (int)uVar17 >> 4;
        puVar24 = &DAT_0008c090;
        local_88 = 0;
        dVar30 = dVar31;
        while( true ) {
          if (iVar16 < 2) break;
          if (iVar16 << 0x1f < 0) {
            dVar30 = (double)__muldf3(SUB84(dVar30,0),(uint)((ulonglong)dVar30 >> 0x20),*puVar24,
                                      puVar24[1]);
            bVar27 = true;
          }
          iVar16 = iVar16 >> 1;
          puVar24 = puVar24 + 2;
          local_88 = local_88 + 1;
        }
        if (bVar27) {
          dVar31 = dVar30;
        }
        uVar17 = (int)((ulonglong)dVar31 >> 0x20) + 0xfcb00000;
        uVar32 = __muldf3((&DAT_0008c090)[local_88 * 2],(&DAT_0008c094)[local_88 * 2],
                          SUB84(dVar31,0),uVar17);
        uVar11 = (uint)(uVar32 >> 0x20);
        uVar28 = (undefined4)uVar32;
        uVar13 = uVar11 & 0x7ff00000;
        if (uVar13 < 0x7ca00001) {
          if (0x7c900000 < uVar13) {
            uVar17 = 0x7fefffff;
            uVar28 = 0xffffffff;
          }
          dVar31 = (double)CONCAT44(uVar17,uVar28);
          if (uVar13 < 0x7c900001) {
            dVar31 = (double)CONCAT44(uVar11 + 0x3500000,uVar28);
          }
          goto LAB_000143f0;
        }
      }
    }
    __nptr[0] = '\"';
    __nptr[1] = '\0';
    __nptr[2] = '\0';
    __nptr[3] = '\0';
  }
  dVar31 = INFINITY;
LAB_00013f8e:
  if (__loc != (__locale_t)0x0) {
    __loc->__locales[0] = local_3c;
  }
  if (local_64 != 0) {
    dVar31 = (double)CONCAT44((int)((ulonglong)dVar31 >> 0x20) + -0x80000000,SUB84(dVar31,0));
  }
  return dVar31;
}


