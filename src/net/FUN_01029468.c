/*
 * Function: FUN_01029468
 * Entry:    01029468
 * Prototype: int __stdcall FUN_01029468(undefined1 * param_1, undefined4 param_2)
 */


int FUN_01029468(undefined1 *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  char cVar3;
  char cVar4;
  ushort local_10;
  undefined2 local_e;
  undefined2 local_c;
  undefined2 uStack_a;
  
  bVar1 = param_1[2];
  cVar3 = param_1[3];
  cVar4 = param_1[4];
  if ((cVar3 == '\0' && (bVar1 & 1) == 0) || (cVar4 == '\0' && (bVar1 & 2) == 0)) {
    iVar2 = 0x11;
  }
  else {
    if ((bVar1 & 1) != 0) {
      cVar3 = '\0';
    }
    if ((bVar1 & 2) != 0) {
      cVar4 = '\0';
    }
    _local_10 = CONCAT22(CONCAT11(cVar4,cVar3),CONCAT11(param_1[1],*param_1));
    _local_c = CONCAT22((short)((uint)param_2 >> 0x10),*(undefined2 *)(param_1 + 5));
    iVar2 = FUN_01029438(&local_10);
  }
  return iVar2;
}


