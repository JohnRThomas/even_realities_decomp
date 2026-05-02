/*
 * Function: FUN_00087af8
 * Entry:    00087af8
 * Prototype: undefined4 __stdcall FUN_00087af8(int param_1, int param_2, char * param_3)
 */


undefined4 FUN_00087af8(int param_1,int param_2,char *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  switch(*(undefined1 *)(iVar1 + 0x20)) {
  case 0:
    uVar2 = 0;
    break;
  case 1:
    uVar2 = 1;
    break;
  case 2:
    uVar2 = 0;
    goto LAB_00087b24;
  case 3:
    uVar2 = 1;
LAB_00087b24:
    uVar2 = FUN_00087a7c(iVar1,uVar2,param_2,param_3);
    return uVar2;
  default:
    return 0xffffffed;
  }
  uVar2 = FUN_00087ab0(iVar1,uVar2,param_2,param_3);
  return uVar2;
}


