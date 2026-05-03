/*
 * Function: FUN_01029438
 * Entry:    01029438
 * Prototype: int __stdcall FUN_01029438(ushort * param_1)
 */


int FUN_01029438(ushort *param_1)

{
  int iVar1;
  
  if (param_1[2] < 3) {
    iVar1 = FUN_01028ca8((uint)*(byte *)((int)param_1 + 3));
    if ((iVar1 != 0) && (iVar1 = FUN_01028ca8((uint)(byte)param_1[1]), iVar1 != 0)) {
      iVar1 = FUN_01028f8a(param_1,1);
      return iVar1;
    }
    iVar1 = 0x11;
  }
  else {
    iVar1 = 0x12;
  }
  return iVar1;
}


