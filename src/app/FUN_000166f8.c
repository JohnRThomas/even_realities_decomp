/*
 * Function: FUN_000166f8
 * Entry:    000166f8
 * Prototype: undefined __stdcall FUN_000166f8(void)
 */


/* WARNING: Struct "GlassesState": ignoring multiple overlapping fields */

void FUN_000166f8(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar5;
  
  uVar1 = GLOBAL_STATE._0_4_;
  **(int **)(GLOBAL_STATE._0_4_ + 0xff0) = DAT_2007fc00 + 1;
  *(undefined1 *)(*(int *)(uVar1 + 0xff0) + 4) = DAT_2007fc04;
  *(undefined1 *)(*(int *)(uVar1 + 0xff0) + 5) = DAT_2007fc05;
  uVar3 = DAT_2007fc0c;
  iVar2 = *(int *)(uVar1 + 0xff0);
  *(undefined4 *)(iVar2 + 6) = DAT_2007fc08;
  *(undefined4 *)(iVar2 + 10) = uVar3;
  *(undefined1 *)(*(int *)(uVar1 + 0xff0) + 0x5d) = DAT_2007fc5f;
  *(undefined1 *)(*(int *)(uVar1 + 0xff0) + 0x5e) = DAT_2007fc60;
  *(undefined1 *)(*(int *)(uVar1 + 0xff0) + 0x62) = ERASE_DFU_ON_NEXT_PASS;
  *(undefined1 *)(*(int *)(uVar1 + 0xff0) + 0x61) = DAT_2007fc61;
  *(undefined1 *)(*(int *)(uVar1 + 0xff0) + 100) = DAT_2007fc68;
  if (DAT_2007fc69 < 4) {
    DAT_2001c4e6 = DAT_2007fc69;
  }
  puVar4 = (undefined4 *)(*(int *)(uVar1 + 0xff0) + 0xe);
  puVar6 = &DAT_2007fc10;
  do {
    puVar7 = puVar6;
    puVar5 = puVar4;
    uVar3 = puVar7[1];
    *puVar5 = *puVar7;
    puVar5[1] = uVar3;
    puVar4 = puVar5 + 2;
    puVar6 = puVar7 + 2;
  } while (puVar7 + 2 != (undefined4 *)0x2007fc30);
  puVar5[2] = uRam2007fc30;
  *(undefined1 *)(puVar5 + 3) = *(undefined1 *)(puVar7 + 3);
  puVar4 = &DAT_2007fc35;
  puVar6 = (undefined4 *)(*(int *)(uVar1 + 0xff0) + 0x33);
  do {
    puVar5 = puVar4 + 1;
    puVar7 = puVar6 + 1;
    *puVar6 = *puVar4;
    puVar4 = puVar5;
    puVar6 = puVar7;
  } while (puVar5 != (undefined4 *)0x2007fc5d);
  *(undefined2 *)puVar7 = uRam2007fc5d;
  return;
}


