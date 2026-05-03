/*
 * Function: FUN_010129e4
 * Entry:    010129e4
 * Prototype: undefined __stdcall FUN_010129e4(undefined4 * param_1, undefined1 param_2)
 */


void FUN_010129e4(undefined4 *param_1,undefined1 param_2)

{
  undefined1 *puVar1;
  int iVar2;
  undefined1 *extraout_r1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 auStack_20 [2];
  byte abStack_18 [12];
  
  FUN_01026284(param_1,0,0x150);
  *(undefined2 *)((int)param_1 + 0x22) = 10000;
  *(undefined1 *)param_1 = 0xff;
  *(undefined2 *)((int)param_1 + 2) = 0x13;
  puVar1 = FUN_0100ac40();
  param_1[0x11] = puVar1;
  FUN_01028384(auStack_20,(int)puVar1,0);
  FUN_01028580(param_1[0x11],'\x01',0);
  FUN_01028384(auStack_20,param_1[0x11],4);
  FUN_01028580(param_1[0x11],'\0',0);
  *(undefined1 *)(param_1 + 4) = param_2;
  FUN_010131a4((undefined2 *)(param_1 + 10));
  iVar2 = FUN_0100dfbc((undefined4 *)abStack_18);
  if (iVar2 != 0) {
    FUN_0100e040((int)param_1 + 0x2e,abStack_18);
    return;
  }
  FUN_01009500(0x2d,0x339,extraout_r2,extraout_r3);
  *extraout_r1 = 0xff;
  **(undefined1 **)(extraout_r1 + 0x44) = 1;
  return;
}


