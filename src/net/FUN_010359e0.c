/*
 * Function: FUN_010359e0
 * Entry:    010359e0
 * Prototype: undefined __stdcall FUN_010359e0(int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_010359e0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if ((param_1 == 0) || (iVar1 = *(int *)(param_1 + 4), iVar1 == 0)) {
    FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                 "WEST_TOPDIR/modules/hal/libmetal/libmetal/lib/device.c",0x51,param_4);
    iVar1 = FUN_0103a370();
  }
  if (*(code **)(iVar1 + 0xc) != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x01035a04. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(iVar1 + 0xc))();
    return;
  }
  return;
}


