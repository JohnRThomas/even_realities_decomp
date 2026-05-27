/*
 * Function: $_?_cJSON_FUN_0008a32e
 * Entry:    0008a32e
 * Prototype: undefined4 __stdcall $_?_cJSON_FUN_0008a32e(int * param_1, int param_2, undefined4 * param_3, uint * param_4)
 */


undefined4 ____cJSON_FUN_0008a32e(int *param_1,int param_2,undefined4 *param_3,uint *param_4)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 auStack_68 [4];
  uint local_64;
  
  if ((*(short *)(param_2 + 0xe) < 0) ||
     (iVar1 = ____cJSON_FUN_0007b0f4(param_1,(int)*(short *)(param_2 + 0xe),(int)auStack_68),
     iVar1 < 0)) {
    uVar2 = 0;
    if ((*(ushort *)(param_2 + 0xc) & 0x80) == 0) {
      uVar3 = 0x400;
    }
    else {
      uVar3 = 0x40;
    }
  }
  else {
    uVar2 = (uint)((local_64 & 0xf000) == 0x2000);
    uVar3 = 0x400;
  }
  *param_4 = uVar2;
  *param_3 = uVar3;
  return 0;
}


