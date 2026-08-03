/*
 * Function: _ASSERT
 * Entry:    00081a92
 * Prototype: void __stdcall _ASSERT(char * fmt, char * test, char * file, int line)
 */


/* exclude_from_export */

void _ASSERT(char *fmt,char *test,char *file,int line)

{
  char *pcStack_c;
  char *pcStack_8;
  int iStack_4;
  
  pcStack_c = test;
  pcStack_8 = file;
  iStack_4 = line;
  vprintk(fmt,(va_list)&pcStack_c);
  return;
}


