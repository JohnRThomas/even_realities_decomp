/*
 * Function: FUN_0101e960
 * Entry:    0101e960
 * Prototype: undefined __stdcall FUN_0101e960(undefined4 param_1, int param_2)
 */


void FUN_0101e960(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 extraout_r2_01;
  undefined4 uVar2;
  char cVar3;
  undefined4 extraout_r3;
  undefined4 extraout_r3_00;
  undefined4 extraout_r3_01;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  if ((*(char *)(param_2 + 0x30) == '\x03') &&
     (iVar1 = FUN_0102a2ea((ushort)*(byte *)(param_2 + 0xa6),0), iVar1 != 0)) {
    *(undefined2 *)(iVar1 + 0x2e) = 0xffff;
  }
  iVar1 = FUN_0102a388(param_2 + 200);
  uVar2 = extraout_r2;
  uVar4 = extraout_r3;
  if (iVar1 == 0) {
    do {
      puVar5 = *(undefined4 **)(param_2 + 0x98);
      if (puVar5 == (undefined4 *)0x0) {
        return;
      }
      *(undefined4 *)(param_2 + 0x98) = *puVar5;
      cVar3 = *(char *)(param_2 + 0x30);
      if (cVar3 == '\x03') {
        FUN_0102a47c((int)(puVar5 + -0x3f));
        cVar3 = *(char *)(param_2 + 0x30);
      }
      if (cVar3 == '\x02') {
        FUN_0102a3fa((int)(puVar5 + -0x3f));
      }
      iVar1 = FUN_0100a564(*(ushort *)((int)puVar5 + -6),10);
    } while (iVar1 == 0);
    FUN_01009500(0x49,0xe2,extraout_r2_00,extraout_r3_00);
    uVar2 = extraout_r2_01;
    uVar4 = extraout_r3_01;
  }
  FUN_01009500(0x49,0xd1,uVar2,uVar4);
  return;
}


