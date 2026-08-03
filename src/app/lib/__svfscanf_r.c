/*
 * Function: __svfscanf_r
 * Entry:    0007c230
 * Prototype: int __stdcall __svfscanf_r(void * rptr, FILE * fp, char * fmt0, va_list ap)
 */


/* WARNING: Removing unreachable block (ram,0x0007c4f8) */
/* exclude_from_export_ai */

int __svfscanf_r(void *rptr,FILE *fp,char *fmt0,va_list ap)

{
  int iVar1;
  void *pvVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  byte *pbVar6;
  undefined4 *local_2a8;
  undefined1 auStack_2a4 [256];
  uint local_1a4;
  undefined4 local_1a0;
  uint local_19c;
  int local_198;
  int local_194;
  undefined1 *local_190;
  int local_18c;
  undefined4 local_28;
  code *local_24;
  
  local_198 = 0;
  local_194 = 0;
  local_28 = 0x8af9d;
  local_24 = (code *)0x8b013;
  local_2a8 = (undefined4 *)ap;
  local_190 = auStack_2a4;
LAB_0007c256:
  while( true ) {
    while( true ) {
      uVar5 = (uint)(byte)*fmt0;
      if (uVar5 == 0) {
        return local_198;
      }
      pbVar6 = (byte *)(fmt0 + 1);
      uVar3 = (byte)(&DAT_000f6aa2)[uVar5] & 8;
      if (((&DAT_000f6aa2)[uVar5] & 8) == 0) break;
      while (((fmt0 = (char *)pbVar6, 0 < (int)fp->_IO_read_ptr ||
              (iVar1 = (*local_24)(rptr,fp), iVar1 == 0)) &&
             ((int)((uint)(byte)(&DAT_000f6aa2)[*(byte *)fp->_flags] << 0x1c) < 0))) {
        local_194 = local_194 + 1;
        fp->_flags = (int)((byte *)fp->_flags + 1);
        fp->_IO_read_ptr = fp->_IO_read_ptr + -1;
      }
    }
    if (uVar5 == L'%') break;
LAB_0007c2a0:
    if (((int)fp->_IO_read_ptr < 1) && (iVar1 = (*local_24)(rptr,fp), iVar1 != 0))
    goto LAB_0007c3e0;
    if (*(byte *)fp->_flags != uVar5) {
      return local_198;
    }
    fp->_flags = (int)((byte *)fp->_flags + 1);
    fp->_IO_read_ptr = fp->_IO_read_ptr + -1;
    local_194 = local_194 + 1;
    fmt0 = (char *)pbVar6;
  }
  local_1a4 = uVar3;
  local_19c = uVar3;
  if (fmt0[1] == '*') {
    local_1a4 = 0x10;
    pbVar6 = (byte *)(fmt0 + 2);
  }
  while( true ) {
    uVar5 = (uint)*pbVar6;
    if (9 < uVar5 - L'0') break;
    local_19c = (local_19c * 10 + uVar5) - 0x30;
    pbVar6 = pbVar6 + 1;
  }
  pvVar2 = memchr("hlL",uVar5,3);
  if (pvVar2 != (void *)0x0) {
    local_1a4 = 1 << ((int)pvVar2 - 0xf6ba8U & 0xff) | local_1a4;
    pbVar6 = pbVar6 + 1;
  }
  fmt0 = (char *)(pbVar6 + 1);
  uVar5 = (uint)*pbVar6;
  if (uVar5 < L'y') {
    if (L'W' < uVar5) {
      switch(uVar5) {
      case L'X':
      case L'x':
        local_1a4 = local_1a4 | 0x200;
        local_1a0 = 0x10;
        goto LAB_0007c43c;
      default:
        goto switchD_0007c340_caseD_59;
      case L'[':
        fmt0 = (char *)____FUN_0008b04c((int)auStack_2a4,(byte *)fmt0);
        local_1a4 = local_1a4 | 0x40;
        local_18c = 1;
        break;
      case L'c':
        local_1a4 = local_1a4 | 0x40;
        local_18c = 0;
        break;
      case L'd':
      case L'u':
        local_1a0 = 10;
LAB_0007c43c:
        if (0x6e < uVar5) goto LAB_0007c3fa;
LAB_0007c448:
        local_18c = 3;
        break;
      case L'e':
      case L'f':
      case L'g':
switchD_0007c340_caseD_65:
        local_18c = 5;
        break;
      case L'i':
        local_1a0 = 0;
        goto LAB_0007c448;
      case L'n':
        if (-1 < (int)(local_1a4 << 0x1b)) {
          if ((local_1a4 & 1) == 0) {
            *(int *)*local_2a8 = local_194;
            local_2a8 = local_2a8 + 1;
          }
          else {
            *(short *)*local_2a8 = (short)local_194;
            local_2a8 = local_2a8 + 1;
          }
        }
        goto LAB_0007c256;
      case L'o':
        local_1a0 = 8;
        goto LAB_0007c3fa;
      case L'p':
        local_1a4 = local_1a4 | 0x220;
        local_1a0 = 0x10;
LAB_0007c3fa:
        local_18c = 4;
        break;
      case L's':
        local_18c = 2;
      }
LAB_0007c3fe:
      if (((int)fp->_IO_read_ptr < 1) && (iVar1 = (*local_24)(rptr,fp), iVar1 != 0))
      goto LAB_0007c3e0;
      if (-1 < (int)(local_1a4 << 0x19)) {
        while ((int)((uint)(byte)(&DAT_000f6aa2)[*(byte *)fp->_flags] << 0x1c) < 0) {
          local_194 = local_194 + 1;
          pcVar4 = fp->_IO_read_ptr;
          fp->_IO_read_ptr = pcVar4 + -1;
          if ((int)(pcVar4 + -1) < 1) {
            iVar1 = (*local_24)(rptr,fp);
            if (iVar1 != 0) goto LAB_0007c3e0;
          }
          else {
            fp->_flags = (int)((byte *)fp->_flags + 1);
          }
        }
      }
      if (local_18c < 3) {
        iVar1 = print_value(rptr,&local_1a4,&fp->_flags,&local_2a8);
      }
      else {
        if (4 < local_18c) goto LAB_0007c256;
        iVar1 = parse_string(rptr,&local_1a4,&fp->_flags,&local_2a8);
      }
      if (iVar1 == 1) {
        return local_198;
      }
      if (iVar1 == 2) {
LAB_0007c3e0:
        if ((local_198 == 0) || ((int)((uint)*(ushort *)&fp->_IO_read_base << 0x19) < 0)) {
LAB_0007c3e8:
          local_198 = -1;
        }
        return local_198;
      }
      goto LAB_0007c256;
    }
    pbVar6 = (byte *)fmt0;
    if (uVar5 == 0x25) goto LAB_0007c2a0;
    if (uVar5 < 0x26) {
      if (uVar5 != 0) goto switchD_0007c340_caseD_59;
      goto LAB_0007c3e8;
    }
    if (uVar5 - 0x45 < 3) goto switchD_0007c340_caseD_65;
  }
switchD_0007c340_caseD_59:
  local_18c = 3;
  local_1a0 = 10;
  goto LAB_0007c3fe;
}


