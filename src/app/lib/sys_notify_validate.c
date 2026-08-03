/*
 * Function: sys_notify_validate
 * Entry:    000819d0
 * Prototype: int __stdcall sys_notify_validate(sys_notify * notify)
 */


/* exclude_from_export */

int sys_notify_validate(sys_notify *notify)

{
  uint uVar1;
  
  if (notify != (sys_notify *)0x0) {
    uVar1 = notify->callback & 3;
    if ((uVar1 == 2) || (uVar1 == 3)) {
      if (notify->signal != (undefined *)0x0) goto LAB_000819f2;
    }
    else if (uVar1 == 1) {
LAB_000819f2:
      notify->method = 0;
      return 0;
    }
  }
  return -0x16;
}


