/*
 * Function: FUN_01028580
 * Entry:    01028580
 * Prototype: undefined __stdcall FUN_01028580(int param_1, char param_2, undefined2 param_3)
 */


void FUN_01028580(int param_1,char param_2,undefined2 param_3)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = FUN_010282d2(param_2);
  *(undefined1 *)(param_1 + 2) = 0xff;
  if (*(char *)((uVar1 & 0xff) + param_1 + 0x14) == '\x01') {
    *(undefined2 *)(param_1 + ((uVar1 & 0xff) + 0xc) * 2) = param_3;
    *(undefined1 *)((uVar1 & 0xff) + param_1 + 0x14) = 2;
  }
  else {
    uVar2 = (uint)*(byte *)((uVar1 & 0xff) + param_1 + 0x15);
    if (uVar2 == 1) {
      *(undefined2 *)(param_1 + ((uVar1 & 0xff) + 0xd) * 2) = param_3;
      *(undefined1 *)((uVar1 & 0xff) + param_1 + 0x15) = 2;
    }
    else {
      FUN_01009500(9,0x116,param_1,uVar2);
    }
  }
  *(undefined1 *)(param_1 + 2) = 0;
  return;
}


