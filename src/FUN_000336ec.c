/*
 * Function: FUN_000336ec
 * Entry:    000336ec
 * Prototype: undefined __stdcall FUN_000336ec(void)
 */


void FUN_000336ec(void)

{
  int iVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar2 = 0;
  do {
    iVar1 = __set_charger_status();
    if (iVar1 == 0) {
      uVar2 = uVar2 & 0xff;
      break;
    }
    __enable_charger();
    uVar2 = uVar2 + 1;
    z_impl_k_sleep((k_timeout_t)0x290);
  } while (uVar2 != 10);
  uVar3 = FUN_00080638();
  iVar1 = (int)uVar3;
  if (999 < (uint)(iVar1 - DAT_200085d0)) {
    if (uVar2 == 10) {
      DAT_2001abbe = DAT_2001abbe + 1;
      if (3 < DAT_2001abbe) {
        DAT_20003054 = 0;
        DAT_200085d0 = iVar1;
        DAT_2001abbe = 3;
        return;
      }
    }
    else {
      DAT_2001abbe = 0;
    }
    DAT_20003054 = 1;
    DAT_200085d0 = iVar1;
  }
  return;
}


