/*
 * Function: FUN_000812ec
 * Entry:    000812ec
 * Prototype: undefined __stdcall FUN_000812ec(uint param_1, uint param_2)
 */


void FUN_000812ec(uint param_1,uint param_2)

{
  byte bVar1;
  GlassesState *pGVar3;
  undefined8 uVar4;
  uint uVar2;
  
  bVar1 = FUN_00081216();
  uVar2 = (uint)bVar1;
  if (uVar2 < 7) {
    pGVar3 = __get_dashboard_state();
    uVar4 = __aeabi_ldivmod(param_1,param_2,1000,0);
    *(int *)(&pGVar3->field_0x11f4 + uVar2 * 0xc) =
         *(int *)(&pGVar3->field_0x11f4 + uVar2 * 0xc) + (int)uVar4;
    pGVar3 = __get_dashboard_state();
    *(int *)&pGVar3->field_0x11e8 = *(int *)&pGVar3->field_0x11e8 + (int)uVar4;
  }
  return;
}


