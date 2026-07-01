/*
 * Function: FUN_000166f8
 * Entry:    000166f8
 * Prototype: undefined __stdcall FUN_000166f8(void)
 */


void FUN_000166f8(void)

{
  GlassesState *pGVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined4 uVar5;
  dashboard_ts_context *pdVar6;
  undefined4 uVar7;
  undefined4 *puVar8;
  undefined4 *puVar10;
  undefined4 *puVar11;
  undefined4 *puVar9;
  
  pGVar1 = GLOBAL_STATE;
  *(int *)GLOBAL_STATE->dashboard_ts = DAT_2007fc00 + 1;
  pGVar1->dashboard_ts->field_0x4 = DAT_2007fc04;
  pGVar1->dashboard_ts->field_0x5 = DAT_2007fc05;
  uVar7 = DAT_2007fc0c;
  pdVar6 = pGVar1->dashboard_ts;
  uVar2 = DAT_2007fc08._1_1_;
  uVar3 = DAT_2007fc08._2_1_;
  uVar4 = DAT_2007fc08._3_1_;
  pdVar6->field6_0x6 = (undefined1)DAT_2007fc08;
  uVar5 = DAT_2007fc0c;
  pdVar6->field7_0x7 = uVar2;
  pdVar6->field8_0x8 = uVar3;
  pdVar6->field9_0x9 = uVar4;
  DAT_2007fc0c._0_1_ = (undefined1)uVar7;
  DAT_2007fc0c._1_1_ = SUB41(uVar7,1);
  uVar2 = DAT_2007fc0c._1_1_;
  DAT_2007fc0c._2_1_ = SUB41(uVar7,2);
  uVar3 = DAT_2007fc0c._2_1_;
  DAT_2007fc0c._3_1_ = SUB41(uVar7,3);
  uVar4 = DAT_2007fc0c._3_1_;
  pdVar6->field10_0xa = (undefined1)DAT_2007fc0c;
  DAT_2007fc0c = uVar5;
  pdVar6->field11_0xb = uVar2;
  pdVar6->field12_0xc = uVar3;
  pdVar6->field13_0xd = uVar4;
  pGVar1->dashboard_ts->field_0x5d = DAT_2007fc5f;
  pGVar1->dashboard_ts->field_0x5e = DAT_2007fc60;
  pGVar1->dashboard_ts->field_0x62 = ERASE_DFU_ON_NEXT_PASS;
  pGVar1->dashboard_ts->field_0x61 = DAT_2007fc61;
  pGVar1->dashboard_ts->field_0x64 = DAT_2007fc68;
  if (DAT_2007fc69 < 4) {
    DAT_2001c4e6 = DAT_2007fc69;
  }
  puVar8 = (undefined4 *)&pGVar1->dashboard_ts->field_0xe;
  puVar10 = &DAT_2007fc10;
  do {
    puVar11 = puVar10;
    puVar9 = puVar8;
    uVar7 = puVar11[1];
    *puVar9 = *puVar11;
    puVar9[1] = uVar7;
    puVar8 = puVar9 + 2;
    puVar10 = puVar11 + 2;
  } while (puVar11 + 2 != (undefined4 *)0x2007fc30);
  puVar9[2] = uRam2007fc30;
  *(undefined1 *)(puVar9 + 3) = *(undefined1 *)(puVar11 + 3);
  puVar8 = &DAT_2007fc35;
  puVar10 = (undefined4 *)&pGVar1->dashboard_ts->field_0x33;
  do {
    puVar9 = puVar8 + 1;
    puVar11 = puVar10 + 1;
    *puVar10 = *puVar8;
    puVar8 = puVar9;
    puVar10 = puVar11;
  } while (puVar9 != (undefined4 *)0x2007fc5d);
  *(undefined2 *)puVar11 = uRam2007fc5d;
  return;
}


