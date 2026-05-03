/*
 * Function: FUN_01028384
 * Entry:    01028384
 * Prototype: undefined4 * __stdcall FUN_01028384(undefined4 * param_1, int param_2, byte param_3)
 */


undefined4 * FUN_01028384(undefined4 *param_1,int param_2,byte param_3)

{
  undefined2 uVar1;
  uint uVar2;
  byte bVar3;
  bool bVar4;
  undefined4 uVar5;
  byte local_9;
  
  bVar3 = param_3 & 0xfb;
  if (((*(char *)(param_2 + 1) == '\0') || (bVar3 == 0)) &&
     ((*(char *)(param_2 + 1) == '\x01' || (bVar3 != 0)))) {
    bVar4 = false;
  }
  else {
    bVar4 = true;
  }
  if (bVar4) {
    FUN_0100ab1c(param_2,bVar3 == 0);
  }
  *(undefined1 *)(param_2 + 2) = 0xff;
  uVar2 = FUN_010282d2((param_3 & 4) == 0);
  local_9 = (byte)uVar2;
  if ((*(char *)((uVar2 & 0xff) + param_2 + 0x14) == '\x03') && (bVar3 != 2)) {
    local_9 = local_9 + 1;
  }
  *(undefined1 *)((uint)local_9 + param_2 + 0x14) = 1;
  *(undefined2 *)(param_2 + (local_9 + 0xc) * 2) = 0;
  uVar5 = *(undefined4 *)((uint)local_9 * 4 + param_2 + 4);
  uVar1 = *(undefined2 *)(param_2 + (local_9 + 0xc) * 2);
  *(undefined1 *)(param_2 + 2) = 0;
  *param_1 = uVar5;
  *(undefined2 *)(param_1 + 1) = uVar1;
  return param_1;
}


