/*
 * Function: FUN_01035324
 * Entry:    01035324
 * Prototype: undefined1 * __stdcall FUN_01035324(uint param_1, uint param_2)
 */


undefined1 * FUN_01035324(uint param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  P1_NS *pPVar3;
  undefined1 *puVar4;
  uint local_c;
  
  local_c = param_2;
  uVar1 = FUN_01034c7c(param_1);
  if (uVar1 == 0) {
    puVar4 = &DAT_0bad0004;
  }
  else {
    FUN_010352d8(param_1);
    uVar2 = FUN_01034c94(param_1);
    if (uVar2 != 0) {
      uVar1 = FUN_01034ce0(param_1);
      (&Peripherals::GPIOTE_NS.CONFIG_0_)[uVar1] = 0;
      (&Peripherals::GPIOTE_NS.CONFIG_0_)[uVar1] = 0;
    }
    FUN_01034d38(param_1);
    uVar2 = FUN_01034c68(param_1);
    *(undefined2 *)((int)&DAT_210006a8 + (uVar2 + 8) * 2) = 0;
    local_c = param_1;
    pPVar3 = FUN_01034db4(&local_c);
    (&pPVar3->PIN_CNF_0_)[local_c] = (&pPVar3->PIN_CNF_0_)[local_c] & 0xfffcf0f0 | 2;
    puVar4 = &DAT_0bad0000;
  }
  return puVar4;
}


