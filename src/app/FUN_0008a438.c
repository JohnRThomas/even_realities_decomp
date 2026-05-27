/*
 * Function: $_?_FUN_0008a438
 * Entry:    0008a438
 * Prototype: uint __stdcall $_?_FUN_0008a438(int * param_1, uint param_2, int * param_3)
 */


uint ____FUN_0008a438(int *param_1,uint param_2,int *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  uint uVar4;
  
  iVar3 = param_3[2] + -1;
  param_3[2] = iVar3;
  if ((-1 < iVar3) || ((param_3[6] <= iVar3 && (param_2 != 10)))) {
    puVar2 = (undefined1 *)*param_3;
    *param_3 = (int)(puVar2 + 1);
    *puVar2 = (char)param_2;
    return param_2;
  }
  if ((param_1 != (int *)0x0) && (param_1[6] == 0)) {
    __sfp(param_1);
  }
  if (param_3 == (int *)&DAT_0009c2ac) {
    param_3 = (int *)param_1[1];
  }
  else if (param_3 == (int *)&DAT_0009c28c) {
    param_3 = (int *)param_1[2];
  }
  else if (param_3 == (int *)&DAT_0009c26c) {
    param_3 = (int *)param_1[3];
  }
  param_3[2] = param_3[6];
  if ((((int)((uint)*(ushort *)(param_3 + 3) << 0x1c) < 0) && (param_3[4] != 0)) ||
     (iVar3 = _fclose_r(param_1,param_3), iVar3 == 0)) {
    uVar4 = param_2 & 0xff;
    iVar3 = *param_3 - param_3[4];
    if (param_3[5] <= iVar3) {
      iVar1 = _fflush_r(param_1,param_3);
      iVar3 = 0;
      if (iVar1 != 0) {
        return 0xffffffff;
      }
    }
    param_3[2] = param_3[2] + -1;
    puVar2 = (undefined1 *)*param_3;
    *param_3 = (int)(puVar2 + 1);
    *puVar2 = (char)param_2;
    if (param_3[5] != iVar3 + 1) {
      if (-1 < (int)((uint)*(ushort *)(param_3 + 3) << 0x1f)) {
        return uVar4;
      }
      if (uVar4 != 10) {
        return uVar4;
      }
    }
    iVar3 = _fflush_r(param_1,param_3);
    if (iVar3 == 0) {
      return uVar4;
    }
  }
  return 0xffffffff;
}


