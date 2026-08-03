/*
 * Function: validate_args
 * Entry:    0008195e
 * Prototype: int __stdcall validate_args(onoff_manager * mgr, onoff_client * cli)
 */


/* exclude_from_export */

int validate_args(onoff_manager *mgr,onoff_client *cli)

{
  int iVar1;
  
  if (((mgr == (onoff_manager *)0x0) || (cli == (onoff_client *)0x0)) ||
     ((iVar1 = sys_notify_validate((sys_notify *)(cli + 1)), iVar1 == 0 && (3 < (uint)cli[2])))) {
    iVar1 = -0x16;
  }
  return iVar1;
}


