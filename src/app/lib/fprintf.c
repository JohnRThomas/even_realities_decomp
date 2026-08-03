/*
 * Function: fprintf
 * Entry:    0007c038
 * Prototype: int __stdcall fprintf(undefined4 * ptr, FILE * __stream, char * __format, ...)
 */


/* WARNING: Removing unreachable block (ram,0x0007c1a0) */
/* exclude_from_export */

int fprintf(undefined4 *ptr,FILE *__stream,char *__format,...)

{
  bool bVar1;
  char *pcVar2;
  int iVar3;
  void *pvVar4;
  uint *puVar5;
  uint *in_r3;
  byte *pbVar6;
  byte *pbVar7;
  uint uVar8;
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
  
                    /* exclude_from_export */
  if (((int)((uint)*(ushort *)&__stream->_IO_read_base << 0x18) < 0) &&
     (__stream->_IO_write_base == (char *)0x0)) {
    pcVar2 = _malloc_r((size_t)ptr,0x40);
    __stream->_flags = (int)pcVar2;
    __stream->_IO_write_base = pcVar2;
    if (pcVar2 == (char *)0x0) {
      *ptr = 0xc;
      return -1;
    }
    __stream->_IO_write_ptr = &IRQ;
  }
  local_74 = 0;
  local_6f = 0x20;
  local_6e = 0x30;
  pbVar7 = (byte *)__format;
  local_8c = in_r3;
LAB_0007c08c:
  pbVar6 = pbVar7;
  if (*pbVar6 != 0) goto code_r0x0007c094;
  goto LAB_0007c098;
code_r0x0007c094:
  pbVar7 = pbVar6 + 1;
  if (*pbVar6 == 0x25) {
LAB_0007c098:
    uVar8 = (int)pbVar6 - (int)__format;
    if (uVar8 != 0) {
      iVar3 = __ssputs_r(ptr,&__stream->_flags,__format,uVar8);
      if (iVar3 == -1) {
LAB_0007c1fe:
        if ((int)((uint)*(ushort *)&__stream->_IO_read_base << 0x19) < 0) {
          return -1;
        }
        return local_74;
      }
      local_74 = local_74 + uVar8;
    }
    if (*pbVar6 == 0) goto LAB_0007c1fe;
    local_88 = 0;
    local_7c = 0;
    local_45 = 0;
    local_30 = 0;
    local_84 = 0xffffffff;
    uStack_80 = 0;
    pbVar7 = pbVar6 + 1;
    while( true ) {
      pbVar6 = pbVar7 + 1;
      pvVar4 = memchr("#-0+ ",(uint)*pbVar7,5);
      if (pvVar4 == (void *)0x0) break;
      local_88 = 1 << ((int)pvVar4 - 0xf6ba2U & 0xff) | local_88;
      pbVar7 = pbVar6;
    }
    if ((int)(local_88 << 0x1b) < 0) {
      local_45 = 0x20;
    }
    if ((int)(local_88 << 0x1c) < 0) {
      local_45 = 0x2b;
    }
    if (*pbVar7 == 0x2a) {
      puVar5 = local_8c + 1;
      local_7c = *local_8c;
      local_8c = puVar5;
      if ((int)local_7c < 0) {
        local_7c = -local_7c;
        local_88 = local_88 | 2;
      }
    }
    else {
      bVar1 = false;
      uVar8 = local_7c;
      pbVar6 = pbVar7;
      while( true ) {
        if (9 < *pbVar6 - 0x30) break;
        uVar8 = uVar8 * 10 + (*pbVar6 - 0x30);
        bVar1 = true;
        pbVar6 = pbVar6 + 1;
      }
      if (bVar1) {
        local_7c = uVar8;
      }
    }
    if (*pbVar6 == 0x2e) {
      if (pbVar6[1] == 0x2a) {
        pbVar6 = pbVar6 + 2;
        uVar8 = *local_8c;
        local_8c = local_8c + 1;
        local_84 = uVar8 | (int)uVar8 >> 0x1f;
      }
      else {
        bVar1 = false;
        uVar8 = 0;
        local_84 = 0;
        while( true ) {
          pbVar6 = pbVar6 + 1;
          if (9 < *pbVar6 - 0x30) break;
          uVar8 = uVar8 * 10 + (*pbVar6 - 0x30);
          bVar1 = true;
        }
        if (bVar1) {
          local_84 = uVar8;
        }
      }
    }
    pvVar4 = memchr("hlL",(uint)*pbVar6,3);
    if (pvVar4 != (void *)0x0) {
      pbVar6 = pbVar6 + 1;
      local_88 = local_88 | 0x40 << ((int)pvVar4 - 0xf6ba8U & 0xff);
    }
    __format = (char *)(pbVar6 + 1);
    local_70 = *pbVar6;
    pvVar4 = memchr("efgEFG",(uint)local_70,6);
    if (pvVar4 == (void *)0x0) {
      uVar8 = _printf_float();
    }
    else {
      uVar8 = _printf_i((int)ptr,&local_88,__stream,(undefined *)0x8aee7,(int *)&local_8c);
    }
    if (uVar8 == 0xffffffff) goto LAB_0007c1fe;
    local_74 = local_74 + uVar8;
    pbVar7 = (byte *)__format;
  }
  goto LAB_0007c08c;
}


