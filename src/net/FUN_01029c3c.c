/*
 * Function: FUN_01029c3c
 * Entry:    01029c3c
 * Prototype: undefined4 __stdcall FUN_01029c3c(byte * param_1)
 */


undefined4 FUN_01029c3c(byte *param_1)

{
  char cVar1;
  undefined4 *puVar2;
  
  cVar1 = FUN_01020088();
  if (cVar1 == '\0') {
    puVar2 = (undefined4 *)FUN_0100a518((ushort)*param_1,2);
    if (puVar2 == (undefined4 *)0x0) {
      return 0x42;
    }
  }
  else {
    puVar2 = FUN_0101ee2c();
  }
  FUN_01013170((int)puVar2,param_1[1] & 1,(byte)(((uint)param_1[1] << 0x1e) >> 0x1f));
  return 0;
}


