/*
 * Function: FUN_0100e7bc
 * Entry:    0100e7bc
 * Prototype: undefined __stdcall FUN_0100e7bc(byte * param_1, uint param_2)
 */


void FUN_0100e7bc(byte *param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined8 uVar3;
  
  uVar2 = *param_1 & 0xfffffff0 | param_2 & 0xf;
  *param_1 = (byte)uVar2;
  switch(param_2) {
  case 0:
  case 2:
  case 4:
  case 6:
    param_1[1] = 6;
    return;
  case 1:
  case 3:
    param_1[1] = 0xc;
    return;
  case 5:
    param_1[1] = 0x22;
    return;
  case 7:
    param_1[3] = 0;
    param_1[1] = 1;
    return;
  case 8:
    param_1[1] = 0xe;
    return;
  default:
    uVar3 = FUN_01009500(0x2a,0xa8,param_2 & 0xf,uVar2);
    puVar1 = (undefined4 *)((ulonglong)uVar3 >> 0x20);
    *(undefined4 *)((int)uVar3 + 3) = *puVar1;
    *(undefined2 *)((int)uVar3 + 7) = *(undefined2 *)(puVar1 + 1);
    return;
  }
}


