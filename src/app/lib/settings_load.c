/*
 * Function: settings_load
 * Entry:    0008292a
 * Prototype: int __stdcall settings_load(void)
 */


/* exclude_from_export */

int settings_load(void)

{
  int iVar1;
  
  iVar1 = settings_load_subtree((char *)0x0);
  return iVar1;
}


