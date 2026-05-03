/*
 * Function: remove_timeout
 * Entry:    00077e64
 * Prototype: undefined __stdcall remove_timeout(int * param_1)
 */


/* Library Function - Single Match
    remove_timeout
   
   Libraries: application fake_app 2.5.1, application mcuboot 2.5.1, network b0n 2.5.1, network
   hci_rpmsg 2.5.1 */

void remove_timeout(int *param_1)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  if (((param_1 != (int *)0x0) && (param_1 != DAT_20002d20)) && (iVar3 = *param_1, iVar3 != 0)) {
    uVar1 = *(uint *)(iVar3 + 0x10);
    uVar4 = param_1[4];
    iVar5 = param_1[5];
    *(uint *)(iVar3 + 0x10) = uVar1 + uVar4;
    *(uint *)(iVar3 + 0x14) = *(int *)(iVar3 + 0x14) + iVar5 + (uint)CARRY4(uVar1,uVar4);
  }
  iVar3 = *param_1;
  piVar2 = (int *)param_1[1];
  *piVar2 = iVar3;
  *(int **)(iVar3 + 4) = piVar2;
  *param_1 = 0;
  param_1[1] = 0;
  return;
}


