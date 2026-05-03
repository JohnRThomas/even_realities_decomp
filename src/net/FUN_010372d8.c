/*
 * Function: FUN_010372d8
 * Entry:    010372d8
 * Prototype: uint __stdcall FUN_010372d8(undefined4 * param_1, int * param_2, undefined4 param_3, undefined4 param_4)
 */


uint FUN_010372d8(undefined4 *param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  int extraout_r3;
  int iVar3;
  uint uVar4;
  
  iVar2 = param_1[3];
  uVar4 = (uint)(iVar2 << 0x1e) >> 0x1f;
  if (iVar2 << 0x1e < 0) {
LAB_0103735a:
    uVar4 = 0xfffffff0;
  }
  else {
    if (iVar2 << 0x1d < 0) goto LAB_01037336;
    if (*param_2 == 0) {
      *param_2 = param_1[2];
    }
    if ((int)(param_1[3] << 0x1f) < 0) {
      iVar2 = param_1[2];
      if (iVar2 == 0) {
        FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n","WEST_TOPDIR/zephyr/kernel/work.c",0x14e,0);
        FUN_0103a370();
        iVar2 = extraout_r3;
      }
      uVar4 = 2;
      *param_2 = iVar2;
    }
    else {
      uVar4 = 1;
    }
    iVar2 = *param_2;
    if (iVar2 == 0) {
      uVar4 = 0xffffffea;
      goto LAB_01037336;
    }
    if (DAT_21004b30 == iVar2) {
      bVar1 = FUN_0103b90a();
      iVar3 = *(int *)(iVar2 + 0xb0);
      if (bVar1) goto LAB_0103732a;
      if (iVar3 << 0x1f < 0) {
        if ((-1 < iVar3 << 0x1c) || (iVar3 << 0x1d < 0)) goto LAB_0103736c;
        goto LAB_0103735a;
      }
    }
    else {
      iVar3 = *(int *)(iVar2 + 0xb0);
LAB_0103732a:
      if (iVar3 << 0x1f < 0) {
        if ((-1 < iVar3 << 0x1d) && (-1 < iVar3 << 0x1c)) {
LAB_0103736c:
          *param_1 = 0;
          if (*(undefined4 **)(iVar2 + 0x9c) == (undefined4 *)0x0) {
            *(undefined4 **)(iVar2 + 0x98) = param_1;
            *(undefined4 **)(iVar2 + 0x9c) = param_1;
          }
          else {
            **(undefined4 **)(iVar2 + 0x9c) = param_1;
            *(undefined4 **)(iVar2 + 0x9c) = param_1;
          }
          FUN_0103ba1a(iVar2);
          param_1[3] = param_1[3] | 4;
          param_1[2] = *param_2;
          return uVar4;
        }
        goto LAB_0103735a;
      }
    }
    uVar4 = 0xffffffed;
  }
LAB_01037336:
  *param_2 = 0;
  return uVar4;
}


