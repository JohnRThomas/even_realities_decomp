/*
 * Function: _vfprintf_r
 * Entry:    0007a17c
 * Prototype: int __stdcall _vfprintf_r(undefined4 * data, FILE * fp, char * fmt0, va_list ap)
 */


/* WARNING: Removing unreachable block (ram,0x0007a324) */
/* exclude_from_export */

int _vfprintf_r(undefined4 *data,FILE *fp,char *fmt0,va_list ap)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  void *pvVar4;
  uint *puVar5;
  uint uVar6;
  byte *pbVar7;
  byte *pbVar8;
  uint *local_8c;
  uint local_88;
  uint local_84;
  undefined4 uStack_80;
  uint local_7c;
  int local_74;
  byte local_70;
  undefined1 local_6f;
  undefined1 local_6e;
  undefined1 local_45;
  undefined4 local_30;
  
  if ((data != (undefined4 *)0x0) && (data[6] == 0)) {
    __sinit(data);
  }
  if (fp == (FILE *)&DAT_0009c2ac) {
    fp = (FILE *)data[1];
  }
  else if (fp == (FILE *)&DAT_0009c28c) {
    fp = (FILE *)data[2];
  }
  else if (fp == (FILE *)&DAT_0009c26c) {
    fp = (FILE *)data[3];
  }
  if ((-1 < (int)fp->__pad4 << 0x1f) && (-1 < (int)((uint)*(ushort *)&fp->_IO_read_base << 0x16))) {
    __retarget_lock_acquire_recursive((_LOCK_T)fp->__pad1);
  }
  if (((-1 < (int)((uint)*(ushort *)&fp->_IO_read_base << 0x1c)) ||
      (fp->_IO_write_base == (char *)0x0)) && (iVar2 = __swsetup_r(data,&fp->_flags), iVar2 != 0)) {
    if ((-1 < (int)fp->__pad4 << 0x1f) && (-1 < (int)((uint)*(ushort *)&fp->_IO_read_base << 0x16)))
    {
      __retarget_lock_release_recursive((_LOCK_T)fp->__pad1);
    }
    return -1;
  }
  local_74 = 0;
  local_6f = 0x20;
  local_6e = 0x30;
  pbVar8 = (byte *)fmt0;
  local_8c = (uint *)ap;
LAB_0007a212:
  pbVar7 = pbVar8;
  if (*pbVar7 != 0) goto code_r0x0007a21a;
  goto LAB_0007a21e;
code_r0x0007a21a:
  pbVar8 = pbVar7 + 1;
  if (*pbVar7 == 0x25) {
LAB_0007a21e:
    iVar2 = (int)pbVar7 - (int)fmt0;
    if (iVar2 != 0) {
      iVar3 = __sprint_r(data,&fp->_flags,(byte *)fmt0,iVar2);
      if (iVar3 == -1) {
LAB_0007a382:
        if ((-1 < (int)fp->__pad4 << 0x1f) &&
           (-1 < (int)((uint)*(ushort *)&fp->_IO_read_base << 0x16))) {
          __retarget_lock_release_recursive((_LOCK_T)fp->__pad1);
        }
        if ((int)((uint)*(ushort *)&fp->_IO_read_base << 0x19) < 0) {
          return -1;
        }
        return local_74;
      }
      local_74 = local_74 + iVar2;
    }
    if (*pbVar7 == 0) goto LAB_0007a382;
    local_88 = 0;
    local_7c = 0;
    local_45 = 0;
    local_30 = 0;
    local_84 = 0xffffffff;
    uStack_80 = 0;
    pbVar8 = pbVar7 + 1;
    while( true ) {
      pbVar7 = pbVar8 + 1;
      pvVar4 = memchr("#-0+ ",(uint)*pbVar8,5);
      if (pvVar4 == (void *)0x0) break;
      local_88 = 1 << ((int)pvVar4 - 0xf6ba2U & 0xff) | local_88;
      pbVar8 = pbVar7;
    }
    if ((int)(local_88 << 0x1b) < 0) {
      local_45 = 0x20;
    }
    if ((int)(local_88 << 0x1c) < 0) {
      local_45 = 0x2b;
    }
    if (*pbVar8 == 0x2a) {
      puVar5 = local_8c + 1;
      uVar6 = *local_8c;
      local_8c = puVar5;
      if ((int)uVar6 < 0) {
        local_88 = local_88 | 2;
        uVar6 = -uVar6;
      }
    }
    else {
      bVar1 = false;
      uVar6 = local_7c;
      pbVar7 = pbVar8;
      while( true ) {
        if (9 < *pbVar7 - 0x30) break;
        uVar6 = uVar6 * 10 + (*pbVar7 - 0x30);
        bVar1 = true;
        pbVar7 = pbVar7 + 1;
      }
      if (!bVar1) {
        uVar6 = local_7c;
      }
    }
    local_7c = uVar6;
    if (*pbVar7 == 0x2e) {
      if (pbVar7[1] == 0x2a) {
        pbVar7 = pbVar7 + 2;
        uVar6 = *local_8c;
        local_8c = local_8c + 1;
        local_84 = uVar6 | (int)uVar6 >> 0x1f;
      }
      else {
        bVar1 = false;
        uVar6 = 0;
        local_84 = 0;
        while( true ) {
          pbVar7 = pbVar7 + 1;
          if (9 < *pbVar7 - 0x30) break;
          uVar6 = uVar6 * 10 + (*pbVar7 - 0x30);
          bVar1 = true;
        }
        if (bVar1) {
          local_84 = uVar6;
        }
      }
    }
    pvVar4 = memchr("hlL",(uint)*pbVar7,3);
    if (pvVar4 != (void *)0x0) {
      pbVar7 = pbVar7 + 1;
      local_88 = local_88 | 0x40 << ((int)pvVar4 - 0xf6ba8U & 0xff);
    }
    fmt0 = (char *)(pbVar7 + 1);
    local_70 = *pbVar7;
    pvVar4 = memchr("efgEFG",(uint)local_70,6);
    if (pvVar4 == (void *)0x0) {
      uVar6 = _printf_float();
    }
    else {
      uVar6 = _printf_i((int)data,&local_88,fp,(undefined *)0x8a467,(int *)&local_8c);
    }
    if (uVar6 == 0xffffffff) goto LAB_0007a382;
    local_74 = local_74 + uVar6;
    pbVar8 = (byte *)fmt0;
  }
  goto LAB_0007a212;
}


