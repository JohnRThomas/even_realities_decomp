/*
 * Function: FUN_010273fe
 * Entry:    010273fe
 * Prototype: undefined4 __stdcall FUN_010273fe(short * param_1, undefined4 * param_2)
 */


undefined4 FUN_010273fe(short *param_1,undefined4 *param_2)

{
  ushort *puVar1;
  undefined4 uVar2;
  
  puVar1 = (ushort *)((int)param_1 + ((ushort)param_1[2] & 0x7fff) + 0x18);
  *param_2 = 0;
  if (param_1[7] == 0) {
    uVar2 = 0;
  }
  else {
    param_1[5] = param_1[7] + param_1[5];
    if ((uint)*puVar1 < (uint)(ushort)param_1[5]) {
      FUN_01009500(0x14,0x151,(uint)(ushort)param_1[5],(uint)*puVar1);
    }
    if (param_1[5] == *puVar1) {
      FUN_01009d1c(param_1,(ushort *)(param_1 + 2));
      param_1[5] = 0;
      *param_2 = puVar1;
    }
    param_1[7] = 0;
    uVar2 = 1;
  }
  return uVar2;
}


