/*
 * Function: FUN_01028834
 * Entry:    01028834
 * Prototype: undefined2 __stdcall FUN_01028834(int param_1, char param_2)
 */


undefined2 FUN_01028834(int param_1,char param_2)

{
  uint uVar1;
  undefined2 uVar2;
  
  uVar1 = FUN_010282d2(param_2);
  if (*(char *)((uVar1 & 0xff) + param_1 + 0x14) == '\x02') {
    uVar2 = *(undefined2 *)(param_1 + ((uVar1 & 0xff) + 0xc) * 2);
  }
  else if (*(char *)((uVar1 & 0xff) + param_1 + 0x15) == '\x02') {
    uVar2 = *(undefined2 *)(param_1 + ((uVar1 & 0xff) + 0xd) * 2);
  }
  else if (*(char *)((uVar1 & 0xff) + param_1 + 0x14) == '\x03') {
    uVar2 = *(undefined2 *)(param_1 + ((uVar1 & 0xff) + 0xc) * 2);
  }
  else if (*(char *)((uVar1 & 0xff) + param_1 + 0x15) == '\x03') {
    uVar2 = *(undefined2 *)(param_1 + ((uVar1 & 0xff) + 0xd) * 2);
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


