/*
 * Function: FUN_0100a6a4
 * Entry:    0100a6a4
 * Prototype: int __stdcall FUN_0100a6a4(int * param_1, byte param_2, uint param_3)
 */


int FUN_0100a6a4(int *param_1,byte param_2,uint param_3)

{
  int iVar1;
  uint extraout_r2;
  uint uVar2;
  undefined4 extraout_r2_00;
  int local_c;
  
  local_c = 0;
  uVar2 = param_3;
  if (((uint)param_1 & 3) != 0) {
    FUN_01009500(0x18,0x86,param_3,(uint)param_1 & 3);
    uVar2 = extraout_r2;
  }
  if (param_2 != 0) {
    iVar1 = FUN_01027a58((undefined4 *)0x0,param_3,uVar2);
    local_c = (uint)param_2 * 4 + iVar1 + 0xc;
    if (param_1 != (int *)0x0) {
      DAT_21000bb4 = param_1;
      *(byte *)(param_1 + 2) = param_2;
      DAT_21000bb4[1] = (int)(param_1 + 3);
      *DAT_21000bb4 = (uint)param_2 * 4 + DAT_21000bb4[1];
      FUN_01026284((undefined4 *)DAT_21000bb4[1],0,(uint)param_2 << 2);
      FUN_01027a58(DAT_21000bb4,param_3,extraout_r2_00);
    }
  }
  return local_c;
}


