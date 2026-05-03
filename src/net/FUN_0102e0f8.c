/*
 * Function: FUN_0102e0f8
 * Entry:    0102e0f8
 * Prototype: undefined4 __stdcall FUN_0102e0f8(int param_1, char * param_2, int * param_3)
 */


undefined4 FUN_0102e0f8(int param_1,char *param_2,int *param_3)

{
  bool bVar1;
  char *pcVar2;
  uint uVar3;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r3;
  int iVar4;
  undefined4 extraout_r3_00;
  int iVar5;
  int *piVar6;
  char *local_24;
  int *piStack_20;
  
  iVar5 = *(int *)(param_1 + 0x10);
  if (*(int *)(iVar5 + 0x37c) != 2) {
    return 0xfffffff0;
  }
  if (((char *)*param_3 != (char *)0x0) && (*(char *)*param_3 != '\0')) {
    local_24 = param_2;
    piStack_20 = param_3;
    if (*(int *)(iVar5 + 0x378) == 0) {
      piVar6 = (int *)(iVar5 + 0x1b0);
      FUN_01036bd0(piVar6,param_2,0xffffffff,-1);
      bVar1 = FUN_0102dea0(iVar5,(int *)&local_24,(byte *)*param_3);
      pcVar2 = local_24;
      if (local_24 != (char *)0x0) {
        *(int **)(local_24 + 0x68) = param_3 + 2;
        iVar4 = param_3[5];
        local_24[100] = '\0';
        *(int *)(local_24 + 0x6c) = iVar4;
        *(char **)(local_24 + 0x3c) = local_24;
        if (bVar1) {
          src/*FUN_01036d3c(piVar6,extraout_r1,extraout_r2,iVar4);
          FUN_0102de5c(iVar5,pcVar2,(char *)*param_3,*(undefined4 *)(pcVar2 + 0x60));
        }
        else {
          FUN_0103bd64(local_24 + 0x40,*param_3,0x20);
          src/*FUN_01036d3c(piVar6,extraout_r1_00,extraout_r2_00,extraout_r3_00);
        }
LAB_0102e178:
        *(char **)param_2 = pcVar2;
        return 0;
      }
      src/*FUN_01036d3c(piVar6,extraout_r1,extraout_r2,extraout_r3);
    }
    else {
      pcVar2 = (char *)FUN_0103a70c(iVar5,(byte *)0x103ce8c);
      if (pcVar2 != (char *)0x0) {
        *(int **)(pcVar2 + 0x68) = param_3 + 2;
        iVar4 = param_3[5];
        *(char **)(pcVar2 + 0x3c) = pcVar2;
        *(int *)(pcVar2 + 0x6c) = iVar4;
        pcVar2[100] = '\0';
        FUN_0103bd64(pcVar2 + 0x40,*param_3,0x20);
        uVar3 = FUN_0102e244(iVar5,1,pcVar2);
        if (uVar3 == 0) goto LAB_0102e178;
      }
    }
  }
  return 0xffffffea;
}


