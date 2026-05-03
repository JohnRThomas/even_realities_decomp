/*
 * Function: FUN_01029bb2
 * Entry:    01029bb2
 * Prototype: undefined1 __stdcall FUN_01029bb2(ushort param_1, uint param_2)
 */


undefined1 FUN_01029bb2(ushort param_1,uint param_2)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)FUN_0100a518(param_1,1);
  if (puVar2 == (undefined4 *)0x0) {
    uVar1 = 2;
  }
  else if (param_2 < 3) {
    *(char *)((int)puVar2 + 0x2ed) = (char)(param_2 & 1);
    *(byte *)(puVar2 + 0xbb) = (byte)((param_2 << 0x1e) >> 0x1f);
    if ((param_2 & 1) != 0) {
      if (*(char *)((int)puVar2 + 0x2ea) == '\0') {
        return 0;
      }
      FUN_010145a8(puVar2);
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0x12;
  }
  return uVar1;
}


