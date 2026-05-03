/*
 * Function: FUN_01035000
 * Entry:    01035000
 * Prototype: undefined1 * __stdcall FUN_01035000(uint param_1, undefined4 param_2, byte * param_3, undefined4 param_4)
 */


undefined1 * FUN_01035000(uint param_1,undefined4 param_2,byte *param_3,undefined4 param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 *puVar7;
  int iVar8;
  int extraout_r1;
  byte *extraout_r1_00;
  undefined4 uStack_1c;
  
  uStack_1c = param_4;
  uVar5 = FUN_01034c68(param_1);
  if (extraout_r1 == 0) {
LAB_0103505c:
    if (param_3 != (byte *)0x0) {
      uVar6 = FUN_01034cc8(param_1);
      if (uVar6 == 0) goto LAB_010350f0;
      iVar8 = uVar5 + 8;
      bVar1 = *param_3;
      uVar4 = *(ushort *)((int)&DAT_210006a8 + iVar8 * 2) & 0x1fdf;
      (&Peripherals::GPIOTE_NS.CONFIG_0_)[bVar1] = 0;
      *(ushort *)((int)&DAT_210006a8 + iVar8 * 2) = uVar4;
      (&Peripherals::GPIOTE_NS.CONFIG_0_)[bVar1] = 0;
      bVar2 = param_3[1];
      if (bVar2 != 0) {
        bVar3 = param_3[2];
        (&Peripherals::GPIOTE_NS.CONFIG_0_)[bVar1] =
             (&Peripherals::GPIOTE_NS.CONFIG_0_)[bVar1] & 0xffecc0ff;
        (&Peripherals::GPIOTE_NS.CONFIG_0_)[bVar1] =
             (param_1 & 0x3f) << 8 | (bVar2 & 3) << 0x10 |
             (&Peripherals::GPIOTE_NS.CONFIG_0_)[bVar1] | (bVar3 & 1) << 0x14;
        *(ushort *)((int)&DAT_210006a8 + iVar8 * 2) = uVar4 | (ushort)bVar1 << 0xd | 0x20;
      }
    }
    puVar7 = &DAT_0bad0000;
  }
  else {
    uVar6 = FUN_01034cc8(param_1);
    if (((uVar6 != 0) || (uVar6 = FUN_01034c94(param_1), uVar6 == 0)) &&
       ((uVar4 = FUN_01034cac(param_1), uVar4 == 0 || (extraout_r1_00[1] != 1)))) {
      uStack_1c = CONCAT13(1,(undefined3)uStack_1c);
      FUN_0103b0e4(param_1,(byte *)((int)&uStack_1c + 3),extraout_r1_00 + 1,extraout_r1_00 + 2,
                   extraout_r1_00,(byte *)0x0);
      *(ushort *)((int)&DAT_210006a8 + (uVar5 + 8) * 2) =
           *(ushort *)((int)&DAT_210006a8 + (uVar5 + 8) * 2) | 3;
      goto LAB_0103505c;
    }
LAB_010350f0:
    puVar7 = &DAT_0bad0004;
  }
  return puVar7;
}


