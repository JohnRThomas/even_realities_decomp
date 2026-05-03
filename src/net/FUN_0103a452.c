/*
 * Function: FUN_0103a452
 * Entry:    0103a452
 * Prototype: undefined4 __stdcall FUN_0103a452(uint * param_1, int param_2, int * param_3, int * param_4)
 */


undefined4 FUN_0103a452(uint *param_1,int param_2,int *param_3,int *param_4)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar6 = param_1[3];
  uVar5 = param_1[8];
  iVar7 = uVar5 + uVar6 * 4;
  if ((*(byte *)(uVar5 + uVar6 * 4) & 3) == 2) {
    uVar4 = *(uint *)(uVar5 + uVar6 * 4);
    *param_3 = 0;
    uVar4 = uVar4 >> 2;
    *param_4 = 0;
    if (uVar4 == 0) goto LAB_0103a47c;
    FUN_0103a3fc((int)param_1,uVar4);
    param_1[2] = param_1[3];
LAB_0103a4a0:
    uVar2 = 1;
  }
  else {
    *param_3 = 0;
    *param_4 = 0;
LAB_0103a47c:
    if ((int)(param_1[4] << 0x1e) < 0) {
      iVar3 = (*(code *)param_1[7])(iVar7);
      bVar1 = *(byte *)(uVar5 + uVar6 * 4);
      if ((int)((uint)bVar1 << 0x1f) < 0) {
        if ((bVar1 & 2) == 0) {
          FUN_0103a3fc((int)param_1,iVar3);
          param_1[2] = param_1[3];
          if (param_2 != 0) {
            *(uint *)(param_1[8] + *param_1 * 4) = bVar1 & 2;
          }
          *param_4 = iVar3 + param_2;
          uVar4 = FUN_0103a3e0((int)param_1,*param_1,iVar3 + param_2);
          *param_1 = uVar4;
          param_1[4] = param_1[4] | 8;
          *(byte *)(uVar5 + uVar6 * 4) = *(byte *)(uVar5 + uVar6 * 4) & 0xfe;
          *param_3 = iVar7;
        }
        else {
          if (param_2 != 0) {
            FUN_0103a414(param_1,param_2);
          }
          uVar5 = FUN_0103a3e0((int)param_1,param_1[1],iVar3);
          param_1[1] = uVar5;
          if (param_1[3] == param_1[2]) {
            uVar5 = FUN_0103a3e0((int)param_1,param_1[3],iVar3);
            param_1[2] = uVar5;
          }
          *param_1 = param_1[2];
          param_1[3] = param_1[2];
          param_1[4] = param_1[4] | 8;
        }
        goto LAB_0103a4a0;
      }
    }
    uVar2 = 0;
  }
  return uVar2;
}


