/*
 * Function: settings_delete
 * Entry:    00082930
 * Prototype: int __stdcall settings_delete(char * name)
 */


/* exclude_from_export */

int settings_delete(char *name)

{
  int iVar1;
  
  iVar1 = settings_save_one(name,(void *)0x0,0);
  return iVar1;
}


