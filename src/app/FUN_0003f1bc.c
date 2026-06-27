/*
 * Function: FUN_0003f1bc
 * Entry:    0003f1bc
 * Prototype: undefined __stdcall FUN_0003f1bc(void)
 */


void FUN_0003f1bc(void)

{
  longlong lVar1;
  undefined1 uVar2;
  GlassesState *pGVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ulonglong uVar7;
  
  uVar2 = FUN_0003eee0();
  DAT_2001c6cc = uVar2;
  pGVar3 = __get_dashboard_state();
  *(undefined1 *)(*(int *)&pGVar3->field_0x1018 + 2) = uVar2;
  pGVar3 = __get_dashboard_state();
  pGVar3->field_0xcd = DAT_2001c6cc;
  pGVar3 = __get_dashboard_state();
  **(undefined1 **)&pGVar3->field_0x1018 = 1;
  uVar7 = sys_clock_tick_get();
  pGVar3 = __get_dashboard_state();
  lVar1 = (uVar7 & 0xffffffff) * 1000;
  uVar5 = (int)(uVar7 >> 0x20) * 1000 + (int)((ulonglong)lVar1 >> 0x20);
  uVar6 = (uint)lVar1 >> 0xf | uVar5 * 0x20000;
  iVar4 = *(int *)&pGVar3->field_0x1018;
  *(uint *)(iVar4 + 3) = uVar6 + 10000;
  *(uint *)(iVar4 + 7) = (uVar5 >> 0xf) + (uint)(0xffffd8ef < uVar6);
  pGVar3 = __get_dashboard_state();
  update_persist_task_status((int)pGVar3,7,2);
  return;
}


