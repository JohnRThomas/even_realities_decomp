/*
 * Function: FUN_0008a8de
 * Entry:    0008a8de
 * Prototype: int __stdcall FUN_0008a8de(undefined4 * param_1, undefined1 * param_2, int param_3, byte * param_4, uint * param_5)
 */


int FUN_0008a8de(undefined4 *param_1,undefined1 *param_2,int param_3,byte *param_4,uint *param_5)

{
  int iVar1;
  undefined1 *local_78 [2];
  int local_70;
  undefined2 local_6c;
  undefined2 local_6a;
  undefined1 *local_68;
  int local_64;
  
  if (param_3 < 0) {
    *param_1 = 0x8b;
    iVar1 = -1;
  }
  else {
    local_6c = 0x208;
    if (param_3 == 0) {
      local_70 = 0;
    }
    else {
      local_70 = param_3 + -1;
    }
    local_6a = 0xffff;
    local_78[0] = param_2;
    local_68 = param_2;
    local_64 = local_70;
    iVar1 = ____VFPRINTF(param_1,(int *)local_78,param_4,param_5);
    if (iVar1 < -1) {
      *param_1 = 0x8b;
    }
    if (param_3 != 0) {
      *local_78[0] = 0;
    }
  }
  return iVar1;
}


