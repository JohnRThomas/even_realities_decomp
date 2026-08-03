/*
 * Function: k_is_in_isr
 * Entry:    00089bb6
 * Prototype: bool __stdcall k_is_in_isr(void)
 */


/* exclude_from_export */

bool k_is_in_isr(void)

{
  bool bVar1;
  undefined1 uVar2;
  uint uVar3;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = getCurrentExceptionNumber();
    uVar3 = uVar3 & 0x1f;
  }
  uVar2 = (undefined1)uVar3;
  if (uVar3 != 0) {
    uVar2 = 1;
  }
  return (bool)uVar2;
}


