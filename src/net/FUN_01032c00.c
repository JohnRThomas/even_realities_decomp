/*
 * Function: FUN_01032c00
 * Entry:    01032c00
 * Prototype: undefined __stdcall FUN_01032c00(undefined1 * param_1, undefined1 * param_2)
 */


void FUN_01032c00(undefined1 *param_1,undefined1 *param_2)

{
  undefined1 *puVar1;
  undefined1 *extraout_r1;
  undefined1 *puVar2;
  undefined1 *extraout_r3;
  char cVar3;
  bool bVar4;
  
  cVar3 = param_1 == param_2;
  puVar2 = param_2 + 0x20;
  if (param_1 <= param_2) goto LAB_01032c24;
  cVar3 = param_1 == puVar2;
  bVar4 = puVar2 <= param_1;
  while (!bVar4) {
    do {
      FUN_0103a37e((byte *)"ASSERTION FAIL @ %s:%d\n",
                   "WEST_TOPDIR/zephyr/include/zephyr/sys/byteorder.h",0x215,puVar2);
      param_1 = (undefined1 *)FUN_0103a370();
      param_2 = extraout_r1;
      puVar2 = extraout_r3;
LAB_01032c24:
    } while (cVar3 != '\0');
    cVar3 = param_2 == param_1 + 0x20;
    bVar4 = param_1 + 0x20 <= param_2;
  }
  puVar1 = param_1 + -1;
  do {
    puVar2 = puVar2 + -1;
    puVar1 = puVar1 + 1;
    *puVar1 = *puVar2;
  } while (puVar2 != param_2);
  return;
}


