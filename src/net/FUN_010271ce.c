/*
 * Function: FUN_010271ce
 * Entry:    010271ce
 * Prototype: ushort * __stdcall FUN_010271ce(ushort * param_1, ushort param_2)
 */


ushort * FUN_010271ce(ushort *param_1,ushort param_2)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  char cVar5;
  short sVar6;
  ushort uVar7;
  ushort *puVar8;
  
  uVar1 = param_1[3];
  uVar2 = param_1[4];
  uVar3 = (ushort)(((uint)uVar1 << 0x11) >> 0x11);
  uVar4 = (ushort)(((uint)uVar2 << 0x11) >> 0x11);
  uVar7 = *param_1;
  if (uVar7 < 0x45) {
    uVar7 = 0x45;
  }
  if ((uint)uVar7 < (uint)param_2) {
    FUN_01009500(0x14,0xc6,(uint)param_2,(uint)uVar7);
  }
  cVar5 = FUN_010270ce(uVar2,uVar1);
  if (cVar5 == '\0') {
    if ((uVar3 < uVar4) &&
       (sVar6 = FUN_01027056(*(byte *)((int)param_1 + 0x13)),
       (int)(((uint)uVar4 - (uint)uVar3) - (int)sVar6) < (int)(uint)param_2)) {
      *(undefined1 *)(param_1 + 9) = 0;
      return (ushort *)0x0;
    }
    puVar8 = (ushort *)((int)param_1 + uVar3 + 0x18);
    *puVar8 = param_2;
    *(undefined1 *)(param_1 + 9) = 1;
  }
  else {
    puVar8 = (ushort *)0x0;
  }
  return puVar8;
}


