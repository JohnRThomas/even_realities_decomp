/*
 * Function: FUN_010141a4
 * Entry:    010141a4
 * Prototype: undefined * __stdcall FUN_010141a4(int param_1, undefined4 param_2, undefined1 param_3)
 */


undefined * FUN_010141a4(int param_1,undefined4 param_2,undefined1 param_3)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  int iVar4;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 uVar5;
  undefined4 uVar6;
  
  *(undefined1 *)(param_1 + 0x108) = 0;
  puVar2 = *(undefined4 **)(param_1 + 0x104);
  uVar5 = *(undefined4 *)(param_1 + 0x138);
  uVar6 = *(undefined4 *)(param_1 + 0x13c);
  *(undefined1 *)((int)puVar2 + 0x2ef) = param_3;
  *(undefined1 *)(param_1 + 0x120) = 0;
  *(undefined1 *)(param_1 + 0x121) = 1;
  FUN_0100d7f4(puVar2,1);
  puVar2 = *(undefined4 **)(param_1 + 0x104);
  puVar2[0xd4] = uVar5;
  puVar2[0xd5] = uVar6;
  uVar1 = *(undefined1 *)(param_1 + 0x100);
  puVar2[0xda] = param_2;
  *(undefined1 *)(puVar2 + 0xd9) = uVar1;
  *(undefined1 *)(puVar2 + 199) = 0;
  *(undefined2 *)(puVar2 + 0xd8) = 0;
  puVar2[0xd6] = uVar5;
  puVar2[0xd7] = uVar6;
  puVar3 = FUN_01013718(puVar2,0,0,0,(undefined2 *)0x0);
  if (puVar3 == (undefined *)0x0) {
    *(undefined1 *)(puVar2 + 199) = 1;
    puVar2[0xc6] = 0;
    puVar2[0xc4] = 0;
    *(undefined2 *)((int)puVar2 + 0x32e) = 0;
    *(undefined2 *)(puVar2 + 0xcb) = 0;
    *(undefined1 *)((int)puVar2 + 0x331) = 0;
    *(undefined2 *)((int)puVar2 + 0x362) = 0;
    *(short *)(puVar2 + 0x2f) = *(short *)(puVar2 + 0x2f) + -1;
    FUN_01020e34();
    puVar3 = FUN_01023284();
    return puVar3;
  }
  iVar4 = FUN_01009500(0x30,0x21e,extraout_r2,extraout_r3);
  return *(undefined **)(iVar4 + 0x104);
}


