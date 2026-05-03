/*
 * Function: FUN_0102e2f0
 * Entry:    0102e2f0
 * Prototype: int __stdcall FUN_0102e2f0(int param_1, undefined4 param_2)
 */


int FUN_0102e2f0(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 extraout_r1;
  undefined4 extraout_r1_00;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  int local_24;
  undefined1 *local_20;
  undefined4 uStack_1c;
  
  if (param_1 == 0) {
    iVar1 = -0x16;
  }
  else {
    *(undefined4 *)(param_1 + 0x3c) = 1;
    *(char **)(param_1 + 0x34) = "sram0.shm";
    *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(param_1 + 0x98);
    FUN_0103b208((undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x98),
                 (undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x9c),0xffffffff,0,
                 (undefined4 *)0x0);
    local_20 = &LAB_01035ac0_1;
    uStack_1c = 6;
    iVar1 = FUN_01035a4c(&local_20);
    if (((iVar1 == 0) && (iVar1 = FUN_01035a10((undefined4 *)(param_1 + 0x34)), iVar1 == 0)) &&
       (iVar1 = FUN_0103b1cc((byte *)"generic","sram0.shm",(int)&local_24), iVar1 == 0)) {
      iVar1 = *(int *)(local_24 + 8);
      if (iVar1 == 0) {
        local_24 = 0;
      }
      else {
        local_24 = local_24 + 0xc;
      }
      *(int *)(param_1 + 0xa0) = local_24;
      puVar2 = FUN_0103a9b0(*(int *)(param_1 + 0x94),extraout_r1,iVar1,local_24);
      *(undefined4 **)(param_1 + 0xd4) = puVar2;
      if (puVar2 != (undefined4 *)0x0) {
        puVar2 = FUN_0103a9b0(*(int *)(param_1 + 0x94),extraout_r1_00,extraout_r2,extraout_r3);
        *(undefined4 **)(param_1 + 0xd8) = puVar2;
        if (puVar2 != (undefined4 *)0x0) {
          *(undefined4 *)(param_1 + 0xa8) = *(undefined4 *)(param_1 + 0x8c);
          *(undefined4 *)(param_1 + 0xac) = 4;
          *(undefined4 *)(param_1 + 0xc4) = 4;
          *(undefined4 *)(param_1 + 0x28) = 2;
          *(undefined4 *)(param_1 + 0xb8) = *(undefined4 *)(param_1 + 0xa0);
          *(undefined4 *)(param_1 + 0xd0) = *(undefined4 *)(param_1 + 0xa0);
          *(undefined **)(param_1 + 0x20) = &DAT_0103c894;
          *(undefined2 *)(param_1 + 0xb0) = *(undefined2 *)(param_1 + 0x94);
          *(undefined4 *)(param_1 + 0xa4) = *(undefined4 *)(param_1 + 0xd4);
          *(undefined4 *)(param_1 + 0xc0) = *(undefined4 *)(param_1 + 0x90);
          *(undefined2 *)(param_1 + 200) = *(undefined2 *)(param_1 + 0x94);
          *(undefined4 **)(param_1 + 0xbc) = puVar2;
          *(undefined4 *)(param_1 + 0x18) = param_2;
          *(int *)(param_1 + 0x2c) = param_1 + 0xa4;
          return 0;
        }
      }
      iVar1 = -0xc;
    }
  }
  return iVar1;
}


