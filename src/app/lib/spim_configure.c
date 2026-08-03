/*
 * Function: spim_configure
 * Entry:    0006a168
 * Prototype: void __stdcall spim_configure(nrfx_spim_t * p_instance, nrfx_spim_config_t * p_config)
 */


/* exclude_from_export */

void spim_configure(nrfx_spim_t *p_instance,nrfx_spim_config_t *p_config)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  bool bVar8;
  int iVar9;
  undefined4 uVar10;
  undefined **ppuVar11;
  nrfx_spim_t nVar12;
  undefined4 uVar13;
  undefined4 uVar14;
  uint uVar15;
  nrf_gpio_pin_drive_t drive;
  int iVar16;
  
  ppuVar11 = *(undefined ***)p_config[5].opaque;
  uVar15 = (uint)(byte)p_instance[1];
  if (ppuVar11 == (undefined **)0x1e8480) {
    uVar14 = 0x20000000;
  }
  else if (ppuVar11 < (undefined **)0x1e8481) {
    if (ppuVar11 == (undefined **)0x7a120) {
      uVar14 = 0x8000000;
    }
    else if (ppuVar11 < (undefined **)0x7a121) {
      if (ppuVar11 == &PTR_s_ble_process_put_req_0001e848) {
        uVar14 = 0x2000000;
      }
      else {
        if (ppuVar11 != (undefined **)0x3d090) goto LAB_0006a19a;
        uVar14 = 0x4000000;
      }
    }
    else {
      if (ppuVar11 != (undefined **)0xf4240) {
LAB_0006a19a:
        _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","0",
                "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_spim.c",348);
                    /* WARNING: Subroutine does not return */
        k_panic();
      }
      uVar14 = 0x10000000;
    }
  }
  else if (ppuVar11 == (undefined **)0xf42400) {
    uVar14 = 0xa000000;
  }
  else if (ppuVar11 < (undefined **)0xf42401) {
    if (ppuVar11 == (undefined **)&DAT_003d0900) {
      uVar14 = 0x40000000;
    }
    else {
      if (ppuVar11 != (undefined **)0x7a1200) goto LAB_0006a19a;
      uVar14 = 0x80000000;
    }
  }
  else {
    if (ppuVar11 != (undefined **)0x1e84800) goto LAB_0006a19a;
    uVar14 = 0x14000000;
  }
  (&DAT_2000bd8a)[uVar15 * 0x24] = (&DAT_2000bd8a)[uVar15 * 0x24] & 0xfe | p_config[8].opaque[3] & 1
  ;
  (&DAT_2000bd8b)[(uint)(byte)p_instance[1] * 0x24] = p_config[4].opaque[0];
  if (p_config[8].opaque[3] == 0) {
    if (*(int *)p_config[5].opaque == 32000000) {
      drive = 3;
    }
    else {
      drive = 0;
    }
    pin_init(*(uint32_t *)p_config->opaque,1,0,drive,(uint)(1 < p_config[6].opaque[0]));
    pin_init(*(uint32_t *)p_config[1].opaque,1,0,drive,0);
    pin_init(*(uint32_t *)p_config[2].opaque,0,(uint)p_config[6].opaque[2],drive,0);
    pin_init(*(uint32_t *)p_config[3].opaque,1,0,drive,p_config[4].opaque[0] ^ 1);
    pin_init(*(uint32_t *)p_config[7].opaque,1,0,drive,1);
  }
  nVar12 = p_instance[1];
  bVar3 = p_config[8].opaque[1];
  if (((char)nVar12 == '\0') || (bVar3 == 0)) {
    (&DAT_2000bd8c)[uVar15 * 9] = *(undefined4 *)p_config[3].opaque;
    (&DAT_2000bd8b)[uVar15 * 0x24] = p_config[4].opaque[0];
  }
  else {
    (&DAT_2000bd8c)[uVar15 * 9] = 0xffffffff;
  }
  bVar1 = p_config[6].opaque[1];
  bVar4 = p_config[4].opaque[2];
  bVar5 = p_config[6].opaque[0];
  iVar16 = *(int *)p_config[7].opaque;
  if (p_config[8].opaque[1] == 0) {
    iVar9 = -1;
  }
  else {
    iVar9 = *(int *)p_config[3].opaque;
  }
  bVar2 = p_config[4].opaque[0];
  bVar6 = p_config[8].opaque[2];
  bVar7 = p_config[8].opaque[0];
  bVar8 = false;
  if ((char)nVar12 != '\0') {
    if (bVar3 == 0) {
      bVar8 = false;
      if (iVar16 != -1) {
        bVar8 = true;
      }
    }
    else {
      bVar8 = true;
    }
  }
  bVar3 = p_config[9].opaque[0];
  nVar12 = *p_instance;
  if (bVar3 == 0) {
    uVar10 = *(undefined4 *)p_config[1].opaque;
    uVar13 = *(undefined4 *)p_config[2].opaque;
    *(undefined4 *)(nVar12 + 0x508) = *(undefined4 *)p_config->opaque;
    *(undefined4 *)(nVar12 + 0x50c) = uVar10;
    *(undefined4 *)(nVar12 + 0x510) = uVar13;
  }
  *(uint *)(nVar12 + 0x5c0) = (uint)bVar4;
  uVar15 = (uint)(bVar1 != 0);
  *(undefined4 *)(nVar12 + 0x524) = uVar14;
  if (bVar5 == 2) {
    uVar15 = uVar15 | 4;
  }
  else if (bVar5 == 3) {
    uVar15 = uVar15 | 6;
  }
  else if (bVar5 == 1) {
    uVar15 = uVar15 | 2;
  }
  *(uint *)(nVar12 + 0x554) = uVar15;
  if (bVar8) {
    if (bVar3 == 0) {
      if (iVar16 != -1) {
        *(int *)(nVar12 + 0x56c) = iVar16;
      }
      if (iVar9 != -1) {
        *(int *)(nVar12 + 0x514) = iVar9;
        *(uint *)(nVar12 + 0x568) = (uint)bVar2;
        *(uint *)(nVar12 + 0x564) = (uint)bVar6;
      }
    }
    *(uint *)(nVar12 + 0x560) = (uint)bVar7;
  }
  if ((&DAT_2000bd6c)[(uint)(byte)p_instance[1] * 9] == 0) {
    return;
  }
  arch_irq_enable((int)(*p_instance << 0xc) >> 0x18);
  return;
}


