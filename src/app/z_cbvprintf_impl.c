/*
 * Function: $_?_z_cbvprintf_impl
 * Entry:    00011300
 * Prototype: int __stdcall $_?_z_cbvprintf_impl(cbprintf_cb out, void * ctx, char * format, va_list ap, uint32_t flags)
 */


/* WARNING: Type propagation algorithm not settling */

int ____z_cbvprintf_impl(cbprintf_cb out,void *ctx,char *format,va_list ap,uint32_t flags)

{
  ulonglong uVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  bool bVar5;
  ushort uVar6;
  ushort uVar7;
  undefined1 uVar8;
  byte bVar9;
  byte *pbVar10;
  uint uVar11;
  size_t sVar12;
  byte *pbVar13;
  char *pcVar14;
  uint uVar15;
  uint extraout_r0;
  byte *pbVar16;
  char cVar17;
  byte *pbVar18;
  uint extraout_r1;
  uint extraout_r1_00;
  uint extraout_r1_01;
  byte bVar19;
  uint uVar20;
  char *extraout_r2;
  char *extraout_r2_00;
  char *extraout_r2_01;
  char *extraout_r2_02;
  uint uVar21;
  uint uVar22;
  undefined4 uVar23;
  byte *pbVar24;
  uint *puVar25;
  uint *puVar26;
  undefined4 *puVar27;
  byte *pbVar28;
  byte *pbVar29;
  int iVar30;
  int iVar31;
  uint uVar32;
  bool bVar33;
  byte *in_stack_ffffff60;
  byte *local_90;
  byte *local_88;
  uint local_74;
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
  
  pbVar28 = (byte *)0x0;
  do {
    bVar9 = *format;
    if (bVar9 == 0) {
      return (int)pbVar28;
    }
    local_88 = (byte *)(format + 1);
    if (bVar9 != 0x25) {
LAB_00011324:
      pbVar10 = (byte *)(*(code *)out)(bVar9,ctx);
      if ((int)pbVar10 < 0) {
        return (int)pbVar10;
      }
      pbVar28 = pbVar28 + 1;
      goto switchD_000118a6_caseD_59;
    }
    memset(&local_60,0,0x18);
    if (format[1] == 0x25) {
      local_88 = (byte *)(format + 2);
      local_56 = CONCAT11(0x25,(byte)local_56);
    }
    else {
      bVar33 = false;
      bVar2 = false;
      bVar3 = false;
      bVar4 = false;
      bVar5 = false;
      pbVar10 = (byte *)(format + 1);
      while( true ) {
        while( true ) {
          while( true ) {
            while( true ) {
              pbVar18 = pbVar10 + 1;
              bVar9 = *pbVar10;
              if (bVar9 != 0x2b) break;
              bVar4 = true;
              pbVar10 = pbVar18;
            }
            if (bVar9 < 0x2c) break;
            if (bVar9 == 0x2d) {
              bVar5 = true;
              pbVar10 = pbVar18;
            }
            else {
              if (bVar9 != 0x30) goto LAB_0001136a;
              bVar33 = true;
              pbVar10 = pbVar18;
            }
          }
          if (bVar9 != 0x20) break;
          bVar3 = true;
          pbVar10 = pbVar18;
        }
        if (bVar9 != 0x23) break;
        bVar2 = true;
        pbVar10 = pbVar18;
      }
LAB_0001136a:
      if (bVar33) {
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
      local_68 = CONCAT44(local_68._4_4_,pbVar10);
      uVar8 = local_58._1_1_;
      local_58 = local_58 | 0x80;
      if (bVar9 == 0x2a) {
        local_58 = CONCAT11(uVar8,(byte)local_58) | 0x100;
        pbVar18 = pbVar10 + 1;
      }
      else {
        pbVar29 = (byte *)extract_conversion((undefined4 *)&local_68);
        pbVar18 = (byte *)local_68;
        if ((byte *)local_68 != pbVar10) {
          local_58 = CONCAT11(local_58._1_1_,
                              (byte)local_58 & 0xfd | (byte)(((uint)pbVar29 >> 0x1f) << 1));
          local_54 = pbVar29;
        }
      }
      bVar9 = local_58._1_1_ & 0xfd | (*pbVar18 == 0x2e) << 1;
      local_58._1_1_ = bVar9;
      if (*pbVar18 == 0x2e) {
        local_68 = CONCAT44(local_68._4_4_,pbVar18 + 1);
        if (pbVar18[1] == 0x2a) {
          local_58._1_1_ = bVar9 | 4;
          pbVar18 = pbVar18 + 2;
        }
        else {
          local_50 = (byte *)extract_conversion((undefined4 *)&local_68);
          local_58._0_1_ =
               (byte)local_58 & 0xfd |
               (byte)((((uint)(byte)local_58 << 0x1e | (uint)local_50) >> 0x1f) << 1);
          pbVar18 = (byte *)local_68;
        }
      }
      bVar9 = *pbVar18;
      if (bVar9 == 0x6c) {
        if (pbVar18[1] != 0x6c) {
          cVar17 = '\x03';
          goto LAB_00011596;
        }
        cVar17 = '\x04';
LAB_00011588:
        local_58._1_1_ = local_58._1_1_ & 0x87 | cVar17 << 3;
        pbVar18 = pbVar18 + 2;
      }
      else {
        if (bVar9 < 0x6d) {
          if (bVar9 == 0x68) {
            if (pbVar18[1] == 0x68) {
              cVar17 = '\x01';
              goto LAB_00011588;
            }
            cVar17 = '\x02';
            goto LAB_00011596;
          }
          if (bVar9 == 0x6a) {
            cVar17 = '\x05';
            goto LAB_00011596;
          }
          if (bVar9 != 0x4c) goto LAB_00011442;
          local_58._0_1_ = (byte)local_58 & 0xfd | 2;
          local_58._1_1_ = local_58._1_1_ & 0x87 | 0x40;
        }
        else {
          if (bVar9 == 0x74) {
            cVar17 = '\a';
          }
          else {
            if (bVar9 != 0x7a) goto LAB_00011442;
            cVar17 = '\x06';
          }
LAB_00011596:
          local_58._1_1_ = local_58._1_1_ & 0x87 | cVar17 << 3;
        }
        pbVar18 = pbVar18 + 1;
      }
LAB_00011442:
      local_88 = pbVar18 + 1;
      bVar9 = *pbVar18;
      uVar20 = (uint)bVar9;
      local_56 = CONCAT11(bVar9,(byte)local_56);
      if (0x78 < uVar20) goto LAB_00011654;
      if (uVar20 < 0x6e) {
        if (uVar20 < 0x6a) {
          if (0x57 < uVar20) {
            uVar21 = 1 << (uVar20 - 0x58 & 0xff);
            if ((uVar21 & 0xe200) != 0) goto LAB_00011472;
            if ((uVar21 & 0x801) != 0) {
              uVar21 = local_58._1_1_ & 0x78;
              local_56 = local_56 & 0xfff8 | 2;
              if (uVar21 == 0x40) {
                local_58._0_1_ = (byte)local_58 | 1;
              }
              if (uVar20 == 99) {
                if ((local_58._1_1_ & 0x78) != 0) {
                  uVar21 = 1;
                }
                goto LAB_0001169c;
              }
              goto LAB_000114b2;
            }
            if ((uVar21 & 0x21000) != 0) {
              bVar19 = (byte)local_56 & 0xf8 | 1;
              goto LAB_00011646;
            }
            goto LAB_00011654;
          }
          if ((uVar20 != 0x41) && (2 < uVar20 - 0x45)) goto LAB_00011654;
LAB_00011472:
          bVar9 = ((uVar20 & 0xdf) == 0x41) << 7;
          bVar19 = local_58._1_1_ & 0x7f | bVar9;
          local_56 = local_56 & 0xfff8 | 4;
          if ((int)((uint)bVar19 << 0x18) < 0) {
            uVar21 = 1;
            local_58._1_1_ = bVar19;
            goto LAB_0001169c;
          }
          if ((local_58._1_1_ & 0x78) == 0x18) {
            local_58._1_1_ = local_58._1_1_ & 7 | bVar9;
          }
          else {
            bVar9 = local_58._1_1_ & 0x38;
            local_58._1_1_ = bVar19;
            if (bVar9 != 0) goto LAB_00011654;
          }
        }
        else {
LAB_00011654:
          local_58._0_1_ = (byte)local_58 | 1;
        }
LAB_000114b2:
        uVar21 = 0;
      }
      else {
        uVar20 = 1 << (uVar20 - 0x6e & 0xff);
        if ((uVar20 & 0x482) != 0) {
          bVar19 = (byte)local_56 & 0xf8 | 2;
LAB_00011646:
          local_56 = CONCAT11(bVar9,bVar19);
          if ((local_58._1_1_ & 0x78) == 0x40) goto LAB_00011654;
          goto LAB_000114b2;
        }
        if ((uVar20 & 0x24) == 0) {
          if (-1 < (int)(uVar20 << 0x1f)) goto LAB_00011654;
          local_56 = local_56 & 0xfff8 | 3;
          uVar21 = (uint)((local_58._1_1_ & 0x78) == 0x40);
        }
        else {
          uVar21 = (uint)((local_58._1_1_ & 0x78) != 0);
          local_56 = local_56 & 0xfff8 | 3;
        }
      }
LAB_0001169c:
      local_58 = CONCAT11(local_58._1_1_,
                          (byte)local_58 & 0xfd |
                          (byte)((uVar21 & 1 | ((byte)local_58 & 3) >> 1) << 1));
    }
    uVar20 = (uint)local_58._1_1_;
    if ((int)(uVar20 << 0x1f) < 0) {
      local_90 = *(byte **)ap;
      puVar26 = (uint *)(ap + 4);
      if ((int)local_90 < 0) {
        local_58 = local_58 | 4;
        local_90 = (byte *)-(int)local_90;
      }
    }
    else {
      puVar26 = (uint *)ap;
      local_90 = local_54;
      if (-1 < (char)(byte)local_58) {
        local_90 = (byte *)0xffffffff;
      }
    }
    if ((int)(uVar20 << 0x1d) < 0) {
      puVar25 = puVar26 + 1;
      pbVar10 = (byte *)*puVar26;
      puVar26 = puVar25;
      if ((int)pbVar10 < 0) {
        local_58 = local_58 & 0xfdff;
LAB_00011500:
        pbVar10 = (byte *)0xffffffff;
      }
    }
    else {
      pbVar10 = local_50;
      if (-1 < (int)(uVar20 << 0x1e)) goto LAB_00011500;
    }
    uVar7 = local_58;
    local_54 = (byte *)0x0;
    local_50 = (byte *)0x0;
    if ((((byte)local_56 & 7) == 4) && (-1 < (int)((uint)local_58._1_1_ << 0x1e))) {
      if ((short)local_58 < 0) {
        pbVar10 = (byte *)0xd;
      }
      else {
        pbVar10 = (byte *)0x6;
      }
    }
    bVar9 = (byte)local_56 & 7;
    uVar20 = (local_58._1_1_ & 0x7f) >> 3;
    if (bVar9 == 1) {
      switch(uVar20) {
      case 3:
      case 6:
      case 7:
        local_60 = (byte *)*puVar26;
        local_5c = (int)local_60 >> 0x1f;
LAB_00011772:
        ap = (va_list)(puVar26 + 1);
        break;
      case 4:
      case 5:
switchD_00011726_caseD_4:
        puVar27 = (undefined4 *)((int)puVar26 + 7U & 0xfffffff8);
        ap = (va_list)(puVar27 + 2);
        local_60 = (byte *)*puVar27;
        local_5c = puVar27[1];
        break;
      default:
        pbVar18 = (byte *)*puVar26;
        local_5c = (int)pbVar18 >> 0x1f;
        if (uVar20 == 1) {
          local_60._0_1_ = (char)pbVar18;
          local_5c = (int)(char)local_60 >> 0x1f;
          local_60 = (byte *)(int)(char)local_60;
        }
        else {
          local_60 = pbVar18;
          if (uVar20 == 2) {
            local_60 = (byte *)(int)(short)pbVar18;
            local_5c = ((int)pbVar18 << 0x10) >> 0x1f;
          }
        }
        ap = (va_list)(puVar26 + 1);
      }
    }
    else if (bVar9 == 2) {
      switch(uVar20) {
      case 3:
      case 6:
      case 7:
        ap = (va_list)(puVar26 + 1);
        local_60 = (byte *)*puVar26;
        local_5c = 0;
        break;
      case 4:
      case 5:
        goto switchD_00011726_caseD_4;
      default:
        local_5c = 0;
        local_60 = (byte *)*puVar26;
        if (uVar20 == 1) {
          local_60 = (byte *)((uint)local_60 & 0xff);
          goto LAB_00011772;
        }
        local_5c = 0;
        ap = (va_list)(puVar26 + 1);
        if (uVar20 == 2) {
          local_60 = (byte *)((uint)local_60 & 0xffff);
          goto LAB_000117b2;
        }
      }
    }
    else if (bVar9 == 4) {
      puVar27 = (undefined4 *)((int)puVar26 + 7U & 0xfffffff8);
      local_60 = (byte *)*puVar27;
      local_5c = puVar27[1];
      ap = (va_list)(puVar27 + 2);
    }
    else {
      ap = (va_list)puVar26;
      if (bVar9 == 3) {
        local_60 = (byte *)*puVar26;
LAB_000117b2:
        ap = (va_list)(puVar26 + 1);
      }
    }
    pcVar14 = (char *)local_60;
    uVar21 = (uint)(byte)local_58;
    if ((local_58 & 3) != 0) {
      pbVar10 = (byte *)extract_width(out,ctx,format,(char *)local_88);
      if ((int)pbVar10 < 0) {
        return (int)pbVar10;
      }
      pbVar28 = pbVar28 + (int)pbVar10;
      goto switchD_000118a6_caseD_59;
    }
    uVar32 = (uint)local_56._1_1_;
    if (0x78 < uVar32) goto switchD_000118a6_caseD_59;
    if (uVar32 < 0x58) {
      if (uVar32 == 0x25) {
        bVar9 = 0x25;
        goto LAB_00011324;
      }
      if ((0x24 < uVar32) && ((uVar32 == 0x41 || (uVar32 - 0x45 < 3))))
      goto switchD_000118a6_caseD_61;
      goto switchD_000118a6_caseD_59;
    }
    switch(uVar32) {
    case 0x58:
    case 0x6f:
    case 0x75:
    case 0x78:
      uVar20 = 0;
      goto LAB_000119fa;
    case 0x61:
    case 0x65:
    case 0x66:
    case 0x67:
switchD_000118a6_caseD_61:
      if ((int)local_5c < 0) {
        uVar20 = 0x2d;
      }
      else if ((int)(uVar21 << 0x1c) < 0) {
        uVar20 = 0x2b;
      }
      else {
        uVar20 = ((uVar21 & 0x1f) >> 4) << 5;
      }
      uVar11 = (local_5c & 0x7fffffff) >> 0x14;
      uVar22 = local_5c & 0xfffff;
      if (uVar11 == 0) {
        if (local_60 == (byte *)0x0 && uVar22 == 0) {
          bVar33 = false;
        }
        else {
          bVar33 = true;
        }
LAB_00011854:
        local_70._4_4_ = (char *)(uVar22 << 0xb | (uint)local_60 >> 0x15);
        local_70._0_4_ = (int)local_60 << 0xb;
        if (uVar32 == 0x46) {
          uVar32 = 0x66;
        }
        if ((uVar11 == 0 && (uint)local_70 == 0) &&
            (local_70._4_4_ == (char *)0x0 && -1 < (int)uVar11)) {
          iVar30 = 0;
        }
        else {
          if (bVar33) {
            while( true ) {
              bVar33 = CARRY4((uint)local_70,(uint)local_70);
              local_70._0_4_ = (uint)local_70 * 2;
              local_70._4_4_ = (char *)((int)local_70._4_4_ * 2 + (uint)bVar33);
              if ((int)local_70._4_4_ < 0) break;
              uVar11 = uVar11 - 1;
            }
          }
          iVar30 = uVar11 - 0x3fe;
          local_70._4_4_ = (char *)((uint)local_70._4_4_ | 0x80000000);
        }
        bVar33 = false;
        pbVar29 = (byte *)0x0;
        uVar11 = (uint)local_70;
        uVar22 = (uint)local_70._4_4_;
        while (iVar30 < -2) {
          do {
            iVar31 = iVar30;
            uVar11 = uVar11 >> 1 | uVar22 << 0x1f;
            uVar22 = uVar22 >> 1;
            iVar30 = iVar31 + 1;
          } while (0x33333332 < uVar22);
          bVar33 = true;
          uVar1 = (ulonglong)uVar11;
          uVar11 = (uint)(uVar1 * 5);
          pbVar29 = pbVar29 + -1;
          uVar22 = (int)(uVar1 * 5 >> 0x20) + uVar22 * 5;
          iVar30 = iVar31 + 2;
        }
        if (bVar33) {
          local_70._0_4_ = uVar11;
          local_70._4_4_ = (char *)uVar22;
        }
        while (0 < iVar30) {
          bVar33 = 0xfffffffd < (uint)local_70;
          local_70._0_4_ = (uint)local_70 + 2;
          local_70._4_4_ = (char *)((int)local_70._4_4_ + (uint)bVar33);
          iVar30 = iVar30 + -1;
          pbVar29 = pbVar29 + 1;
          _ldiv5(&local_70);
          do {
            bVar33 = CARRY4((uint)local_70,(uint)local_70);
            local_70._0_4_ = (uint)local_70 * 2;
            local_70._4_4_ = (char *)((int)local_70._4_4_ * 2 + (uint)bVar33);
            iVar30 = iVar30 + -1;
          } while (-1 < (int)local_70._4_4_);
        }
        uVar11 = -iVar30 + 4;
        uVar22 = (uint)local_70._4_4_ >> (uVar11 & 0xff);
        uVar11 = (uint)local_70 >> (uVar11 & 0xff) | (int)local_70._4_4_ << (iVar30 + 0x1cU & 0xff)
                 | (uint)local_70._4_4_ >> (-iVar30 - 0x1cU & 0xff);
        if ((uVar32 & 0xdf) == 0x47) {
          if (((int)pbVar29 < -3) || ((int)pbVar10 < (int)pbVar29)) {
            uVar32 = uVar32 - 2 & 0xff;
            if (((int)pbVar10 < 1) ||
               (pbVar10 = pbVar10 + -1, (int)((uint)(byte)local_58 << 0x1a) < 0)) {
              bVar33 = false;
            }
            else {
              bVar33 = false;
              if (pbVar10 != (byte *)0x0) {
                bVar33 = true;
              }
            }
            goto LAB_00011bac;
          }
          pbVar10 = pbVar10 + -(int)pbVar29;
          if ((int)((uint)(byte)local_58 << 0x1a) < 0) {
            bVar33 = false;
          }
          else {
            bVar33 = false;
            if (pbVar10 != (byte *)0x0) {
              bVar33 = true;
            }
          }
LAB_00011c02:
          pbVar18 = pbVar10 + (int)pbVar29;
          uVar32 = 0x66;
          if (-1 < (int)pbVar18) goto LAB_00011c0c;
          pbVar18 = (byte *)0x0;
        }
        else {
          bVar33 = false;
          if (uVar32 == 0x66) goto LAB_00011c02;
LAB_00011bac:
          pbVar18 = pbVar10 + 1;
LAB_00011c0c:
          if (0xf < (int)pbVar18) {
            pbVar18 = (byte *)0x10;
          }
        }
        local_68 = 0x800000000000000;
        local_74 = 0x10;
        while( true ) {
          if (pbVar18 == (byte *)0x0) break;
          local_68 = CONCAT44((uint)local_68._4_4_ >> 1,
                              (uint)(byte *)local_68 >> 1 | (int)local_68._4_4_ << 0x1f);
          pbVar18 = pbVar18 + -1;
          _ldiv5(&local_68);
        }
        uVar15 = (int)(byte *)local_68 + uVar11;
        local_70._4_4_ = local_68._4_4_ + uVar22 + CARRY4((uint)(byte *)local_68,uVar11);
        pcVar14 = local_68._4_4_;
        local_70._0_4_ = uVar15;
        if ((char *)0xfffffff < local_70._4_4_) {
          local_70._0_4_ = uVar15 >> 1 | (int)local_70._4_4_ * -0x80000000;
          local_70._4_4_ = (char *)((uint)local_70._4_4_ >> 1);
          _ldiv5(&local_70);
          pbVar29 = pbVar29 + 1;
          uVar15 = extraout_r0;
          pcVar14 = extraout_r2;
        }
        bVar9 = (byte)uVar15;
        pbVar24 = (byte *)(uVar21 & 0x20);
        if (uVar32 == 0x66) {
          if ((int)pbVar29 < 1) {
            uVar21 = 0x30;
            local_44[0] = 0x30;
            pbVar24 = pbVar29;
            if ((uVar7 & 0x20) == 0) {
              if ((int)pbVar10 < 1) goto LAB_00011fc6;
              local_44[1] = 0x2e;
              if (pbVar29 != (byte *)0x0) goto LAB_00011c66;
            }
            else {
              local_44[1] = 0x2e;
              if (pbVar29 != (byte *)0x0) {
                if ((int)pbVar10 < 1) {
                  pbVar18 = local_44 + 2;
                  goto LAB_00011d46;
                }
LAB_00011c66:
                local_54 = (byte *)-(int)pbVar29;
                if ((int)pbVar10 <= -(int)pbVar29) {
                  local_54 = pbVar10;
                }
                pbVar10 = pbVar10 + -(int)local_54;
                uVar21 = (byte)local_56 & 0xffffffdf | (uint)(0 < (int)local_54) << 5;
                local_56 = CONCAT11(local_56._1_1_,(char)uVar21);
              }
            }
LAB_00011c88:
            local_44[1] = 0x2e;
            pbVar18 = local_44 + 2;
          }
          else {
            pbVar13 = local_44;
            do {
              uVar21 = local_74;
              pbVar18 = pbVar13;
              if ((int)local_74 < 1) break;
              uVar15 = z_cbvprintf_impl((cbprintf_cb)&local_70,&local_74,pcVar14,(va_list)pbVar24,
                                        (uint32_t)in_stack_ffffff60);
              pbVar29 = pbVar29 + -1;
              pbVar18 = pbVar13 + 1;
              *pbVar13 = (byte)uVar15;
              uVar21 = extraout_r1;
              pcVar14 = extraout_r2_00;
              pbVar13 = pbVar18;
            } while (pbVar29 != (byte *)0x0);
            bVar9 = (byte)uVar15;
            local_54 = pbVar29;
            if ((uVar7 & 0x20) == 0) {
              if ((int)pbVar10 < 1) goto LAB_00011d46;
              uVar21 = 0x2e;
              *pbVar18 = 0x2e;
            }
            else {
              *pbVar18 = 0x2e;
            }
            pbVar18 = pbVar18 + 1;
            pbVar24 = (byte *)0x0;
          }
          while ((bVar9 = (byte)uVar15, 0 < (int)pbVar10 && (0 < (int)local_74))) {
            uVar15 = z_cbvprintf_impl((cbprintf_cb)&local_70,&local_74,pcVar14,local_74,
                                      (uint32_t)in_stack_ffffff60);
            pbVar10 = pbVar10 + -1;
            *pbVar18 = (byte)uVar15;
            uVar21 = extraout_r1_00;
            pcVar14 = extraout_r2_01;
            pbVar18 = pbVar18 + 1;
          }
        }
        else {
          uVar15 = z_cbvprintf_impl((cbprintf_cb)&local_70,&local_74,pcVar14,(va_list)pbVar24,
                                    (uint32_t)in_stack_ffffff60);
          local_44[0] = (byte)uVar15;
          if (uVar15 != 0x30) {
            pbVar29 = pbVar29 + -1;
          }
          uVar21 = extraout_r1_01;
          if (((uVar7 & 0x20) != 0) || (0 < (int)pbVar10)) {
            local_44[1] = 0x2e;
            pcVar14 = extraout_r2_02;
            pbVar24 = pbVar29;
            goto LAB_00011c88;
          }
LAB_00011fc6:
          bVar9 = (byte)uVar15;
          pbVar18 = local_44 + 1;
          pbVar24 = pbVar29;
        }
LAB_00011d46:
        if (bVar33) {
          do {
            pbVar29 = pbVar18;
            pbVar18 = pbVar29 + -1;
          } while (pbVar29[-1] == 0x30);
          pbVar18 = pbVar29;
          pbVar10 = local_50;
          if (pbVar29[-1] == 0x2e) {
            pbVar18 = pbVar29 + -1;
          }
        }
        local_50 = pbVar10;
        if ((uVar32 & 0xdf) == 0x45) {
          if ((int)pbVar24 < 0) {
            pbVar24 = (byte *)-(int)pbVar24;
            bVar19 = 0x2d;
          }
          else {
            bVar19 = 0x2b;
          }
          if (99 < (int)pbVar24) {
            uVar21 = 100;
          }
          pbVar18[1] = bVar19;
          pbVar10 = pbVar24;
          if (99 < (int)pbVar24) {
            pbVar10 = pbVar24 + -(uVar21 * ((uint)pbVar24 / uVar21));
            bVar9 = (char)((uint)pbVar24 / uVar21) + 0x30;
          }
          if ((int)pbVar24 < 100) {
            pbVar29 = pbVar18 + 2;
          }
          else {
            pbVar29 = pbVar18 + 3;
            pbVar18[2] = bVar9;
          }
          *pbVar18 = (byte)uVar32;
          cVar17 = (char)((uint)pbVar10 / 10);
          pbVar18 = pbVar29 + 2;
          *pbVar29 = cVar17 + 0x30;
          pbVar29[1] = (char)pbVar10 + cVar17 * -10 + 0x30;
        }
        if ((int)local_54 < 1) {
          if ((int)local_50 < 1) {
            cVar17 = '\0';
          }
          else {
            cVar17 = '\x01';
          }
        }
        else {
          cVar17 = '\x01';
        }
        local_56 = CONCAT11(local_56._1_1_,(byte)local_56 & 0xbf | cVar17 << 6);
        *pbVar18 = 0;
      }
      else {
        if (uVar11 != 0x7ff) {
          bVar33 = false;
          goto LAB_00011854;
        }
        if (uVar22 == 0 && local_60 == (byte *)0x0) {
          if (((&DAT_000f6aa1)[uVar32 + 1 & 0xff] & 3) == 1) {
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
        else if (((&DAT_000f6aa1)[uVar32 + 1 & 0xff] & 3) == 1) {
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
        pbVar18 = local_44 + 3;
      }
      pcVar14 = (char *)local_44;
      goto LAB_00011af0;
    case 99:
      uVar20 = 0;
      local_44[0] = (byte)local_60;
      pbVar18 = local_44 + 1;
      iVar30 = 1;
      pcVar14 = (char *)local_44;
      goto LAB_00011952;
    case 100:
    case 0x69:
      if ((int)(uVar21 << 0x1c) < 0) {
        uVar20 = 0x2b;
      }
      else {
        uVar20 = ((uVar21 & 0x1f) >> 4) << 5;
      }
      if ((int)local_5c < 0) {
        uVar20 = 0x2d;
        bVar33 = local_60 != (byte *)0x0;
        local_60 = (byte *)-(int)local_60;
        local_5c = -local_5c - (uint)bVar33;
      }
LAB_000119fa:
      in_stack_ffffff60 = abStack_2b;
      pcVar14 = extract_specifier((uint)local_60,local_5c,(byte *)&local_58,(char *)local_44,
                                  (char *)in_stack_ffffff60);
LAB_00011a0e:
      if (-1 < (int)pbVar10) {
        local_58 = local_58 & 0xffbf;
        if (abStack_2b + -(int)pcVar14 < pbVar10) {
          local_54 = pbVar10 + -(int)(abStack_2b + -(int)pcVar14);
        }
      }
      if ((byte *)pcVar14 != (byte *)0x0) {
        pbVar18 = abStack_2b;
LAB_00011af0:
        iVar30 = (int)pbVar18 - (int)pcVar14;
        if (uVar20 != 0) {
          iVar30 = iVar30 + 1;
        }
        goto LAB_00011952;
      }
      break;
    case 0x6e:
      switch(uVar20) {
      case 0:
      case 3:
      case 6:
      case 7:
        *(byte **)local_60 = pbVar28;
        break;
      case 1:
        *local_60 = (byte)pbVar28;
        break;
      case 2:
        *(short *)local_60 = (short)pbVar28;
        break;
      case 4:
      case 5:
        *(byte **)local_60 = pbVar28;
        *(int *)(local_60 + 4) = (int)pbVar28 >> 0x1f;
      }
      break;
    case 0x70:
      if (local_60 == (byte *)0x0) {
        pbVar18 = (byte *)0xee997;
        iVar30 = 5;
        pcVar14 = "(nil)";
        uVar20 = 0;
        goto LAB_00011952;
      }
      in_stack_ffffff60 = abStack_2b;
      pcVar14 = extract_specifier((uint)local_60,0,(byte *)&local_58,(char *)local_44,
                                  (char *)in_stack_ffffff60);
      local_56 = local_56 & 0xef | 0x7810;
      uVar20 = 0;
      goto LAB_00011a0e;
    case 0x73:
      if ((int)pbVar10 < 0) {
        sVar12 = strlen((char *)local_60);
      }
      else {
        sVar12 = extract_decimal((char *)local_60,(int)pbVar10);
        if ((byte *)pcVar14 == (byte *)0x0) break;
      }
      uVar20 = 0;
      pbVar18 = (byte *)(pcVar14 + sVar12);
      iVar30 = (int)pbVar18 - (int)pcVar14;
LAB_00011952:
      pbVar10 = local_54;
      uVar7 = local_56 & 0x10;
      if ((local_56 & 0x10) == 0) {
        if ((int)((uint)(byte)local_56 << 0x1c) < 0) {
          iVar30 = iVar30 + 1;
        }
      }
      else {
        iVar30 = iVar30 + 2;
      }
      uVar6 = local_56 & 0x40;
      bVar33 = (local_56 & 0x40) != 0;
      pbVar29 = (byte *)((byte)local_56 & 0x40);
      if (bVar33) {
        pbVar29 = local_50;
      }
      pbVar24 = local_54 + iVar30;
      if (bVar33) {
        pbVar24 = pbVar24 + (int)pbVar29;
      }
      if (0 < (int)local_90) {
        pbVar29 = local_90 + -(int)pbVar24;
        uVar21 = (uint)(byte)local_58;
        local_90 = pbVar29;
        if (-1 < (int)(uVar21 << 0x1d)) {
          pbVar24 = pbVar29;
          if ((int)(uVar21 << 0x19) < 0) {
            if (uVar20 != 0) {
              pbVar13 = (byte *)(*(code *)out)(uVar20,ctx);
              if ((int)pbVar13 < 0) {
                return (int)pbVar13;
              }
              pbVar28 = pbVar28 + 1;
              uVar20 = (uVar21 & 7) >> 2;
            }
            uVar23 = 0x30;
          }
          else {
            uVar23 = 0x20;
          }
          while (local_90 = pbVar24 + -1, 0 < (int)pbVar24) {
            pbVar13 = (byte *)(*(code *)out)(uVar23,ctx);
            pbVar24 = local_90;
            if ((int)pbVar13 < 0) {
              return (int)pbVar13;
            }
          }
          pbVar28 = pbVar29 + ((int)pbVar28 - (int)pbVar24);
        }
      }
      if (uVar20 != 0) {
        pbVar29 = (byte *)(*(code *)out)(uVar20,ctx);
        if ((int)pbVar29 < 0) {
          return (int)pbVar29;
        }
        pbVar28 = pbVar28 + 1;
      }
      if (uVar6 == 0) {
        if (((int)((uint)(byte)local_56 << 0x1b) < 0) || ((int)((uint)(byte)local_56 << 0x1c) < 0))
        {
          pbVar29 = (byte *)(*(code *)out)(0x30,ctx);
          if ((int)pbVar29 < 0) {
            return (int)pbVar29;
          }
          pbVar28 = pbVar28 + 1;
        }
        pbVar29 = pbVar28;
        if (uVar7 != 0) {
          pbVar29 = (byte *)(*(code *)out)(local_56._1_1_,ctx);
          if ((int)pbVar29 < 0) {
            return (int)pbVar29;
          }
          pbVar28 = pbVar28 + 1;
          pbVar29 = pbVar28;
        }
        for (; 0 < (int)(pbVar10 + ((int)pbVar29 - (int)pbVar28)); pbVar28 = pbVar28 + 1) {
          pbVar24 = (byte *)(*(code *)out)(0x30,ctx);
          if ((int)pbVar24 < 0) {
            return (int)pbVar24;
          }
        }
        pbVar10 = (byte *)extract_width(out,ctx,pcVar14,(char *)pbVar18);
        if ((int)pbVar10 < 0) {
          return (int)pbVar10;
        }
        pbVar28 = pbVar10 + (int)pbVar28;
        pbVar10 = pbVar28;
      }
      else {
        pbVar29 = (byte *)pcVar14;
        if ((short)local_58 < 0) {
          while( true ) {
            if (*pbVar29 == 0x70) break;
            pbVar10 = (byte *)(*(code *)out)(*pbVar29,ctx);
            pbVar29 = pbVar29 + 1;
            if ((int)pbVar10 < 0) {
              return (int)pbVar10;
            }
          }
          iVar30 = (int)pbVar28 - (int)pcVar14;
        }
        else {
          while( true ) {
            if (-1 < (int)((uint)(byte)(&DAT_000f6aa2)[*pbVar29] << 0x1d)) break;
            pbVar24 = (byte *)(*(code *)out)((uint)*pbVar29,ctx);
            pbVar29 = pbVar29 + 1;
            if ((int)pbVar24 < 0) {
              return (int)pbVar24;
            }
          }
          pbVar13 = pbVar29 + ((int)pbVar28 - (int)pcVar14);
          pbVar28 = pbVar10;
          pbVar24 = pbVar10;
          if (-1 < (int)((uint)(byte)local_56 << 0x1a)) {
            while (pbVar24 = pbVar28 + -1, 0 < (int)pbVar28) {
              pbVar16 = (byte *)(*(code *)out)(0x30,ctx);
              pbVar28 = pbVar24;
              if ((int)pbVar16 < 0) {
                return (int)pbVar16;
              }
            }
            pbVar13 = pbVar13 + ((int)pbVar10 - (int)pbVar28);
          }
          pbVar28 = pbVar29;
          if (*pbVar29 == 0x2e) {
            pbVar28 = (byte *)(*(code *)out)(0x2e,ctx);
            while( true ) {
              if ((int)pbVar28 < 0) {
                return (int)pbVar28;
              }
              pbVar13 = pbVar13 + 1;
              if ((int)pbVar24 < 1) break;
              pbVar28 = (byte *)(*(code *)out)(0x30,ctx);
              pbVar24 = pbVar24 + -1;
            }
            pbVar29 = pbVar29 + 1;
            pbVar28 = pbVar29;
          }
          while( true ) {
            if (-1 < (int)((uint)(byte)(&DAT_000f6aa2)[*pbVar29] << 0x1d)) break;
            pbVar10 = (byte *)(*(code *)out)((uint)*pbVar29,ctx);
            pbVar29 = pbVar29 + 1;
            if ((int)pbVar10 < 0) {
              return (int)pbVar10;
            }
          }
          iVar30 = (int)pbVar13 - (int)pbVar28;
        }
        pbVar28 = local_50;
        for (pbVar10 = pbVar29 + iVar30; 0 < (int)(pbVar29 + iVar30 + ((int)pbVar28 - (int)pbVar10))
            ; pbVar10 = pbVar10 + 1) {
          pbVar24 = (byte *)(*(code *)out)(0x30,ctx);
          if ((int)pbVar24 < 0) {
            return (int)pbVar24;
          }
        }
        pbVar28 = (byte *)extract_width(out,ctx,(char *)pbVar29,(char *)pbVar18);
        if ((int)pbVar28 < 0) {
          return (int)pbVar28;
        }
        pbVar28 = pbVar28 + (int)pbVar10;
        pbVar10 = pbVar28;
      }
      for (; 0 < (int)(local_90 + ((int)pbVar10 - (int)pbVar28)); pbVar28 = pbVar28 + 1) {
        pbVar18 = (byte *)(*(code *)out)(0x20,ctx);
        if ((int)pbVar18 < 0) {
          return (int)pbVar18;
        }
      }
    }
switchD_000118a6_caseD_59:
    format = (char *)local_88;
  } while( true );
}


