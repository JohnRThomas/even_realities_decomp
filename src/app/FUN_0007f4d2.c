/*
 * Function: FUN_0007f4d2
 * Entry:    0007f4d2
 * Prototype: undefined4 __stdcall FUN_0007f4d2(int param_1)
 */


undefined4 FUN_0007f4d2(int param_1)

{
  int iVar1;
  size_t sVar2;
  char local_d4;
  undefined1 auStack_d3 [203];
  
  while( true ) {
    memset(auStack_d3,0,0xca);
    local_d4 = -0xc;
    iVar1 = FUN_00019e04(auStack_d3);
    if (iVar1 != 0) break;
    sVar2 = strlen(&local_d4);
    (**(code **)(param_1 + 0xc))(&local_d4,sVar2 + 1 & 0xffff);
  }
  return 0;
}


