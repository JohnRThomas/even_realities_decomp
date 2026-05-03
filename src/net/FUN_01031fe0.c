/*
 * Function: FUN_01031fe0
 * Entry:    01031fe0
 * Prototype: undefined4 __stdcall FUN_01031fe0(void)
 */


undefined4 FUN_01031fe0(void)

{
  bool bVar1;
  undefined1 *unaff_r4;
  
  FUN_0102e7c0();
  FUN_0102ea44(0x103c024,0x1040,&stack0xfffffff0,(undefined1 *)0x0);
  FUN_0102fcac();
  FUN_0102ea44(0x103c004,0x2040,&stack0xfffffff0,unaff_r4);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  software_interrupt(2);
  return 0xfffffff4;
}


