/*
 * Function: FUN_0102cca4
 * Entry:    0102cca4
 * Prototype: int __stdcall FUN_0102cca4(int * param_1, uint param_2, uint param_3)
 */


int FUN_0102cca4(int *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint extraout_r1;
  uint uVar2;
  uint extraout_r2;
  uint uVar3;
  uint extraout_r3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  iVar5 = *param_1;
  uVar2 = *(uint *)(iVar5 + 8);
  if (uVar2 < 0x8000) {
    uVar1 = 4;
  }
  else {
    uVar1 = 8;
  }
  uVar3 = param_2 - 1 & param_2;
  if (uVar3 == 0) {
    uVar6 = 0;
    uVar3 = param_2;
    if (param_2 <= uVar1) {
      iVar5 = *param_1;
      if ((param_3 != 0) && (param_3 >> 3 < *(uint *)(iVar5 + 8))) {
        uVar2 = FUN_01039f80(*(uint *)(iVar5 + 8),param_3);
        uVar1 = FUN_0103a034(iVar5,uVar2);
        if (uVar1 != 0) {
          uVar3 = FUN_01039f28(iVar5,uVar1);
          if (uVar2 < uVar3) {
            FUN_0103a0a8(iVar5,uVar1,uVar2 + uVar1);
            FUN_0103a132(iVar5,uVar2 + uVar1);
          }
          iVar4 = FUN_01039f34(iVar5,uVar1,1);
          if (*(uint *)(iVar5 + 8) < 0x8000) {
            iVar5 = 4;
          }
          else {
            iVar5 = 8;
          }
          return iVar4 + iVar5 + uVar1 * 8;
        }
      }
      return 0;
    }
  }
  else {
    uVar6 = -param_2 & param_2;
    if (uVar6 <= uVar1) {
      uVar1 = uVar6;
    }
    if ((uVar3 - 1 & uVar3) != 0) {
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/lib/os/heap.c",0x144,uVar3
                  );
      FUN_0103a370();
      uVar1 = extraout_r1;
      uVar2 = extraout_r2;
      uVar3 = param_2;
      uVar6 = extraout_r3;
    }
  }
  if ((param_3 != 0) && (param_3 >> 3 < uVar2)) {
    uVar2 = FUN_01039f80(uVar2,(param_3 + uVar3) - uVar1);
    uVar2 = FUN_0103a034(iVar5,uVar2);
    if (uVar2 != 0) {
      if (*(uint *)(iVar5 + 8) < 0x8000) {
        iVar4 = 4;
      }
      else {
        iVar4 = 8;
      }
      iVar4 = uVar3 * ((uVar6 + uVar2 * 8 + iVar4 + iVar5 + (uVar3 - 1)) / uVar3) - uVar6;
      uVar3 = FUN_01039f6c(iVar5,iVar4);
      uVar1 = (int)((param_3 + iVar4 + 7 & 0xfffffff8) - iVar5) >> 3;
      if (uVar2 < uVar3) {
        FUN_0103a0a8(iVar5,uVar2,uVar3);
        FUN_0103a132(iVar5,uVar2);
      }
      uVar2 = FUN_01039f28(iVar5,uVar3);
      if (uVar1 < uVar2 + uVar3) {
        FUN_0103a0a8(iVar5,uVar3,uVar1);
        FUN_0103a132(iVar5,uVar1);
      }
      FUN_01039f34(iVar5,uVar3,1);
      return iVar4;
    }
  }
  return 0;
}


