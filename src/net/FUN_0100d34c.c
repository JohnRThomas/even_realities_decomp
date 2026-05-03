/*
 * Function: FUN_0100d34c
 * Entry:    0100d34c
 * Prototype: char __stdcall FUN_0100d34c(int param_1)
 */


char FUN_0100d34c(int param_1)

{
  char cVar1;
  byte bVar2;
  
  cVar1 = DAT_21000ea2;
  bVar2 = 0;
  if ((DAT_21000ea2 != '\0') && (bVar2 = DAT_21000d19, DAT_21000d19 != 0)) {
    FUN_01020440(0x21000d1a,(uint)DAT_21000d19,param_1);
    return cVar1;
  }
  return bVar2;
}


