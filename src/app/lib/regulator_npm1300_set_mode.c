/*
 * Function: regulator_npm1300_set_mode
 * Entry:    00087a4e
 * Prototype: int __stdcall regulator_npm1300_set_mode(int param_1, int param_2)
 */


/* exclude_from_export */

int regulator_npm1300_set_mode(int param_1,int param_2)

{
  int iVar1;
  char cVar2;
  int iVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  switch(*(undefined1 *)(iVar1 + 0x20)) {
  case 0:
    iVar3 = 0;
    break;
  case 1:
    iVar3 = 1;
    break;
  case 2:
    cVar2 = '\0';
    goto LAB_00087a6e;
  case 3:
    cVar2 = '\x01';
LAB_00087a6e:
    iVar1 = set_ldsw_mode(iVar1,cVar2,param_2);
    return iVar1;
  default:
    return -0x86;
  }
  iVar1 = set_buck_mode(iVar1,iVar3,param_2);
  return iVar1;
}


