/*
 * Function: FUN_000804e6
 * Entry:    000804e6
 * Prototype: int __stdcall FUN_000804e6(void)
 */


int FUN_000804e6(void)

{
  void *pvVar1;
  int iVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  
  pvVar1 = cJSON_malloc(0x4704);
  if ((((pvVar1 == (void *)0x0) && (pvVar1 = cJSON_malloc(0x4708), pvVar1 == (void *)0x0)) &&
      (pvVar1 = cJSON_malloc(0x4710), pvVar1 == (void *)0x0)) &&
     (pvVar1 = cJSON_malloc(0x4714), pvVar1 == (void *)0x0)) {
    iVar2 = FUN_000804b6(0,extraout_r1,extraout_r2);
    iVar2 = -(uint)(iVar2 != 0);
  }
  else {
    iVar2 = -1;
  }
  return iVar2;
}


