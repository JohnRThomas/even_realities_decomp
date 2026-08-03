/*
 * Function: __smakebuf_r
 * Entry:    00079f94
 * Prototype: void __stdcall __smakebuf_r(int * param_1, FILE * param_2)
 */


/* exclude_from_export */

void __smakebuf_r(int *param_1,FILE *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  char *pcVar3;
  int iVar4;
  int *local_20;
  FILE *local_1c [2];
  
  if (-1 < (int)((uint)*(ushort *)&param_2->_IO_read_base << 0x1e)) {
    local_20 = param_1;
    local_1c[0] = param_2;
    uVar2 = __swhatbuf_r(param_1,(int)param_2,&local_20,(uint *)local_1c);
    piVar1 = local_20;
    pcVar3 = _malloc_r((size_t)param_1,(size_t)local_20);
    if (pcVar3 != (char *)0x0) {
      param_1[10] = 0x79e39;
      param_2->_flags = (int)pcVar3;
      *(ushort *)&param_2->_IO_read_base = *(ushort *)&param_2->_IO_read_base | 0x80;
      param_2->_IO_write_base = pcVar3;
      param_2->_IO_write_ptr = (char *)piVar1;
      if ((local_1c[0] != (FILE *)0x0) &&
         (iVar4 = _isatty_r(param_1,(int)*(short *)((int)&param_2->_IO_read_base + 2)), iVar4 != 0))
      {
        *(ushort *)&param_2->_IO_read_base = *(ushort *)&param_2->_IO_read_base & 0xfffc | 1;
      }
      *(ushort *)&param_2->_IO_read_base = (ushort)uVar2 | *(ushort *)&param_2->_IO_read_base;
      return;
    }
    if ((int)(short)*(ushort *)&param_2->_IO_read_base << 0x16 < 0) {
      return;
    }
    *(ushort *)&param_2->_IO_read_base = *(ushort *)&param_2->_IO_read_base & 0xfffc | 2;
  }
  param_2->_flags = (int)param_2->_shortbuf;
  param_2->_IO_write_base = param_2->_shortbuf;
  param_2->_IO_write_ptr = &DAT_00000001;
  return;
}


