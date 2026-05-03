/*
 * Function: FUN_01028e08
 * Entry:    01028e08
 * Prototype: undefined4 __stdcall FUN_01028e08(char * param_1)
 */


undefined4 FUN_01028e08(char *param_1)

{
  bool bVar1;
  char cVar2;
  undefined4 uVar3;
  ushort *puVar4;
  int iVar5;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  
  bVar1 = FUN_01012aa8(param_1);
  if (bVar1) {
    cVar2 = FUN_010149d4((int)param_1);
    if (cVar2 != '\0') {
      puVar4 = (ushort *)FUN_01014240((int)param_1);
      iVar5 = FUN_010144d8((int)param_1);
      if (iVar5 != 0) {
        return 0xc;
      }
      if (puVar4 != (ushort *)0x0) {
        FUN_0100b0dc((uint)*puVar4);
        iVar5 = FUN_0100a564(*puVar4,1);
        if (iVar5 != 0) {
          FUN_01009500(0x39,&DAT_000017af,extraout_r2,extraout_r3);
          goto LAB_01028e4e;
        }
      }
    }
    uVar3 = 0;
  }
  else {
LAB_01028e4e:
    uVar3 = 0x42;
  }
  return uVar3;
}


