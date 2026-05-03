/*
 * Function: FUN_01010a74
 * Entry:    01010a74
 * Prototype: undefined __stdcall FUN_01010a74(byte * param_1)
 */


void FUN_01010a74(byte *param_1)

{
  undefined2 uVar1;
  uint uVar2;
  undefined1 *puVar3;
  undefined4 extraout_r2;
  undefined1 uVar4;
  undefined4 extraout_r3;
  int iVar5;
  undefined8 uVar6;
  
  iVar5 = *(int *)(param_1 + 4);
  uVar2 = FUN_0100dbc0(iVar5 + 0xa8,0,(uint)*(byte *)(iVar5 + 0xc5),(uint)*param_1);
  if (uVar2 != 0) {
    if (*param_1 == 0) {
      uVar4 = 5;
    }
    else {
      uVar4 = 0x10;
    }
    *(undefined1 *)(iVar5 + 0xc5) = uVar4;
    return;
  }
  uVar6 = FUN_01009500(0x4b,0x71,extraout_r2,extraout_r3);
  puVar3 = (undefined1 *)((ulonglong)uVar6 >> 0x20);
  iVar5 = (int)uVar6;
  do {
    *puVar3 = 1;
    uVar1 = *(undefined2 *)(iVar5 + -0x108);
    puVar3[2] = 0;
    *(undefined2 *)(puVar3 + 3) = uVar1;
    puVar3[5] = *(undefined1 *)(iVar5 + 9);
    *(undefined4 *)(puVar3 + 6) = *(undefined4 *)(iVar5 + 10);
  } while( true );
}


