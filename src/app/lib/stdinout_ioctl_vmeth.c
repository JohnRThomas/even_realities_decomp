/*
 * Function: stdinout_ioctl_vmeth
 * Entry:    00081438
 * Prototype: int __stdcall stdinout_ioctl_vmeth(void * obj, uint request, va_list args)
 */


/* exclude_from_export */

int stdinout_ioctl_vmeth(void *obj,uint request,va_list args)

{
  int *piVar1;
  
  piVar1 = __errno();
  *piVar1 = 0x16;
  return -1;
}


