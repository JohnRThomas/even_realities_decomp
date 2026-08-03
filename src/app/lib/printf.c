/*
 * Function: printf
 * Entry:    0007aa98
 * Prototype: int __stdcall printf(char * f, ...)
 */


/* exclude_from_export_ai */

int printf(char *f,...)

{
  undefined4 *data;
  int iVar1;
  undefined4 in_r1;
  undefined4 in_r2;
  undefined4 in_r3;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  data = _REENT;
  uStack_c = in_r1;
  uStack_8 = in_r2;
  uStack_4 = in_r3;
  if ((_REENT != (undefined4 *)0x0) && (_REENT[6] == 0)) {
    __sinit(_REENT);
  }
  iVar1 = _vfprintf_r(data,(FILE *)data[2],f,(va_list)&uStack_c);
  return iVar1;
}


