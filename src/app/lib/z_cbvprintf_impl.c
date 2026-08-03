/*
 * Function: z_cbvprintf_impl
 * Entry:    00011300
 * Prototype: int __stdcall z_cbvprintf_impl(cbprintf_cb out, void * ctx, char * format, va_list ap, uint32_t flags)
 */


/* WARNING: Type propagation algorithm not settling */
/* WARNING: Unable to use type for symbol bVar9 */
/* exclude_from_export */

int z_cbvprintf_impl(cbprintf_cb out,void *ctx,char *format,va_list ap,uint32_t flags)

{
  ulonglong uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  ushort uVar6;
  ushort uVar7;
  undefined1 uVar8;
  char bVar10;
  char *pbVar9;
  int iVar9;
  uint uVar10;
  size_t sVar11;
  uint uVar12;
  uint extraout_r0;
  char cVar13;
  byte *pbVar14;
  char *pcVar15;
  char *extraout_r1;
  char *extraout_r1_00;
  char *extraout_r1_01;
  byte bVar16;
  byte bVar17;
  uint uVar18;
  uint extraout_r2;
  uint extraout_r2_00;
  uint extraout_r2_01;
  uint extraout_r2_02;
  uint uVar19;
  uint uVar20;
  undefined4 uVar21;
  byte *pbVar22;
  undefined4 *puVar23;
  undefined4 *puVar24;
  byte *pbVar25;
  byte *pbVar26;
  byte *pbVar27;
  byte *pbVar28;
  int iVar29;
  uint uVar30;
  bool bVar31;
  byte *local_90;
  byte *local_88;
  char *local_74;
  undefined8 local_70;
  undefined8 local_68;
  byte *local_60;
  uint local_5c;
  undefined2 local_58;
  undefined2 local_56;
  byte *local_54;
  byte *local_50;
  byte local_44 [25];
  byte abStack_2b [7];
  byte bVar9;
  
  pbVar25 = (byte *)0x0;
  do {
    pbVar9 = (char *)(uint)(byte)*format;
    if (pbVar9 == (char *)0x0) {
      return (int)pbVar25;
    }
    local_88 = (byte *)(format + 1);
    if (pbVar9 != &DAT_00000025) {
LAB_00011324:
      pbVar9 = (char *)(*(code *)out)(pbVar9,ctx);
      if ((int)pbVar9 < 0) {
        return (int)pbVar9;
      }
      pbVar25 = pbVar25 + 1;
      goto switchD_000118a6_caseD_59;
    }
    memset(&local_60,0,0x18);
    if (format[1] == '%') {
      local_88 = (byte *)(format + 2);
      local_56 = CONCAT11('%',(byte)local_56);
    }
    else {
      bVar31 = false;
      bVar2 = false;
      bVar3 = false;
      bVar4 = false;
      bVar5 = false;
      pbVar28 = (byte *)(format + 1);
      while( true ) {
        while( true ) {
          while( true ) {
            while( true ) {
              pbVar14 = pbVar28 + 1;
              bVar17 = *pbVar28;
              if (bVar17 != '+') break;
              bVar4 = true;
              pbVar28 = pbVar14;
            }
            if ('+' < bVar17) break;
            if (bVar17 == ' ') {
              bVar3 = true;
              pbVar28 = pbVar14;
            }
            else {
              if (bVar17 != '#') goto LAB_0001136a;
              bVar2 = true;
              pbVar28 = pbVar14;
            }
          }
          if (bVar17 != '-') break;
          bVar5 = true;
          pbVar28 = pbVar14;
        }
        if (bVar17 != '0') break;
        bVar31 = true;
        pbVar28 = pbVar14;
      }
LAB_0001136a:
      if (bVar31) {
        local_58 = local_58 | 0x40;
      }
      if (bVar2) {
        local_58 = local_58 | 0x20;
      }
      if (bVar3) {
        local_58 = local_58 | 0x10;
      }
      if (bVar4) {
        local_58 = local_58 | 8;
      }
      if (bVar5) {
        local_58 = local_58 | 4;
      }
      if (((byte)local_58 & 0x44) == 0x44) {
        local_58 = local_58 & 0xffbf;
      }
      local_68 = CONCAT44(local_68._4_4_,pbVar28);
      uVar8 = local_58._1_1_;
      local_58 = local_58 | 0x80;
      if (bVar17 == 0x2a) {
        local_58 = CONCAT11(uVar8,(byte)local_58) | 0x100;
        pbVar14 = pbVar28 + 1;
      }
      else {
        pbVar26 = (byte *)extract_conversion((undefined4 *)&local_68);
        pbVar14 = (byte *)local_68;
        if ((byte *)local_68 != pbVar28) {
          local_58 = CONCAT11(local_58._1_1_,
                              (byte)local_58 & 0xfd | (byte)(((uint)pbVar26 >> 0x1f) << 1));
          local_54 = pbVar26;
        }
      }
      bVar17 = local_58._1_1_ & 0xfd | (*pbVar14 == 0x2e) << 1;
      local_58._1_1_ = bVar17;
      if (*pbVar14 == 0x2e) {
        local_68 = CONCAT44(local_68._4_4_,pbVar14 + 1);
        if (pbVar14[1] == 0x2a) {
          local_58._1_1_ = bVar17 | 4;
          pbVar14 = pbVar14 + 2;
        }
        else {
          local_50 = (byte *)extract_conversion((undefined4 *)&local_68);
          local_58._0_1_ =
               (byte)local_58 & 0xfd |
               (byte)((((uint)(byte)local_58 << 0x1e | (uint)local_50) >> 0x1f) << 1);
          pbVar14 = (byte *)local_68;
        }
      }
      bVar9 = *pbVar14;
      if (bVar9 == 0x6c) {
        if (pbVar14[1] != 0x6c) {
          cVar13 = '\x03';
          goto LAB_00011596;
        }
        cVar13 = '\x04';
LAB_00011588:
        local_58._1_1_ = local_58._1_1_ & 0x87 | cVar13 << 3;
        pbVar14 = pbVar14 + 2;
      }
      else {
        if (bVar9 < 0x6d) {
          if (bVar9 == 0x68) {
            if (pbVar14[1] == 0x68) {
              cVar13 = '\x01';
              goto LAB_00011588;
            }
            cVar13 = '\x02';
            goto LAB_00011596;
          }
          if (bVar9 == 0x6a) {
            cVar13 = '\x05';
            goto LAB_00011596;
          }
          if (bVar9 != 0x4c) goto LAB_00011442;
          local_58._0_1_ = (byte)local_58 & 0xfd | 2;
          local_58._1_1_ = local_58._1_1_ & 0x87 | 0x40;
        }
        else {
          if (bVar9 == 0x74) {
            cVar13 = '\a';
          }
          else {
            if (bVar9 != 'z') goto LAB_00011442;
            cVar13 = '\x06';
          }
LAB_00011596:
          local_58._1_1_ = local_58._1_1_ & 0x87 | cVar13 << 3;
        }
        pbVar14 = pbVar14 + 1;
      }
LAB_00011442:
      local_88 = pbVar14 + 1;
      bVar17 = *pbVar14;
      uVar18 = (uint)bVar17;
      local_56 = CONCAT11(bVar17,(byte)local_56);
      if (0x78 < uVar18) goto LAB_00011654;
      if (uVar18 < 0x6e) {
        if (uVar18 < 0x6a) {
          if (0x57 < uVar18) {
            uVar19 = 1 << (uVar18 - 0x58 & 0xff);
            if ((uVar19 & 0xe200) != 0) goto LAB_00011472;
            if ((uVar19 & 0x801) != 0) {
              uVar19 = local_58._1_1_ & 0x78;
              local_56 = local_56 & 0xfff8 | 2;
              if (uVar19 == 0x40) {
                local_58._0_1_ = (byte)local_58 | 1;
              }
              if (uVar18 == 99) {
                if ((local_58._1_1_ & 0x78) != 0) {
                  uVar19 = 1;
                }
                goto LAB_0001169c;
              }
              goto LAB_000114b2;
            }
            if ((uVar19 & 0x21000) != 0) {
              bVar16 = (byte)local_56 & 0xf8 | 1;
              goto LAB_00011646;
            }
            goto LAB_00011654;
          }
          if ((uVar18 != 0x41) && (2 < uVar18 - 0x45)) goto LAB_00011654;
LAB_00011472:
          bVar17 = ((uVar18 & 0xdf) == 0x41) << 7;
          bVar16 = local_58._1_1_ & 0x7f | bVar17;
          local_56 = local_56 & 0xfff8 | 4;
          if ((int)((uint)bVar16 << 0x18) < 0) {
            uVar19 = 1;
            local_58._1_1_ = bVar16;
            goto LAB_0001169c;
          }
          if ((local_58._1_1_ & 0x78) == 0x18) {
            local_58._1_1_ = local_58._1_1_ & 7 | bVar17;
          }
          else {
            bVar17 = local_58._1_1_ & 0x38;
            local_58._1_1_ = bVar16;
            if (bVar17 != 0) goto LAB_00011654;
          }
        }
        else {
LAB_00011654:
          local_58._0_1_ = (byte)local_58 | 1;
        }
LAB_000114b2:
        uVar19 = 0;
      }
      else {
        uVar18 = 1 << (uVar18 - 0x6e & 0xff);
        if ((uVar18 & 0x482) != 0) {
          bVar16 = (byte)local_56 & 0xf8 | 2;
LAB_00011646:
          local_56 = CONCAT11(bVar17,bVar16);
          if ((local_58._1_1_ & 0x78) == 0x40) goto LAB_00011654;
          goto LAB_000114b2;
        }
        if ((uVar18 & 0x24) == 0) {
          if (-1 < (int)(uVar18 << 0x1f)) goto LAB_00011654;
          local_56 = local_56 & 0xfff8 | 3;
          uVar19 = (uint)((local_58._1_1_ & 0x78) == 0x40);
        }
        else {
          uVar19 = (uint)((local_58._1_1_ & 0x78) != 0);
          local_56 = local_56 & 0xfff8 | 3;
        }
      }
LAB_0001169c:
      local_58 = CONCAT11(local_58._1_1_,
                          (byte)local_58 & 0xfd |
                          (byte)((uVar19 & 1 | ((byte)local_58 & 3) >> 1) << 1));
    }
    uVar18 = (uint)local_58._1_1_;
    if ((int)(uVar18 << 0x1f) < 0) {
      local_90 = *(byte **)ap;
      puVar24 = (undefined4 *)(ap + 4);
      if ((int)local_90 < 0) {
        local_58 = local_58 | 4;
        local_90 = (byte *)-(int)local_90;
      }
    }
    else {
      puVar24 = (undefined4 *)ap;
      local_90 = local_54;
      if (-1 < (char)(byte)local_58) {
        local_90 = (byte *)0xffffffff;
      }
    }
    if ((int)(uVar18 << 0x1d) < 0) {
      puVar23 = puVar24 + 1;
      pbVar28 = (byte *)*puVar24;
      puVar24 = puVar23;
      if ((int)pbVar28 < 0) {
        local_58 = local_58 & 0xfdff;
LAB_00011500:
        pbVar28 = (byte *)0xffffffff;
      }
    }
    else {
      pbVar28 = local_50;
      if (-1 < (int)(uVar18 << 0x1e)) goto LAB_00011500;
    }
    uVar7 = local_58;
    local_54 = (byte *)0x0;
    local_50 = (byte *)0x0;
    if ((((byte)local_56 & 7) == 4) && (-1 < (int)((uint)local_58._1_1_ << 0x1e))) {
      if ((short)local_58 < 0) {
        pbVar28 = &DAT_0000000d;
      }
      else {
        pbVar28 = &DAT_00000006;
      }
    }
    bVar17 = (byte)local_56 & 7;
    uVar18 = (local_58._1_1_ & 0x7f) >> 3;
    if (bVar17 == 1) {
      switch(uVar18) {
      case 3:
      case 6:
      case 7:
        local_60 = (byte *)*puVar24;
        local_5c = (int)local_60 >> 0x1f;
LAB_00011772:
        ap = (va_list)(puVar24 + 1);
        break;
      case 4:
      case 5:
switchD_00011726_caseD_4:
        puVar24 = (undefined4 *)((int)puVar24 + 7U & 0xfffffff8);
        ap = (va_list)(puVar24 + 2);
        local_60 = (byte *)*puVar24;
        local_5c = puVar24[1];
        break;
      default:
        pbVar14 = (byte *)*puVar24;
        local_5c = (int)pbVar14 >> 0x1f;
        if (uVar18 == 1) {
          local_60._0_1_ = (char)pbVar14;
          local_5c = (int)(char)local_60 >> 0x1f;
          local_60 = (byte *)(int)(char)local_60;
        }
        else {
          local_60 = pbVar14;
          if (uVar18 == 2) {
            local_60 = (byte *)(int)(short)pbVar14;
            local_5c = ((int)pbVar14 << 0x10) >> 0x1f;
          }
        }
        ap = (va_list)(puVar24 + 1);
      }
    }
    else if (bVar17 == 2) {
      switch(uVar18) {
      case 3:
      case 6:
      case 7:
        ap = (va_list)(puVar24 + 1);
        local_60 = (byte *)*puVar24;
        local_5c = 0;
        break;
      case 4:
      case 5:
        goto switchD_00011726_caseD_4;
      default:
        local_5c = 0;
        local_60 = (byte *)*puVar24;
        if (uVar18 == 1) {
          local_60 = (byte *)((uint)local_60 & 0xff);
          goto LAB_00011772;
        }
        local_5c = 0;
        ap = (va_list)(puVar24 + 1);
        if (uVar18 == 2) {
          local_60 = (byte *)((uint)local_60 & 0xffff);
          goto LAB_000117b2;
        }
      }
    }
    else if (bVar17 == 4) {
      puVar24 = (undefined4 *)((int)puVar24 + 7U & 0xfffffff8);
      local_60 = (byte *)*puVar24;
      local_5c = puVar24[1];
      ap = (va_list)(puVar24 + 2);
    }
    else {
      ap = (va_list)puVar24;
      if (bVar17 == 3) {
        local_60 = (byte *)*puVar24;
LAB_000117b2:
        ap = (va_list)(puVar24 + 1);
      }
    }
    pcVar15 = (char *)local_60;
    uVar19 = (uint)(byte)local_58;
    if ((local_58 & 3) != 0) {
      iVar9 = extract_width(out,ctx,format,(char *)local_88);
      if (iVar9 < 0) {
        return iVar9;
      }
      pbVar25 = pbVar25 + iVar9;
      goto switchD_000118a6_caseD_59;
    }
    uVar30 = (uint)local_56._1_1_;
    if (0x78 < uVar30) goto switchD_000118a6_caseD_59;
    if (uVar30 < 0x58) {
      if (uVar30 == 0x25) {
        pbVar9 = &DAT_00000025;
        goto LAB_00011324;
      }
      if ((0x24 < uVar30) && ((uVar30 == 0x41 || (uVar30 - 0x45 < 3))))
      goto switchD_000118a6_caseD_61;
      goto switchD_000118a6_caseD_59;
    }
    switch(uVar30) {
    case L'X':
    case L'o':
    case L'u':
    case L'x':
      uVar18 = 0;
      goto LAB_000119fa;
    case L'a':
    case L'e':
    case L'f':
    case L'g':
switchD_000118a6_caseD_61:
      if ((int)local_5c < 0) {
        uVar18 = 0x2d;
      }
      else if ((int)(uVar19 << 0x1c) < 0) {
        uVar18 = 0x2b;
      }
      else {
        uVar18 = ((uVar19 & 0x1f) >> 4) << 5;
      }
      uVar10 = (local_5c & 0x7fffffff) >> 0x14;
      uVar20 = local_5c & 0xfffff;
      if (uVar10 == 0) {
        if (local_60 == (byte *)0x0 && uVar20 == 0) {
          bVar31 = false;
        }
        else {
          bVar31 = true;
        }
LAB_00011854:
        local_70._4_4_ = uVar20 << 0xb | (uint)local_60 >> 0x15;
        local_70._0_4_ = (int)local_60 << 0xb;
        if (uVar30 == 0x46) {
          uVar30 = 0x66;
        }
        if ((uVar10 == 0 && (uint)local_70 == 0) && (local_70._4_4_ == 0 && -1 < (int)uVar10)) {
          iVar9 = 0;
        }
        else {
          if (bVar31) {
            while( true ) {
              bVar31 = CARRY4((uint)local_70,(uint)local_70);
              local_70._0_4_ = (uint)local_70 * 2;
              local_70._4_4_ = local_70._4_4_ * 2 + (uint)bVar31;
              if ((int)local_70._4_4_ < 0) break;
              uVar10 = uVar10 - 1;
            }
          }
          iVar9 = uVar10 - 0x3fe;
          local_70._4_4_ = local_70._4_4_ | 0x80000000;
        }
        bVar31 = false;
        pbVar26 = (byte *)0x0;
        uVar10 = (uint)local_70;
        uVar20 = local_70._4_4_;
        while (iVar9 < -2) {
          do {
            iVar29 = iVar9;
            uVar10 = uVar10 >> 1 | uVar20 << 0x1f;
            uVar20 = uVar20 >> 1;
            iVar9 = iVar29 + 1;
          } while (0x33333332 < uVar20);
          bVar31 = true;
          uVar1 = (ulonglong)uVar10;
          uVar10 = (uint)(uVar1 * 5);
          pbVar26 = pbVar26 + -1;
          uVar20 = (int)(uVar1 * 5 >> 0x20) + uVar20 * 5;
          iVar9 = iVar29 + 2;
        }
        if (bVar31) {
          local_70._0_4_ = uVar10;
          local_70._4_4_ = uVar20;
        }
        while (0 < iVar9) {
          bVar31 = 0xfffffffd < (uint)local_70;
          local_70._0_4_ = (uint)local_70 + 2;
          local_70._4_4_ = local_70._4_4_ + bVar31;
          iVar9 = iVar9 + -1;
          pbVar26 = pbVar26 + 1;
          _ldiv5(&local_70);
          do {
            bVar31 = CARRY4((uint)local_70,(uint)local_70);
            local_70._0_4_ = (uint)local_70 * 2;
            local_70._4_4_ = local_70._4_4_ * 2 + (uint)bVar31;
            iVar9 = iVar9 + -1;
          } while (-1 < (int)local_70._4_4_);
        }
        uVar10 = -iVar9 + 4;
        uVar20 = local_70._4_4_ >> (uVar10 & 0xff);
        uVar10 = (uint)local_70 >> (uVar10 & 0xff) | local_70._4_4_ << (iVar9 + 0x1cU & 0xff) |
                 local_70._4_4_ >> (-iVar9 - 0x1cU & 0xff);
        if ((uVar30 & 0xdf) == 0x47) {
          if ((-4 < (int)pbVar26) && ((int)pbVar26 <= (int)pbVar28)) {
            pbVar28 = pbVar28 + -(int)pbVar26;
            if ((int)((uint)(byte)local_58 << 0x1a) < 0) {
              bVar31 = false;
            }
            else {
              bVar31 = false;
              if (pbVar28 != (byte *)0x0) {
                bVar31 = true;
              }
            }
            goto LAB_00011c02;
          }
          uVar30 = uVar30 - 2 & 0xff;
          if (((int)pbVar28 < 1) ||
             (pbVar28 = pbVar28 + -1, (int)((uint)(byte)local_58 << 0x1a) < 0)) {
            bVar31 = false;
          }
          else {
            bVar31 = false;
            if (pbVar28 != (byte *)0x0) {
              bVar31 = true;
            }
          }
LAB_00011bac:
          pbVar14 = pbVar28 + 1;
LAB_00011c0c:
          if (0xf < (int)pbVar14) {
            pbVar14 = &MemManage;
          }
        }
        else {
          bVar31 = false;
          if (uVar30 != 0x66) goto LAB_00011bac;
LAB_00011c02:
          pbVar14 = pbVar28 + (int)pbVar26;
          uVar30 = 0x66;
          if (-1 < (int)pbVar14) goto LAB_00011c0c;
          pbVar14 = (byte *)0x0;
        }
        local_68 = 0x800000000000000;
        local_74 = &MemManage;
        while( true ) {
          if (pbVar14 == (byte *)0x0) break;
          local_68 = CONCAT44(local_68._4_4_ >> 1,
                              (uint)(byte *)local_68 >> 1 | local_68._4_4_ << 0x1f);
          pbVar14 = pbVar14 + -1;
          _ldiv5(&local_68);
        }
        uVar12 = (int)(byte *)local_68 + uVar10;
        local_70._4_4_ = local_68._4_4_ + uVar20 + CARRY4((uint)(byte *)local_68,uVar10);
        uVar10 = local_68._4_4_;
        local_70._0_4_ = uVar12;
        if (0xfffffff < local_70._4_4_) {
          local_70._0_4_ = uVar12 >> 1 | local_70._4_4_ * -0x80000000;
          local_70._4_4_ = local_70._4_4_ >> 1;
          _ldiv5(&local_70);
          pbVar26 = pbVar26 + 1;
          uVar12 = extraout_r0;
          uVar10 = extraout_r2;
        }
        bVar10 = (char)uVar12;
        pbVar22 = (byte *)(uVar19 & 0x20);
        if (uVar30 == 0x66) {
          if ((int)pbVar26 < 1) {
            pcVar15 = &Reserved5;
            local_44[0] = 0x30;
            pbVar22 = pbVar26;
            if ((uVar7 & 0x20) == 0) {
              if ((int)pbVar28 < 1) goto LAB_00011fc6;
              local_44[1] = 0x2e;
              if (pbVar26 != (byte *)0x0) goto LAB_00011c66;
            }
            else {
              local_44[1] = 0x2e;
              if (pbVar26 != (byte *)0x0) {
                if ((int)pbVar28 < 1) {
                  pbVar14 = local_44 + 2;
                  goto LAB_00011d46;
                }
LAB_00011c66:
                local_54 = (byte *)-(int)pbVar26;
                if ((int)pbVar28 <= -(int)pbVar26) {
                  local_54 = pbVar28;
                }
                pbVar28 = pbVar28 + -(int)local_54;
                pcVar15 = (char *)((byte)local_56 & 0xffffffdf | (uint)(0 < (int)local_54) << 5);
                local_56 = CONCAT11(local_56._1_1_,(char)pcVar15);
              }
            }
LAB_00011c88:
            local_44[1] = 0x2e;
            pbVar14 = local_44 + 2;
          }
          else {
            pbVar27 = local_44;
            do {
              pcVar15 = local_74;
              pbVar14 = pbVar27;
              if ((int)local_74 < 1) break;
              uVar12 = convert_value((uint32_t)&local_70,(uint)&local_74,uVar10,(char *)pbVar22);
              pbVar26 = pbVar26 + -1;
              pbVar14 = pbVar27 + 1;
              *pbVar27 = (byte)uVar12;
              pcVar15 = extraout_r1;
              uVar10 = extraout_r2_00;
              pbVar27 = pbVar14;
            } while (pbVar26 != (byte *)0x0);
            bVar10 = (char)uVar12;
            local_54 = pbVar26;
            if ((uVar7 & 0x20) == 0) {
              if ((int)pbVar28 < 1) goto LAB_00011d46;
              pcVar15 = &DAT_0000002e;
              *pbVar14 = 0x2e;
            }
            else {
              *pbVar14 = 0x2e;
            }
            pbVar14 = pbVar14 + 1;
            pbVar22 = (byte *)0x0;
          }
          while ((bVar10 = (char)uVar12, 0 < (int)pbVar28 && (0 < (int)local_74))) {
            uVar12 = convert_value((uint32_t)&local_70,(uint)&local_74,uVar10,local_74);
            pbVar28 = pbVar28 + -1;
            *pbVar14 = (byte)uVar12;
            pcVar15 = extraout_r1_00;
            uVar10 = extraout_r2_01;
            pbVar14 = pbVar14 + 1;
          }
        }
        else {
          uVar12 = convert_value((uint32_t)&local_70,(uint)&local_74,uVar10,(char *)pbVar22);
          local_44[0] = (byte)uVar12;
          if (uVar12 != 0x30) {
            pbVar26 = pbVar26 + -1;
          }
          pcVar15 = extraout_r1_01;
          if (((uVar7 & 0x20) != 0) || (0 < (int)pbVar28)) {
            local_44[1] = 0x2e;
            uVar10 = extraout_r2_02;
            pbVar22 = pbVar26;
            goto LAB_00011c88;
          }
LAB_00011fc6:
          bVar10 = (char)uVar12;
          pbVar14 = local_44 + 1;
          pbVar22 = pbVar26;
        }
LAB_00011d46:
        if (bVar31) {
          do {
            pbVar26 = pbVar14;
            pbVar14 = pbVar26 + -1;
          } while (pbVar26[-1] == 0x30);
          pbVar14 = pbVar26;
          pbVar28 = local_50;
          if (pbVar26[-1] == 0x2e) {
            pbVar14 = pbVar26 + -1;
          }
        }
        local_50 = pbVar28;
        if ((uVar30 & 0xdf) == 0x45) {
          if ((int)pbVar22 < 0) {
            pbVar22 = (byte *)-(int)pbVar22;
            bVar17 = 0x2d;
          }
          else {
            bVar17 = 0x2b;
          }
          if (99 < (int)pbVar22) {
            pcVar15 = (char *)0x64;
          }
          pbVar14[1] = bVar17;
          pbVar28 = pbVar22;
          if (99 < (int)pbVar22) {
            pbVar28 = pbVar22 + -((int)pcVar15 * ((uint)pbVar22 / (uint)pcVar15));
            bVar10 = (char)((uint)pbVar22 / (uint)pcVar15) + '0';
          }
          if ((int)pbVar22 < 100) {
            pbVar26 = pbVar14 + 2;
          }
          else {
            pbVar26 = pbVar14 + 3;
            pbVar14[2] = bVar10;
          }
          *pbVar14 = (byte)uVar30;
          cVar13 = (char)((uint)pbVar28 / 10);
          pbVar14 = pbVar26 + 2;
          *pbVar26 = cVar13 + 0x30;
          pbVar26[1] = (char)pbVar28 + cVar13 * -10 + 0x30;
        }
        if ((int)local_54 < 1) {
          if ((int)local_50 < 1) {
            cVar13 = '\0';
          }
          else {
            cVar13 = '\x01';
          }
        }
        else {
          cVar13 = '\x01';
        }
        local_56 = CONCAT11(local_56._1_1_,(byte)local_56 & 0xbf | cVar13 << 6);
        *pbVar14 = 0;
      }
      else {
        if (uVar10 != 0x7ff) {
          bVar31 = false;
          goto LAB_00011854;
        }
        if (uVar20 == 0 && local_60 == (byte *)0x0) {
          if (((&DAT_000f6aa1)[uVar30 + 1 & 0xff] & 3) == 1) {
            local_44[0] = 0x49;
            local_44[1] = 0x4e;
            local_44[2] = 0x46;
          }
          else {
            local_44[0] = 0x69;
            local_44[1] = 0x6e;
            local_44[2] = 0x66;
          }
        }
        else if (((&DAT_000f6aa1)[uVar30 + 1 & 0xff] & 3) == 1) {
          local_44[0] = 0x4e;
          local_44[1] = 0x41;
          local_44[2] = local_44[0];
        }
        else {
          local_44[0] = 0x6e;
          local_44[1] = 0x61;
          local_44[2] = local_44[0];
        }
        local_58 = local_58 & 0xffbf;
        pbVar14 = local_44 + 3;
      }
      pcVar15 = (char *)local_44;
      goto LAB_00011af0;
    case L'c':
      uVar18 = 0;
      local_44[0] = (byte)local_60;
      pbVar14 = local_44 + 1;
      iVar9 = 1;
      pcVar15 = (char *)local_44;
      goto LAB_00011952;
    case L'd':
    case L'i':
      if ((int)(uVar19 << 0x1c) < 0) {
        uVar18 = 0x2b;
      }
      else {
        uVar18 = ((uVar19 & 0x1f) >> 4) << 5;
      }
      if ((int)local_5c < 0) {
        uVar18 = 0x2d;
        bVar31 = local_60 != (byte *)0x0;
        local_60 = (byte *)-(int)local_60;
        local_5c = -local_5c - (uint)bVar31;
      }
LAB_000119fa:
      pcVar15 = extract_specifier((uint)local_60,local_5c,(byte *)&local_58,(char *)local_44,
                                  (char *)abStack_2b);
LAB_00011a0e:
      if (-1 < (int)pbVar28) {
        local_58 = local_58 & 0xffbf;
        if (abStack_2b + -(int)pcVar15 < pbVar28) {
          local_54 = pbVar28 + -(int)(abStack_2b + -(int)pcVar15);
        }
      }
      if ((byte *)pcVar15 != (byte *)0x0) {
        pbVar14 = abStack_2b;
LAB_00011af0:
        iVar9 = (int)pbVar14 - (int)pcVar15;
        if (uVar18 != 0) {
          iVar9 = iVar9 + 1;
        }
        goto LAB_00011952;
      }
      break;
    case L'n':
      switch(uVar18) {
      case 0:
      case 3:
      case 6:
      case 7:
        *(byte **)local_60 = pbVar25;
        break;
      case 1:
        *local_60 = (byte)pbVar25;
        break;
      case 2:
        *(short *)local_60 = (short)pbVar25;
        break;
      case 4:
      case 5:
        *(byte **)local_60 = pbVar25;
        *(int *)(local_60 + 4) = (int)pbVar25 >> 0x1f;
      }
      break;
    case L'p':
      if (local_60 == (byte *)0x0) {
        pbVar14 = (byte *)0xee997;
        iVar9 = 5;
        pcVar15 = "(nil)";
        uVar18 = 0;
        goto LAB_00011952;
      }
      pcVar15 = extract_specifier((uint)local_60,0,(byte *)&local_58,(char *)local_44,
                                  (char *)abStack_2b);
      local_56 = local_56 & 0xef | 0x7810;
      uVar18 = 0;
      goto LAB_00011a0e;
    case L's':
      if ((int)pbVar28 < 0) {
        sVar11 = strlen((char *)local_60);
      }
      else {
        sVar11 = extract_decimal((char *)local_60,(int)pbVar28);
        if ((byte *)pcVar15 == (byte *)0x0) break;
      }
      uVar18 = 0;
      pbVar14 = (byte *)(pcVar15 + sVar11);
      iVar9 = (int)pbVar14 - (int)pcVar15;
LAB_00011952:
      pbVar28 = local_54;
      uVar7 = local_56 & 0x10;
      if ((local_56 & 0x10) == 0) {
        if ((int)((uint)(byte)local_56 << 0x1c) < 0) {
          iVar9 = iVar9 + 1;
        }
      }
      else {
        iVar9 = iVar9 + 2;
      }
      uVar6 = local_56 & 0x40;
      bVar31 = (local_56 & 0x40) != 0;
      pbVar26 = (byte *)((byte)local_56 & 0x40);
      if (bVar31) {
        pbVar26 = local_50;
      }
      pbVar22 = local_54 + iVar9;
      if (bVar31) {
        pbVar22 = pbVar22 + (int)pbVar26;
      }
      if (0 < (int)local_90) {
        pbVar26 = local_90 + -(int)pbVar22;
        uVar19 = (uint)(byte)local_58;
        local_90 = pbVar26;
        if (-1 < (int)(uVar19 << 0x1d)) {
          pbVar22 = pbVar26;
          if ((int)(uVar19 << 0x19) < 0) {
            if (uVar18 != 0) {
              iVar9 = (*(code *)out)(uVar18,ctx);
              if (iVar9 < 0) {
                return iVar9;
              }
              pbVar25 = pbVar25 + 1;
              uVar18 = (uVar19 & 7) >> 2;
            }
            uVar21 = 0x30;
          }
          else {
            uVar21 = 0x20;
          }
          while (local_90 = pbVar22 + -1, 0 < (int)pbVar22) {
            iVar9 = (*(code *)out)(uVar21,ctx);
            pbVar22 = local_90;
            if (iVar9 < 0) {
              return iVar9;
            }
          }
          pbVar25 = pbVar26 + (int)pbVar25 + -(int)pbVar22;
        }
      }
      if (uVar18 != 0) {
        iVar9 = (*(code *)out)(uVar18,ctx);
        if (iVar9 < 0) {
          return iVar9;
        }
        pbVar25 = pbVar25 + 1;
      }
      if (uVar6 == 0) {
        if (((int)((uint)(byte)local_56 << 0x1b) < 0) || ((int)((uint)(byte)local_56 << 0x1c) < 0))
        {
          iVar9 = (*(code *)out)(0x30,ctx);
          if (iVar9 < 0) {
            return iVar9;
          }
          pbVar25 = pbVar25 + 1;
        }
        if (uVar7 != 0) {
          iVar9 = (*(code *)out)(local_56._1_1_,ctx);
          if (iVar9 < 0) {
            return iVar9;
          }
          pbVar25 = pbVar25 + 1;
        }
        pbVar28 = pbVar28 + (int)pbVar25;
        for (; 0 < (int)pbVar28 - (int)pbVar25; pbVar25 = pbVar25 + 1) {
          iVar9 = (*(code *)out)(0x30,ctx);
          if (iVar9 < 0) {
            return iVar9;
          }
        }
        iVar9 = extract_width(out,ctx,pcVar15,(char *)pbVar14);
        if (iVar9 < 0) {
          return iVar9;
        }
        pbVar25 = pbVar25 + iVar9;
      }
      else {
        pbVar26 = (byte *)pcVar15;
        if ((short)local_58 < 0) {
          while( true ) {
            if (*pbVar26 == 0x70) break;
            iVar9 = (*(code *)out)(*pbVar26,ctx);
            pbVar26 = pbVar26 + 1;
            if (iVar9 < 0) {
              return iVar9;
            }
          }
          iVar9 = (int)pbVar25 - (int)pcVar15;
        }
        else {
          while( true ) {
            if (-1 < (int)((uint)(byte)(&DAT_000f6aa2)[*pbVar26] << 0x1d)) break;
            iVar9 = (*(code *)out)((uint)*pbVar26,ctx);
            pbVar26 = pbVar26 + 1;
            if (iVar9 < 0) {
              return iVar9;
            }
          }
          pbVar27 = pbVar26 + ((int)pbVar25 - (int)pcVar15);
          pbVar25 = pbVar28;
          pbVar22 = pbVar28;
          if (-1 < (int)((uint)(byte)local_56 << 0x1a)) {
            while (pbVar22 = pbVar25 + -1, 0 < (int)pbVar25) {
              iVar9 = (*(code *)out)(0x30,ctx);
              pbVar25 = pbVar22;
              if (iVar9 < 0) {
                return iVar9;
              }
            }
            pbVar27 = pbVar28 + (int)pbVar27 + -(int)pbVar25;
          }
          pbVar25 = pbVar26;
          if (*pbVar26 == 0x2e) {
            iVar9 = (*(code *)out)(0x2e,ctx);
            while( true ) {
              if (iVar9 < 0) {
                return iVar9;
              }
              pbVar27 = pbVar27 + 1;
              if ((int)pbVar22 < 1) break;
              iVar9 = (*(code *)out)(0x30,ctx);
              pbVar22 = pbVar22 + -1;
            }
            pbVar26 = pbVar26 + 1;
            pbVar25 = pbVar26;
          }
          while( true ) {
            if (-1 < (int)((uint)(byte)(&DAT_000f6aa2)[*pbVar26] << 0x1d)) break;
            iVar9 = (*(code *)out)((uint)*pbVar26,ctx);
            pbVar26 = pbVar26 + 1;
            if (iVar9 < 0) {
              return iVar9;
            }
          }
          iVar9 = (int)pbVar27 - (int)pbVar25;
        }
        pbVar25 = pbVar26 + iVar9;
        pbVar28 = local_50 + (int)pbVar25;
        for (; 0 < (int)pbVar28 - (int)pbVar25; pbVar25 = pbVar25 + 1) {
          iVar9 = (*(code *)out)(0x30,ctx);
          if (iVar9 < 0) {
            return iVar9;
          }
        }
        iVar9 = extract_width(out,ctx,(char *)pbVar26,(char *)pbVar14);
        if (iVar9 < 0) {
          return iVar9;
        }
        pbVar25 = pbVar25 + iVar9;
      }
      local_90 = local_90 + (int)pbVar25;
      for (; 0 < (int)local_90 - (int)pbVar25; pbVar25 = pbVar25 + 1) {
        iVar9 = (*(code *)out)(0x20,ctx);
        if (iVar9 < 0) {
          return iVar9;
        }
      }
    }
switchD_000118a6_caseD_59:
    format = (char *)local_88;
  } while( true );
}


