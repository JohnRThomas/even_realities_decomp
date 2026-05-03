/*
 * Function: FUN_01034e98
 * Entry:    01034e98
 * Prototype: undefined1 * __stdcall FUN_01034e98(uint param_1, undefined4 param_2, byte * param_3, int * param_4)
 */


undefined1 * FUN_01034e98(uint param_1,undefined4 param_2,byte *param_3,int *param_4)

{
  byte bVar1;
  byte bVar2;
  uint3 uVar3;
  uint uVar4;
  uint uVar5;
  undefined1 *puVar6;
  byte *extraout_r1;
  int extraout_r1_00;
  ushort uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  undefined4 uStack_1c;
  
  uStack_1c = param_4;
  uVar4 = FUN_01034c68(param_1);
  if (extraout_r1 == (byte *)0x0) {
LAB_01034ee6:
    if (param_3 != (byte *)0x0) {
      bVar1 = *param_3;
      uVar9 = (uint)bVar1;
      uVar5 = FUN_01034cc8(param_1);
      if (uVar5 == 0) {
        iVar8 = uVar4 + 8;
        uVar7 = *(ushort *)((int)&DAT_210006a8 + iVar8 * 2) & 0x1fdf;
        *(ushort *)((int)&DAT_210006a8 + iVar8 * 2) = uVar7;
        if (extraout_r1_00 != 0) {
          if (3 < uVar9) goto LAB_01034efe;
          bVar2 = **(byte **)(param_3 + 4);
          if (uVar9 == 0) {
            (&Peripherals::GPIOTE_NS.CONFIG_0_)[bVar2] = 0;
            (&Peripherals::GPIOTE_NS.CONFIG_0_)[bVar2] = 0;
          }
          else {
            (&Peripherals::GPIOTE_NS.CONFIG_0_)[bVar2] =
                 (&Peripherals::GPIOTE_NS.CONFIG_0_)[bVar2] & 0xfffffffc;
            (&Peripherals::GPIOTE_NS.CONFIG_0_)[bVar2] =
                 (&Peripherals::GPIOTE_NS.CONFIG_0_)[bVar2] & 0xfffcc0ff;
            (&Peripherals::GPIOTE_NS.CONFIG_0_)[bVar2] =
                 (param_1 & 0x3f) << 8 | (&Peripherals::GPIOTE_NS.CONFIG_0_)[bVar2] | uVar9 << 0x10;
            *(ushort *)((int)&DAT_210006a8 + iVar8 * 2) = uVar7 | (ushort)bVar2 << 0xd | 0x20;
          }
        }
      }
      else if (extraout_r1_00 != 0) goto LAB_01034efe;
      *(ushort *)((int)&DAT_210006a8 + (uVar4 + 8) * 2) =
           *(ushort *)((int)&DAT_210006a8 + (uVar4 + 8) * 2) & 0xffe3 | (ushort)bVar1 << 2;
    }
    if (param_4 != (int *)0x0) {
      iVar10 = *param_4;
      iVar8 = param_4[1];
      FUN_01034d38(param_1);
      if (iVar10 != 0) {
        if ((iVar10 == DAT_210006a8) && (iVar8 == DAT_210006ac)) {
          uVar5 = 0;
        }
        else {
          puVar6 = FUN_01034ae8(&DAT_2100071c,(undefined1 *)((int)&uStack_1c + 3));
          if (puVar6 != &DAT_0bad0000) {
            return puVar6;
          }
          uVar5 = (uint)uStack_1c >> 0x18;
        }
        (&DAT_210006ac)[uVar5 * 2] = iVar8;
        uVar7 = *(ushort *)((int)&DAT_210006a8 + (uVar4 + 8) * 2);
        (&DAT_210006a8)[uVar5 * 2] = iVar10;
        *(ushort *)((int)&DAT_210006a8 + (uVar4 + 8) * 2) = uVar7 | (ushort)(uVar5 << 9) | 0x100;
      }
    }
    puVar6 = &DAT_0bad0000;
  }
  else {
    uVar5 = FUN_0103b0ce(param_1);
    if (uVar5 == 0) {
      uVar3 = (uint3)uStack_1c;
      uStack_1c = (int *)(uint)(uVar3 & 0xffff);
      FUN_0103b0e4(param_1,(byte *)((int)&uStack_1c + 2),(byte *)((int)&uStack_1c + 3),extraout_r1,
                   (byte *)0x0,(byte *)0x0);
      *(ushort *)((int)&DAT_210006a8 + (uVar4 + 8) * 2) =
           *(ushort *)((int)&DAT_210006a8 + (uVar4 + 8) * 2) & 0xfffd | 1;
      goto LAB_01034ee6;
    }
LAB_01034efe:
    puVar6 = &DAT_0bad0004;
  }
  return puVar6;
}


