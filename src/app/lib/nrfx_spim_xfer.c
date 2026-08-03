/*
 * Function: nrfx_spim_xfer
 * Entry:    0006a5ac
 * Prototype: nrfx_err_t __stdcall nrfx_spim_xfer(nrfx_spim_t * p_instance, nrfx_spim_xfer_desc_t * p_xfer_desc, uint32_t flags)
 */


/* exclude_from_export */

nrfx_err_t nrfx_spim_xfer(nrfx_spim_t *p_instance,nrfx_spim_xfer_desc_t *p_xfer_desc,uint32_t flags)

{
  uint32_t uVar1;
  int iVar2;
  nrfx_spim_xfer_desc_t nVar3;
  nrfx_spim_xfer_desc_t nVar4;
  sbyte sVar5;
  nrfx_spim_xfer_desc_t nVar6;
  NRF_SPIM_Type *p_reg;
  uint uVar7;
  nrfx_spim_t *local_30;
  nrfx_spim_xfer_desc_t *pnStack_2c;
  uint32_t uStack_28;
  nrfx_spim_xfer_desc_t local_24;
  
  uVar7 = (uint)(byte)p_instance[1];
  local_30 = p_instance;
  pnStack_2c = p_xfer_desc;
  uStack_28 = flags;
  if ((&DAT_2000bd88)[uVar7 * 0x24] == '\0') {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","p_cb->state != NRFX_DRV_STATE_UNINITIALIZED",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_spim.c",0x314);
    goto LAB_0006a5d6;
  }
  if ((*p_xfer_desc == 0) && (p_xfer_desc[1] != 0)) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
            "p_xfer_desc->p_tx_buffer != ((void *)0) || p_xfer_desc->tx_length == 0",
            "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_spim.c",789);
    goto LAB_0006a5d6;
  }
  if (p_xfer_desc[2] == 0) {
    if (p_xfer_desc[3] != 0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
              "p_xfer_desc->p_rx_buffer != ((void *)0) || p_xfer_desc->rx_length == 0",
              "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_spim.c",790);
      goto LAB_0006a5d6;
    }
    sVar5 = (&DAT_000f5013)[uVar7];
LAB_0006a618:
    if (p_xfer_desc[1] >> sVar5 == 0) {
      if (((flags & 8) == 0) || ((&DAT_2000bd8c)[uVar7 * 9] == -1)) {
        if ((&DAT_2000bd89)[uVar7 * 0x24] != '\0') {
          return NRFX_ERROR_BUSY;
        }
        if (((&DAT_2000bd6c)[uVar7 * 9] != 0) && ((flags & 0x14) == 0)) {
          (&DAT_2000bd89)[uVar7 * 0x24] = 1;
        }
        nVar3 = p_xfer_desc[1];
        nVar4 = p_xfer_desc[2];
        nVar6 = p_xfer_desc[3];
        iVar2 = uVar7 * 0x24;
        *(nrfx_spim_xfer_desc_t *)(&DAT_2000bd78 + iVar2) = *p_xfer_desc;
        *(nrfx_spim_xfer_desc_t *)(&DAT_2000bd7c + iVar2) = nVar3;
        *(nrfx_spim_xfer_desc_t *)(&DAT_2000bd80 + iVar2) = nVar4;
        *(nrfx_spim_xfer_desc_t *)(&DAT_2000bd84 + iVar2) = nVar6;
        uVar1 = (&DAT_2000bd8c)[uVar7 * 9];
        if (uVar1 != 0xffffffff) {
          if ((&DAT_2000bd8b)[iVar2] == '\0') {
            nrfy_gpio_pin_clear(uVar1);
          }
          else {
            nrfy_gpio_pin_set(uVar1);
          }
        }
        p_reg = (NRF_SPIM_Type *)*p_instance;
        if (((*p_xfer_desc != 0) && ((*p_xfer_desc & 0xe0000000) != 0x20000000)) ||
           ((p_xfer_desc[2] != 0 && ((p_xfer_desc[2] & 0xe0000000) != 0x20000000)))) {
          (&DAT_2000bd89)[uVar7 * 0x24] = 0;
          return NRFX_ERROR_INVALID_ADDR;
        }
        p_reg[0x154] = (uint)((flags & 1) != 0);
        p_reg[0x150] = (uint)((flags & 2) != 0);
        local_30 = (nrfx_spim_t *)*p_xfer_desc;
        pnStack_2c = (nrfx_spim_xfer_desc_t *)p_xfer_desc[1];
        uStack_28 = p_xfer_desc[2];
        local_24 = p_xfer_desc[3];
        p_reg[0x151] = (NRF_SPIM_Type)local_30;
        p_reg[0x152] = (NRF_SPIM_Type)pnStack_2c;
        p_reg[0x14d] = uStack_28;
        p_reg[0x14e] = local_24;
        p_reg[0x46] = 0;
        p_reg[0x140] = 7;
        if ((flags & 8) == 0) {
          iVar2 = (&DAT_2000bd6c)[uVar7 * 9];
          p_reg[4] = 1;
          if (iVar2 == 0) {
            do {
            } while (p_reg[0x46] == 0);
            __nrfy_internal_spim_events_process(p_reg,0x40,(nrfy_spim_xfer_desc_t *)&local_30);
          }
          if ((&DAT_2000bd6c)[uVar7 * 9] == 0) {
            uVar1 = (&DAT_2000bd8c)[uVar7 * 9];
            if (uVar1 != 0xffffffff) {
              if ((&DAT_2000bd8b)[uVar7 * 0x24] == '\0') {
                nrfy_gpio_pin_set(uVar1);
              }
              else {
                nrfy_gpio_pin_clear(uVar1);
              }
            }
            spim_abort(p_reg,&DAT_2000bd6c + uVar7 * 9);
            return NRFX_SUCCESS;
          }
        }
        else if ((&DAT_2000bd6c)[uVar7 * 9] == 0) {
          uVar1 = (&DAT_2000bd8c)[uVar7 * 9];
          if (uVar1 == 0xffffffff) {
            return NRFX_SUCCESS;
          }
          if ((&DAT_2000bd8b)[uVar7 * 0x24] != '\0') {
            nrfy_gpio_pin_clear(uVar1);
            return NRFX_SUCCESS;
          }
          nrfy_gpio_pin_set(uVar1);
          return NRFX_SUCCESS;
        }
        if ((flags & 4) == 0) {
          p_reg[0xc1] = 0x40;
        }
        else {
          p_reg[0xc2] = 0x40;
        }
        return NRFX_SUCCESS;
      }
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
              "!(flags & (1UL << 3)) || (p_cb->ss_pin == 0xFFFFFFFF)",
              "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_spim.c",794);
      goto LAB_0006a5d6;
    }
  }
  else {
    sVar5 = (&DAT_000f5013)[uVar7];
    if (p_xfer_desc[3] >> sVar5 == 0) goto LAB_0006a618;
  }
  _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
          "((p_xfer_desc->rx_length < (1UL << (easydma_support_bits[p_instance->drv_inst_idx]))) && (p_xfer_desc->tx_length < (1UL << (easydma_support_bits[p_instance->drv_inst_idx]))))"
          ,"WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_spim.c",791);
LAB_0006a5d6:
                    /* WARNING: Subroutine does not return */
  k_panic();
}


