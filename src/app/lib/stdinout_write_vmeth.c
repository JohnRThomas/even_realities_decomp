/*
 * Function: stdinout_write_vmeth
 * Entry:    00081448
 * Prototype: ssize_t __stdcall stdinout_write_vmeth(void * obj, void * buffer, size_t count)
 */


/* exclude_from_export */

ssize_t stdinout_write_vmeth(void *obj,void *buffer,size_t count)

{
  int iVar1;
  
  iVar1 = z_impl_zephyr_write_stdout(buffer,count);
  return iVar1;
}


