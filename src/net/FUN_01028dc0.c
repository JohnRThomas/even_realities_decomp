/*
 * Function: FUN_01028dc0
 * Entry:    01028dc0
 * Prototype: undefined4 __stdcall FUN_01028dc0(char * param_1, uint param_2, int param_3)
 */


undefined4 FUN_01028dc0(char *param_1,uint param_2,int param_3)

{
  bool bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  
  if (param_3 == 0) {
    uVar2 = FUN_0100acd0();
    if (uVar2 < param_2) {
      return 7;
    }
    uVar3 = FUN_01012ee8((int)param_1);
    if ((uVar3 != 0) && (0x1f < param_2)) {
      return 0x12;
    }
    bVar1 = FUN_01012aa8(param_1);
    if (!bVar1) {
      return 0x42;
    }
    iVar4 = FUN_01012afc((int)param_1,param_2);
    if (iVar4 == 0) {
      return 0x45;
    }
  }
  else if (0x1f < param_2) {
    return 0x12;
  }
  return 0;
}


