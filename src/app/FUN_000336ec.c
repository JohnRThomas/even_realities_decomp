/*
 * Function: FUN_000336ec
 * Entry:    000336ec
 * Prototype: undefined __stdcall FUN_000336ec(size_t param_1, undefined4 param_2)
 */


void FUN_000336ec(size_t param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 extraout_r1;
  uint uVar3;
  undefined8 uVar4;
  
  uVar3 = 0;
  do {
    uVar1 = __set_charger_status(param_1,(uint3)param_2);
    if (uVar1 == 0) {
      uVar3 = uVar3 & 0xff;
      break;
    }
    __enable_charger();
    uVar3 = uVar3 + 1;
    param_1 = z_impl_k_sleep((k_timeout_t)0x290);
    param_2 = extraout_r1;
  } while (uVar3 != 10);
  uVar4 = FUN_00080638();
  iVar2 = (int)uVar4;
  if (999 < (uint)(iVar2 - DAT_200085d0)) {
    if (uVar3 == 10) {
      DAT_2001abbe = DAT_2001abbe + 1;
      if (3 < DAT_2001abbe) {
        DAT_20003054 = 0;
        DAT_200085d0 = iVar2;
        DAT_2001abbe = 3;
        return;
      }
    }
    else {
      DAT_2001abbe = 0;
    }
    DAT_20003054 = 1;
    DAT_200085d0 = iVar2;
  }
  return;
}


