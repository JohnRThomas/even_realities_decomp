/*
 * Function: nrfx_twim_xfer
 * Entry:    0006abe0
 * Prototype: nrfx_err_t __stdcall nrfx_twim_xfer(nrfx_twim_t * p_instance, nrfx_twim_xfer_desc_t * p_xfer_desc, uint32_t flags)
 */


/* exclude_from_export */

nrfx_err_t nrfx_twim_xfer(nrfx_twim_t *p_instance,nrfx_twim_xfer_desc_t *p_xfer_desc,uint32_t flags)

{
  int iVar1;
  bool bVar2;
  uint32_t uVar3;
  undefined4 uVar4;
  int iVar5;
  nrfy_twim_xfer_desc_t *extraout_r2;
  nrfy_twim_xfer_desc_t *pnVar6;
  undefined4 uVar7;
  undefined **p_xfer;
  undefined **extraout_r2_00;
  undefined **p_xfer_00;
  undefined **extraout_r2_01;
  uint uVar8;
  int iVar9;
  NRF_TWIM_Type *p_reg;
  uint uVar10;
  nrfx_err_t nVar11;
  
  uVar10 = (uint)(byte)p_instance[1];
  if (((1 < uVar10) || (0xffff < *(uint *)p_xfer_desc[1].opaque)) ||
     (0xffff < *(uint *)p_xfer_desc[2].opaque)) {
    _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
            "(0 || (((p_instance->drv_inst_idx) == NRFX_TWIM1_INST_IDX) && (((p_xfer_desc->primary_length) < (1U << 16)) && ((p_xfer_desc->secondary_length) < (1U << 16)))) || (((p_instance->drv_inst_idx) == NRFX_TWIM2_INST_IDX) && (((p_xfer_desc->primary_length) < (1U << 16)) && ((p_xfer_desc->secondary_length) < (1U << 16)))) || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 || 0 |..." /* TRUNCATED STRING LITERAL */
            ,"WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_twim.c",593);
    goto LAB_0006ac10;
  }
  if (*(int *)(&DAT_2000bdb4 + uVar10 * 0x28) == 0) {
    if (p_xfer_desc->opaque[0] == 2) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
              "!((p_cb->handler == ((void *)0)) && (p_xfer_desc->type == NRFX_TWIM_XFER_TXRX))",
              "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_twim.c",601);
      goto LAB_0006ac10;
    }
    if (p_xfer_desc->opaque[0] == 3) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n",
              "!((p_cb->handler == ((void *)0)) && (p_xfer_desc->type == NRFX_TWIM_XFER_TXTX))",
              "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_twim.c",0x25a);
      goto LAB_0006ac10;
    }
  }
  p_reg = (NRF_TWIM_Type *)*p_instance;
  (&DAT_2000bdd7)[uVar10 * 0x28] = 0;
  if (((*(int *)p_xfer_desc[1].opaque != 0) &&
      ((*(uint *)p_xfer_desc[3].opaque & 0xe0000000) != 0x20000000)) ||
     ((p_xfer_desc->opaque[0] - 2 < 2 &&
      ((*(uint *)p_xfer_desc[4].opaque & 0xe0000000) != 0x20000000)))) {
    return NRFX_ERROR_INVALID_ADDR;
  }
  *(undefined4 *)p_reg[0xc2].opaque = 0x19c0202;
  iVar5 = uVar10 * 0x28;
  if ((&DAT_2000bdd8)[iVar5] != '\0') {
    *(undefined4 *)p_reg[0xc1].opaque = *(undefined4 *)(&DAT_2000bdbc + iVar5);
    return NRFX_ERROR_BUSY;
  }
  (&DAT_2000bdd8)[iVar5] = (flags & 0x14) == 0;
  (&DAT_2000bdd4)[iVar5] = p_xfer_desc->opaque[0];
  iVar1 = uVar10 * 0x28;
  (&DAT_2000bdd5)[iVar5] = p_xfer_desc->opaque[1];
  *(undefined4 *)(&DAT_2000bdc0 + iVar5) = *(undefined4 *)p_xfer_desc[3].opaque;
  *(undefined4 *)(&DAT_2000bdc4 + iVar5) = *(undefined4 *)p_xfer_desc[1].opaque;
  *(undefined4 *)(&DAT_2000bdc8 + iVar5) = *(undefined4 *)p_xfer_desc[4].opaque;
  uVar4 = *(undefined4 *)p_xfer_desc[2].opaque;
  *(uint32_t *)(&DAT_2000bdd0 + iVar5) = flags;
  *(undefined4 *)(&DAT_2000bdcc + iVar5) = uVar4;
  (&DAT_2000bdd9)[iVar5] = (byte)((flags << 0x1b) >> 0x1f);
  *(uint *)p_reg[0x162].opaque = (uint)p_xfer_desc->opaque[1];
  *(undefined4 *)p_reg[0x58].opaque = 0;
  *(undefined4 *)p_reg[0x52].opaque = 0;
  *(undefined4 *)p_reg[0x49].opaque = 0;
  *(undefined4 *)p_reg[0x41].opaque = 0;
  *(uint *)p_reg[0x154].opaque = (uint)((flags & 1) != 0);
  *(uint *)p_reg[0x150].opaque = (uint)((flags & 2) != 0);
  switch(p_xfer_desc->opaque[0]) {
  case 0:
    bVar2 = (flags & 0x20) != 0;
    uVar4 = *(undefined4 *)(&DAT_2000bdc4 + iVar1);
    *(undefined4 *)p_reg[0x151].opaque = *(undefined4 *)(&DAT_2000bdc0 + iVar1);
    if (bVar2) {
      uVar7 = 0x100;
    }
    else {
      uVar7 = 0x200;
    }
    *(undefined4 *)p_reg[0x152].opaque = uVar4;
    if (bVar2) {
      *(undefined4 *)p_reg[0x80].opaque = uVar7;
      p_xfer_00 = &PTR_s__s____Received_exit_command_from_00040000;
    }
    else {
      *(undefined4 *)p_reg[0x80].opaque = uVar7;
      p_xfer_00 = (undefined **)&DAT_00000002;
    }
    *(undefined ***)(&DAT_2000bdbc + uVar10 * 0x28) = p_xfer_00;
    *(undefined4 *)p_reg[8].opaque = 1;
    goto LAB_0006adce;
  case 1:
    uVar4 = *(undefined4 *)(&DAT_2000bdc4 + iVar1);
    *(undefined4 *)p_reg[0x14d].opaque = *(undefined4 *)(&DAT_2000bdc0 + iVar1);
    *(undefined4 *)p_reg[0x14e].opaque = uVar4;
    uVar4 = 0x1000;
    break;
  case 2:
    uVar4 = *(undefined4 *)(&DAT_2000bdc4 + iVar1);
    *(undefined4 *)p_reg[0x151].opaque = *(undefined4 *)(&DAT_2000bdc0 + iVar1);
    *(undefined4 *)p_reg[0x152].opaque = uVar4;
    uVar4 = *(undefined4 *)(&DAT_2000bdcc + iVar1);
    *(undefined4 *)p_reg[0x14d].opaque = *(undefined4 *)(&DAT_2000bdc8 + iVar1);
    *(undefined4 *)p_reg[0x14e].opaque = uVar4;
    uVar4 = 0x1080;
    break;
  case 3:
    if ((flags & 0x10) != 0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!(flags & (1UL << 4))",
              "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_twim.c",468);
LAB_0006ac10:
                    /* WARNING: Subroutine does not return */
      k_panic();
    }
    if ((flags & 8) != 0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!(flags & (1UL << 3))",
              "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_twim.c",0x1d5);
      goto LAB_0006ac10;
    }
    if ((flags & 4) != 0) {
      _ASSERT("ASSERTION FAIL [%s] @ %s:%d\n","!(flags & (1UL << 2))",
              "WEST_TOPDIR/modules/hal/nordic/nrfx/drivers/src/nrfx_twim.c",470);
      goto LAB_0006ac10;
    }
    *(undefined4 *)p_reg[0x80].opaque = 0x100;
    pnVar6 = *(nrfy_twim_xfer_desc_t **)(&DAT_2000bdc0 + iVar1);
    uVar4 = *(undefined4 *)(&DAT_2000bdc4 + iVar1);
    *(nrfy_twim_xfer_desc_t **)p_reg[0x151].opaque = pnVar6;
    *(undefined4 *)p_reg[0x152].opaque = uVar4;
    *(undefined4 *)p_reg[2].opaque = 1;
    do {
      uVar3 = __nrfy_internal_twim_events_process(p_reg,0x100000,pnVar6);
      pnVar6 = extraout_r2;
    } while (uVar3 != 0);
    uVar4 = *(undefined4 *)(&DAT_2000bdcc + iVar1);
    *(undefined4 *)p_reg[0x151].opaque = *(undefined4 *)(&DAT_2000bdc8 + iVar1);
    *(undefined4 *)p_reg[0x152].opaque = uVar4;
    p_xfer_00 = &PTR_s__s____Received_exit_command_from_00040000;
    goto LAB_0006adcc;
  default:
    nVar11 = NRFX_ERROR_INVALID_PARAM;
    p_xfer_00 = (undefined **)0x0;
    goto LAB_0006add2;
  }
  *(undefined4 *)p_reg[0x80].opaque = uVar4;
  *(undefined4 *)p_reg[8].opaque = 1;
  p_xfer_00 = (undefined **)&DAT_00000002;
LAB_0006adcc:
  *(undefined ***)(&DAT_2000bdbc + uVar10 * 0x28) = p_xfer_00;
LAB_0006adce:
  nVar11 = NRFX_SUCCESS;
LAB_0006add2:
  iVar5 = uVar10 * 0x28;
  iVar9 = *(int *)(&DAT_2000bdb4 + iVar5);
  if (((flags & 8) == 0) && (p_xfer_desc->opaque[0] != 3)) {
    if (p_xfer_desc->opaque[0] == 1) {
      *(undefined4 *)p_reg->opaque = 1;
      if (iVar9 == 0) {
        pnVar6 = *(nrfy_twim_xfer_desc_t **)(&DAT_2000bdc4 + iVar5);
        if (pnVar6 == (nrfy_twim_xfer_desc_t *)0x0) {
          *(undefined4 *)p_reg[5].opaque = 1;
        }
        do {
          uVar3 = __nrfy_internal_twim_events_process(p_reg,0x40202,pnVar6);
          pnVar6 = (nrfy_twim_xfer_desc_t *)&DAT_00000001;
          if ((uVar3 & 0x200) != 0) {
            *(undefined4 *)p_reg[5].opaque = 1;
          }
        } while ((uVar3 & 0x40002) == 0);
      }
    }
    else {
      *(undefined4 *)p_reg[2].opaque = 1;
      if (iVar9 == 0) {
        uVar8 = 0;
        if (*(int *)(&DAT_2000bdc4 + iVar5) == 0) {
          *(undefined4 *)p_reg[5].opaque = 1;
        }
LAB_0006af3e:
        do {
          if ((uVar8 & 0x40002) != 0) break;
          uVar8 = __nrfy_internal_twim_events_process
                            (p_reg,0x40202,(nrfy_twim_xfer_desc_t *)p_xfer_00);
          p_xfer_00 = p_xfer;
          if ((uVar8 & 0x200) != 0) {
            uVar3 = __nrfy_internal_twim_events_process
                              (p_reg,0x1000000,(nrfy_twim_xfer_desc_t *)p_xfer);
            if (uVar3 == 0) {
              p_xfer_00 = (undefined **)&DAT_00000001;
              *(undefined4 *)p_reg[8].opaque = 1;
              *(undefined4 *)p_reg[5].opaque = 1;
            }
            else {
              p_xfer_00 = extraout_r2_00;
              if ((*(uint *)p_reg[0x80].opaque & 0x200) == 0) {
                p_xfer_00 = (undefined **)&DAT_00000001;
                *(undefined4 *)p_reg[8].opaque = 1;
                *(undefined4 *)p_reg[5].opaque = 1;
                uVar8 = 0;
              }
              if (-1 < (int)(*(uint *)p_reg[0x80].opaque << 0x17)) goto LAB_0006af3e;
              __nrfy_internal_twim_events_process(p_reg,0x40000,(nrfy_twim_xfer_desc_t *)p_xfer_00);
              p_xfer_00 = extraout_r2_01;
            }
            uVar8 = 0;
          }
        } while( true );
      }
    }
    if (*(int *)p_xfer_desc[1].opaque == 0) {
      if (*(int *)(&DAT_2000bdb4 + uVar10 * 0x28) == 0) goto LAB_0006af96;
      *(undefined4 *)p_reg[5].opaque = 1;
    }
  }
  if (*(int *)(&DAT_2000bdb4 + uVar10 * 0x28) != 0) {
    if ((flags & 4) != 0) {
      *(undefined4 *)(&DAT_2000bdbc + uVar10 * 0x28) = 0;
    }
    if ((flags & 0x40) == 0) {
      *(uint *)(&DAT_2000bdbc + uVar10 * 0x28) = *(uint *)(&DAT_2000bdbc + uVar10 * 0x28) | 2;
    }
    iVar5 = uVar10 * 0x28;
    *(uint *)(&DAT_2000bdbc + iVar5) = *(uint *)(&DAT_2000bdbc + iVar5) | 0x200;
    *(undefined4 *)p_reg[0xc1].opaque = *(undefined4 *)(&DAT_2000bdbc + iVar5);
    return nVar11;
  }
LAB_0006af96:
  uVar8 = *(uint *)p_reg[0x131].opaque;
  *(uint *)p_reg[0x131].opaque = uVar8;
  (&DAT_2000bdd8)[uVar10 * 0x28] = 0;
  if (uVar8 == 0) {
    if (((flags & 0x40) == 0) &&
       (bVar2 = xfer_completeness_check
                          ((NRF_TWI_Type *)p_reg,(twi_control_block_t *)(&DAT_2000bdb4 + iVar1)),
       !bVar2)) {
      nVar11 = NRFX_ERROR_INTERNAL;
    }
  }
  else {
    nVar11 = (uVar8 & 2) != 0 || (uVar8 & 1) == 0;
    if ((uVar8 & 4) != 0) {
      nVar11 = NRFX_ERROR_NO_MEM;
    }
  }
  return nVar11;
}


