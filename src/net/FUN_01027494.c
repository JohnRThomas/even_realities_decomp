/*
 * Function: FUN_01027494
 * Entry:    01027494
 * Prototype: undefined2 __stdcall FUN_01027494(short * param_1, undefined4 * param_2)
 */


undefined2 FUN_01027494(short *param_1,undefined4 *param_2)

{
  ushort uVar1;
  bool bVar2;
  undefined2 uVar3;
  
  uVar1 = (ushort)(((uint)(ushort)param_1[4] << 0x11) >> 0x11);
  bVar2 = FUN_01027112(param_1[4],param_1[2]);
  if (bVar2) {
    uVar3 = 0;
  }
  else {
    if (param_2 != (undefined4 *)0x0) {
      FUN_01026198(param_2,(undefined4 *)((int)param_1 + uVar1 + 0x1a),
                   (uint)*(byte *)((int)param_1 + 0x13));
    }
    uVar3 = *(undefined2 *)((int)param_1 + uVar1 + 0x18);
    FUN_01009d1c(param_1,(ushort *)(param_1 + 4));
  }
  return uVar3;
}


