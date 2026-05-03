/*
 * Function: FUN_01026e48
 * Entry:    01026e48
 * Prototype: undefined4 __stdcall FUN_01026e48(ushort * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


undefined4 FUN_01026e48(ushort *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 == (ushort *)0x0) ||
     (iVar1 = FUN_010267f0(param_1,param_2,param_3,param_4), iVar1 == 0)) {
    uVar2 = 0xffffffea;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


