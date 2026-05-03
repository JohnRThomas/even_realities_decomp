/*
 * Function: FUN_0007f704
 * Entry:    0007f704
 * Prototype: int __stdcall FUN_0007f704(char * param_1)
 */


int FUN_0007f704(char *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if ((param_1 != (char *)0x0) && (*param_1 == '\b')) {
    uVar3 = 0;
    iVar2 = 1;
    do {
      uVar1 = uVar3 & 0xff;
      uVar3 = uVar3 + 1;
      if ((int)((uint)((byte)param_1[0x10] >> uVar1) << 0x1f) < 0) {
        iVar2 = iVar2 + 1;
      }
    } while (uVar3 != 8);
    return iVar2;
  }
  return 0;
}


