/*
 * Function: update_offset
 * Entry:    000886c6
 * Prototype: void __stdcall update_offset(printbuffer * buffer)
 */


/* exclude_from_export_ai */

void update_offset(printbuffer *buffer)

{
  size_t sVar1;
  int iVar2;
  
  if ((buffer != (printbuffer *)0x0) && (*(int *)buffer->opaque != 0)) {
    iVar2 = *(int *)buffer[2].opaque;
    sVar1 = strlen((char *)(*(int *)buffer->opaque + iVar2));
    *(size_t *)buffer[2].opaque = iVar2 + sVar1;
  }
  return;
}


