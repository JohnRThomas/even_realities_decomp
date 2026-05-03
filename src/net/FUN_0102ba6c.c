/*
 * Function: FUN_0102ba6c
 * Entry:    0102ba6c
 * Prototype: undefined __stdcall FUN_0102ba6c(undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4)
 */


void FUN_0102ba6c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  undefined1 *puVar3;
  char *pcVar4;
  
  puVar1 = FUN_0103bcf0(0x100,param_2,param_3,param_4);
  param_1[4] = puVar1;
  FUN_0103bdee((undefined1 *)puVar1,0,0x100);
  puVar3 = (undefined1 *)param_1[4];
  *puVar3 = 0xfb;
  *(undefined4 *)(puVar3 + 0x11) = *(undefined4 *)((int)param_1 + 0x1a);
  *(undefined2 *)(puVar3 + 0x15) = *(undefined2 *)((int)param_1 + 0x1e);
  *param_1 = 0x102b989;
  pcVar4 = "cpunet-esbm";
  if (param_1[-0x2c] == 1) {
    uVar2 = 2;
  }
  else {
    pcVar4 = "cpunet-esbs";
    uVar2 = 4;
  }
  param_1[2] = pcVar4;
  *(undefined1 *)(param_1 + 1) = uVar2;
  param_1[3] = 0x102b91d;
  (*(code *)param_1[-1])(param_1 + 1);
  DAT_21004610 = param_1;
  return;
}


