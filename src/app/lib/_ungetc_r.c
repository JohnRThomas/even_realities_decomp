/*
 * Function: _ungetc_r
 * Entry:    0008af9c
 * Prototype: int __stdcall _ungetc_r(void * rptr, int c, FILE * fp)
 */


/* exclude_from_export */

int _ungetc_r(void *rptr,int c,FILE *fp)

{
  char *pcVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  
  if (c == -1) {
LAB_0008afa4:
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = c & 0xff;
    *(ushort *)&fp->_IO_read_base = *(ushort *)&fp->_IO_read_base & 0xffdf;
    pcVar2 = fp->_IO_read_ptr;
    if (fp->_chain == (_IO_FILE *)0x0) {
      pcVar1 = (char *)fp->_flags;
      if (((fp->_IO_write_base != (char *)0x0) && (fp->_IO_write_base < pcVar1)) &&
         ((byte)pcVar1[-1] == uVar4)) {
        fp->_flags = (int)(pcVar1 + -1);
        goto LAB_0008afce;
      }
      fp->_flags2 = (int)pcVar1;
      fp->_old_offset = (__off_t)pcVar2;
      fp->_chain = (_IO_FILE *)&fp->_cur_column;
      fp->_fileno = 3;
      fp->_vtable_offset = (char)c;
      fp->_flags = (int)&fp->_vtable_offset;
      pcVar2 = &DAT_00000001;
    }
    else {
      if ((fp->_fileno <= (int)pcVar2) && (iVar3 = __submore(rptr,fp), iVar3 != 0))
      goto LAB_0008afa4;
      iVar3 = fp->_flags;
      fp->_flags = iVar3 + -1;
      *(char *)(iVar3 + -1) = (char)c;
      pcVar2 = fp->_IO_read_ptr;
LAB_0008afce:
      pcVar2 = pcVar2 + 1;
    }
    fp->_IO_read_ptr = pcVar2;
  }
  return uVar4;
}


