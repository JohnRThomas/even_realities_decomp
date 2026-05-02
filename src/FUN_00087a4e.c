/*
 * Function: FUN_00087a4e
 * Entry:    00087a4e
 * Prototype: nrfx_err_t __stdcall FUN_00087a4e(int param_1, int param_2)
 */


nrfx_err_t FUN_00087a4e(int param_1,int param_2)

{
  int iVar1;
  nrfx_err_t nVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  switch(*(undefined1 *)(iVar1 + 0x20)) {
  case 0:
    uVar3 = 0;
    break;
  case 1:
    uVar3 = 1;
    break;
  case 2:
    uVar3 = 0;
    goto LAB_00087a6e;
  case 3:
    uVar3 = 1;
LAB_00087a6e:
    nVar2 = FUN_00087a00(iVar1,uVar3,param_2);
    return nVar2;
  default:
    return 0xffffff7a;
  }
  nVar2 = FUN_00087a26(iVar1,uVar3,param_2);
  return nVar2;
}


