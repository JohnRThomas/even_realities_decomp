/*
 * Function: FUN_0102e244
 * Entry:    0102e244
 * Prototype: uint __stdcall FUN_0102e244(int param_1, int param_2, char * param_3)
 */


uint FUN_0102e244(int param_1,int param_2,char *param_3)

{
  uint uVar1;
  
  if ((param_1 == 0) || (param_3 == (char *)0x0)) {
    uVar1 = 0xffffffea;
  }
  else if (param_2 == 1) {
    uVar1 = FUN_01035c7c(param_3,param_1 + 0xe0,param_3 + 0x40,0xffffffff,0xffffffff,
                         *(int *)(param_1 + 0x1ac),&LAB_0103a94e_1);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


