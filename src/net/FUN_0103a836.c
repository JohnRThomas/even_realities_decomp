/*
 * Function: FUN_0103a836
 * Entry:    0103a836
 * Prototype: int __stdcall FUN_0103a836(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


int FUN_0103a836(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 extraout_r2;
  code *pcVar3;
  undefined4 extraout_r3;
  undefined1 *puVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  
  puVar4 = *(undefined1 **)(param_1 + 0x10);
  piVar7 = (int *)(puVar4 + 0x37c);
  if (*piVar7 != 2) {
    return -0x78;
  }
  *piVar7 = 1;
  if ((puVar4[100] != '\0') || (puVar4[0xd4] != '\0')) {
    return -0x10;
  }
  iVar1 = FUN_0103a952((int)puVar4,*(int *)(puVar4 + 0x378));
  if (iVar1 == 0) {
    iVar5 = *(int *)(param_1 + 0x10);
    iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x14);
    pcVar3 = *(code **)(*(int *)(iVar1 + 8) + 0x10);
    if (pcVar3 == (code *)0x0) {
      iVar1 = -0x58;
    }
    else {
      iVar1 = (*pcVar3)(iVar1,*(undefined4 *)(*(int *)(param_1 + 4) + 0x18),0,pcVar3,param_4);
      if (iVar1 == 0) {
        piVar6 = (int *)(iVar5 + 0x2c0);
        FUN_01037564((int)piVar6,1,extraout_r2,extraout_r3);
        FUN_0102fd40(piVar6);
        iVar1 = FUN_0103a9cc(puVar4 + 0x1c8);
        if (iVar1 == 0) {
          FUN_0103bdee(puVar4 + 0x1c8,0,0xe8);
          FUN_0103bdee(puVar4,0,0x1c4);
          uVar2 = 0;
          goto LAB_0103a8cc;
        }
      }
    }
  }
  uVar2 = 2;
LAB_0103a8cc:
  FUN_0103a776(piVar7,uVar2);
  return iVar1;
}


