/*
 * Function: FUN_0008af9c
 * Entry:    0008af9c
 * Prototype: uint __stdcall FUN_0008af9c(undefined4 * param_1, uint param_2, uint * param_3)
 */


uint FUN_0008af9c(undefined4 *param_1,uint param_2,uint *param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  if (param_2 == 0xffffffff) {
LAB_0008afa4:
    uVar4 = 0xffffffff;
  }
  else {
    uVar4 = param_2 & 0xff;
    *(ushort *)(param_3 + 3) = (ushort)param_3[3] & 0xffdf;
    uVar3 = param_3[1];
    if (param_3[0xd] == 0) {
      uVar2 = *param_3;
      if (((param_3[4] != 0) && (param_3[4] < uVar2)) && (*(byte *)(uVar2 - 1) == uVar4)) {
        *param_3 = uVar2 - 1;
        goto LAB_0008afce;
      }
      param_3[0xf] = uVar2;
      param_3[0x10] = uVar3;
      param_3[0xd] = (uint)(param_3 + 0x11);
      param_3[0xe] = 3;
      *(undefined1 *)((int)param_3 + 0x46) = (char)param_2;
      *param_3 = (uint)((int)param_3 + 0x46);
      uVar3 = 1;
    }
    else {
      if (((int)param_3[0xe] <= (int)uVar3) && (iVar1 = FUN_0008b0be(param_1,param_3), iVar1 != 0))
      goto LAB_0008afa4;
      uVar3 = *param_3;
      *param_3 = uVar3 - 1;
      *(char *)(uVar3 - 1) = (char)param_2;
      uVar3 = param_3[1];
LAB_0008afce:
      uVar3 = uVar3 + 1;
    }
    param_3[1] = uVar3;
  }
  return uVar4;
}


