/*
 * Function: FUN_0103a7a6
 * Entry:    0103a7a6
 * Prototype: undefined __stdcall FUN_0103a7a6(int param_1, byte * param_2, undefined4 param_3)
 */


void FUN_0103a7a6(int param_1,byte *param_2,undefined4 param_3)

{
  byte *pbVar1;
  bool bVar2;
  undefined4 extraout_r1;
  undefined4 uVar3;
  undefined4 extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 uVar4;
  undefined4 extraout_r2_00;
  undefined4 extraout_r3;
  undefined4 uVar5;
  undefined4 extraout_r3_00;
  int *piVar6;
  int iVar7;
  byte *local_1c;
  
  if ((param_2 != (byte *)0x0) && (*param_2 != 0)) {
    iVar7 = *(int *)(param_1 + 0xb0) + -0x19c;
    piVar6 = (int *)(*(int *)(param_1 + 0xb0) + 0x14);
    local_1c = param_2;
    FUN_01036bd0(piVar6,param_2,0xffffffff,-1);
    bVar2 = FUN_0102dea0(iVar7,(int *)&local_1c,param_2);
    pbVar1 = local_1c;
    uVar3 = extraout_r1;
    uVar4 = extraout_r2;
    uVar5 = extraout_r3;
    if (local_1c != (byte *)0x0) {
      if (bVar2) {
        src/*FUN_01036d3c(piVar6,extraout_r1,extraout_r2,extraout_r3);
        FUN_0102de5c(iVar7,(char *)pbVar1,(char *)param_2,param_3);
        return;
      }
      FUN_0103bd64((char *)(local_1c + 0x40),(int)param_2,0x20);
      *(undefined4 *)(pbVar1 + 0x60) = param_3;
      uVar3 = extraout_r1_00;
      uVar4 = extraout_r2_00;
      uVar5 = extraout_r3_00;
    }
    src/*FUN_01036d3c(piVar6,uVar3,uVar4,uVar5);
    return;
  }
  return;
}


