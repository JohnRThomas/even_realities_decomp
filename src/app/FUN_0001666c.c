/*
 * Function: FUN_0001666c
 * Entry:    0001666c
 * Prototype: undefined __stdcall FUN_0001666c(void)
 */


void FUN_0001666c(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  dashboard_ts_context *pdVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  pdVar4 = GLOBAL_STATE->dashboard_ts;
  DAT_2007fc00 = *(undefined4 *)pdVar4;
  DAT_2007fc08._0_1_ = pdVar4->field6_0x6;
  DAT_2007fc08._1_1_ = pdVar4->field7_0x7;
  DAT_2007fc08._2_1_ = pdVar4->field8_0x8;
  DAT_2007fc08._3_1_ = pdVar4->field9_0x9;
  DAT_2007fc04 = pdVar4->field_0x4;
  DAT_2007fc05 = pdVar4->field_0x5;
  DAT_2007fc0c._0_1_ = pdVar4->field10_0xa;
  DAT_2007fc0c._1_1_ = pdVar4->field11_0xb;
  DAT_2007fc0c._2_1_ = pdVar4->field12_0xc;
  DAT_2007fc0c._3_1_ = pdVar4->field13_0xd;
  DAT_2007fc5f = pdVar4->field_0x5d;
  DAT_2007fc60 = pdVar4->field_0x5e;
  ERASE_DFU_ON_NEXT_PASS = pdVar4->field_0x62;
  DAT_2007fc61 = pdVar4->field_0x61;
  puVar2 = &DAT_2007fc10;
  puVar5 = (undefined4 *)&pdVar4->field_0xe;
  do {
    puVar6 = puVar5;
    puVar3 = puVar2;
    uVar1 = puVar6[1];
    puVar5 = puVar6 + 2;
    *puVar3 = *puVar6;
    puVar3[1] = uVar1;
    puVar2 = puVar3 + 2;
  } while (puVar5 != (undefined4 *)&pdVar4->field_0x2e);
  puVar3[2] = *puVar5;
  *(undefined1 *)(puVar3 + 3) = *(undefined1 *)(puVar6 + 3);
  puVar2 = &DAT_2007fc35;
  puVar5 = (undefined4 *)&pdVar4->field_0x33;
  do {
    puVar6 = puVar5 + 1;
    puVar3 = puVar2 + 1;
    *puVar2 = *puVar5;
    puVar2 = puVar3;
    puVar5 = puVar6;
  } while (puVar6 != (undefined4 *)&pdVar4->field_0x5b);
  *(undefined2 *)puVar3 = *(undefined2 *)puVar6;
  return;
}


