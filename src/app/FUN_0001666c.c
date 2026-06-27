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
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar4 = *(undefined4 **)(GLOBAL_STATE._0_4_ + 0xff0);
  DAT_2007fc00 = *puVar4;
  DAT_2007fc08 = *(undefined4 *)((int)puVar4 + 6);
  DAT_2007fc04 = *(undefined1 *)(puVar4 + 1);
  DAT_2007fc05 = *(undefined1 *)((int)puVar4 + 5);
  DAT_2007fc0c = *(undefined4 *)((int)puVar4 + 10);
  DAT_2007fc5f = *(undefined1 *)((int)puVar4 + 0x5d);
  DAT_2007fc60 = *(undefined1 *)((int)puVar4 + 0x5e);
  ERASE_DFU_ON_NEXT_PASS = *(undefined1 *)((int)puVar4 + 0x62);
  DAT_2007fc61 = *(undefined1 *)((int)puVar4 + 0x61);
  puVar2 = &DAT_2007fc10;
  puVar5 = (undefined4 *)((int)puVar4 + 0xe);
  do {
    puVar6 = puVar5;
    puVar3 = puVar2;
    uVar1 = puVar6[1];
    puVar5 = puVar6 + 2;
    *puVar3 = *puVar6;
    puVar3[1] = uVar1;
    puVar2 = puVar3 + 2;
  } while (puVar5 != (undefined4 *)((int)puVar4 + 0x2e));
  puVar3[2] = *puVar5;
  *(undefined1 *)(puVar3 + 3) = *(undefined1 *)(puVar6 + 3);
  puVar2 = &DAT_2007fc35;
  puVar5 = (undefined4 *)((int)puVar4 + 0x33);
  do {
    puVar6 = puVar5 + 1;
    puVar3 = puVar2 + 1;
    *puVar2 = *puVar5;
    puVar2 = puVar3;
    puVar5 = puVar6;
  } while (puVar6 != (undefined4 *)((int)puVar4 + 0x5b));
  *(undefined2 *)puVar3 = *(undefined2 *)puVar6;
  return;
}


