/*
 * Function: FUN_0103a370
 * Entry:    0103a370
 * Prototype: undefined4 __stdcall FUN_0103a370(void)
 */


undefined4 FUN_0103a370(void)

{
  bool bVar1;
  
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  software_interrupt(2);
  return 4;
}


