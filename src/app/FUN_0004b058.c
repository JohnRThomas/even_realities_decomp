/*
 * Function: FUN_0004b058
 * Entry:    0004b058
 * Prototype: uint __stdcall FUN_0004b058(byte * param_1, int param_2)
 */


uint FUN_0004b058(byte *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (uint)*param_1;
  if ((uVar2 & 0xf0) == 0xe0) {
    if (2 < param_2) {
      uVar1 = param_1[2] & 0x30 | (param_1[1] & 3) << 6 | param_1[2] & 0xf;
      uVar2 = (param_1[1] & 0x3f) >> 2 | (uVar2 & 0xf) << 4;
LAB_0004b08c:
      return uVar1 | uVar2 << 8;
    }
  }
  else if ((uVar2 & 0xe0) == 0xc0) {
    if (1 < param_2) {
      uVar1 = param_1[1] & 0x3f | (uVar2 & 3) << 6;
      uVar2 = (uVar2 & 0x1f) >> 2;
      goto LAB_0004b08c;
    }
    print("length error!");
  }
  else {
    printf("maybe [%x] not unicode ?\n",uVar2);
  }
  return 0;
}


