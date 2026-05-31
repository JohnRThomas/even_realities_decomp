/*
 * Function: FUN_0004b0cc
 * Entry:    0004b0cc
 * Prototype: int __stdcall FUN_0004b0cc(int param_1, int param_2, int param_3, int param_4)
 */


int FUN_0004b0cc(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int param1;
  
  iVar2 = 0;
  param1 = 0;
LAB_0004b0e0:
  do {
    if (param_2 <= iVar2) {
LAB_0004b10e:
      *(undefined2 *)(param_3 + param1 * 2) = 0;
      return param1;
    }
    uVar1 = (uint)*(byte *)(param_1 + iVar2);
    if (uVar1 == 0) goto LAB_0004b10e;
    if (((uVar1 == 0xd) || (uVar1 == 10)) || (uVar1 - 0x20 < 0x60)) {
      iVar2 = iVar2 + 1;
LAB_0004b0fe:
      *(short *)(param_3 + param1 * 2) = (short)uVar1;
      if (param_4 + -1 == param1) {
        printf("maybe array overflow!(k=%d)\n",param1);
        goto LAB_0004b10e;
      }
      param1 = param1 + 1;
      goto LAB_0004b0e0;
    }
    if ((uVar1 & 0xf0) == 0xe0) {
      uVar1 = FUN_0004b058((byte *)(param_1 + iVar2),3);
      iVar2 = iVar2 + 3;
      goto LAB_0004b0fe;
    }
    if ((uVar1 & 0xe0) == 0xc0) {
      uVar1 = FUN_0004b058((byte *)(param_1 + iVar2),2);
      iVar2 = iVar2 + 2;
      goto LAB_0004b0fe;
    }
    iVar2 = iVar2 + 1;
  } while( true );
}


