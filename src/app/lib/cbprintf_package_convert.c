/*
 * Function: cbprintf_package_convert
 * Entry:    0004de60
 * Prototype: int __stdcall cbprintf_package_convert(void * in_packaged, size_t in_len, cbprintf_convert_cb cb, void * ctx, uint32_t flags, uint16_t * strl, size_t strl_len)
 */


/* exclude_from_export */

int cbprintf_package_convert
              (void *in_packaged,size_t in_len,cbprintf_convert_cb cb,void *ctx,uint32_t flags,
              uint16_t *strl,size_t strl_len)

{
  byte bVar1;
  byte bVar2;
  log_msg_desc desc;
  bool bVar3;
  undefined1 uVar4;
  char *pcVar5;
  size_t sVar6;
  int iVar7;
  int iVar8;
  undefined *puVar9;
  uint uVar10;
  undefined1 uVar11;
  byte extraout_r1;
  byte bVar12;
  uint uVar13;
  uint uVar14;
  byte *pbVar15;
  byte *pbVar16;
  byte *pbVar17;
  uint uVar18;
  int iVar19;
  dword in_stack_ffffff60;
  uint8_t *in_stack_ffffff64;
  void *in_stack_ffffff68;
  undefined1 *local_90;
  char *local_8c;
  char *local_88;
  undefined2 local_80;
  uint local_78;
  int local_74;
  byte *local_70;
  int local_6c;
  uint local_68;
  uint local_64;
  void *local_60;
  char *local_5c;
  uint local_58;
  code *local_54;
  byte local_49;
  byte abStack_48 [16];
  byte abStack_38 [20];
  
  local_60 = ctx;
  local_54 = (code *)cb;
  if (in_packaged == (void *)0x0) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","in_packaged != ((void *)0)",
            "WEST_TOPDIR/zephyr/lib/os/cbprintf_packaged.c",916);
LAB_0004de84:
                    /* WARNING: Subroutine does not return */
    k_panic();
  }
  bVar1 = *(byte *)((int)in_packaged + 2);
  uVar18 = (uint)bVar1;
  local_68 = (flags & 0xf) >> 3;
  if (in_len == 0) {
    bVar12 = *(byte *)((int)in_packaged + 1);
    pcVar5 = (char *)(uVar18 + (uint)*(byte *)in_packaged * 4 + (int)in_packaged);
    for (uVar13 = 0; uVar13 < bVar12; uVar13 = uVar13 + 1) {
      sVar6 = strlen(pcVar5 + 1);
      pcVar5 = pcVar5 + 1 + sVar6 + 1;
    }
    in_len = (int)pcVar5 - (int)in_packaged;
  }
  local_64 = (uint)*(byte *)((int)in_packaged + 3);
  uVar13 = uVar18;
  if ((uVar18 == 0) || (-1 < (int)(flags << 0x1f))) {
    if ((local_64 == 0) || (-1 < (int)(flags << 0x1e))) {
      if (local_54 == (code *)0x0) {
        return in_len;
      }
      (*local_54)(in_packaged,in_len,local_60);
      return in_len;
    }
    local_58 = (uint)*(byte *)in_packaged;
    local_6c = local_58 << 2;
    local_5c = *(char **)((int)in_packaged + 4);
    pbVar15 = (byte *)((int)in_packaged + local_58 * 4);
    if (local_54 == (code *)0x0) {
      if (uVar18 == 0) {
        uVar13 = 0;
      }
      else {
        if ((flags & 4) != 0) {
          pbVar15 = pbVar15 + uVar18;
        }
        uVar13 = 0;
      }
      goto LAB_0004df3c;
    }
    uVar14 = uVar18;
    if (uVar18 == 0) goto LAB_0004e046;
    if ((flags & 4) == 0) {
      uVar13 = 0;
      uVar14 = 0;
      goto LAB_0004e046;
    }
    pbVar17 = abStack_38;
    uVar13 = 0;
  }
  else {
    local_58 = (uint)*(byte *)in_packaged;
    local_5c = *(char **)((int)in_packaged + 4);
    local_6c = local_58 << 2;
    pbVar15 = (byte *)((int)in_packaged + local_58 * 4);
    if (local_54 == (code *)0x0) {
      uVar13 = 0;
      pbVar17 = pbVar15;
      while (pbVar15 + uVar18 != pbVar17) {
        sVar6 = strlen(*(char **)((int)in_packaged + (uint)*pbVar17 * 4));
        if ((strl != (uint16_t *)0x0) && (uVar13 < strl_len)) {
          strl[uVar13] = (uint16_t)(sVar6 + 1);
          uVar13 = uVar13 + 1;
        }
        in_len = in_len + sVar6 + 1;
        pbVar17 = pbVar17 + 1;
      }
      pbVar15 = pbVar15 + uVar18;
LAB_0004df3c:
      if ((flags & 5) == 0) {
        iVar19 = 2;
      }
      else {
        iVar19 = 1;
      }
      iVar7 = local_64 * 2;
      local_54 = (code *)(flags & 2);
      pbVar17 = pbVar15;
      do {
        while( true ) {
          if (pbVar17 == pbVar15 + iVar7) {
            return in_len;
          }
          pbVar16 = pbVar17 + 2;
          pcVar5 = *(char **)((int)in_packaged + (uint)pbVar17[1] * 4);
          if ((&DAT_0008b160 <= pcVar5) && (pcVar5 <= "")) break;
          if ((local_68 != 0) && (bVar3 = is_ptr(local_5c,(uint)*pbVar17), bVar3))
          goto LAB_0004df86;
          pbVar17 = pbVar16;
          if (local_54 != (code *)0x0) {
LAB_0004e008:
            sVar6 = strlen(pcVar5);
            if ((strl != (uint16_t *)0x0) && (uVar13 < strl_len)) {
              strl[uVar13] = (short)sVar6 + 1;
              uVar13 = uVar13 + 1;
            }
            in_len = in_len + sVar6;
            pbVar17 = pbVar16;
          }
        }
        if ((local_68 == 0) || (bVar3 = is_ptr(local_5c,(uint)*pbVar17), !bVar3)) {
          if ((int)(flags << 0x1f) < 0) goto LAB_0004e008;
          in_len = in_len - iVar19;
          pbVar17 = pbVar16;
        }
        else {
LAB_0004df86:
          local_8c = 
          "(unsigned) char * used for %%p argument. It\'s recommended to cast it to void * because it may cause misbehavior in certain configurations. String:\"%s\" argument:%d"
          ;
          local_88 = local_5c;
          local_80 = 0x200;
          local_90 = &DAT_01000004;
          desc.level = (dword)&local_90;
          desc.domain = 0x2480;
          desc.package_len_Z_LOG_MSG_PACKAGE_BITS = 0;
          desc.data_len = in_stack_ffffff60;
          z_impl_z_log_msg_static_create
                    (&PTR_s_cbprintf_package_0008b938,desc,in_stack_ffffff64,in_stack_ffffff68);
          in_len = in_len - 2;
          pbVar17 = pbVar16;
        }
      } while( true );
    }
    uVar14 = 0;
    pbVar17 = abStack_48;
  }
  memcpy(pbVar17,pbVar15,uVar18);
LAB_0004e046:
  local_74 = local_64 << 1;
  local_70 = pbVar15 + uVar18 + local_64 * 2;
  local_78 = flags & 2;
  pbVar15 = pbVar15 + uVar18;
LAB_0004e05e:
  while( true ) {
    do {
      if (pbVar15 == local_70) {
        local_5c = (char *)(uint)*(byte *)((int)in_packaged + 1);
        uVar11 = 0;
        if (-1 < (int)(flags << 0x1e)) {
          uVar11 = (undefined1)(uVar14 >> 1);
        }
        if ((int)(flags << 0x1f) < 0) {
          uVar4 = 0;
        }
        else if ((flags & 4) == 0) {
          uVar4 = 0;
        }
        else {
          uVar4 = (undefined1)uVar14;
        }
        *(byte *)((int)in_packaged + 1) = (char)uVar13 + *(byte *)((int)in_packaged + 1);
        *(undefined1 *)((int)in_packaged + 2) = uVar4;
        *(undefined1 *)((int)in_packaged + 3) = uVar11;
        iVar19 = (*local_54)(in_packaged,local_6c,local_60);
        if (iVar19 < 0) {
          return iVar19;
        }
        *(char *)in_packaged = (char)local_58;
        *(char *)((int)in_packaged + 1) = (char)local_5c;
        *(byte *)((int)in_packaged + 2) = bVar1;
        *(char *)((int)in_packaged + 3) = (char)local_64;
        iVar7 = (*local_54)(abStack_38,uVar14,local_60);
        if (iVar7 < 0) {
          return iVar7;
        }
        iVar8 = (*local_54)(pbVar15,((in_len - uVar18) - local_6c) - local_74,local_60);
        if (iVar8 < 0) {
          return iVar8;
        }
        uVar18 = 0;
        iVar8 = iVar7 + iVar19 + iVar8;
        while( true ) {
          if (uVar13 <= uVar18) {
            (*local_54)(0,0,local_60);
            return iVar8;
          }
          local_49 = abStack_48[uVar18];
          pcVar5 = *(char **)((int)in_packaged + (uint)local_49 * 4);
          if (strl == (uint16_t *)0x0) {
            uVar14 = 0;
          }
          else {
            uVar14 = (uint)strl[uVar18];
          }
          iVar19 = (*local_54)(&local_49,1,local_60);
          if (iVar19 < 0) break;
          if (uVar14 == 0) {
            sVar6 = strlen(pcVar5);
            uVar14 = sVar6 + 1 & 0xffff;
          }
          iVar7 = (*local_54)(pcVar5,uVar14,local_60);
          if (iVar7 < 0) {
            return iVar7;
          }
          iVar8 = iVar8 + iVar19 + iVar7;
          uVar18 = uVar18 + 1;
        }
        return iVar19;
      }
      pbVar17 = pbVar15 + 2;
      bVar12 = *pbVar15;
      bVar2 = pbVar15[1];
      puVar9 = *(undefined **)((int)in_packaged + (uint)bVar2 * 4);
      pbVar15 = pbVar17;
      if (((undefined *)0x8b15f < puVar9) && (puVar9 < &DAT_000f6d9c)) goto LAB_0004e17e;
    } while ((local_68 != 0) && (bVar3 = is_ptr(local_5c,(uint)bVar12), bVar12 = extraout_r1, bVar3)
            );
    if (local_78 != 0) {
      if (uVar13 < 0x10) goto LAB_0004e1e8;
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","scpy_cnt < sizeof(cpy_str_pos)",
              "WEST_TOPDIR/zephyr/lib/os/cbprintf_packaged.c",0x448);
      goto LAB_0004de84;
    }
    if (0xf < uVar14) break;
    uVar10 = uVar14 + 1;
    abStack_38[uVar14] = bVar12;
    uVar14 = uVar14 + 2 & 0xff;
    abStack_38[uVar10 & 0xff] = bVar2;
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","keep_cnt < sizeof(keep_str_pos)",
          "WEST_TOPDIR/zephyr/lib/os/cbprintf_packaged.c",1099);
  goto LAB_0004de84;
LAB_0004e17e:
  if ((local_68 == 0) || (bVar3 = is_ptr(local_5c,(uint)bVar12), !bVar3)) {
    if ((int)(flags << 0x1f) < 0) {
      if (0xf < uVar13) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","scpy_cnt < sizeof(cpy_str_pos)",
                "WEST_TOPDIR/zephyr/lib/os/cbprintf_packaged.c",1086);
        goto LAB_0004de84;
      }
LAB_0004e1e8:
      abStack_48[uVar13] = bVar2;
      uVar13 = uVar13 + 1 & 0xff;
    }
    else if ((int)(flags << 0x1d) < 0) {
      if (0xf < uVar14) {
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","keep_cnt < sizeof(keep_str_pos)",
                "WEST_TOPDIR/zephyr/lib/os/cbprintf_packaged.c",1089);
        goto LAB_0004de84;
      }
      abStack_38[uVar14] = bVar2;
      uVar14 = uVar14 + 1 & 0xff;
    }
  }
  goto LAB_0004e05e;
}


