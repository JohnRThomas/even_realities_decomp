/*
 * Function: FUN_0103a91a
 * Entry:    0103a91a
 * Prototype: undefined4 __stdcall FUN_0103a91a(int param_1, char * param_2)
 */


undefined4 FUN_0103a91a(int param_1,char *param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x10) + 0x37c) == 2) {
    if (param_2 == (char *)0x0) {
      uVar1 = 0xfffffffe;
    }
    else {
      FUN_0103b644(param_2,param_2);
      FUN_0103bdee(param_2,0,0x70);
      uVar1 = 0;
    }
  }
  else {
    uVar1 = 0xfffffff0;
  }
  return uVar1;
}


