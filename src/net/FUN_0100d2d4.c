/*
 * Function: FUN_0100d2d4
 * Entry:    0100d2d4
 * Prototype: char __stdcall FUN_0100d2d4(int param_1, int param_2)
 */


char FUN_0100d2d4(int param_1,int param_2)

{
  char cVar1;
  undefined *puVar2;
  byte bVar3;
  
  FUN_010210b0();
  FUN_010204a8();
  cVar1 = DAT_21000ea2;
  bVar3 = 0;
  if ((DAT_21000ea2 != '\0') && (bVar3 = DAT_21000d19, DAT_21000d19 != 0)) {
    puVar2 = &DAT_21000d1a;
    if (param_2 == 0) {
      puVar2 = &DAT_21000d9a;
    }
    FUN_01020440((uint)puVar2,(uint)DAT_21000d19,param_1);
    FUN_010204f4();
    return cVar1;
  }
  return bVar3;
}


