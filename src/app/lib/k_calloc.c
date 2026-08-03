/*
 * Function: k_calloc
 * Entry:    0008a07a
 * Prototype: void * __stdcall k_calloc(size_t nmemb, size_t size)
 */


/* exclude_from_export */

void * k_calloc(size_t nmemb,size_t size)

{
  void *buf;
  size_t size_00;
  
  size_00 = (size_t)((ulonglong)nmemb * (ulonglong)size);
  if (((int)((ulonglong)nmemb * (ulonglong)size >> 0x20) == 0) &&
     (buf = k_malloc(size_00), buf != (void *)0x0)) {
    memset(buf,0,size_00);
  }
  else {
    buf = (void *)0x0;
  }
  return buf;
}


