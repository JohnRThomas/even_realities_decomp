/*
 * Function: FUN_0008a6e4
 * Entry:    0008a6e4
 * Prototype: undefined __stdcall FUN_0008a6e4(int param_1, int param_2, size_t param_3)
 */


void FUN_0008a6e4(int param_1,int param_2,size_t param_3)

{
  ssize_t sVar1;
  
  sVar1 = _write(param_1,(void *)(int)*(short *)(param_2 + 0xe),param_3);
  if (sVar1 < 0) {
    *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) & 0xefff;
  }
  else {
    *(int *)(param_2 + 0x54) = *(int *)(param_2 + 0x54) + sVar1;
  }
  return;
}


