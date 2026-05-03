/*
 * Function: FUN_01032bb8
 * Entry:    01032bb8
 * Prototype: undefined4 __stdcall FUN_01032bb8(undefined4 param_1)
 */


/* WARNING: Removing unreachable block (ram,0x01032bd0) */

undefined4 FUN_01032bb8(byte *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  ushort in_r1;
  
  bVar1 = FUN_0103b8b0(0x103bf30);
  if (!bVar1) {
    return 0xffffffed;
  }
  uVar2 = FUN_01030e64(0x103bf30,param_1,(uint)in_r1);
  return uVar2;
}


