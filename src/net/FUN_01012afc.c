/*
 * Function: FUN_01012afc
 * Entry:    01012afc
 * Prototype: undefined4 __stdcall FUN_01012afc(int param_1, undefined4 param_2)
 */


undefined4 FUN_01012afc(int param_1,uint param_2)

{
  uint uVar1;
  int iStack_20;
  ushort uStack_1c;
  undefined4 uStack_18;
  ushort uStack_14;
  
  uStack_1c = *(ushort *)(param_1 + 2);
  if ((uStack_1c & 0x18) != 0) {
    return 1;
  }
  uStack_18 = *(undefined4 *)(param_1 + 8);
  uStack_14 = *(ushort *)(param_1 + 4);
  iStack_20 = param_1 + 0x28;
  uVar1 = FUN_01012514(param_2,&iStack_20,(uint)uStack_14,(uint)uStack_1c);
  return uVar1;
}


