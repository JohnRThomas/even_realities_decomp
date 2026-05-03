/*
 * Function: FUN_01029094
 * Entry:    01029094
 * Prototype: undefined4 __stdcall FUN_01029094(byte * param_1, undefined4 param_2, undefined4 param_3)
 */


undefined4 FUN_01029094(byte *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  
  if (*param_1 < 2) {
    bVar1 = FUN_01028cc2((int)param_1,param_2,param_3);
    if ((bVar1) && (cVar2 = FUN_0100cf0c(), cVar2 != '\0')) {
      return 0xc;
    }
    bVar1 = FUN_01028a96((uint)*param_1);
    if ((bVar1 != 1) || ((param_1[6] & 0xc0) == 0xc0)) {
      uVar3 = FUN_0100c7b8((uint)bVar1,param_1 + 1,(uint *)(param_1 + 7),(uint *)(param_1 + 0x17));
      return uVar3;
    }
  }
  return 0x12;
}


