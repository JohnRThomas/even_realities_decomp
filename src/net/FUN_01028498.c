/*
 * Function: FUN_01028498
 * Entry:    01028498
 * Prototype: bool __stdcall FUN_01028498(int param_1, char param_2, undefined4 * param_3, ushort param_4)
 */


bool FUN_01028498(int param_1,char param_2,undefined4 *param_3,ushort param_4)

{
  bool bVar1;
  uint uVar2;
  byte local_9;
  
  uVar2 = FUN_010282d2(param_2);
  local_9 = (byte)uVar2;
  *(undefined1 *)(param_1 + 2) = 0xff;
  if (*(char *)((uVar2 & 0xff) + param_1 + 0x14) != '\x01') {
    if (*(char *)((uVar2 & 0xff) + param_1 + 0x15) != '\x01') {
      return false;
    }
    local_9 = local_9 + 1;
  }
  bVar1 = (uint)param_4 + (uint)*(ushort *)(param_1 + (local_9 + 0xc) * 2) <=
          (uint)*(ushort *)(param_1 + (local_9 + 0x10) * 2);
  if (bVar1) {
    FUN_01026198((undefined4 *)
                 (*(int *)((uint)local_9 * 4 + param_1 + 4) +
                 (uint)*(ushort *)(param_1 + (local_9 + 0xc) * 2)),param_3,(uint)param_4);
    *(ushort *)(param_1 + (local_9 + 0xc) * 2) = param_4 + *(short *)(param_1 + (local_9 + 0xc) * 2)
    ;
    *(undefined1 *)(param_1 + 2) = 0;
  }
  else {
    *(undefined2 *)(param_1 + (local_9 + 0xc) * 2) = 0;
    *(undefined1 *)((uint)local_9 + param_1 + 0x14) = 0;
  }
  return bVar1;
}


