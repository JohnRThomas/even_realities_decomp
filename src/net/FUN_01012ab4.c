/*
 * Function: FUN_01012ab4
 * Entry:    01012ab4
 * Prototype: undefined8 __stdcall FUN_01012ab4(int param_1, int param_2)
 */


undefined8 FUN_01012ab4(int param_1,int param_2)

{
  ushort uVar1;
  ushort uVar2;
  uint uVar3;
  undefined *puVar4;
  undefined4 extraout_r3;
  uint uVar5;
  undefined8 uVar6;
  
  uVar3 = FUN_01013324((byte *)(param_1 + 0x28));
  uVar1 = *(ushort *)(param_1 + 2);
  uVar5 = (uint)uVar1;
  if ((int)(uVar5 << 0x1b) < 0) {
    uVar6 = FUN_01013350(uVar3,uVar5,0x28,extraout_r3);
    return uVar6;
  }
  if ((int)(uVar5 << 0x1e) < 0) {
    uVar2 = *(ushort *)(param_1 + 0x54);
  }
  else {
    uVar2 = *(ushort *)(param_1 + 0x4c);
  }
  puVar4 = (undefined *)FUN_01011190(uVar3,(uint)*(byte *)(param_1 + 4));
  uVar6 = FUN_010111ec((uint)uVar2,puVar4,(uint)*(byte *)(param_1 + 5),param_2,uVar1);
  return uVar6;
}


