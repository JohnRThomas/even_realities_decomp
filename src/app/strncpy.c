/*
 * Function: $_?_strncpy
 * Entry:    0008a76e
 * Prototype: char * __stdcall $_?_strncpy(char * dst, char * src, size_t n)
 */


char * ____strncpy(char *dst,char *src,size_t n)

{
  char *pcVar1;
  char *pcVar2;
  
  pcVar2 = dst;
  while (*pcVar2 != '\0') {
    if (n == 0) goto LAB_0008a78a;
    n = n - 1;
    pcVar2 = pcVar2 + 1;
  }
  pcVar1 = src + -1;
  while( true ) {
    pcVar1 = pcVar1 + 1;
    if (*pcVar1 == '\0') break;
    if (n == 0) goto LAB_0008a78a;
    n = n - 1;
    *pcVar2 = *pcVar1;
    pcVar2 = pcVar2 + 1;
  }
  if (n != 0) {
    *pcVar2 = '\0';
    return dst;
  }
LAB_0008a78a:
                    /* WARNING: Subroutine does not return */
  __chk_fail();
}


