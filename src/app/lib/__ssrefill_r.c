/*
 * Function: __ssrefill_r
 * Entry:    0008b012
 * Prototype: int __stdcall __ssrefill_r(void * ptr, FILE * fp)
 */


/* exclude_from_export */

int __ssrefill_r(void *ptr,FILE *fp)

{
  _IO_FILE *p_Var1;
  
  p_Var1 = fp->_chain;
  if (p_Var1 != (_IO_FILE *)0x0) {
    if (p_Var1 != (_IO_FILE *)&fp->_cur_column) {
      _free_r(ptr,(int)p_Var1);
    }
    fp->_chain = (_IO_FILE *)0x0;
    fp->_IO_read_ptr = (char *)fp->_old_offset;
    if ((char *)fp->_old_offset != (char *)0x0) {
      fp->_flags = fp->_flags2;
      return 0;
    }
  }
  fp->_flags = (int)fp->_IO_write_base;
  fp->_IO_read_ptr = (char *)0x0;
  *(ushort *)&fp->_IO_read_base = *(ushort *)&fp->_IO_read_base | 0x20;
  return -1;
}


