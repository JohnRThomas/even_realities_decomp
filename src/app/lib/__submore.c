/*
 * Function: __submore
 * Entry:    0008b0be
 * Prototype: int __stdcall __submore(void * rptr, FILE * fp)
 */


/* exclude_from_export */

int __submore(void *rptr,FILE *fp)

{
  _IO_FILE *p_Var1;
  undefined1 *puVar2;
  size_t n;
  
  if (fp->_chain == (_IO_FILE *)&fp->_cur_column) {
    p_Var1 = _malloc_r((size_t)rptr,0x400);
    if (p_Var1 != (_IO_FILE *)0x0) {
      fp->_chain = p_Var1;
      puVar2 = (undefined1 *)((int)&p_Var1[6]._mode + 1);
      fp->_fileno = 0x400;
      *(char *)((int)&p_Var1[6]._mode + 3) = fp->_vtable_offset;
      *(undefined1 *)((int)&p_Var1[6]._mode + 2) = *(undefined1 *)((int)&fp->_cur_column + 1);
      *puVar2 = (char)fp->_cur_column;
      fp->_flags = (int)puVar2;
      return 0;
    }
  }
  else {
    n = fp->_fileno;
    p_Var1 = _realloc_r(rptr,fp->_chain,n << 1);
    if (p_Var1 != (_IO_FILE *)0x0) {
      memcpy(p_Var1->_shortbuf + (n - 0x47),p_Var1,n);
      fp->_flags = (int)(p_Var1->_shortbuf + (n - 0x47));
      fp->_chain = p_Var1;
      fp->_fileno = n << 1;
      return 0;
    }
  }
  return -1;
}


