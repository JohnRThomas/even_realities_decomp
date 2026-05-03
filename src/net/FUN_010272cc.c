/*
 * Function: FUN_010272cc
 * Entry:    010272cc
 * Prototype: undefined4 __stdcall FUN_010272cc(ushort * param_1, ushort param_2)
 */


undefined4 FUN_010272cc(ushort *param_1,ushort param_2)

{
  ushort uVar1;
  ushort *puVar2;
  undefined4 uVar3;
  
  puVar2 = (ushort *)((int)param_1 + (param_1[3] & 0x7fff) + 0x18);
  uVar1 = *param_1;
  if (uVar1 < 0x45) {
    uVar1 = 0x45;
  }
  if ((uint)uVar1 < (uint)param_2) {
    FUN_01009500(0x14,0x104,(uint)param_2,(uint)uVar1);
  }
  if ((char)param_1[9] == '\x01') {
    if (*puVar2 < param_2) {
      uVar3 = 0;
    }
    else {
      *puVar2 = param_2;
      FUN_01009d1c((short *)param_1,param_1 + 3);
      *(undefined1 *)(param_1 + 9) = 0;
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}


