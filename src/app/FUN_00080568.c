/*
 * Function: FUN_00080568
 * Entry:    00080568
 * Prototype: int __stdcall FUN_00080568(uint * param_1)
 */


int FUN_00080568(uint *param_1)

{
  void *pvVar1;
  int iVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  
  pvVar1 = cJSON_malloc(0x4704);
  if ((((pvVar1 == (void *)0x0) && (pvVar1 = cJSON_malloc(0x4710), pvVar1 == (void *)0x0)) &&
      (pvVar1 = cJSON_malloc(0x4714), pvVar1 == (void *)0x0)) &&
     (iVar2 = FUN_000804b6(0,extraout_r1,extraout_r2), iVar2 == 0)) {
    iVar2 = cJSON_SetValuestring(0x470c,param_1,extraout_r2_00);
    iVar2 = -(uint)(iVar2 != 0);
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}


