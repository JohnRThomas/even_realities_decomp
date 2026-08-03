/*
 * Function: __sprintf_chk
 * Entry:    0008a6b0
 * Prototype: int __stdcall __sprintf_chk(char * buf, int flags, size_t slen, char * fmt, ...)
 */


/* exclude_from_export */

int __sprintf_chk(char *buf,int flags,size_t slen,char *fmt,...)

{
  uint uVar1;
  
  if ((int)slen < 0) {
    uVar1 = vsprintf(buf,fmt,(va_list)&stack0x00000000);
  }
  else {
    uVar1 = vsnprintf(buf,slen,fmt,&stack0x00000000);
    if ((-1 < (int)uVar1) && (slen <= uVar1)) {
                    /* WARNING: Subroutine does not return */
      __chk_fail();
    }
  }
  return uVar1;
}


