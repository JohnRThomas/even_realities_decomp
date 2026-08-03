/*
 * Function: nrfx_gpiote_trigger_enable
 * Entry:    00068e44
 * Prototype: void __stdcall nrfx_gpiote_trigger_enable(nrfx_gpiote_pin_t pin, bool int_enable)
 */


/* exclude_from_export_ai */

void nrfx_gpiote_trigger_enable(nrfx_gpiote_pin_t pin,bool int_enable)

{
  ushort uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  NRF_GPIO_Type *pNVar7;
  uint extraout_r1;
  uint uVar8;
  uint pin_00;
  uint uVar9;
  uint *puVar10;
  int iVar11;
  bool bVar12;
  uint local_34;
  uint local_30 [3];
  
  uVar6 = Peripherals::GPIOTE0_S.INTENSET;
  uVar6 = nrfx_gpiote_in_event_get(uVar6 & 0xff | 0x80000000);
  if ((int)uVar6 < 0) {
    local_30[0] = Peripherals::P0_S.LATCH;
    Peripherals::P0_S.LATCH = local_30[0];
    local_30[1] = Peripherals::P1_S.LATCH;
    Peripherals::P1_S.LATCH = local_30[1];
LAB_00068e76:
    iVar11 = 0;
    puVar10 = local_30;
    do {
      while (uVar8 = *puVar10, uVar8 != 0) {
        bVar2 = (byte)uVar8;
        bVar3 = (byte)(uVar8 >> 8);
        bVar4 = (byte)(uVar8 >> 0x10);
        bVar5 = (byte)(uVar8 >> 0x18);
        pin_00 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1
                                          ) << 1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                       bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) <<
                         0x18 | (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 |
                                                 bVar3 >> 2 & 1) << 1 | bVar3 >> 3 & 1) << 1 |
                                               bVar3 >> 4 & 1) << 1 | bVar3 >> 5 & 1) << 1 |
                                             bVar3 >> 6 & 1) << 1 | bVar3 >> 7) << 0x10 |
                         (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 | bVar4 >> 2 & 1
                                          ) << 1 | bVar4 >> 3 & 1) << 1 | bVar4 >> 4 & 1) << 1 |
                                       bVar4 >> 5 & 1) << 1 | bVar4 >> 6 & 1) << 1 | bVar4 >> 7) <<
                         8 | (uint)(byte)((((((((bVar5 & 1) << 1 | bVar5 >> 1 & 1) << 1 |
                                              bVar5 >> 2 & 1) << 1 | bVar5 >> 3 & 1) << 1 |
                                            bVar5 >> 4 & 1) << 1 | bVar5 >> 5 & 1) << 1 |
                                          bVar5 >> 6 & 1) << 1 | bVar5 >> 7)) |
                 (uint)(byte)" 00000000000000"[iVar11 + 0xf] << 5;
        bVar5 = get_pin_idx(pin_00);
        uVar1 = *(ushort *)((int)&DAT_20002be0 + (bVar5 + 8) * 2);
        *(byte *)((int)puVar10 + (extraout_r1 >> 3)) =
             *(byte *)((int)puVar10 + (extraout_r1 >> 3)) & ~(byte)(1 << (extraout_r1 & 7));
        local_34 = pin_00;
        pNVar7 = nrf_gpio_pin_port_decode(&local_34);
        uVar9 = (uVar1 & 0x1f) >> 2;
        uVar8 = (pNVar7[local_34 + 0x80] & 0x3ffff) >> 0x10;
        if ((int)((uint)(uVar1 >> 2) << 0x1d) < 0) {
          nrfx_gpiote_pin_uninit(pin_00);
          local_34 = pin_00;
          pNVar7 = nrf_gpio_pin_port_decode(&local_34);
          if (uVar8 == (pNVar7[local_34 + 0x80] & 0x3ffff) >> 0x10) {
            nrfy_gpio_cfg_sense_set(pin_00,0);
            nrfy_gpio_cfg_sense_set(pin_00,uVar8);
          }
        }
        else {
          if (uVar8 == 2) {
            nrfy_gpio_cfg_sense_set(pin_00,3);
            bVar12 = (uVar9 & 5) == 1;
LAB_00068f4c:
            if (!bVar12) goto LAB_00068f12;
          }
          else {
            nrfy_gpio_cfg_sense_set(pin_00,2);
            if (uVar9 != 3) {
              if (uVar8 != 3) goto LAB_00068f12;
              bVar12 = uVar9 == 2;
              goto LAB_00068f4c;
            }
          }
          nrfx_gpiote_pin_uninit(pin_00);
        }
LAB_00068f12:
        local_34 = pin_00;
        pNVar7 = nrf_gpio_pin_port_decode(&local_34);
        pNVar7[8] = 1 << (local_34 & 0xff);
      }
      puVar10 = puVar10 + 1;
      if (iVar11 != 0) goto LAB_00068f70;
      iVar11 = 1;
    } while( true );
  }
LAB_00068f96:
  for (; uVar6 != 0; uVar6 = uVar6 & ~(1 << iVar11)) {
    bVar2 = (byte)uVar6;
    bVar3 = (byte)(uVar6 >> 8);
    bVar4 = (byte)(uVar6 >> 0x10);
    bVar5 = (byte)(uVar6 >> 0x18);
    iVar11 = LZCOUNT((uint)(byte)((((((((bVar2 & 1) << 1 | bVar2 >> 1 & 1) << 1 | bVar2 >> 2 & 1) <<
                                      1 | bVar2 >> 3 & 1) << 1 | bVar2 >> 4 & 1) << 1 |
                                   bVar2 >> 5 & 1) << 1 | bVar2 >> 6 & 1) << 1 | bVar2 >> 7) << 0x18
                     | (uint)(byte)((((((((bVar3 & 1) << 1 | bVar3 >> 1 & 1) << 1 | bVar3 >> 2 & 1)
                                        << 1 | bVar3 >> 3 & 1) << 1 | bVar3 >> 4 & 1) << 1 |
                                     bVar3 >> 5 & 1) << 1 | bVar3 >> 6 & 1) << 1 | bVar3 >> 7) <<
                       0x10 | (uint)(byte)((((((((bVar4 & 1) << 1 | bVar4 >> 1 & 1) << 1 |
                                               bVar4 >> 2 & 1) << 1 | bVar4 >> 3 & 1) << 1 |
                                             bVar4 >> 4 & 1) << 1 | bVar4 >> 5 & 1) << 1 |
                                           bVar4 >> 6 & 1) << 1 | bVar4 >> 7) << 8 |
                     (uint)(byte)((((((((bVar5 & 1) << 1 | bVar5 >> 1 & 1) << 1 | bVar5 >> 2 & 1) <<
                                      1 | bVar5 >> 3 & 1) << 1 | bVar5 >> 4 & 1) << 1 |
                                   bVar5 >> 5 & 1) << 1 | bVar5 >> 6 & 1) << 1 | bVar5 >> 7));
    nrfx_gpiote_pin_uninit(((&Peripherals::GPIOTE0_S.CONFIG_0_)[iVar11] & 0x3fff) >> 8);
  }
  return;
LAB_00068f70:
  nrfx_gpiote_in_event_get(0x80000000);
  local_30[0] = Peripherals::P0_S.LATCH;
  Peripherals::P0_S.LATCH = local_30[0];
  local_30[1] = Peripherals::P1_S.LATCH;
  Peripherals::P1_S.LATCH = local_30[1];
  if (local_30[0] == 0 && local_30[1] == 0) goto code_r0x00068f90;
  goto LAB_00068e76;
code_r0x00068f90:
  uVar6 = uVar6 & 0x7fffffff;
  goto LAB_00068f96;
}


