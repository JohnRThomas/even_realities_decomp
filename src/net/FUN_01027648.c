/*
 * Function: FUN_01027648
 * Entry:    01027648
 * Prototype: int __stdcall FUN_01027648(ushort * param_1, ushort param_2)
 */


int FUN_01027648(ushort *param_1,ushort param_2)

{
  ushort uVar1;
  ushort uVar2;
  char cVar3;
  short sVar4;
  ushort uVar5;
  int iVar6;
  uint uVar7;
  uint local_14;
  
  uVar1 = (ushort)(((uint)param_1[4] << 0x11) >> 0x11);
  uVar2 = (ushort)(((uint)param_1[3] << 0x11) >> 0x11);
  cVar3 = FUN_010270ce(param_1[4],param_1[3]);
  if (cVar3 == '\0') {
    uVar5 = *param_1;
    if (uVar5 < 0x45) {
      uVar5 = 0x45;
    }
    local_14 = (uint)uVar5;
    if (uVar2 < uVar1) {
      sVar4 = FUN_01027056(*(byte *)((int)param_1 + 0x13));
      uVar7 = ((uint)uVar1 - (uint)uVar2) - (int)sVar4;
      if ((int)uVar7 <= (int)local_14) {
        local_14 = uVar7;
      }
    }
    if (param_1[6] != 0) {
      local_14 = local_14 - *(ushort *)((int)param_1 + uVar2 + 0x18);
    }
    if ((int)local_14 < (int)(uint)param_2) {
      param_1[8] = 0;
      iVar6 = 0;
    }
    else {
      sVar4 = FUN_01027056(*(byte *)((int)param_1 + 0x13));
      iVar6 = (int)param_1 + (int)sVar4 + (uint)uVar2 + (uint)param_1[6] + 0x15;
      param_1[8] = param_2;
    }
  }
  else {
    param_1[8] = 0;
    iVar6 = 0;
  }
  return iVar6;
}


