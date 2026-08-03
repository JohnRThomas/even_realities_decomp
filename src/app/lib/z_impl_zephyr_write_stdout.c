/*
 * Function: z_impl_zephyr_write_stdout
 * Entry:    000542f0
 * Prototype: int __stdcall z_impl_zephyr_write_stdout(void * buffer, int nbytes)
 */


/* exclude_from_export */

int z_impl_zephyr_write_stdout(void *buffer,int nbytes)

{
  undefined1 *puVar1;
  
  puVar1 = (undefined1 *)((int)buffer + -1);
  while ((int)(puVar1 + (1 - (int)buffer)) < nbytes) {
    if (puVar1[1] == '\n') {
      (*_stdout_hook)(L'\r');
    }
    puVar1 = puVar1 + 1;
    (*_stdout_hook)(*puVar1);
  }
  return nbytes;
}


