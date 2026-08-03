/*
 * Function: vsnprintk
 * Entry:    0004e488
 * Prototype: int __stdcall vsnprintk(char * str, size_t size, char * fmt, va_list ap)
 */


/* exclude_from_export */

int vsnprintk(char *str,size_t size,char *fmt,va_list ap)

{
  char *local_1c;
  size_t local_18;
  int local_14;
  
  local_14 = 0;
  local_1c = str;
  local_18 = size;
  z_cbvprintf_impl((cbprintf_cb)0x81517,&local_1c,fmt,ap,0);
  if (local_14 < (int)local_18) {
    str[local_14] = '\0';
  }
  return local_14;
}


