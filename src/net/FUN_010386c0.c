/*
 * Function: FUN_010386c0
 * Entry:    010386c0
 * Prototype: int __stdcall FUN_010386c0(void)
 */


int FUN_010386c0(void)

{
  undefined8 uVar1;
  
  if (DAT_21004b6c == 0) {
    uVar1 = FUN_01031b68();
    return (int)uVar1 - DAT_21002b80;
  }
  return 0;
}


