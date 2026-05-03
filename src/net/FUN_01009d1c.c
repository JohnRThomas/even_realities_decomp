/*
 * Function: FUN_01009d1c
 * Entry:    01009d1c
 * Prototype: undefined __stdcall FUN_01009d1c(short * param_1, ushort * param_2)
 */


void FUN_01009d1c(short *param_1,ushort *param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort local_a;
  
  uVar1 = *param_2;
  local_a = (ushort)(((uint)uVar1 << 0x11) >> 0x11);
  uVar2 = FUN_01027056(*(byte *)((int)param_1 + 0x13));
  uVar3 = uVar2 + *param_1;
  local_a = uVar3 * (short)((int)((uint)uVar3 +
                                  (uint)*(ushort *)((int)param_1 + local_a + 0x18) + (uint)uVar2 +
                                 -1) / (int)(uint)uVar3) + local_a;
  if (local_a < (ushort)param_1[1]) {
    local_a = local_a | uVar1 & 0x8000;
  }
  else {
    local_a = ~uVar1 & 0x8000;
  }
  *param_2 = local_a;
  return;
}


