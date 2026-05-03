/*
 * Function: FUN_0102861c
 * Entry:    0102861c
 * Prototype: undefined4 __stdcall FUN_0102861c(int param_1, undefined4 * param_2, char param_3)
 */


undefined4 FUN_0102861c(int param_1,undefined4 *param_2,char param_3)

{
  byte bVar1;
  uint uVar2;
  undefined4 uVar3;
  byte local_a;
  byte local_9;
  
  if (*(char *)(param_1 + 2) == '\0') {
    uVar2 = FUN_010282d2(param_3);
    bVar1 = (byte)uVar2;
    if (*(char *)((uVar2 & 0xff) + param_1 + 0x14) == '\x02') {
      local_a = bVar1 + 1;
      local_9 = bVar1;
    }
    else {
      if (*(char *)((uVar2 & 0xff) + param_1 + 0x15) != '\x02') {
        return 0;
      }
      local_9 = bVar1 + 1;
      local_a = bVar1;
    }
    if (param_2 != (undefined4 *)0x0) {
      *(undefined1 *)((uint)local_a + param_1 + 0x14) = 0;
      *(undefined2 *)(param_1 + (local_a + 0xc) * 2) = 0;
      *(undefined1 *)((uint)local_9 + param_1 + 0x14) = 3;
      *param_2 = *(undefined4 *)((uint)local_9 * 4 + param_1 + 4);
      *(undefined2 *)(param_2 + 1) = *(undefined2 *)(param_1 + (local_9 + 0xc) * 2);
    }
    uVar3 = 1;
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


