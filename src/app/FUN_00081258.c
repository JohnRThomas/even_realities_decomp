/*
 * Function: FUN_00081258
 * Entry:    00081258
 * Prototype: undefined __stdcall FUN_00081258(uint param_1, uint param_2)
 */


void FUN_00081258(uint param_1,uint param_2)

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
    *(int *)(&(pGVar3->__burial_point_ctx).field_0x1c + uVar2 * 0xc) =
         *(int *)(&(pGVar3->__burial_point_ctx).field_0x1c + uVar2 * 0xc) + (int)uVar4;
    pGVar3 = __get_dashboard_state();
    *(int *)&(pGVar3->__burial_point_ctx).field_0x4 =
         *(int *)&(pGVar3->__burial_point_ctx).field_0x4 + (int)uVar4;
  }
  return;
}


