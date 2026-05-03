/*
 * Function: FUN_0103b6d4
 * Entry:    0103b6d4
 * Prototype: undefined4 __stdcall FUN_0103b6d4(int param_1, int param_2, int param_3)
 */


undefined4 FUN_0103b6d4(int param_1,int param_2,int param_3)

{
  int *piVar1;
  byte *pbVar2;
  uint uVar3;
  undefined4 extraout_r1;
  code *pcVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 auStack_38 [8];
  
  puVar5 = *(undefined4 **)(param_1 + 0x20);
  piVar1 = (int *)puVar5[0x2b];
  if (param_3 == 0x28) {
    uVar3 = param_2 - *piVar1;
    if ((uint)piVar1[2] <= uVar3) {
      uVar3 = 0xffffffff;
    }
    FUN_0103b25c(piVar1,uVar3,auStack_38,0x20);
    piVar1 = puVar5 + 0x16;
    iVar6 = *(int *)(param_2 + 0x20);
    FUN_0103b686(piVar1,extraout_r1);
    pbVar2 = FUN_0103b5d0(puVar5,(int)auStack_38,-1,iVar6);
    if (*(int *)(param_2 + 0x24) << 0x1f < 0) {
      if (pbVar2 == (byte *)0x0) {
        src/*FUN_01036fe4(piVar1);
      }
      else {
        pbVar2[0x28] = 0xff;
        pbVar2[0x29] = 0xff;
        pbVar2[0x2a] = 0xff;
        pbVar2[0x2b] = 0xff;
        src/*FUN_01036fe4(piVar1);
        if (*(code **)(pbVar2 + 0x30) != (code *)0x0) {
          (**(code **)(pbVar2 + 0x30))(pbVar2);
        }
      }
      pcVar4 = (code *)puVar5[0x1d];
    }
    else {
      if (pbVar2 != (byte *)0x0) {
        *(int *)(pbVar2 + 0x28) = iVar6;
        src/*FUN_01036fe4(piVar1);
        return 0;
      }
      src/*FUN_01036fe4(piVar1);
      pcVar4 = (code *)puVar5[0x1c];
    }
    if (pcVar4 != (code *)0x0) {
      (*pcVar4)(puVar5,auStack_38,iVar6);
    }
  }
  return 0;
}


