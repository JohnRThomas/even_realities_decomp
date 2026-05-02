/*
 * Function: FUN_00080568
 * Entry:    00080568
 * Prototype: int __stdcall FUN_00080568(uint * param_1, uint param_2, undefined4 param_3)
 */


int FUN_00080568(uint *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 extraout_r2_02;
  
  iVar1 = cJSON_malloc(0x4704,param_2,param_3);
  if ((((iVar1 == 0) && (iVar1 = cJSON_malloc(0x4710,3,extraout_r2), iVar1 == 0)) &&
      (iVar1 = cJSON_malloc(0x4714,1,extraout_r2_00), iVar1 == 0)) &&
     (iVar1 = FUN_000804b6(0,extraout_r1,extraout_r2_01), iVar1 == 0)) {
    iVar1 = cJSON_SetValuestring(0x470c,param_1,extraout_r2_02);
    iVar1 = -(uint)(iVar1 != 0);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


