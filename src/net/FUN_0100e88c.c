/*
 * Function: FUN_0100e88c
 * Entry:    0100e88c
 * Prototype: uint __stdcall FUN_0100e88c(int param_1, undefined4 * param_2, uint param_3, undefined4 param_4)
 */


uint FUN_0100e88c(int param_1,undefined4 *param_2,uint param_3,undefined4 param_4)

{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  undefined8 uVar4;
  
  if (param_3 < 0x20) {
    uVar1 = FUN_01026198((undefined4 *)(param_1 + 9),param_2,param_3);
    *(char *)(param_1 + 1) = (char)param_3 + '\x06';
    return uVar1;
  }
  uVar4 = FUN_01009500(0x2a,0x110,param_3,param_4);
  pbVar2 = (byte *)uVar4;
  if ((*pbVar2 & 0xf) == 3) {
    return (uint)(pbVar2[1] == 0xc);
  }
  if ((((*pbVar2 & 0xf) != 5) ||
      ((((pbVar2[0x1f] == 0 && pbVar2[0x20] == 0) && pbVar2[0x21] == 0) && pbVar2[0x22] == 0) &&
       (pbVar2[0x23] & 0xe0) == 0)) || (pbVar2[1] != 0x22)) {
    return 0;
  }
  uVar1 = (uint)*(ushort *)(pbVar2 + 0x19);
  if (uVar1 - 0xd01 < 7) {
    uVar3 = (uint)((ulonglong)uVar4 >> 0x20) & 1;
  }
  else {
    uVar3 = 0;
  }
  if (uVar3 != 0) {
LAB_0100e940:
    if (499 < *(ushort *)(pbVar2 + 0x1b)) {
      return 0;
    }
    return (uint)((ushort)(*(short *)(pbVar2 + 0x1d) - 10U) < 0xc77);
  }
  if (((uVar1 - 6 & 0xffff) < 0xc7b) && (pbVar2[0x16] - 1 < 8)) {
    uVar3 = (uint)*(ushort *)(pbVar2 + 0x17);
    if (*(ushort *)(pbVar2 + 0x17) <= uVar1) {
      uVar3 = (uint)pbVar2[0x16];
    }
    if (uVar3 < uVar1) goto LAB_0100e940;
  }
  return 0;
}


