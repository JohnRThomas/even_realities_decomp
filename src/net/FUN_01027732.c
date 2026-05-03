/*
 * Function: FUN_01027732
 * Entry:    01027732
 * Prototype: undefined4 __stdcall FUN_01027732(short * param_1, ushort param_2, char param_3)
 */


undefined4 FUN_01027732(short *param_1,ushort param_2,char param_3)

{
  ushort uVar1;
  short sVar2;
  ushort *puVar3;
  undefined4 uVar4;
  
  uVar1 = (ushort)(((uint)(ushort)param_1[3] << 0x11) >> 0x11);
  puVar3 = (ushort *)((int)param_1 + uVar1 + 0x18);
  if ((param_1[8] == 0) || ((ushort)param_1[8] < param_2)) {
    uVar4 = 0;
  }
  else {
    if (param_1[6] == 0) {
      *(undefined1 *)puVar3 = 0;
      *(undefined1 *)((int)puVar3 + 1) = 0;
    }
    else {
      if ((uint)(ushort)param_1[6] != (uint)*puVar3) {
        FUN_01009500(0x14,0x204,(uint)(ushort)param_1[6],(uint)*puVar3);
      }
      sVar2 = FUN_01027056(*(byte *)((int)param_1 + 0x13));
      FUN_01026198((undefined4 *)
                   ((int)param_1 + (int)sVar2 + (uint)uVar1 + (uint)(ushort)param_1[6] + 0x15),
                   (undefined4 *)(param_1 + 10),3);
    }
    param_1[6] = param_2 + param_1[6];
    *puVar3 = param_2 + *puVar3;
    if (param_3 == '\0') {
      sVar2 = FUN_01027056(*(byte *)((int)param_1 + 0x13));
      FUN_01026198((undefined4 *)(param_1 + 10),
                   (undefined4 *)
                   ((int)param_1 + (int)sVar2 + (uint)uVar1 + (uint)(ushort)param_1[6] + 0x15),3);
    }
    else {
      FUN_01009d1c(param_1,(ushort *)(param_1 + 3));
      param_1[6] = 0;
    }
    param_1[8] = 0;
    uVar4 = 1;
  }
  return uVar4;
}


